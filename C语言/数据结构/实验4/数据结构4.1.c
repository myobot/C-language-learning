#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 12
struct queue
{
	int data[MAXSIZE];
	int front;
	int rear;
};
struct queue * chushihua(void)
{
	struct queue *New;
	New=(struct queue *)malloc(sizeof(struct queue));
	New->front=0;
	New->rear=0;
	return New;
}
int kong(struct queue *Q)
{
	return Q->front==Q->rear;
}
int full(struct queue *Q)
{
	return ((Q->rear+1)%MAXSIZE)==(Q->front);
}
int in(struct queue *Q,int x)
{
	if(full(Q))
	{
		printf("�ж�����!,�޷��ٽ�������\n");
		return 0;
	}
	else
	{
		Q->data[Q->rear]=x;
		Q->rear=(Q->rear+1)%MAXSIZE;
		return 1;
	}
}
int out(struct queue *Q,int *x)
{
	if(kong(Q))
	{
		printf("�ж�Ϊ�գ��޷���������\n");
		return 0;
	}
	else
	{
		*x=Q->data[Q->front];
		Q->front=(Q->front+1)%MAXSIZE;
		return 1;
	}
}
int changdu(struct queue *Q)
{
	return (Q->rear-Q->front+MAXSIZE)%MAXSIZE;
}
void print(struct queue *Q)
{
	int i;
	if(kong(Q))
	{
		printf("�ж�Ϊ��!\n");
	}
	else
	{
		if(Q->rear>Q->front)
		{
			for(i=Q->front;i<Q->rear;i++)
			{
				printf("%d\n",Q->data[i]);
			}
		}
		else
		{
			for(i=Q->front;i<MAXSIZE;i++)
			{
				printf("%d\n",Q->data[i]);
			}
			for(i=0;i<Q->rear;i++)
			{
				printf("%d\n",Q->data[i]);
			}
		}
	}
}

int main()
{
	int j,k;
	struct queue *Q;
	Q=(struct queue*)malloc(sizeof(struct queue));
	Q=chushihua();
	printf("����������,����ż�������жӣ��������������ж�\n");
	while(scanf("%d",&k)==1&&k!=0)
	{
		if(k%2==0)
		{
			if(in(Q,k))
				printf("%d  �����ж�\n",k);
		}
		else
		{
			if(out(Q,&j))
				printf("%d  �����ж�\n",j);
		}

		printf("�ж���������:\n");
		print(Q);
		system("pause");
		system("cls");
		printf("�������������,����ż�������жӣ��������������ж�\n����0�������,�����㷨\n");
	}
	printf("�㷨����\n�����ж���������:\n");
	print(Q);
	free(Q);
	return 0;
}

		