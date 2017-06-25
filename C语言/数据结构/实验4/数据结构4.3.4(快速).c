#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
char zqsr(char *c);
struct data
{
	int jinru;
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
	int mark;
	int ksfw;
	int jiaoyisj;
};
int P;			// ����̨����
char zqsr(char *c)
{
	char xz;
	xz=getchar();
	fflush(stdin);
	while(strchr(c,xz)==NULL)
	{
		puts("������������ȷѡ��:");
		xz=getchar();
		fflush(stdin);
	}
	return xz;
}
struct queue *chushihua(void)
{
	struct data *head;
	struct queue *q;
	head=(struct data *)malloc(sizeof(struct data));
	q=(struct queue *)malloc(sizeof(struct queue));
	head->next=NULL;
	q->front=head;
	q->rear=head;
	return q;
}
int kong(struct queue *Q)
{
	return Q->front==Q->rear;
}
int rudui(struct queue *Q,int sjz)
{
	struct data *p;
	p=(struct data *)malloc(sizeof(struct data));
	if(p==NULL)
		return 0;
	p->jinru=sjz;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return 1;
}
int chudui(struct queue *Q,int *sj)
{
	struct data *p;
	if(kong(Q))
		return 0;
	p=Q->front->next;
	Q->front->next=p->next;
	*sj=p->jinru;
	if(p==Q->rear)
		Q->rear=Q->front;
	free(p);
	return 1;
}
int findkong(struct fwt p[])
{
	int i;
	for(i=0;i<P;i++)
	{
		if(p[i].mark==0)
			return i;
	}
	return -1;
}
int	moni(void)
{
	int i,j,sjz,renshu,sj1,mark,t,t2,sum,js;
	int *sj;
	int *fwtjs;
	int fuwusj,suijisj;
	double pingjun;
/*  sjz:       ʱ����,��ʱ����
	renshu:    ��¼ƽ��ÿ������˴�
	sj1 + *sj: ���Ӽ�¼����ʱ��
	mark:      ������ɿ��˱��
	t:		   ������ɿ��˼��ʱ��
	t2:		   ��� t ���������ɿ������
	sum:	   �ܵȴ�ʱ��
	js:		   �Է����˼���
	pingjun:   ƽ���ȴ�ʱ��
*/ 
	struct queue *Q;
	struct fwt *p;
	sj=&sj1;
	srand((unsigned)time(0));
	printf("���������̨����:\n");
	while(scanf("%d",&P)!=1&&P<=0)
	{
		printf("����̨��������������������ȷ�ĸ���:\n");
		fflush(stdin);
	}
	fflush(stdin);
	printf("������ƽ������ʱ��:\n");
	while(scanf("%d",&fuwusj)!=1&&fuwusj<=0)
	{
		printf("������������������\n");
		fflush(stdin);
	}
	fflush(stdin);
	printf("������ƽ������ʱ��:\n");
	while(scanf("%d",&suijisj)!=1&&suijisj<=0)
	{
		printf("������������������:\n");
		fflush(stdin);
	}
	fflush(stdin);
	fwtjs=(int *)malloc(sizeof(int)*P);
	p=(struct fwt *)malloc(sizeof(struct fwt)*P);
	for(i=0;i<P;i++)
	{
		p[i].xuhao=i+1;
		p[i].mark=0;
		p[i].ksfw=0;
		p[i].jiaoyisj=0;
		fwtjs[i]=0;
	}
	Q=chushihua();
	printf("������ƽ��ÿ�콻���˴�:\n");
	while(scanf("%d",&renshu)!=1&&renshu<=0)
	{
		printf("����������������ȷ������:\n");
		fflush(stdin);
	}
	fflush(stdin);
	sjz=0;mark=0;t2=sjz;sum=0;js=0;
	while(js<renshu)
	{
		if(mark==1)
		{	
			t=(rand()%suijisj+1);mark=0;
		}
		if(t2+t<=sjz&&mark==0)
		{
			rudui(Q,sjz);
			mark=1;
			t2=sjz;
		}
		while(!kong(Q))
		{
			j=findkong(p);
			if(j==-1)
				break;
			else
			{
				if(chudui(Q,sj)==0)
					break;
				else
				{
					js++;
					sum=sum+(sjz-*sj);
					fwtjs[j]++;
					p[j].ksfw=sjz;
					p[j].jiaoyisj=rand()%fuwusj+1;
					p[j].mark=1;
				}
			}
		}
		for(i=0;i<P;i++)
		{
			if(p[i].mark==1)
			{
				if(p[i].ksfw+p[i].jiaoyisj<=sjz)
				{
					p[i].mark=0;
				}
			}
		}
		sjz++;
	}
	printf("����%d������̨\n����ģ�������̨������������:\n",P);
	for(i=0;i<P;i++)
		printf("����̨%d):%d��\n",i+1,fwtjs[i]);
	pingjun=sum/(1.0*js);
	printf("ƽ���ȴ�ʱ��Ϊ:%.4lf\n",pingjun);
	for(;;)
	{
		if(chudui(Q,sj)==0)
			break;
	}

	return 0;
}
int main()
{
	char xz;
	while(1)
	{
		moni();
		printf("1)����ģ��ֵ����\n0)�˳�\n��ѡ��:\n");
		xz=zqsr("10");
		if(xz=='0')
			break;
		else
			system("cls");
	}
	return 0;
}

		
			



	