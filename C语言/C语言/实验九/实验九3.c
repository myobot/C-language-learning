#include<stdio.h>
#include<stdlib.h>
int he(int *i,int n);
void huan(int *i,int n);
int main()
{
	int *i,j;
	char c,cc;
	i=(int *)malloc(2*sizeof(int));
	while(1)
	{
		printf("请输入两个数\n");
		for(j=0;j<2;j++)
		{
			while(scanf("%d",&i[j])!=1)
			{
				while((c=getchar())!='\n')
					continue;
				printf("输入错误，请重新输入\n");
			}
		}
		huan(i,2);
		printf("和为:%d\n交换后为:%d %d\n",he(i,2),i[0],i[1]);
		printf("是否继续？\n输入y 继续 ，输入其他字符退出（如 n ）\n");
		while((c=getchar())!='\n')
			continue;
		cc=getchar();
		while((c=getchar())!='\n')
			continue;
		if(cc!='y')
			break;
	}
	pritnf("拜拜\n");
	free(i);
	return 0;
}
int he(int *i,int n)
{
	int j,sum=0;
	for(j=0;j<n;j++)
		sum+=i[j];
	return sum;
}
void huan(int *i,int n)
{
	int swap,j;
	for(j=0;j<n-1;j++)
	{
		swap=i[j];
		i[j]=i[j+1];
		i[j+1]=swap;
	}
}
		
	
		