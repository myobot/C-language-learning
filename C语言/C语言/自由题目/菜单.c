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
		printf("    ����������:\n");
		printf("����:___\b\b\b");
		scanf("%d",&key);
	//	system("pause");
		system("cls");
		if(key==PASS)
		{
			flag++;
			system("cls");
			printf("������ȷ\n");
			while(1)
			{
				for(i=0;i<N;i++)
					printf("%4d",x[i]);
				output('*',46);
				printf("\n");
				printf("1.�����ֵ             2.����Сֵ\n3.���                 4.��ƽ����\n5.����                 6.����\n0.�˳�\n");
				output('*',46);
				printf("\n������ѡ��\n");
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
					default :printf("�������,����������\n");
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
				printf("�������,��������룬����%d�λ���\n",2-i);
			if(i==2)
				printf("�������������û�л�����!!!  �ݰ�\n");
		}
		if(p>0)
			break;
	}
	if(flag==0)
		printf("\n");
	if(flag>0)
		printf("�ټ�\n");
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
	printf("���ֵΪ%d\n",k);
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
	printf("��СֵΪ%d\n",k);
}
void sum(int x[],int n)
{
	int i,isum=0;
	for(i=0;i<n;i++)
		isum+=x[i];
	printf("��Ϊ%d\n",isum);
}
void average(int x[],int n)
{
	double faverage;
	int i,isum=0;
	for(i=0;i<n;i++)
		isum+=x[i];
	faverage=1.0*isum/n;
	printf("ƽ��ֵΪ%.3lf\n",faverage);
}
void xuanpai(int x[],int n)
{
	int p;
	printf("��ѡ���Ƿ�����˳��ı�\n1.����   2.��\n");
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
			printf("����������������\n");
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
	printf("������Ҫ���ҵ�����\n");
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
		printf("û�и�����\n");
	if(j==1)
	{
		printf("�и����֣���%d��\n�ڵ�%dλ\n",j,s[0]);
	}
	if(j>1)
	{
		printf("�и����֣���%d��\n�ֱ���:",j);
		for(i=0;i<p;i++)
			printf("��%dλ  ",s[i]);
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

	


					

	
