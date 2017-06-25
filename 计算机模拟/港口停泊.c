#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*#define MAXSIZE 100
struct queue
{
	int time[MAXSIZE];
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
}*/
int tdrand()
{
	double t;
	t=(double)rand()/RAND_MAX;
	if(t<=0.01)
		return 5;
	else if(t<=0.04)
		return 6;
	else if(t<=0.10)
		return 7;
	else if(t<=0.17)
		return 8;
	else if(t<=0.26)
		return 9;
	else if(t<=0.36)
		return 10;
	else if(t<=0.47)
		return 11;
	else if(t<=0.58)
		return 12;
	else if(t<=0.69)
		return 13;
	else if(t<=0.78)
		return 14;
	else if(t<=0.85)
		return 15;
	else if(t<=0.91)
		return 16;
	else if(t<=0.96)
		return 17;
	else 
		return 18;
}
int tsrand()
{
	double t;
	t=(double)rand()/RAND_MAX;
	if(t<=0.20)
		return 9;
	else if(t<=0.42)
		return 10;
	else if(t<=0.61)
		return 11;
	else if(t<=0.77)
		return 12;
	else if(t<=0.87)
		return 13;
	else if(t<=0.95)
		return 14;
	else if(t<=0.98)
		return 15;
	else 
		return 16;
}
int main()
{
	int *num,*t,*tl,*tf,*tw,ts,td,n,i;
	double average,l;
	
	srand((unsigned int)time(0));

	printf("请输入模拟次数：");
	scanf("%d",&n);

	t=(int *)malloc(sizeof(int)*n);
	tl=(int *)malloc(sizeof(int)*n);
	tf=(int *)malloc(sizeof(int)*n);
	tw=(int *)malloc(sizeof(int)*n);
	num=(int *)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
	{
		t[i]=0;
		tl[i]=0;
		tf[i]=0;
		tw[i]=0;
		num[i]=0;
	}
	for(i=0;i<n;i++)
	{
		while(1)
		{
			td=tdrand();
			num[i]++;
			t[i]+=td;
			if(t[i]>=8640)
				break;
			ts=tsrand();
			if(t[i]<tl[i])
			{
				tw[i]=tw[i]+tl[i]-t[i];
				tl[i]=tl[i]+ts;
			}
			else
			{
				tf[i]=tf[i]+t[i]-tl[i];
				tl[i]=t[i]+ts;
			}
		}
	}
	printf("%8s%12s%12s%14s%8s%10s%12s\n","模拟次数","到达船舶数","滞留总时间","滞留平均时间","滞留费","空闲时间","平均利用率");

	for(i=0;i<n;i++)
	{
		average=(double)tw[i]/num[i];
		l=(8640-tf[i])/(double)8640;
		printf("%8d%12d%12d%14.3lf%8d%10d%8.1lf%%\n",i+1,num[i],tw[i],average,num[i]*100,tf[i],l*100);
	}
	free(t);
	free(tl);
	free(tf);
	free(tw);
	free(num);
	return 0;
}




	


		

		
	
