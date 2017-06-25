#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Danci
{
	char d[20];
};
int main()
{
	int i=0,j,p,i1,ji=0,sum=0;
	char c[20]={'\0'},c1[20],ch,n,ch1,file[41],*chp;
	struct Danci *danci;
	FILE *fp;
//	printf("请输入句子\n");
	printf("请输入要打开的文件(请确保该文件在源文件所在文件夹内)\n");
	gets(file);
	if((fp=fopen(file,"r"))==NULL)
	{
		printf("打开文件失败!\n");
		exit(1);
	}
	while(1)
	{
		if((fscanf(fp,"%c",&ch1))==1)
		{
			ji++;
		//	printf("%c",ch1);
		}
		else
			break;
	}
	chp=(char*)malloc(ji*sizeof(char));
	danci=(struct Danci *)malloc(sizeof(struct Danci)*14746);
	if(chp==NULL)
	{
		printf("内存不足，创建数组失败！\n");
		exit(1);
	}
	rewind(fp);
	for(i=0;i<ji;i++)
	{
		if((fscanf(fp,"%c",&chp[i]))!=1)
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
	
	
		for(i=0,j=0,p=0;i<=ji;i++,j++)
		{
			c[j]=chp[i];
		//	if(chp[i]>=32&&chp[i]<=47||chp[i]=='?'||chp[i]=='0')
			if(chp[i]==' ')
			{
				c[j]='\0';
				
				
				strcpy(danci[sum].d,c);
				sum++;
				for(i1=0;i1<j;i1++)
				{
					c[i1]='\0';
				}
				j=-1;
				i++;
				while(chp[i]==' ')
					i++;
				i--;
			}	
		}
	
	
	for(i=0,j=0;i<sum;i++,j++)
	{
		
		printf("%16s",danci[i].d);
		if(j%5==0)
			printf("\n");
	}
	printf("\n共有%d个字母\n%d个单词\n",ji,sum);


/*	while(1)
	{
		printf("共有%d个字母\n",ji);
		printf("\n请输入要查找的单词:\n");
		gets(c1);
		for(i=0,j=0,p=0;i<=ji;i++,j++)
		{
			c[j]=chp[i];
			if(chp[i]>=32&&chp[i]<=47||chp[i]=='?'||chp[i]=='0')
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
//		for(i=0;i<ji;i++)
	//		printf("%c",chp[i]);
		printf("\n");
	}*/
	if(fclose(fp)!=0)
		printf("关闭文件失败!\n");
	free(chp);
	free(danci);
	printf("拜拜\n");
	return 0;
}