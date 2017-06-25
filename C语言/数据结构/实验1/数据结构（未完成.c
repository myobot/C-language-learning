#include<stdio.h>
#include<time.h>
#define N 100
char zqsr(char *c);
struct list * shuru(void);
void print(struct list *l);
struct list 
{
	int data[N];
	int last;
};
char zqsr(char *c)
{
	char xz;
	xz=getchar();
	fflush(stdin);
	while(strchr(c,xz)==NULL)
	{
		puts("请重新输入正确选项:");
		xz=getchar();
		fflush(stdin);
	}
	return xz;
}
struct list * shuru(void)
{
	int i;
	struct list *l;
	l=(struct list *)malloc(sizeof(struct list));
	srand((signed)time(0));
	l->last=-1;
	for(i=0;i<16;i++)
	{
		l->data[i]=rand()%100;l->last++;
	}
	return l;
}
void print(struct list *l)
{
	int i;
	
	for(i=0;i<l-<last+1;i++)
	{
		printf("%4d",l->data[i];
	}
}
int main()
{
	int i,j,k,x;
	char xz;
	struct list *l;
	l=shuru();
	printf("表内数据如下：\n");
	print(l);
	while(1)
	{
		printf("\n\n现在请输入要分隔的数，请输入表中数据\n");
		while(scanf("%d",&x)!=1)
		{
			printf("请输入正确数字，请重新输入\n");
			fflush(stdin);
		}
		fflush(stdin);
		for(i=0,j=0;i<l->last+1;i++)
		{
			if(l->data[i]==x)
			{
				j=i;break;
			}
		}
		if(j>l->last)
		{
			printf("输入的数不再表内\n\n1)重新输入\n\n2)退出\n\n请选择:\n");
			xz=zqsr("12");
			if(xz=='1')
				continue;
			else
				break;
		}
		else
		{		


	