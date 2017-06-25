#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	char c[N],c1;
	int i,j,k,p;
	printf("请输入字符串\n");
	gets(c);
	for(i=0;i<N;i++)
	{
		if(c[i]=='\0')
			break;
	}
//	j=strlen(c);
	j=i;
	printf("共有%d个字符\n",j);
	for(i=0;i<j;i++)
	{
		k=i;
		for(p=k;p<j-1;p++)
		{
			if(c[k]>c[p+1])
				k=p+1;
		}
		if(k!=i)
		{
			c1=c[i];
			c[i]=c[k];
			c[k]=c1;
		}
	}
	printf("整理后的字符串为:\n");
	puts(c);
	return 0;
}


	
