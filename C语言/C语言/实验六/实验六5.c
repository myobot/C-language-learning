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
	printf("������Ҫ���ҵ���,����q����.\n");
	while((scanf("%d",&x))==1)
	{
		printf("���������Ϊ:%d\n",x);
		p=search(a,N,x,s);
		if(p==-1)
			printf("û�и�����\n");
		if(p>=1)
		{
			printf("�и����֣���%d��\n�ֱ��ڣ�\n",p);
			for(i=0;i<p;i++)
				printf("��%dλ   \n",s[i]);
		}
		system("pause");
		system("cls");
		for(i=0;i<N;i++)
		{
			printf("%4d",a[i]);
		}
		printf("������Ҫ���ҵ��������֣�����q��������\n");
//		while((c=getchar())!='\n')
//			continue;
	}
	printf("�ݰ�\n");
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

