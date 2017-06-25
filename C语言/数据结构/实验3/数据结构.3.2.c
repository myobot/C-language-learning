#include<stdio.h>
#include<stdlib.h>
#define X 8
#define Y 8
struct data
{
	int x;
	int y;
};
struct stack
{
	struct data zuobiao;
	int fangxiang;
	struct stack *next;
};
char fx[5][2]={{0,0},{1,0},{0,1},{0,-1},{-1,0}};
struct stack *chushihua(void)
{
	struct stack *top;
	top=(struct stack *)malloc(sizeof(struct stack));
	top->next=NULL;
	return top;
}
int kong(struct stack *top)
{
	return top->next==NULL;
}
void push(struct stack *top,struct data *weizhi,int Fangxiang)
{
	struct stack *New;
	New=(struct stack *)malloc(sizeof(struct stack));
	New->zuobiao.x=weizhi->x;
	New->zuobiao.y=weizhi->y;
	New->fangxiang=Fangxiang;
	New->next=top->next;
	top->next=New;
}
int out(struct stack *top,struct data *weizhi)
{
	struct stack *p;
	if(kong(top))
		return 0;
	p=top->next;
	weizhi->x=p->zuobiao.x;
	weizhi->y=p->zuobiao.y;
	top->next=p->next;
	return 1;
}
void print(struct stack *top)
{
	struct stack *p;
	p=top->next;
	while(p)
	{
		printf("%2d,%2d\n",p->zuobiao.x,p->zuobiao.y);
		p=p->next;
	}
}
int main()
{
	int migong[X][Y]=
	{{1,1,1,1,1,1,1,1}
	,{1,0,1,1,1,1,1,1}
	,{1,0,0,0,1,0,1,1}
	,{1,0,1,1,1,1,1,1}
	,{1,0,0,0,1,0,0,1}
	,{1,0,1,0,0,0,0,1}
	,{1,0,1,1,0,1,0,1}
	,{1,1,1,1,1,1,1,1}};
	int i=1,mark2,mark=0,j;
	struct stack *top;
	struct data *weizhi;
	top=chushihua();
	weizhi=(struct data *)malloc(sizeof(struct data));
	weizhi->x=1;
	weizhi->y=1;
	push(top,weizhi,1);
	migong[1][1]=2;
	while((top->next->zuobiao.x!=(X-2))||(top->next->zuobiao.y!=(Y-2)))				//同事为出口坐标时值为0 结束循环
	{
		for(mark2=0;i<=4;i++)														//i初始化为1.
		{
			if(migong[top->next->zuobiao.x+fx[i][0]][top->next->zuobiao.y+fx[i][1]]==0)
			{
				weizhi->x=top->next->zuobiao.x+fx[i][0];
				weizhi->y=top->next->zuobiao.y+fx[i][1];
				push(top,weizhi,i);
				migong[top->next->zuobiao.x][top->next->zuobiao.y]=2;
				mark2=1;
				break;
			}
		}
		if(mark2==0)
		{
			if(out(top,weizhi)==0)
			{
				mark=1;
				break;
			}
			else
			{
				migong[weizhi->x][weizhi->y]=3;
			}
		}
		if(mark2==0)
		{
			i=top->next->fangxiang;							//如果回退
		}
		else
			i=1;											//如果不会退
	}
	if(mark==1)
	{
		printf("没有出口!\n");
	}
	else
	{
		printf("迷宫出口坐标为:\n");
		print(top);
		printf("迷宫出口路线图如下，2为路线\n");
		for(i=0;i<X;i++)
		{
			for(j=0;j<Y;j++)
			{
				printf("%2d",migong[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

	
