#include<stdio.h>
#define N 100
int strcmp(char c,char c1);
int main()
{
	char c[N]="same",c1[N]={'\0'};
	int i,j=0,k,p;
	printf("%s\n请输入字符串与已知比较\n",c);
	i=0;
	while((c1[i]=getchar())!='\n')
	{
		i++;
	}
	c1[i]='\0';
	p=i;
	for(i=0;i<4;i++)
	{
		if(c[i]!=c1[i])
		{
			k=c[i]-c1[i];
			j++;
			break;
		}
	}
	if(j==0)
	{
		if(p>3)
			k=c1[4];
		else
			k=0;
	}
	printf("%d\n",k);
	return 0;
}


	
	

