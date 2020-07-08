#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

void control_scoreboard(int st,int end,int r[],int h[],int e[], int b[]); 
// 각 회차별 정보를 득점판에 출력 
void display_scoreboard(int r[], int h[], int e[], int b[]); //득점판 출력  
void draw_check02(int c, int r);  //격자모양 출력 
void gotoxy(int x, int y); // 커서 위치 제어  

int main(void)
{
	int  baseball[12][2]={0},r[2]={0},h[2]={0},e[2]={0},b[2]={0}; 
	/* 각팀의 회차별 점수 저장. (첫번째:회차수 1~12회 , 두번째:원정팀0, 홈팀 1)
	r=> 점수저장(0:원정팀 1:홈팀)  h:안타 e:실책 b:포볼 => 0으로 초기화 */ 
	  
	display_scoreboard(r, h, e, b);	//초기상태의 득점판 출력  
	control_scoreboard(1, 9, r, h, e, b); //1~9회 까지 정보 처리 
	control_scoreboard(10, 12, r, h, e, b); //연장전 처리  *메인함수로 되돌아오면 무승부  
	gotoxy(1, 15); // 커서 위치 제어  
	printf("무승부입니다. 아무키나 누르시오\n"); //메인함수로 돌아왔을때 무승부라고 알림  
	getch();
	return 0;
}

void draw_check02(int c, int r) //격자모양 출력  
{
    int i, j;
    unsigned char a=0xa6; //  ┘ 
    unsigned char b[12]; 
    for(i=1;i<12;i++)
	b[i]=0xa0+i;
    printf("%c%c",a, b[3]); // ┌ 
    for(i=0;i<c-1;i++)
    {
	printf("%c%c", a, b[1]);
	printf("%c%c", a, b[8]);
    }
    printf("%c%c", a, b[1]);
    printf("%c%c", a, b[4]);
    printf("\n");
    for(i=0;i<r-1;i++)
    {
	printf("%c%c", a, b[2]);
	for(j=0;j<c;j++)
	{
		printf("  ");
		printf("%c%c",a, b[2]);
	}
	printf("\n");
	printf("%c%c", a, b[7]);
	for(j=0;j<c-1;j++)
	{
		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[11]);
	}
	printf("%c%c",a, b[1]);
	printf("%c%c",a, b[9]);
	printf("\n");
    }
    printf("%c%c", a, b[2]);
    for(j=0;j<c;j++)
    {
	printf("  ");
	printf("%c%c",a, b[2]);
    }
    printf("\n");
    printf("%c%c", a, b[6]);
    for(i=0;i<c-1;i++)
    {
	printf("%c%c", a, b[1]);
	printf("%c%c", a, b[10]);
    }
    printf("%c%c", a, b[1]);
    printf("%c%c", a, b[5]);
    printf("\n");
}

void display_scoreboard(int r[], int h[], int e[], int b[]) //득점판을 출력  
{
	int i, j;
	printf("스코어보드 \n");
	draw_check02(17, 3);
	for(i=1;i<=12;i++)
	{
		gotoxy(i*4+3, 3);
		printf("%2d", i);
	}
	gotoxy(13*4+4, 3);
	printf("R");
	gotoxy(14*4+4, 3);
	printf("H");
	gotoxy(15*4+4, 3);
	printf("E");
	gotoxy(16*4+4, 3);
	printf("B");
	gotoxy(3, 5);
	printf("CL");
	gotoxy(3, 7);
	printf("TG");
	for(j=0;j<=1;j++)
	{
		gotoxy(13*4+3, 5+2*j);
		printf("%2d", r[j]);
		gotoxy(14*4+3, 5+2*j);
		printf("%2d", h[j]);
		gotoxy(15*4+3, 5+2*j);
		printf("%2d", e[j]);
		gotoxy(16*4+3, 5+2*j);
		printf("%2d", b[j]);
	}
}
void control_scoreboard(int st,int end, int r[], int h[], int e[], int b[]) // 각 회차별 정보를 득점판에 출력  
{
   int i, j, k, rr, hh, ee, bb;
   char state[3];
   for(i=st;i<=end;i++)
   {
 	for(j=0;j<=1;j++)
	{
		if (j==0)
			strcpy(state, "초");
		else
			strcpy(state, "말");
		gotoxy(i*4+3, 5+2*j);
		printf("%2d", 0);
		gotoxy(1, 10);
		printf("%d회%s 결과 ", i, state);
		gotoxy(1, 11);

		printf("안타수 입력 : ");
		scanf("%d", &hh);
		h[j]+=hh;
		gotoxy(14*4+3, 5+2*j);
		printf("%2d", h[j]);
		gotoxy(1, 12);

		printf("실책수 입력 : ");
		scanf("%d", &ee);
		e[j]+=ee;
		gotoxy(15*4+3, 5+2*(1-j));
		printf("%2d", e[j]);

		gotoxy(1, 13);
		printf("포볼수 입력 : ");
		scanf("%d", &bb);
		b[j]+=bb;
		gotoxy(16*4+3, 5+2*j);
		printf("%2d", b[j]);
		gotoxy(1, 14);
		printf("점수   입력 : ");
		scanf("%d", &rr);
		r[j]+=rr;
		gotoxy(13*4+3, 5+2*j);
		printf("%2d", r[j]);

		gotoxy(i*4+3, 5+2*j);
		printf("%2d", rr);

		gotoxy(1, 15);
		printf("아무키나 누르시오....");
		getch();
		for(k=10; k<=15; k++)
		{
			gotoxy(1, k);
		    	printf("                       ");
		}
		if (9<=i&&((j==0&& r[0]<r[1]) || (j==1 && r[0]!=r[1])))
		{
			gotoxy(1, 15);
			printf("경기가 끝났습니다. 아무키나 누르시오\n");
			getch();
			exit(0);
		}
	}
   }
}
