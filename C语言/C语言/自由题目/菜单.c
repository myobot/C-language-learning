#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100
#define PASS 123
void max_1 (int x[],int n);
void min_1 (int x[],int n);
void average (int x[],int n);
void jianpai (int x[],int n);
void jiapai (int x[],int n);
void xuanpai (int x[],int n);
void cha (int x[],int n,int s[]);
void sum (int x[],int n);
void output (char c,int n);
int main()
{
	int x[N],i,key,n,p=0,flag=0,s[N];
	srand((unsigned)time(0));
	for(i=0;i<N;i++)
	{
		x[i]=rand()%101;
	}
	for(i=0;i<3;i++)
	{
		printf("    请输入密码:\n");
		printf("密码:___\b\b\b");
		scanf("%d",&key);
	//	system("pause");
		system("cls");
		if(key==PASS)
		{
			flag++;
			system("cls");
			printf("密码正确\n");
			while(1)
			{
				for(i=0;i<N;i++)
					printf("%4d",x[i]);
				output('*',46);
				printf("\n");
				printf("1.求最大值             2.求最小值\n3.求和                 4.求平均数\n5.排序                 6.查找\n0.退出\n");
				output('*',46);
				printf("\n请输入选项\n");
				scanf("%d",&n);
				switch (n)
				{
					case 1 : max_1(x,N);break;
					case 2 : min_1(x,N);break;
					case 3 : sum(x,N);break;
					case 4 : average(x,N);break;
					case 5 : xuanpai(x,N);break;
//					case 5 : jianpai(x,N);break;
//				    case 6 : jiapai(x,N);break;
					case 6 : cha(x,N,s);break;
					case 0 : p++;break;
					default :printf("输入错误,请重新输入\n");
				}
				system("pause");
				system("cls");
				if(p>0)
					break;
			}
			
		}
		if(key!=PASS)
		{	
			if(i<2)
				printf("密码错误,请从新输入，还有%d次机会\n",2-i);
			if(i==2)
				printf("三次输入错误，你没有机会了!!!  拜拜\n");
		}
		if(p>0)
			break;
	}
	if(flag==0)
		printf("\n");
	if(flag>0)
		printf("再见\n");
	return 0;
}
void max_1(int x[],int n)
{
	int i,k=x[0];
	for(i=1;i<n;i++)
	{
		if(x[i]>k)
		{
			k=x[i];
		}
	}
	printf("最大值为%d\n",k);
}
void min_1(int x[],int n)
{
	int i,k=x[0];
	for(i=1;i<n;i++)
	{
		if(x[i]<k)
		{
			k=x[i];
		}
	}
	printf("最小值为%d\n",k);
}
void sum(int x[],int n)
{
	int i,isum=0;
	for(i=0;i<n;i++)
		isum+=x[i];
	printf("和为%d\n",isum);
}
void average(int x[],int n)
{
	double faverage;
	int i,isum=0;
	for(i=0;i<n;i++)
		isum+=x[i];
	faverage=1.0*isum/n;
	printf("平均值为%.3lf\n",faverage);
}
void xuanpai(int x[],int n)
{
	int p;
	printf("请选择是否将数组顺序改变\n1.不变   2.变\n");
	while(1)
	{
		scanf("%d",&p);
		if(p==1)
		{
			jiapai(x,n);
			break;
		}
		if(p==2)
		{
			jianpai(x,n);
			break;
		}
		else
			printf("输入错误，请从新输入\n");
	}
}
void jiapai(int x[],int n)
{
	int i,j;
	for(i=0;i<=N;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==x[j])
			{
				printf("%4d",x[j]);
			}
		}
	}
}
void jianpai(int x[],int n)
{
	int i,j,k,p;
	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(x[k]>x[j])
			{
				k=j;
			}
		}
		if(k!=i)
		{
			p=x[i];
			x[i]=x[k];
			x[k]=p;
		}
	}
	for(i=0;i<n;i++)
		printf("%4d",x[i]);
}
void cha(int x[],int n,int s[])
{
	int i,j,k,p;
	printf("请输入要查找的数字\n");
	scanf("%d",&k);
	for(i=0,p=0,j=0;i<n;i++)
	{
		if(k==x[i])
		{
			s[p]=i+1;
			p++;
			j++;
		}
	}
	if(j==0)
		printf("没有该数字\n");
	if(j==1)
	{
		printf("有该数字，有%d个\n在第%d位\n",j,s[0]);
	}
	if(j>1)
	{
		printf("有该数字，有%d个\n分别在:",j);
		for(i=0;i<p;i++)
			printf("第%d位  ",s[i]);
		printf("\n");
	}
}
void output (char c,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%c",c);
	}
}

	


					

	
