#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	char c[N]="copy:",c1[N];
	int i,j,k;
	printf("请输入要复制的字符串\n");
	gets(c1);
	for(i=0;i<N;i++)
	{
		if(c1[i]=='\0')
			break;
	}
	j=i;
	for(i=0;i<N;i++)
	{
		if(c[i]=='\0')
			break;
	}
	k=i;
	for(i=0;i<j;i++)
	{
		c[i+k]=c1[i];
	}
	for(i=0;i<k+j;i++)
		printf("%c",c[i]);
	printf("\n");
	return 0;
}
