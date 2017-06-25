#include<stdio.h>
#include<string.h>
#define	N 100
int main()
{
	int i,j,k,p,n=0,t=0;
	char c[N][20],ch[20],c1,c2;
	for(i=0;i<N;i++)
	{
		for(j=0,k=0,p=0;j<20;j++)
		{
			c[i][j]=getchar();
			if(c[i][j]>=32&&c[i][j]<=47)
			{
				c[i][j]='\0';
				k++;
				break;
			}
			if(c[i][j]=='0')
			{
				p++;
				break;
			}
		}
		if(k>0&&p==0)
			continue;
		if(p>0)
		{
			n=i;
			break;
		}
	}
	while((c1=getchar())!='\n')
		continue;
	while(1)
	{
		printf("请输入要查找的单词\n");
		gets(ch);
		for(i=0,t=0;i<n;i++)
		{
			if(strcmp(ch,c[i])==0)
			{
				t++;
			}
		}
		if(t==0)
			printf("没有该单词\n");
		if(t>0)
			printf("有该单词，有%d个\n",t);
		printf("是否继续查找其他单词？\n输入 y 继续，输入 n 退出\n");
		scanf("%c",&c2);
		if(c2!='y')
			break;
		while((c1=getchar())!='\n')
			continue;
	}
	printf("拜拜\n");
	return 0;
}

