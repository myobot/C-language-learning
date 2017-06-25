#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <conio.h>
#include <windows.h>
#define N 20
struct snake
{
	int x;
	int y;
	struct snake *next;
};
int fx,fy;										//food坐标
void shuchu(struct snake *head);
struct snake *up(struct snake *head);
struct snake *down(struct snake *head);
struct snake *right(struct snake *head);
struct snake *left(struct snake *head);
void food(struct snake *head);
struct snake *sheshen(struct snake *head);
void goto_xy(int x,int y){ //定位光标位置到指定坐标
HANDLE hOut;
COORD pos={x,y};
hOut = GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleCursorPosition(hOut,pos);
}

int main()
{
	char x,p;
//	int t;char o;
	struct snake *head;
	struct snake a1,a2,a3;
	srand((unsigned int)time(0));
	head=&a1;									//初始化蛇
	a1.x=5;a1.y=5;a1.next=&a2;
	a2.x=5;a2.y=6;a2.next=&a3;
	a3.x=5;a3.y=7;a3.next=NULL;
	food(head);
	shuchu(head);
	while(1)
	{
		x=_getch();
		fflush(stdin);
		while(strchr("was",x)==NULL)					//由于初始化的蛇头向左，第一次移动不能向右
		{
			x=_getch();
			fflush(stdin);
		}
		while(1)
		{
			fflush(stdin);
			switch (x)
			{
				case 'w':head=up(head);break;
				case 'a':head=left(head);break;
				case 'd':head=right(head);break;
				case 's':head=down(head);break;
			}
			if(head==NULL)
				break;
			goto_xy(0,0);
			shuchu(head);
			Sleep(200);
			if(kbhit())									//检测是否按下键盘
			{
				p=_getch();								//接收按下的键
				fflush(stdin);
				if((x=='w'||x=='s')&&strchr("ad",p)!=NULL)		//如果是w或s检测是否为as
					x=p;										//是, x接收
				if((x=='a'||x=='d')&&strchr("ws",p)!=NULL)		
					x=p;
			}
		/*	while(t=kbhit())							//清除多余按键
			{
				o=getch();
			}*/
		}
		break;
	}
	printf("游戏结束\n");system("pause");
	return 0;
}
struct snake *sheshen(struct snake *head)
{
	struct snake *p=head->next;
	while(p)
	{
		if(p->x==head->x&&p->y==head->y)
			return NULL;
		p=p->next;
	}
	return head;
}
void shuchu(struct snake *head)
{
	int i,j;
	char c[N][N];
	struct snake *p=head;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			c[i][j]=' ';
	while(p)
	{
		c[(p->x)-1][(p->y)-1]='*';
		p=p->next;
	}
	c[fx][fy]='*';
	printf("------------------------------------------\n");
	for(i=0;i<N;i++)
	{
		printf("|");
		for(j=0;j<N;j++)
		{
			printf("%2c",c[i][j]);
		}
		printf("|");
		printf("\n");
	}
	printf("------------------------------------------\n");
}
struct snake *up(struct snake *head)
{
	int x_,y_;										//记录尾节点的(x,y)如果吃到food把food放到原来的尾部
	struct snake *p1,*p2,*p3,*creat;				// p1 找到尾节点（移动到头） p2倒数第二个节点变为尾节点
	p1=p2=p3=head;
	while(p1->next)
	{
		p1=p1->next;
	}
	while(p2->next->next)
	{
		p2=p2->next;
	}
	x_=p1->x;
	y_=p1->y;
	p2->next=NULL;
	p1->next=head;
	p1->x=(p3->x)-1;
	p1->y=(p3->y);
	if(p1->x<=0)
	{
		return NULL;
	}
	head=p1;
	if((p1->x-1)==fx&&(p1->y-1)==fy)							//如果是food点，就吃掉,并放到尾节点(x,y)
	{
		creat=(struct snake*)malloc(sizeof(struct snake));
		p2->next=creat;
		creat->next=NULL;
		creat->x=x_;
		creat->y=y_;
		food(head);
	}
	head=sheshen(head);											//检查蛇吃蛇身
	return head;
}
struct snake * left(struct snake *head)
{
	int x_,y_;
	struct snake *p1=head,*p2=head,*p3=head,*creat;
	while(p1->next)
	{
		p1=p1->next;
	}
	while(p2->next->next)
	{
		p2=p2->next;
	}
	x_=p1->x;
	y_=p1->y;
	p2->next=NULL;
	p1->next=head;
	p1->x=p3->x;
	p1->y=p3->y-1;
	if(p1->y<=0)
	{
		return NULL;
	}
	head=p1;
	if((p1->x-1)==fx&&(p1->y-1)==fy)
	{
		creat=(struct snake*)malloc(sizeof(struct snake));
		p2->next=creat;
		creat->next=NULL;
		creat->x=x_;
		creat->y=y_;
		food(head);
	}
	head=sheshen(head);
	return head;
}	
struct snake *right(struct snake *head)
{
	int x_,y_;                          
	struct snake *p1=head,*p2=head,*p3=head,*creat;
	while(p1->next)
	{
		p1=p1->next;
	}
	while(p2->next->next)
	{
		p2=p2->next;
	}
	x_=p1->x;
	y_=p1->y;
	p2->next=NULL;
	p1->next=head;
	p1->x=p3->x;
	p1->y=p3->y+1;
	if(p1->y>N)
	{
		return NULL;
	}
	head=p1;
	if((p1->x-1)==fx&&(p1->y-1)==fy)
	{
		creat=(struct snake*)malloc(sizeof(struct snake));
		p2->next=creat;
		creat->next=NULL;
		creat->x=x_;
		creat->y=y_;
		food(head);
	}
	head=sheshen(head);							
	return head;
}
struct snake *down(struct snake *head)
{
	int x_,y_;
	struct snake *p1=head,*p2=head,*p3=head,*creat;
	while(p1->next)
	{
		p1=p1->next;
	}
	while(p2->next->next)
	{
		p2=p2->next;
	}
	x_=p1->x;
	y_=p1->y;
	p2->next=NULL;
	p1->next=head;
	p1->x=p3->x+1;
	p1->y=p3->y;
	if(p1->x>N)
	{
		return NULL;
	}
	head=p1;
	if((p1->x-1)==fx&&(p1->y-1)==fy)
	{
		creat=(struct snake*)malloc(sizeof(struct snake));
		p2->next=creat;
		creat->next=NULL;
		creat->x=x_;
		creat->y=y_;
		food(head);
	}
	head=sheshen(head);
	return head;
}
void food(struct snake *head)
{
	int i,j,k,x[400][2],p[N][N],o,u=0;
	struct snake *prve=head;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			p[i][j]=0;
	while(prve)							//遍历找到蛇身的点
	{
		p[(prve->x)-1][(prve->y)-1]=1;
		prve=prve->next;
	}
	for(j=0;j<N;j++)					//找到非蛇身的点
	{
		for(k=0;k<N;k++)
		{
			if(p[j][k]==0)
			{
				u++;
				x[u][0]=j;
				x[u][1]=k;
			}
		}
	}
	o=rand()%u;							//在非蛇身的点中随机选取一个点，作为food。
	fx=x[o][0];
	fy=x[o][1];
}
