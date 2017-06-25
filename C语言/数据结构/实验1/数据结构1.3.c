#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct list * shengcheng(void);
void charu(int p,int i,struct list *l);
struct list
{
	int data[100];
	int last;
};
struct list * shengcheng(void)
{
	int i;
	struct list *l;
	srand((unsigned)time(0));
	l=(struct list*)malloc(sizeof(struct list));
	l->last=-1;
	for(i=0;i<10;i++)
	{
		l->data[i]=rand()%40;
		l->last++;
	}
	return l;
}
void charu(int x,int y,struct list *l)
{
	int i,j;
	j=l->data[y];
	for(i=y;i>=x+1;i--)
	{
		l->data[i]=l->data[i-1];
	}
	l->data[x]=j;
}
int main()
{
	int i,p;
	struct list *l;
	l=shengcheng();
	printf("顺序表中的数据为:\n");
	for(i=0;i<l->last+1;i++)
		printf("%4d",l->data[i]);
	printf("\n以第一个元素为界，将顺序表分隔开后，为:\n");
	system("pause");
	for(i=1,p=0;i<l->last+1;i++)
	{
		if(l->data[p]>=l->data[i])
		{
			charu(p,i,l);
			p++;
		}
	}
	for(i=0;i<l->last+1;i++)
		printf("%4d",l->data[i]);
	printf("\n");
	return 0;
}