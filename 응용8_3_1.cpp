#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>

void time_pass(time_t start); // ���۽ð��� ����ð��� ���̸� ���  
void display_time(long nhour, long nmin, long nsecond); //�ð�ǥ��  
void control_watch(void); // Ű�Է¹޾� �����ġ ����  

int main(void)
{
	display_time(0, 0, 0); //0�� 0�� 0�ʷ� �ʰ�ȭ 
	getch(); //Ű�Է� �ޱ�  
	control_watch(); // ����  
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
	   case 10 : //lf (Enter) ����/���� 
		time_pass(start);
	   case 32 : //Space (�ʱ�ȭ) 
		start=time(NULL);
		time_pass(start);
		break;
	   case 27 : //esc (����) 
		exit(0);
		break;
	}
   }while(key!=27); //esc �� �Էµ��� ������ ��� �ݺ� 

}
void time_pass(time_t start)
{
double hour, min, second;
long nhour, nmin, nsecond;
time_t now;
while(!kbhit()) //Ű �Է¿��� (�Է����� ������) �ݺ�  
{
	now=time(NULL); //���۽ð� �ʱ�ȭ(0) 
	second=difftime(now, start); //���۽ð��� ����ð��� ����  
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
	system("cls"); //ȭ�� Ŭ����(�ð� �ʱ�ȭ) 
	printf("stopwatch\n\n");
	printf("%.2ld�� %.2ld�� %.2ld�� \n\n", nhour, nmin, nsecond);
	printf("Enter:(����/����), SPACE:�����, Esc:����\n");

}
