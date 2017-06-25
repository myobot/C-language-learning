#include<stdio.h>
#include<stdlib.h>
void shuru(struct duo *head[],int e,int a[]);
void jiaohuan(struct duo *yi,struct duo *er);
void paixu(struct duo *head[],int e);
struct duo *jiafa(struct duo *head[],int e,int a[]);
void shuchu(struct duo *head);
struct duo
{
	int xishu;
	int zhishu;
	struct duo *next;
};
int main()
{
	int a[2],x,i;
	struct duo *headsum,**head;
	printf("请输入一共有几个多项式:\n");
	while(scanf("%d",&x)!=1||x<=0)
	{
		printf("输入有误，请输入正确数字，并且大于0\n");
		fflush(stdin);
	}
	fflush(stdin);
	head=(struct duo **)malloc(sizeof(struct duo *)*x);
	for(i=0;i<x;i++)
	{
		head[i]=NULL;
	}
	shuru(head,x,a);
	headsum=jiafa(head,x,a);
	shuchu(headsum);
	return 0;
}

void shuru(struct duo *head[],int e,int a[])
{
	int i,max=-1000000,min=10000000;
	struct duo *prve,*creat;
	for(i=0;i<e;i++)
	{
		system("cls");
		while(1)
		{
			creat=(struct duo *)malloc(sizeof(struct duo));
			creat->next=NULL;
			printf("请输入第%d个多项式的系数:(输入0结束该多项式的输入)\n",i+1);
			while(scanf("%d",&creat->xishu)!=1)
			{
				printf("输入有误，请重新输入正确的数字:\n");
				fflush(stdin);
			}
			fflush(stdin);
			if(creat->xishu==0)
			{
				free(creat);
				break;
			}
			printf("现在请输入第%d个多项式的指数:\n",i+1);
			while(scanf("%d",&creat->zhishu)!=1)
			{
				printf("输入有误，请重新输入正确数字:\n");
				fflush(stdin);
			}
			fflush(stdin);
			if(creat->zhishu<min)
				min=creat->zhishu;
			if(creat->zhishu>max)
				max=creat->zhishu;
			if(head[i]==NULL)
				head[i]=prve=creat;
			else
			{
				prve->next=creat;
				prve=creat;
			}
		}
	}
	a[0]=max;
	a[1]=min;
}
void jiaohuan(struct duo *yi,struct duo *er)
{
	int swap1,swap2;
	swap1=yi->xishu;
	swap2=yi->zhishu;
	yi->xishu=er->xishu;
	yi->zhishu=er->zhishu;
	er->xishu=swap1;
	er->zhishu=swap2;
}
void paixu(struct duo *head[],int e)
{
	int i,j,k;
	struct duo *prve;
	for(i=0;i<e;i++)
	{
		k=0;
		if(head!=NULL)
		{
			prve=head[i];
			while(prve)
			{
				prve=prve->next;k++;
			}
			for(j=0;j<k-1;j++)
			{
				prve=head[i];
				while(prve->next)
				{
					if(prve->zhishu>prve->next->zhishu)
						jiaohuan(prve,prve->next);
					prve=prve->next;
				}
			}
		}
	}
}
struct duo *jiafa(struct duo *head[],int e,int a[])
{
	int i,j,sxishu;
	struct duo *headsum=NULL;
	struct duo *creat,*prve,*prve1;
	paixu(head,e);
	for(i=a[1];i<=a[0];i++)
	{
		sxishu=0;
		for(j=0;j<e;j++)
		{
			prve=head[j];
			while(prve)
			{
				if(prve->zhishu==i)
					sxishu+=prve->xishu;
				prve=prve->next;
			}
		}
		if(sxishu!=0)
		{
			creat=(struct duo *)malloc(sizeof(struct duo));
			if(headsum==NULL)
				headsum=creat;
			else
				prve1->next=creat;
			creat->next=NULL;
			creat->xishu=sxishu;
			creat->zhishu=i;
			prve1=creat;
		}
	}
	return headsum;
}
void shuchu(struct duo *head)
{
	struct duo *prve;
	prve=head;
	system("cls");
	printf("加法运算后的结果为\n%d",prve->xishu,prve->zhishu);
	prve=prve->next;
	while(prve)
	{
		if(prve->xishu>0)
			printf(" + %d*(x^%d)",prve->xishu,prve->zhishu);
		else
			printf(" - %d*(x^%d)",-prve->xishu,prve->zhishu);
		prve=prve->next;
	}
	printf("\n");
}
			

