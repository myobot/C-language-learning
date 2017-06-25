#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>
#define F 4
void print(struct queue *Q,int list[],int js,struct fwt fuwutai[F],int list2[F][2],double pingjun);
struct data
{
	int xuhao;
	int jye;
	int weizhi;
	int dengdaisj;
	time_t jinru;
	struct data *next;
};
struct queue
{
	struct data *front;
	struct data *rear;
};
struct fwt
{
	int xuhao;
	int jiaoyie;
	int sum;
	int mark;
	int geshu;
	int jiaoyisj;
	time_t ksfw;
};
struct queue *chushihua(void)
{
	struct queue *Q;
	struct data *head;
	Q=(struct queue *)malloc(sizeof(struct queue));
	head=(struct data*)malloc(sizeof(struct queue));
	head->next=NULL;
	Q->front=head;
	Q->rear=head;
	return Q;
}
int kong(struct queue *Q)
{
	return Q->front==Q->rear;
}
int rudui(struct queue *Q,int xh)
{
	int i;
	struct data *p;
	srand((unsigned)time(0));
	p=(struct data *)malloc(sizeof(struct data));
	if(p==NULL)
	{
		printf("内存不足!\n");
		return 0;
	}
	p->xuhao=xh;
	i=rand()%10;
	if(i<=8)
		p->jye=rand()%10000;
	else
		p->jye=rand()%1000000;
	p->weizhi=-1;
	p->jinru=time(&p->jinru);
	p->dengdaisj=rand()%10+10;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return 1;
}
int chudui(struct queue *Q,struct data *q)
{
	struct data *p;
	if(kong(Q))
		return 0;
	p=Q->front->next;
	Q->front->next=p->next;
	if(p==Q->rear)
		Q->rear=Q->front;
	q->xuhao=p->xuhao;
	q->jye=p->jye;
	q->jinru=p->jinru;
	free(p);
	return 1;
}
int likai(struct queue *Q)
{
	time_t t;
	struct data *p;
	if(kong(Q))
		return 0;
	p=Q->front->next;
	t=time(&t);
	while(p)
	{
		if((p->jinru+p->dengdaisj)<=t)
			p->weizhi=-2;
		p=p->next;
	}
	return 1;
}
void swap(struct data *yi,struct data *er)
{
	struct data swap;
	swap.xuhao=yi->xuhao;
	swap.jye=yi->jye;
	swap.weizhi=yi->weizhi;
	swap.jinru=yi->jinru;
	swap.dengdaisj=yi->dengdaisj;
	yi->xuhao=er->xuhao;
	yi->jye=er->jye;
	yi->weizhi=er->weizhi;
	yi->jinru=er->jinru;
	yi->dengdaisj=er->dengdaisj;
	er->xuhao=swap.xuhao;
	er->jye=swap.jye;
	er->weizhi=swap.weizhi;
	er->jinru=swap.jinru;
	er->dengdaisj=swap.dengdaisj;
}

int shanchu(struct queue *Q,int list[],int *geshu)
{
	int i=0,k;
	struct data *p,*q,*o,*r;
	k=0;
	if(kong(Q))
		return 0;
	p=Q->front->next;
	o=(struct data *)malloc(sizeof(struct data));
	if(Q->front->next==Q->rear&&p->weizhi==-2)
	{
		list[i++]=p->xuhao;
		Q->rear=Q->front;
		Q->front->next=NULL;
	}
	else
	{
		while(p)
		{
			if(p->weizhi==-2)
			{
				if(p==Q->front->next)
				{
					chudui(Q,o);
					list[i++]=o->xuhao;
					p=Q->front->next;
				}
				else
				{
					if(p==Q->rear)
					{
						list[i++]=p->xuhao;
						q=Q->front->next;
						while(q->next->next)
							q=q->next;
						q->next=NULL;
						Q->rear=q;
						r=p;
						free(r);
						break;
					}
					else
					{
						list[i++]=p->xuhao;
						swap(p,p->next);
						q=p->next;
						p->next=q->next;
						p=p->next;
						free(q);
					}
				}
			}
			else
				p=p->next;
			
		}

		
	}
	*geshu=i;
	return 1;
}
int findkong(struct fwt p[])
{
	int i;
	for(i=0;i<F;i++)
	{
		if(p[i].mark==0)
			return i;
	}
	return -1;
}

int main()
{
	int i,js,k,xh=0,j;
	int sj,list[30],list2[F][2];
	int mark1;
	int sum1=0,fwgs=0;
	double pingjun=0;
	time_t t;time_t t2;time_t t3;
	time_t t4;
	struct fwt fuwutai[F];
	struct queue *Q;
	struct data *p;
	srand((unsigned)time(0));
	Q=chushihua();
	p=(struct data *)malloc(sizeof(struct data));
	for(i=0;i<F;i++)
	{
		fuwutai[i].xuhao=-1;
		fuwutai[i].jiaoyie=0;
		fuwutai[i].sum=0;
		fuwutai[i].mark=0;
		fuwutai[i].geshu=0;
		fuwutai[i].jiaoyisj=0;
	}
	for(i=0;i<30;i++)
		list[i]=0;
	mark1=0;sj=0;
	t=time(&t);
	while(1)
	{
		js=0;
		
		t2=time(&t2);
		for(i=0;i<F;i++)
		{
			for(j=0;j<2;j++)
				list2[i][j]=0;
		}
		if(mark1==1)
		{
			sj=(rand()%5+1);mark1=0;			//每（1-5s）随机入队
		}
		if((t+sj)<=t2)
		{
			xh++;
			if(rudui(Q,xh)==0)
			{
				printf("内存不足!\n");
				break;
			}

			mark1=1;
			t=time(&t);
		}
		print(Q,list,js,fuwutai,list2,pingjun);
		Sleep(1000);
		system("cls");
		while(!kong(Q))
		{
			k=findkong(fuwutai);
			if(k==-1)
				break;
			else
			{
				chudui(Q,p);
				t4=time(&t4);
				sum1+=t4-p->jinru;
				fwgs++;
				fuwutai[k].xuhao=p->xuhao;
				fuwutai[k].jiaoyie=p->jye;
				fuwutai[k].jiaoyisj=(rand()%20+10);
				fuwutai[k].ksfw=time(&fuwutai[k].ksfw);
				fuwutai[k].mark=1;
			}
		}
		likai(Q);
		shanchu(Q,list,&js);
		pingjun=sum1/(1.0*fwgs);
		print(Q,list,js,fuwutai,list2,pingjun);
		Sleep(1000);
		system("cls");
		t3=time(&t3);
		for(i=0;i<F;i++)
		{
			if(t3>=fuwutai[i].ksfw+fuwutai[i].jiaoyisj&&fuwutai[i].mark==1)
			{
				list2[i][0]=fuwutai[i].xuhao;
				list2[i][1]=fuwutai[i].jiaoyie;
				fuwutai[i].sum+=fuwutai[i].jiaoyie;
				fuwutai[i].geshu++;
				fuwutai[i].mark=0;
			}
		}
		js=0;
		print(Q,list,js,fuwutai,list2,pingjun);
		Sleep(1000);
		system("cls");
	}
	return 0;
}
void print(struct queue *Q,int list[],int js,struct fwt fuwutai[F],int list2[F][2],double pingjun)
{
	int i,sum;
	struct data *p;
	for(i=0;i<F;i++)
	{
		if(fuwutai[i].mark==1)
		{
			printf("服务台%d: %d 交易额:%d\n",i+1,fuwutai[i].xuhao,fuwutai[i].jiaoyie);
		}
		else
			printf("服务台%d: \n",i+1);
	}
	printf("\n等待区:\n");
	if(!kong(Q))
	{
		p=Q->front->next;
		while(p)
		{
			printf("%4d |",p->xuhao);
			p=p->next;
		}
	}
	printf("\n\n");
	printf("出口:\n");
	printf("---\n");
	for(i=0;i<js;i++)
	{
		printf("%4d |",list[i]);
	}
	for(i=0;i<F;i++)
	{
		if(list2[i][0]!=0)
		{
			printf("%4d |",list2[i][0]);
		}
	}
	printf("\n___\n服务台收入：\n");
	for(i=0;i<F;i++)
	{
		printf("%d: %d元  交易次数:%d次\n",i+1,fuwutai[i].sum,fuwutai[i].geshu);
	}
	for(i=0,sum=0;i<F;i++)
	{
		sum+=fuwutai[i].sum;
	}
	printf("\n银行总收入: %d元\n",sum);
	printf("平均等待时间为：%.3lf秒\n",pingjun);

}





