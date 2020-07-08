#include <stdio.h>
#include <conio.h>
#include <windows.h>
void gotoxy(int x, int y); //커서위치 제어 
void display_text(int count); //문제번호 출력 
void display_question(void); // 문제 내용 출력 
void display_result(void); // 해설 출력 
void intro_game(void);  // 게임 설명  
char sol[10][11];  //사용자의 입력 값을 저장할 배열
int main(void)
{ 
	intro_game(); //게임설명 
	display_question(); //문제 출력 
	printf("\n문제풀이가 모두 끝났습니다.\n");
	printf("\n\n풀이를 보려면 아무키나 누르시오.");
	getch();
	display_result(); //결과 출력 
	return 0;
}

void gotoxy(int x, int y) //커서 위치 이동  
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void display_text(int count) //문제 번호 출력  (count+1)
{
	gotoxy(1,2);
	printf("다음 문제를 읽고 답을 입력하시오.\n\n");
	printf("(%d번 문제) \n\n", count+1);

}
void display_question(void) //심리테스트 질문 표시(파일처리) 
{
	FILE *fp1;
	char chr1[82];
	int line=5, count=0;
	char *file1="심리테스트질문.txt"; //파일 경로 불러오기  
	fp1=fopen(file1, "r"); //파일 오픈  
	system("cls"); //클리어  
	while(!feof(fp1))
	{
		fgets(chr1, 80, fp1);
		if (chr1[0]==10) //Enter
		{
			display_text(count);
			gotoxy(1, line);
			scanf("%s", sol[count]); //답 sol[count] 배열에 저장  
			system("cls");
			line=5;
			count++;
		}
		else
		{
			gotoxy(1, line++);
			printf("%s", chr1);
		}
	}
	display_text(count);
	gotoxy(1, line);
	scanf("%s", sol[count]);
	fclose(fp1);

}
void display_result(void) //질문 해설(파일처리) 
{
	FILE *fp2;
	char chr1[82];
	int line=5, count=0;
	char *file2="심리테스트해설.txt"; //파일경로 불러오기 
	fp2=fopen(file2, "r"); //파일오픈  
	system("cls"); //클리어 
	while(!feof(fp2))
	{
		fgets(chr1, 80, fp2);
		if (chr1[0]==10)
		{
			gotoxy(1, line+1);
			printf("당신의 답은 : %s\n", sol[count]); //저장된 배열 불러와서 출력  
			printf("다음문제의 해설은 아무키나 누르시오.");
			getch();
			system("cls");
			line=5;
			count++;
		}
		else
		{
			gotoxy(1, line++);
			printf("%s", chr1);
		}
	}
	gotoxy(1, line+1);
	printf("당신의 답은 : %s\n", sol[count]);
	fclose(fp2);

}
void intro_game(void) //게임 설명  
{
	system("cls");
	printf("심리테스트 게임\n\n");
	printf("제시되는 문제에 모두 답을 하고나면\n");
	printf("해설이 출력됩니다.\n\n");
	printf("아무키나 누르면 시작합니다. ");
	getch();

}
