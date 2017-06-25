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
	//s���ӣ�����ʱ���¼,i���г���
	struct queue *Q;
	srand((unsigned int)time(0));
	Q = chushihua();
	//���г�ʼ��
	
	next = zrand(5);
	sumdaodasj += next;
	gukenum++;
	F = zrand(2);
	sumfuwusj += F;
	chuangkou=1;
	//��һ��������ʼ��

	while (lieduinum <= 100 || !kong(Q))		//�����о���������100�����жӿ�  ����ѭ��
	{
		
		//��û��100��
		if (lieduinum <= 100)					
		{
			
			//��һ������ʱ��С�ڷ���ʱ��
			if (next < F)						  
			{
				T = next;						//�ƽ�����һ���˵���ʱ��
				lairen = zrand(5);				//�������¸��˵���ʱ��
				next += lairen;
				sumdaodasj += lairen;
				gukenum++;						//�˿�������++
				if (chuangkou == 0 && kong(Q))	//���ڿ���  �Ҷӿ� ֱ�ӷ���
				{
					fuwu = zrand(2);
					F = T + fuwu;				//��������ʱ��
					chuangkou = 1;
					sumfuwusj += fuwu;
				}
				else							//���ڲ����� ���
				{
					rudui(Q, T);
					lieduinum++;				//���о�������++
				}

			}

			//����ʱ��С����һ���˵���ʱ��
			else								
			{
				T = F;							//�ƽ����������ʱ��

				//������п�
				if (kong(Q))					
				{
					chuangkou = 0;				//�ô��ڿ���
					F = next + 1;				//����ʱ���ô��� ��һ���˵���ʱ��
				}

				//������в��� ���Ӳ��ø��Ĵ�������
				else							
				{
					s = chudui(Q);
					sumdengdaisj = sumdengdaisj + T - s;		//�����ܵȴ�ʱ��
					fuwu = zrand(2);
					F = T + fuwu;
					sumfuwusj += fuwu;

				}

			}
		}
		
		//��100�� �������е��˷�����
		else				
		{
			T = F;
			s = chudui(Q);
			sumdengdaisj = sumdengdaisj + T - s;				//�����ܵȴ�ʱ��
			fuwu = zrand(2);
			F = T + fuwu;
			sumfuwusj += fuwu;

		}
		i += changdu(Q);										//��¼��ÿ��ѭ�������е����������

		sum++;													//��¼ѭ������
		//��ƽ�����г���	

	}
	printf("ƽ������ʱ����: %.3lf ����\n", (double)sumdaodasj / gukenum);
	printf("ƽ������ʱ��: %.3lf ����\n", (double)sumfuwusj / gukenum);
	printf("�˿���: %d ��\n", gukenum);
	printf("�˿�ƽ���ȴ�ʱ�� :%.3lf ����\n", (double)sumdengdaisj / gukenum);
	printf("�ж�ƽ������ :%.3lf ��\n", (double)i / sum);

	free(Q);
	return 0;
}
