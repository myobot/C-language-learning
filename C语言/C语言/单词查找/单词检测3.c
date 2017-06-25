#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 2000
int main()
{
	int i=0,j,k,p,i1;
	char x[N]={'\0'},c[20]={'\0'},c1[20],ch,n,ch1,file[41];
	FILE *fp;
//	printf("请输入句子\n");
	printf("请输入要打开的文件(请确保该文件在源文件所在文件夹内)\n");
	gets(file);
	if((fp=fopen(file,"r"))==NULL)
	{
		printf("打开文件失败!\n");
		exit(1);
	}
	for(i=0;i<N;i++)
	{
		if((fscanf(fp,"%c",&x[i]))==1)
		{
			printf("%c",x[i]);
		}
		else
			break;
	}

/*	for(i=0;i<N;i++)
	{	
		x[i]=getchar();
		if(x[i]=='0')
		{
			k=i;
			break;
		}
	}*/
//	while((ch=getchar())!='\n')
//		continue;
	while(1)
	{
		printf("\n请输入要查找的单词:\n");
		gets(c1);
		for(i=0,j=0,p=0;i<=k;i++,j++)
		{
			c[j]=x[i];
			if(x[i]>=32&&x[i]<=47||x[i]=='?'||x[i]=='0')
			{
				c[j]='\0';
				if(strcmp(c1,c)==0)
				{
					p++;
				}
				for(i1=0;i1<j;i1++)
				{
					c[i1]='\0';
				}
				j=-1;
			}
		}
		if(p==0)
			printf("没有此单词\n");
		if(p>0)
			printf("有此单词，有%d个\n",p);
		printf("是否还想查找其他单词？输入 y 继续，输入除 y 的任意字符(如空行)结束\n");
		scanf("%c",&n);
		while((ch=getchar())!='\n')
			continue;
		if(n!='y')
			break;
		system("pause");
		system("cls");
		for(i=0;i<k;i++)
			printf("%c",x[i]);
		printf("\n");
	}
	if(fclose(fp)!=0)
		printf("关闭文件失败!\n");
	printf("拜拜\n");
	return 0;
}