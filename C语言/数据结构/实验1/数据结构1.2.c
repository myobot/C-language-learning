#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void hebing(struct list *la,struct list *lb);
void print(struct list *l);
struct list
{
	int data[100];
	int last;
};
void hebing(struct list *la,struct list *lb)
{
	int i,j,k=0;
	for(i=0;i<lb->last+1;i++)
	{
		for(j=0,k=0;j<la->last+1;j++)
		{
			if(lb->data[i]==la->data[j])
			{
				k++;
				break;
			}
		}
		if(k==0)
		{
			la->data[la->last+1]=lb->data[i];
			la->last++;
		}
	}
}
void print(struct list *l)
{
	int i;
	for(i=0;i<l->last+1;i++)
	{
		printf("%4d",l->data[i]);
	}
}
int main()
{
	int i;
	struct list *la,*lb;
	srand((unsigned)time(0));
	la=(struct list*)malloc(sizeof(struct list));
	lb=(struct list*)malloc(sizeof(struct list));
	la->last=-1;lb->last=-1;
	for(i=0;i<10;i++)
	{
		la->data[i]=rand()%50;
		lb->data[i]=rand()%70;
		la->last++;
		lb->last++;
	}
	printf("集合A：");print(la);
	printf("\n\n集合B：");print(lb);
	hebing(la,lb);
	printf("\n\n合并后:\n");system("pause");
	print(la);printf("\n");
	return 0;
}