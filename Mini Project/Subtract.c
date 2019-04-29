#include<stdio.h>													// This program won't run...
#include<string.h>
#include<stdlib.h>
/*int max(int a,int b)												// If you want to run this module(code) specifically unlock the comments from line 4-41 and 102-116...
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
}*/
int fndlrg(int a1[],int a2[],int l)
{
	int i;
	for(i=0;i<l;i++)
	{
		if(a1[i]>a2[i])
		{
			return 1;
		}
		else
		{
			if(a1[i]<a2[i])
			{
				return 2;
			}
		}
	}
	return 0;
}
int *dosub(int a1[],int a2[],int ln1,int ln2)
{
	int i,carry=0,s;
	int *sub;
	sub=(int *)(malloc(ln1*sizeof(int)));
	for(i=0;i<ln1;i++)
	{
		sub[i]=0;
	}
	
	for(i=1;i<=ln2;i++)
	{
		s=a1[ln1-i]-a2[ln2-i]-carry;
		if(s<0)
		{
			sub[ln1-i]=s+10;
			carry=1;
		}
		else
		{
			sub[ln1-i]=s;
			carry=0;
		}
	}
	
	for(i=ln2+1;i<=ln1;i++)
	{
		s=a1[ln1-i]-carry;
		if(s<0)
		{
			sub[ln1-i]=s+10;
			carry=1;
		}
		else
		{
			sub[ln1-i]=s;
			carry=0;
		}
	}
	return sub;
}
/*int finddot(char n[])
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
int subtract()
{
	int i,ch,fl,sign,fi=0;
	
	char n1[200];
	char n2[200];
	
	printf("\t\t\t     Subtraction Zone---\n");
	
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
	
	int gar = strint(n1,n2,a1,a2,d1,d2);
	if(gar==-1)
	{
		return -1;
	}
	
	int nf1=0;
	int nf2=0;
	if(d1!=-1)
	{
		nf1 = strlen(n1)-d1-1;
	}
	if(d2!=-1)
	{
		nf2 = strlen(n2)-d2-1;
	}
	
	if(nf1==nf2)
	{
	}
	else
	{
		if(nf1<nf2)
		{
			for(i=ln1;i<ln1+(nf2-nf1);i++)
			{
				a1[i]=0;
			}
			ln1+=(nf2-nf1);
		}
		else
		{
			for(i=ln2;i<ln2+(nf1-nf2);i++)
			{
				a2[i]=0;
			}
			ln2+=(nf1-nf2);
		}
	}
	
	int condotpos1 = ln1-1;
	int condotpos2 = ln2-1;
	if(d1!=-1)
	{
		condotpos1=d1;
	}
	if(d2!=-1)
	{
		condotpos2=d2;
	}
	
	int in1=condotpos1,in2=condotpos2;
	for(i=0;i<=condotpos1;i++)
	{
		if(a1[i]!=0)
		{
			in1=i;
			break;
		}
	}
	for(i=0;i<=condotpos2;i++)
	{
		if(a2[i]!=0)
		{
			in2=i;
			break;
		}
	}
	
	for(i=0;i<ln1-in1;i++)
	{
		a1[i]=a1[i+in1];
	}
	for(i=0;i<ln2-in2;i++)
	{
		a2[i]=a2[i+in2];
	}
	
	ln1-=in1;
	ln2-=in2;
	mxl=max(ln1,ln2);
	
	/*for(i=0;i<ln1;i++)
	{
		printf("%d",a1[i]);
	}
	printf("\n");
	for(i=0;i<ln2;i++)
	{
		printf("%d",a2[i]);
	}
	printf("\n");*/
	
	if(ln1==ln2)
	{
		fl=fndlrg(a1,a2,ln1);
		if(fl==0)
		{
			printf("\tYour answer is : %d\n",0);
			while(1)
			{
				char ch=getch();
				if(ch=='Q' || ch=='q')
				{
					return 0;
				}
			}
		}
	}
	
	int *sub;
	if(ln1>ln2 || (ln1==ln2 && fl==1))
	{
		sub=dosub(a1,a2,ln1,ln2);
		sign=0;
	}
	else
	{
		if(ln2>ln1 || (ln1==ln2 && fl==2))
		{
			sub=dosub(a2,a1,ln2,ln1);
			sign=1;
		}
	}
	printf("\tYour answer is : ");
	if(sign==1)
	{
		printf("-");
	}
	
	int sd=-1;
	if(d1!=-1 || d2!=-1)
	{
		sd=max(nf1,nf2);
	}
	fi=(mxl-sd);
	for(i=0;i<=(mxl-sd);i++)
	{
		if(*(sub+i)!=0)
		{
			fi=i;
			break;
		}
	}
	if(fi==(mxl-sd))
	{
		printf("0");
	}
	for(i=fi;i<mxl;i++)
	{
		if(i==(mxl-sd) && sd!=-1)
		{
			printf(".");
		}
		printf("%d",*(sub+i));
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
