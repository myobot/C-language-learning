#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100
int search(int a[],int n,int x,int s[]);
int main()
{
	int a[N],i,x,p,s[N];
	char c;
	srand((unsigned)time(0));
	for(i=0;i<N;i++)
	{
		a[i]=rand()%100;
		printf("%4d",a[i]);
	}
	printf("请输入要查找的数,输入q结束.\n");
	while((scanf("%d",&x))==1)
	{
		printf("输入的数字为:%d\n",x);
		p=search(a,N,x,s);
		if(p==-1)
			printf("没有该数字\n");
		if(p>=1)
		{
			printf("有该数字，有%d个\n分别在：\n",p);
			for(i=0;i<p;i++)
				printf("第%d位   \n",s[i]);
		}
		system("pause");
		system("cls");
		for(i=0;i<N;i++)
		{
			printf("%4d",a[i]);
		}
		printf("请输入要查找的其他数字，输入q结束查找\n");
//		while((c=getchar())!='\n')
//			continue;
	}
	printf("拜拜\n");
	return 0;
}
int search(int a[],int n,int x,int s[])
{
	int i,j=0,k;
	for(i=0,k=0;i<n;i++)
	{
		if(a[i]==x)
		{
			s[k]=i+1;
			k++;
			j++;
		}
	}
	if(j==0)
		return -1;
	if(j>0)
		return j;
}

