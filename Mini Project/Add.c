#include<string.h>
/*int max(int a,int b)
{
	if(a>b)
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
}*/
int strint(char n1[],char n2[],int a1[],int a2[],int d1,int d2)
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
			if(ch<0 || ch>9)
			{
				return -1;
			}
			a1[i]=ch;
		}
		
		if((d2==-1 && i<ln2) || (d2>0 && i<ln2-1))
		{
			ch=n2[i];
			ch-=48;
			if(ch<0 || ch>9)
			{
				return -1;
			}
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
}
int add()
{
	int i,ch,carry=0,s;
	
	char n1[200];
	char n2[200];
	
	printf("\t\t\t\tAddition Zone---\n");
	
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
	
	int gar=strint(n1,n2,a1,a2,d1,d2);
	if(gar==-1)
	{
		return -1;
	}
	
	int nf1=0;		/*nfi is the variable that stores the number of decimal places in i.*/
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
	
	int mxl=max(ln1,ln2);
	int sum[mxl+1];
	
	int minl=min(ln1,ln2);
	for(i=1;i<=minl;i++)
	{
		s=a1[ln1-i]+a2[ln2-i]+carry;
		if(s>9)
		{
			sum[mxl+1-i]=s%10;
			carry=s/10;
		}
		else
		{
			sum[mxl+1-i]=s;
			carry=0;
		}
	}
	
	for(i=minl+1;i<=mxl;i++)
	{
		if(mxl==ln1)
		{
			s=a1[ln1-i]+carry;
			if(s>9)
			{
				sum[mxl+1-i]=s%10;
				carry=s/10;
			}
			else
			{
				sum[mxl+1-i]=s;
				carry=0;
			}
		}
		else
		{
			s=a2[ln2-i]+carry;
			if(s>9)
			{
				sum[mxl+1-i]=s%10;
				carry=s/10;
			}
			else
			{
				sum[mxl+1-i]=s;
				carry=0;
			}
		}
	}
	
	int sd=-1;			/*'sd' stores the decimal places for the sum*/
	if(d1!=-1 || d2!=-1)
	{
		sd=max(nf1,nf2);		/*---  The maximum dp of the 2 values are stored. Since, 1.365+2.2=3.565  ---*/
	}
	
	sum[0]=carry;
	int in=(mxl+1-sd);
	
	for(i=0;i<=(mxl+1-sd);i++)		/*Finds the first non-zero value and initializes it to 'in' variable. But keeps the limit till the decimal point.  ---*/
	{
		if(sum[i]!=0)
		{
			in=i;
			break;
		}
	}
	
	printf("\tYour answer is : ");
	if(in==mxl+1-sd)
	{
		printf("0");
	}
	for(i=in;i<=mxl;i++)
	{
		if(i==(mxl+1-sd) && sd!=-1)
		{
			printf(".");
		}
		printf("%d",sum[i]);
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
