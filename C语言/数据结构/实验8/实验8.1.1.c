#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#define M 100000000
#define N 8
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
//	printf("排序前:\n");
//	print(data,n);
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
//	printf("\n排序后:\n");
//	print(data,n);
}
void bijiao(int *data,int n)
{
	int i,j,k,swap;
//	printf("排序前:\n");
//	print(data,n);
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
//	printf("\n排序后:\n");
//	print(data,n);
}
void charu(int *data,int n)
{
	int swap,i,j;
//	printf("排序前:\n");
//	print(data,n);
	for(i=0;i<n;i++)
	{
		swap=data[i];
		for(j=i-1;j>=0&&swap<data[j];j--)
			data[j+1]=data[j];
		data[j+1]=swap;
	}
//	printf("\n排序后:\n");
//	print(data,n);
}
void leijia(int *data,int n)
{
	int flag=n,i,j,k;
	int *fuzhu;
	fuzhu=(int *)malloc(sizeof(int)*n);
//	printf("排序前:\n");
//	print(data,n);
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
//	printf("\n排序后:\n");
//	print(fuzhu,n);
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
	int j;
//	printf("请输入希尔增量:\n");
//	scanf("%d",&j);
	j=(int)(log(n+1)/log(2));
	fflush(stdin);
//	printf("排序前:\n");
//	print(data,n);
	for(;j>0;j--)
	{
		shellsort(data,n,j);
	}
//	printf("\n排序后:\n");
//	print(data,n);
}
int partition(int *data,int i,int j)
{
	int temp=data[i];
	while(i<j)
	{
		while(data[j]>=temp&&i<j)
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
void builddown(int *data,int n,int rootindex)
{
	int root=data[rootindex];
	int childindex=rootindex*2;
	while(childindex<n)
	{
		if(childindex!=n-1&&data[childindex+1]>data[childindex])
			childindex++;
		if(root<data[childindex])
		{
			data[rootindex]=data[childindex];
			rootindex=childindex;
			childindex=rootindex*2;
		}
		else
			break;
	}
	data[rootindex]=root;
}
void dui(int *data,int n)
{
	int temp,i;
	int rootindex=(n-2)/2;
//	print(data,n);
	for(;rootindex>=0;rootindex--)
		builddown(data,n,rootindex);
	for(i=n-1;i>=0;i--)
	{
		temp=data[0];
		data[0]=data[i];
		data[i]=temp;
		builddown(data,i,0);
	}
//	printf("\n");
//	print(data,n);
}
void merge(int *data,int s1,int e1,int s2,int e2,int *b)
{
	int k=s1;int i=s1;
	while((s1<=e1)&&(s2<=e2))
	{
		if(data[s1]<=data[s2])
			b[k++]=data[s1++];
		else
			b[k++]=data[s2++];
	}
	while(s1<=e1)
		b[k++]=data[s1++];
	while(s2<=e2)
		b[k++]=data[s2++];
	k--;
	while(k>=i)
	{
		data[k]=b[k];k--;
	}
}
void guibing(int *data,int i,int j,int *b)
{
	int k;
	if(i<j)
	{
		k=(i+j)/2;
		guibing(data,i,k,b);
		guibing(data,k+1,j,b);
		merge(data,i,k,k+1,j,b);
	}
}
void printbiao(double x[],int n)
{
	char mingcheng[N][20]={{"冒泡排序"},{"简单比较法排序"},{"插入排序"},{"累加排序"},{"希尔排序"},{"快速排序"},{"堆排序"},{"归并排序"}};
	int i;
	printf("数据量: %d\n",n);
	for(i=0;i<N;i++)
	{
		printf("%s\n用时:%f 秒\n",mingcheng[i],x[i]);
	}
}
int main()
{
	int *data,*swap,*b;
	int n,m,i;
	clock_t time2[N][2];
	double time1[N];
	srand((unsigned)time(0));
	printf("元素个数(随机生成):");
	while(scanf("%d",&n)!=1||n<=0)
	{
		printf("输入有误，请重新输入\n");
		fflush(stdin);
	}fflush(stdin);
	printf("元素最大值:");
	while(scanf("%d",&m)!=1||n<=0)
	{
		printf("输入有误，请重新输入\n");
		fflush(stdin);
	}fflush(stdin);
	data=(int *)malloc(sizeof(int)*n);
	swap=(int *)malloc(sizeof(int)*n);
	b=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		data[i]=rand()%(m+1);
	print(data,n);
	fuzhi(data,swap,n);
	time2[0][0]=clock();
	maopao(swap,n);
	time2[0][1]=clock();
	fuzhi(data,swap,n);
	time2[1][0]=clock();
	bijiao(swap,n);
	time2[1][1]=clock();
	fuzhi(data,swap,n);
	time2[2][0]=clock();
	charu(swap,n);
	time2[2][1]=clock();
	fuzhi(data,swap,n);
	time2[3][0]=clock();
	leijia(swap,n);
	time2[3][1]=clock();
	fuzhi(data,swap,n);
	time2[4][0]=clock();
	xier(swap,n);
	time2[4][1]=clock();
	fuzhi(data,swap,n);
	time2[5][0]=clock();
	quick(swap,0,n);
	time2[5][1]=clock();
	fuzhi(data,swap,n); 
	time2[6][0]=clock();
	dui(swap,n);
	time2[6][1]=clock();
	fuzhi(data,swap,n);
	printf("\n");
	print(data,n);printf("\n");
	time2[7][0]=clock();
	guibing(swap,0,n,b);
	time2[7][1]=clock();
	print(swap,n);
	for(i=0;i<N;i++)
	{
		time1[i]=(double)(time2[i][1]-time2[i][0])/ CLOCKS_PER_SEC;
	}
	printbiao(time1,n);
	return 0;
}
