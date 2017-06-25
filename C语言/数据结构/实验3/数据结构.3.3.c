#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
struct data *chushihua(void);
int full(struct data *zhan);
int empty(struct data *zhan);
struct data
{
	char fu[50];
	int top;
};
struct cun
{
	char shuju[10*N];
	int last;
};
struct data *chushihua(void)
{
	struct data *zhan;
	zhan=(struct data*)malloc(sizeof(struct data));
	zhan->top=-1;
	return zhan;
}
int full(struct data *zhan)
{
	return zhan->top==N-1;
}
int empty(struct data *zhan)
{
	return zhan->top==-1;
}
int push(struct data *zhan,char x)
{
	if(full(zhan))
		return 0;
	zhan->fu[++zhan->top]=x;
	return 1;
}
int out(struct data *zhan,char x)
{
	if(empty(zhan))
		return 0;
	x=zhan->fu[zhan->top--];
	return 1;
}
void outall(struct data *zhan)
{
	zhan->top=-1;
}
void print(struct cun *Shuju)
{
	int i;
	for(i=0;i<Shuju->last;i++)
	{
		printf("%c",Shuju->shuju[i]);
	}
	printf("\n");
}
void chucun(struct data *zhan,struct cun *Shuju)
{
	int i;
	for(i=0;i<zhan->top;i++)
	{
		Shuju->last++;
		Shuju->shuju[Shuju->last]=zhan->fu[i];
	}
	Shuju->last++;
	Shuju->shuju[Shuju->last]='\n';
}
int main()
{
	int i,j;
	char huanchong[N],p='0';
	struct data *zhan;
	struct cun *Shuju;
	Shuju=(struct cun*)malloc(sizeof(struct cun));
	if(Shuju==NULL)
	{
		printf("内存不足!\n");
		return 0;
	}
	Shuju->last=-1;
	zhan=chushihua();
	printf("请输入语句(单行输入 0 结束输入\n");
	while(1)
	{
		i=0;
		huanchong[i]=getchar();
		if(huanchong[i]=='0')
			break;
		while(huanchong[i]!='\n')
		{
			i++;
			huanchong[i]=getchar();
		}
		for(j=0;j<=i;j++)
		{
			if(huanchong[j]=='#')
			{
				if(empty(zhan)==0)
				{
					out(zhan,p);
				}
			}
			else if(huanchong[j]=='@')
			{
				outall(zhan);
			}
			else
			{
				push(zhan,huanchong[j]);
			}
		}
		chucun(zhan,Shuju);
		outall(zhan);
	}
	system("pause");
	print(Shuju);

	return 0;
}