#include<stdio.h>													// This program won't run...
#include<string.h>
/*int max(int a,int b)												// If you want to run this module(code) specifically unlock the comments from line 3-54 only...
{																	// But remember to recomment it if you want the main module to run. Or else, it(main module) won't compile.
	if(a>b)															// But don't uncomment these instructions. Happy Coding!:)
		return a;
	else
		return b;
}
int min(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}
void strint(char n1[],char n2[],int a1[],int a2[],int d1,int d2)
{
	int ln1=strlen(n1);
	int ln2=strlen(n2);
	
	int mxl=max(strlen(n1),strlen(n2));
	int i,ch;
	for(i=mxl-1;i>=0;i--)
	{
		if((d1==-1 && i<ln1) || (d1>0 && i<ln1-1))
		{
			ch=n1[i];
			ch-=48;
			a1[i]=ch;
		}
		
		if((d2==-1 && i<ln2) || (d2>0 && i<ln2-1))
		{
			ch=n2[i];
			ch-=48;
			a2[i]=ch;
		}
	}
}
int finddot(char n[])
{
	int l=strlen(n);
	int i;
	for(i=0;i<l;i++)
	{
		if(n[i]==46)
		{
			return i;
		}
	}
	
	return -1;
}*/
int product()
{
	int i,ch,j,s,carry=0;
	
	char n1[200];
	char n2[200];
	
	printf("\t\t\t      Multiplication Zone---\n");
	
	printf("\n\n\tEnter the first number : ");
	scanf("%s",n1);
	printf("\tEnter the second number : ");
	scanf("%s",n2);
	
	if(n1[0]=='.' || n2[0]=='.')
	{
		return -1;
	}
	
	int d1=finddot(n1);
	int d2=finddot(n2);
	
	int ln1=strlen(n1);
	int ln2=strlen(n2);
	
	if(d1!=-1)
	{
		for(i=d1+1;i<ln1;i++)
		{
			n1[i-1]=n1[i];
		}
		ln1-=1;
	}
	if(d2!=-1)
	{
		for(i=d2+1;i<ln2;i++)
		{
			n2[i-1]=n2[i];
		}
		ln2-=1;
	}
	
	int a1[max(ln1,ln2)];
	int a2[max(ln1,ln2)];
	
	int mxl=max(ln1,ln2);
	
	int gar=strint(n1,n2,a1,a2,d1,d2);
	if(gar==-1)
	{
		return -1;
	}
	
	int mul[ln1+ln2];
	for(i=0;i<ln1+ln2;i++)
	{
		mul[i]=0;
	}
	
	for(i=1;i<=ln2;i++)
	{
		carry=0;
		for(j=1;j<=ln1;j++)
		{
			s=(a1[ln1-j]*a2[ln2-i])+carry+mul[i+j-2];
			if(s>9)
			{
				mul[i+j-2]=s%10;
				carry=s/10;
			}
			else
			{
				mul[i+j-2]=s;
				carry=0;
			}
		}
		mul[i+j-2]=carry;
		/*for(j=ln1+ln2-1;j>=0;j--)
		{
			printf("%d",mul[j]);
		}
		printf("\n");*/
	}
	
	int in=ln1+ln2-1;
	for(i=ln1+ln2-1;i>=0;i--)
	{
		if(mul[i]!=0)
		{
			in=i;
			break;
		}
	}
	
	int muldot=-1;
	if(d1==-1)
	{
		d1=ln1;
	}
	if(d2==-1)
	{
		d2=ln2;
	}
	
	if(d1!=-1 || d2!=-1)
	{
		muldot=(ln1+ln2)-(d1+d2)-1;
	}
	
	if(muldot!=-1)
	{
		in=max(in,muldot);
	}
	printf("\tYour answer is : ");
	if(in==muldot)	/*To consider the '0.' precision*/
	{
		printf("0");
	}
	for(i=in;i>=0;i--)
	{
		if(i==muldot && muldot!=-1)
		{
			printf(".");
		}
		printf("%d",mul[i]);
	}
	printf("\n");
	
	while(1)
	{
		char ch=getch();
		if(ch=='Q' || ch=='q')
		{
			return 0;
		}
	}
}
