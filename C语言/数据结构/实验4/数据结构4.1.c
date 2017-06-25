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
		printf("列队已满!,无法再进入数据\n");
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
		printf("列队为空，无法弹出数据\n");
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
		printf("列队为空!\n");
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
	printf("请输入数据,输入偶数进入列队，出入奇数弹出列队\n");
	while(scanf("%d",&k)==1&&k!=0)
	{
		if(k%2==0)
		{
			if(in(Q,k))
				printf("%d  进入列队\n",k);
		}
		else
		{
			if(out(Q,&j))
				printf("%d  弹出列队\n",j);
		}

		printf("列队内容如下:\n");
		print(Q);
		system("pause");
		system("cls");
		printf("请继续输入数据,输入偶数进入列队，出入奇数弹出列队\n输入0或非数字,结束算法\n");
	}
	printf("算法结束\n最终列队内容如下:\n");
	print(Q);
	free(Q);
	return 0;
}

		