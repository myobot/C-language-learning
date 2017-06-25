#include<stdio.h>
#include<stdlib.h>
struct data
{
	int shu;
	struct data *next;
};
struct queue
{
	struct data *front;
	struct data *rear;
};
struct queue * chushihua(void)
{
	struct data *p;
	struct queue *Q;
	p=(struct data *)malloc(sizeof(struct data));
	Q=(struct queue *)malloc(sizeof(struct queue));
	p->next=NULL;
	Q->front=p;
	Q->rear=p;
	return Q;
}
int kong(struct queue *Q)
{
	return Q->front==Q->rear;
}
int rudui(struct queue *Q,int x)
{
	struct data *New;
	New=(struct data *)malloc(sizeof(struct data));
	if(New==NULL)
	{
		printf("内存不足，无法再入队\n");
		return 0;
	}
	New->shu=x;
	Q->rear->next=New;
	New->next=NULL;
	Q->rear=New;
	return 1;
}
int chudui(struct queue *Q,int *x)
{
	struct data *p;
	if(kong(Q))
	{
		printf("列队为空，无法出队!\n");
		return 0;
	}
	p=Q->front->next;
	*x=p->shu;
	Q->front->next=p->next;
	if (p == Q->rear)
		Q->rear = Q->front;
	free(p);
	return 1;
}
int qutou(struct queue *Q,int *x)
{
	if(kong(Q))
	{
		printf("列队为空，无法取头元素!\n");
		return 0;								//杨辉三角不可能有0
	}
	*x=Q->front->next->shu;
	return *x;
}

int main()
{
	int i,j,k,*yi,*er,a,b,p;
	struct queue *Q;
	Q=chushihua();
	yi=&a;
	er=&b;
	printf("请输入要打印几行\n");
	while(scanf("%d",&k)!=1&&k<=0)
	{
		printf("输入有误，请重新输入\n");
		fflush(stdin);
	}
	fflush(stdin);
	for(i=1;i<k;i++)
		printf("  ");
	printf("%4d\n",1);
	rudui(Q,1);
	rudui(Q,1);
	for(i=2;i<=k;i++)
	{
		rudui(Q,1);
		for(p=0;p<k-i;p++)
			printf("  ");
		for(j=0;j<=i-2;j++)
		{
			chudui(Q,yi);
			qutou(Q,er);
			printf("%4d",*yi);
			rudui(Q,(*yi)+(*er));
		}
		chudui(Q,er);
		printf("%4d\n",*er);
		rudui(Q,1);
	}
}


