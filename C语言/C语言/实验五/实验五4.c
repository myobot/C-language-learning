#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	int i,j,k=0;
	char c[N],c1,ch,cc;
	printf("请输入一个字符串\n");
	gets(c);
	for(i=0;i<N;i++)
	{
		if(c[i]=='\0')
			break;
	}
	j=i;printf("共有%d个字符\n",j);
	printf("请输入你要查找的字符\n");
	scanf("%c",&c1);
	while(1)
	{
		for(i=0;i<j;i++)
		{
			if(c1==c[i])
			{
				k++;
			}
		}
		if(k>0)
			printf("(YES!)有该字符，有%d个.\n",k);
		if(k==0)
			printf("(Not Found!)没有该字符\n");
		printf("是否要查找别的字符？输入y继续，输入n结束\n");
		while((cc=getchar())!='\n')
			continue;
		scanf("%c",&ch);
		while((cc=getchar())!='\n')
			continue;
		if(ch!='y')
			break;
		printf("请输入要查找的字符\n");
		scanf("%c",&c1);
	}
	printf("拜拜\n");
	return 0;
}



