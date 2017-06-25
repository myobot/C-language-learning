#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
struct data
{
	double jinru;
	struct data *next;
};
struct queue
{
	struct data *front;
	struct data *rear;
};
struct queue *chushihua(void)
{
	struct data *head;
	struct queue *q;
	head = (struct data *)malloc(sizeof(struct data));
	q = (struct queue *)malloc(sizeof(struct queue));
	head->next = NULL;
	q->front = head;
	q->rear = head;
	return q;
}
int kong(struct queue *Q)
{
	return Q->front == Q->rear;
}
int rudui(struct queue *Q, double sjz)
{
	struct data *p;
	p = (struct data *)malloc(sizeof(struct data));
	if (p == NULL)
		return 0;
	p->jinru = sjz;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return 1;
}
double chudui(struct queue *Q)
{
	struct data *p;
	double sj;
	if (kong(Q))
		return 0;
	p = Q->front->next;
	Q->front->next = p->next;
	sj = p->jinru;
	if (p == Q->rear)
		Q->rear = Q->front;
	free(p);
	return sj;
}
int changdu(struct queue *Q)
{
	struct data *p;
	int i = 0;
	p = Q->front;
	while (p)
	{
		i++;
		p = p->next;

	}
	return i;
}
double zrand(int l)
{
	double r,x;
	r = (double)rand() / RAND_MAX;
	x = -l*log(1 - r);
	return x;
}
double F = 1, next = 0, T = 0;


int main()
{
	double s,lairen, fuwu, sumdaodasj = 0, sumdengdaisj = 0, sumfuwusj = 0;
	int i=0, sum=0, lieduinum = 0, gukenum = 0;
	int chuangkou;
	//s出队，到达时间记录,i队列长度
	struct queue *Q;
	srand((unsigned int)time(0));
	Q = chushihua();
	//队列初始化
	
	next = zrand(5);
	sumdaodasj += next;
	gukenum++;
	F = zrand(2);
	sumfuwusj += F;
	chuangkou=1;
	//第一次人来初始化

	while (lieduinum <= 100 || !kong(Q))		//队列中经历过多于100人且列队空  跳出循环
	{
		
		//还没到100人
		if (lieduinum <= 100)					
		{
			
			//下一个到达时间小于服务时间
			if (next < F)						  
			{
				T = next;						//推进到下一个人到达时间
				lairen = zrand(5);				//生成下下个人到达时间
				next += lairen;
				sumdaodasj += lairen;
				gukenum++;						//顾客总人数++
				if (chuangkou == 0 && kong(Q))	//窗口空闲  且队空 直接服务
				{
					fuwu = zrand(2);
					F = T + fuwu;				//产生服务时间
					chuangkou = 1;
					sumfuwusj += fuwu;
				}
				else							//窗口不空闲 入队
				{
					rudui(Q, T);
					lieduinum++;				//队列经历人数++
				}

			}

			//服务时间小于下一个人到达时间
			else								
			{
				T = F;							//推进到服务完成时间

				//如果队列空
				if (kong(Q))					
				{
					chuangkou = 0;				//置窗口空闲
					F = next + 1;				//服务时间置大于 下一个人到达时间
				}

				//如果队列不空 出队不用更改窗口属性
				else							
				{
					s = chudui(Q);
					sumdengdaisj = sumdengdaisj + T - s;		//计算总等待时间
					fuwu = zrand(2);
					F = T + fuwu;
					sumfuwusj += fuwu;

				}

			}
		}
		
		//到100人 将队列中的人服务完
		else				
		{
			T = F;
			s = chudui(Q);
			sumdengdaisj = sumdengdaisj + T - s;				//计算总等待时间
			fuwu = zrand(2);
			F = T + fuwu;
			sumfuwusj += fuwu;

		}
		i += changdu(Q);										//记录总每次循环队列中的人数；求和

		sum++;													//记录循环次数
		//求平均队列长度	

	}
	printf("平均到达时间间隔: %.3lf 分钟\n", (double)sumdaodasj / gukenum);
	printf("平均服务时间: %.3lf 分钟\n", (double)sumfuwusj / gukenum);
	printf("顾客数: %d 人\n", gukenum);
	printf("顾客平均等待时间 :%.3lf 分钟\n", (double)sumdengdaisj / gukenum);
	printf("列队平均长度 :%.3lf 人\n", (double)i / sum);

	free(Q);
	return 0;
}
