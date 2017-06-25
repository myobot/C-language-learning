#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
struct A
{
	char *dd;
	int **bian;
	int n,e;
};
struct node
{
	int ldd;				//���Ӷ���
	struct node *next;
};
struct vnode
{
	char dd;					//����
	struct node *firstnode;
};
struct B
{
	struct vnode *adlist;
	int n,e;
};
struct qnode
{
	int dd;
	struct qnode *next;
};
struct queue
{
	struct qnode *front;
	struct qnode *rear;
};
static int visited[MAXSIZE];
char zqsr(char *c)
{
	char xz;
	xz=getchar();
	fflush(stdin);
	while(strchr(c,xz)==NULL)
	{
		puts("������������ȷѡ��:");
		xz=getchar();
		fflush(stdin);
	}
	return xz;
}
struct A* chuA(void)
{
	struct A *g;
	int i,j,k;
	g=(struct A *)malloc(sizeof(struct A));
	printf("�����붥����������(�ո����)\n");
	while(scanf("%d %d",&g->n,&g->e)!=2||g->n<=0||g->e<0)
	{
		printf("������������������\n");
		fflush(stdin);
	}
	fflush(stdin);
	g->dd=(char *)malloc(sizeof(char)*(g->n));
	g->bian=(int **)malloc(sizeof(int *)*(g->n));
	for(i=0;i<g->n;i++)
	{
		g->bian[i]=(int *)malloc(sizeof(int)*(g->n));
	}
	printf("�����붥��(ÿ��һ����\n");
	for(i=0;i<g->n;i++)
	{
		scanf("%c",&g->dd[i]);
		fflush(stdin);
	}
	printf("�������(ÿ��һ��)\n");
	for(i=0;i<g->n;i++)
		for(j=0;j<g->n;j++)
			g->bian[i][j]=0;
	for(i=0;i<g->e;i++)
	{
		while(scanf("%d,%d",&j,&k)!=2||j<0||k<0)
		{
			printf("������������������\n");
			fflush(stdin);
		}fflush(stdin);
		g->bian[j][k]=1;
	}
	return g;
}
struct B *chuB(void)
{
	struct B *g;
	struct node *s;
	int i,j,k;
	g=(struct B *)malloc(sizeof(struct B));
	printf("�����붥����������(�ÿո����)\n");
	while(scanf("%d %d",&g->n,&g->e)!=2||g->n<=0||g->e<0)
	{
		printf("������������������\n");
		fflush(stdin);
	}fflush(stdin);
	g->adlist=(struct vnode *)malloc(sizeof(struct vnode)*g->n);
	printf("�����붥��(ÿ��һ��)\n");
	for(i=0;i<g->n;i++)
	{
		scanf("%c",&g->adlist[i].dd);
		fflush(stdin);
		g->adlist[i].firstnode=NULL;
	}
	printf("�������(ÿ��һ��)\n");
	for(i=0;i<g->e;i++)
	{
		while(scanf("%d,%d",&j,&k)!=2||j<0||k<0)
		{
			printf("������������������\n");
			fflush(stdin);
		}fflush(stdin);
		s=(struct node *)malloc(sizeof(struct node));
		s->ldd=k;
		s->next=g->adlist[j].firstnode;
		g->adlist[j].firstnode=s;
	}
	return g;
}
struct queue *chushihua(void)
{
	struct queue *q=(struct queue *)malloc(sizeof(struct queue));
	struct qnode *head=(struct qnode *)malloc(sizeof(struct qnode));
	head->next=NULL;
	q->rear=head;
	q->front=head;
	return q;
}
int kong(struct queue *q)
{
	return q->rear==q->front;
}
void enter(struct queue *q,int i)
{
	struct qnode *p=(struct qnode *)malloc(sizeof(struct qnode));
	p->next=NULL;
	p->dd=i;
	q->rear->next=p;
	q->rear=p;
}
int out(struct queue *q)
{
	struct qnode *p;
	int i;
	p=q->front->next;
	q->front->next=p->next;
	i=p->dd;
	if(p==q->rear)
		q->rear=q->front;
	free(p);
	return i;
}
void DFSAL1(struct A *g,int i)
{
	int j;
	printf("�ѷ���:%c\n",g->dd[i]);
	visited[i]=1;
	for(j=0;j<g->n;j++)
	{
		if(!visited[j]&&g->bian[i][j]==1)
			DFSAL1(g,j);
	}
}
void dfs1(struct A *g)
{
	int i;
	for(i=0;i<g->n;i++)
		visited[i]=0;
	for(i=0;i<g->n;i++)
		if(!visited[i])
			DFSAL1(g,i);
}
void BFSAL1(struct A *g,int i)
{
	int j;
	struct queue *q;
	q=chushihua();
	printf("�ѷ���:%c\n",g->dd[i]);
	visited[i]=1;
	enter(q,i);
	while(!kong(q))
	{
		i=out(q);
		for(j=0;j<g->n;j++)
		{
			if(!visited[j]&&g->bian[i][j]==1)
			{
				printf("�ѷ���:%c\n",g->dd[j]);
				visited[j]=1;
				enter(q,j);
			}
		}
	}
}
void bfs1(struct A *g)
{
	int i;
	for(i=0;i<g->n;i++)
		visited[i]=0;
	for(i=0;i<g->n;i++)
		if(!visited[i])
			BFSAL1(g,i);
}
void DFSAL2(struct B *g,int i)
{
	struct node *p;
	printf("�ѷ���:%c\n",g->adlist[i].dd);
	visited[i]=1;
	p=g->adlist[i].firstnode;
	while(p)
	{
		if(!visited[p->ldd])
			DFSAL2(g,p->ldd);
		p=p->next;
	}
}
void dfs2(struct B *g)
{
	int i;
	for(i=0;i<g->n;i++)
		visited[i]=0;
	for(i=0;i<g->n;i++)
		if(!visited[i])
			DFSAL2(g,i);
}
void BFSAL2(struct B *g,int i)
{
	struct node *p;
	struct queue *q;
	q=chushihua();
	printf("�ѷ���:%c\n",g->adlist[i].dd);
	visited[i]=1;
	p=g->adlist[i].firstnode;
	while(p)
	{
		enter(q,p->ldd);

		p=p->next;
	}
	while(!kong(q))
	{
		i=out(q);
		if(!visited[i])
		{
			printf("�ѷ���:%c\n",g->adlist[i].dd);
			visited[i]=1;
		}
		p=g->adlist[i].firstnode;
		while(p)
		{
			if(!visited[i])
				enter(q,p->ldd);
			p=p->next;
		}
	}
}
void bfs2(struct B *g)
{
	int i;
	for(i=0;i<g->n;i++)
		visited[i]=0;
	for(i=0;i<g->n;i++)
		if(!visited[i])
			BFSAL2(g,i);
}
struct A* free1(struct A *g)
{
	int i;
	free(g->dd);
	for(i=0;i<g->n;i++)
		free(g->bian[i]);
	free(g->bian);
	free(g);
	return NULL;
}
struct B* free2(struct B *g)
{
	int i;
	struct node *p,*q;
	for(i=0;i<g->n;i++)
	{
		p=g->adlist[i].firstnode;
		while(p)
		{
			q=p;
			p=p->next;
			free(q);
		}
	}
	free(g->adlist);
	free(g);
	return NULL;
}
void juzhen(void)
{
	struct A *g1;
	int mark,mark2=0;
	char xz;
	while(1)
	{
		printf("1)�������ݲ�����ͼ\n\n2)������ȱ���\n\n3)������ȱ���\n\n0)�˳�\n\n��ѡ��\n");
		xz=zqsr("1230");
		mark=0;
		switch (xz)
		{
			case '1':if(mark2==1)
					 {
						 g1=free1(g1);
					 }
					 g1=chuA();mark2=1;break;
			case '2':bfs1(g1);break;
			case '3':dfs1(g1);break;
			case '0':mark=1;break;
		}
		system("pause");system("cls");
		if(mark==1)
			break;
	}
	free1(g1);
}
void biao(void)
{
	struct B *g2;
	int mark,mark2=0;
	char xz;
	while(1)
	{
		printf("1)�������ݲ�����ͼ\n\n2)������ȱ���\n\n3)������ȱ���\n\n0)�˳�\n\n��ѡ��\n");
		xz=zqsr("1230");
		mark=0;
		switch (xz)
		{
			case '1':if(mark2==1)
					 {
						 g2=free2(g2);
					 }
					 g2=chuB();mark2=1;break;
			case '2':bfs2(g2);break;
			case '3':dfs2(g2);break;
			case '0':mark=1;break;
		}
		system("pause");system("cls");
		if(mark==1)
			break;
	}
	free2(g2);
}
int main()
{
	int mark;
	char xz;
	while(1)
	{
		printf("1)�ڽӾ���洢ͼ\n\n2)�ڽӱ�洢ͼ\n\n0)�˳�\n\n��ѡ��\n");
		xz=zqsr("120");
		mark=0;
		switch (xz)
		{
			case '1':system("cls");
					juzhen();break;
			case '2':system("cls");
					biao();break;
			case '0':mark=1;break;
		}
		system("pause");system("cls");
		if(mark==1)
			break;
	}
	return 0;
}

