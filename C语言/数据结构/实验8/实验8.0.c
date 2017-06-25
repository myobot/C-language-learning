#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define M 100000000
char zqsr(char *c)
{
	char xz;
	xz=getchar();
	fflush(stdin);
	while(strchr(c,xz)==NULL)
	{
		puts("请重新输入正确选项:");
		xz=getchar();
		fflush(stdin);
	}
	return xz;
}
void fuzhi(int *data,int *swap,int n)
{
	int i;
	for(i=0;i<n;i++)
		swap[i]=data[i];
}
void print(int *data,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%4d",data[i]);
		if((i+1)%8==0)
			printf("\n");
	}
}
void maopao(int *data,int n)
{
	int i,j,swap;
	printf("排序前:\n");
	print(data,n);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(data[i]>data[j])
			{
				swap=data[i];
				data[i]=data[j];
				data[j]=swap;
			}
		}
	}
	printf("\n排序后:\n");
	print(data,n);
}
void bijiao(int *data,int n)
{
	int i,j,k,swap;
	printf("排序前:\n");
	print(data,n);
	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(data[k]>data[j])
				k=j;
		}
		if(i!=k)
		{
			swap=data[i];
			data[i]=data[k];
			data[k]=swap;
		}
	}
	printf("\n排序后:\n");
	print(data,n);
}
void charu(int *data,int n)
{
	int swap,i,j;
	printf("排序前:\n");
	print(data,n);
	for(i=0;i<n;i++)
	{
		swap=data[i];
		for(j=i-1;j>=0&&swap<data[j];j--)
			data[j+1]=data[j];
		data[j+1]=swap;
	}
	printf("\n排序后:\n");
	print(data,n);
}
void leijia(int *data,int n)
{
	int flag=n,i,j,k;
	int *fuzhu;
	fuzhu=(int *)malloc(sizeof(int)*n));
	printf("排序前:\n");
	print(data,n);
	for(i=0,k=0;i<=M;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==data[j])
			{
				fuzhu[k]=data[j];
				flag--;
				k++;
			}
		}
		if(flag==0)
			break;
	}
	printf("\n排序后:\n");
	print(fuzhu,n);
}
void shellsort(int *data,int n,int delta)
{
	int temp,i,j;
	for(i=delta;i<n;i++)
	{
		temp=data[i];
		for(j=i-delta;j>=0&&temp<data[j];j=j-delta)
			data[j+delta]=data[j];
		if(j!=i-delta)
			data[j+delta]=temp;
	}
}
void xier(int *data,int n)
{
	int i,j;
	printf("请输入希尔增量:\n");
	scanf("%d",&j);
	fflush(stdin);
	printf("排序前:\n");
	print(data,n);
	for(;j>0;j--)
	{
		shellsort(data,n,j);
	}
	printf("\n排序后:\n");
	print(data,n);
}
int partition(int *data,int i,int j);
{
	int temp=data[i];
	while(i<j)
	{
		while(a[j]>=temp&&i<j)
			j--;
		if(i<j)
			data[i++]=data[j];
		while(data[i]<=temp&&i<j)
			i++;
		if(i<j)
			data[j--]=data[i];
	}
	data[i]=temp;
	return i;
}
void quick(int *data,int i,int j)
{
	int k;
	if(i<j)
	{
		k=partition(data,i,j);
		quick(data,i,k-1);
		quick(data,k+1,j);
	}
}
int main()
{
	int *data,*swap;
	int n,i,mark;
	char xz;
	srand((unsigned)time(0));
	printf("元素个数(随机生成):");
	while(scanf("%d",&n)!=1||n<=0)
	{
		printf("输入有误，请重新输入\n");
		fflush(stdin);
	}fflush(stdin);
	data=(int *)malloc(sizeof(int)*n);
	swap=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		data[i]=rand()%n;
	for(;;)
	{
		printf("1)冒泡排序\n\n2)简单比较法排序\n\n3)插入排序\n\n4)累加排序\n\n5)希尔排序\n\n6)快速排序\n\n0)退出\n\n请选择\n");
		xz=zqsr("123450");
		mark=0;
		fuzhi(data,swap,n);
		switch (xz)
		{
			case '1':maopao(swap,n);break;
			case '2':bijiao(swap,n);break;
			case '3':charu(swap,n);break;
			case '4':leijia(swap,n);break;
			case '5':xier(swap,n);break;
			case '6':quick(swap,0,n);break;
			case '0':mark=1;break;
		}
		printf("\n");
		system("pause");system("cls");
		if(mark==1)
			break;
	}
	return 0;
}
