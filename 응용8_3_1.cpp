#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>

void time_pass(time_t start); // 시작시간과 현재시간의 차이를 계산  
void display_time(long nhour, long nmin, long nsecond); //시간표시  
void control_watch(void); // 키입력받아 스톱워치 제어  

int main(void)
{
	display_time(0, 0, 0); //0시 0분 0초로 초가화 
	getch(); //키입력 받기  
	control_watch(); // 제어  
	return 0;
}
void control_watch(void)
{
   char key;
   time_t start;
   start=time(NULL);
   time_pass(start);
   do
   {
	key=getch();
	switch(key)
	{
	   case 10 : //lf (Enter) 정지/시작 
		time_pass(start);
	   case 32 : //Space (초기화) 
		start=time(NULL);
		time_pass(start);
		break;
	   case 27 : //esc (종료) 
		exit(0);
		break;
	}
   }while(key!=27); //esc 가 입력되지 않으면 계속 반복 

}
void time_pass(time_t start)
{
double hour, min, second;
long nhour, nmin, nsecond;
time_t now;
while(!kbhit()) //키 입력여부 (입력하지 않으면) 반복  
{
	now=time(NULL); //시작시간 초기화(0) 
	second=difftime(now, start); //시작시간과 현재시간의 차이  
	hour= (second/3600.);
	nhour= (long) hour;
	min= fmod(second, 3600.)/60;
	nmin= (long) min;
	second= fmod(second, 60);
	nsecond= (long) second;
	display_time(nhour, nmin, nsecond);
 }
}
void display_time(long nhour, long nmin, long nsecond)
{
	system("cls"); //화면 클리어(시간 초기화) 
	printf("stopwatch\n\n");
	printf("%.2ld시 %.2ld분 %.2ld초 \n\n", nhour, nmin, nsecond);
	printf("Enter:(시작/정지), SPACE:재시작, Esc:종료\n");

}
