#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100
int search(int *a,int n,int x,int s[]);
int main()
{
	int a[N],n,x,s[N],i,p;
	srand((unsigned)time(0));
	for(i=0;i<N;i++)
	{
		a[i]=rand()%100;
		printf("%4d",a[i]);
	}
	printf("\n");
	puts("������Ҫ�ҵ���");
	scanf("%d",&x);
	p=search(a,N,x,s);
	if(p==-1)
		puts("û�и�����");
	else
	{
		printf("�и����֣���%d��\n�ֱ���:\n",p);
		for(i=0;i<p;i++)
			printf("��%dλ\n",s[i]);
	}
	return 0;
}
int search(int *a,int n,int x,int s[])
{
	int i,j=0,k;
	for(i=0,k=0;i<n;i++)
	{
		if(*a++==x)
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


