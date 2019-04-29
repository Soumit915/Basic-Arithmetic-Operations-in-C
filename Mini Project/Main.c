#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include"Add.c"
#include"Subtract.c"
#include"Mul.c"
void gotoxy(int x,int y)
{
	HANDLE hStdout=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position={x,y};
	SetConsoleCursorPosition(hStdout,position);
}
int dyman()
{
	system("cls");
	FILE *fp;
	fp = fopen("Dynamic Manual.txt","r");
	char s[50];
	
	while(fgets(s,49,fp)!=NULL)
	{
		printf("%s",s);
	}
	
	while(1)
	{
		char ch=getch();
		if(ch=='Q' || ch=='q')
		{
			return 0;
		}
	}
	
}
void output()
{	
	system("cls");
	printf("\t\t\tWelcome to Child Mathematics...");
	
	gotoxy(53,2);
	printf("Press H for Dynamic Manual");
	gotoxy(53,3);
	printf("Press Q to Quit the system");
	
	gotoxy(0,3);
	printf("\n\n\t    Enter,\n\t      '1' for Addition,\n\t      '2' for Subtraction,\n\t      '3' for Multiplication : ");
}
errzone()
{
	char ch;
	int gar;
	
	system("cls");
	printf("\t\t\tError Detection Zone...");
	printf("\n\n\tWrong input. Your input is against all specifications or norms to run the code. Press 'H' to view Dynamic Manual or C to continue : ");
    fflush(stdin);
    fflush(stdout);
    ch=getch();
	
	while(ch!='C' && ch!='c' && ch!='H' && ch!='h')
    {
	  	system("cls");
	  	printf("\t\t\tError Detection Zone...");
		printf("\n\n\tYou are in error detected zone. Press either 'C' to continue or 'H' to view Dynamic Manual : ");
		fflush(stdin);
		ch=getch();
    }

    if(ch == 'H' || ch == 'h')
    {
		gar = dyman();
    }
    
}
int main()
{
	int gar;
	output();
	fflush(stdin);
	fflush(stdout);
	char ch=getch();
	
	do
	{
		switch(ch)
		{
			case '1' : system("cls");
					   gar = add();
					   if(gar==-1)
					   {
					   	   errzone();
					   }
					   break;
			
			case '2' : system("cls");
					   gar = subtract();
					   if(gar==-1)
					   {
					   	   errzone();
					   }
					   break;
				   
			case '3' : system("cls");
					   gar = product();
					   if(gar==-1)
					   {
					   	   errzone();
					   }
					   break;
				   
			case 'H' : gar = dyman();
					   break;
				   
			case 'h' : gar = dyman();
					   break;
				   
			case 'Q' : exit(0);
		
			case 'q' : exit(0);
		
			default : errzone();
		}
		
		output();
		fflush(stdin);
		ch=getch();
		
	}while(1);
	
}
