#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
struct jihe
{
	struct A *a;
	struct kedge **x;
};
struct A
{
	char *dd;
	int **bian;
	int n,e;
};
struct node
{
	int ldd;				//连接顶点
	int quan;
	struct node *next;
};
struct vnode
{
	char dd;					//顶点
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
struct kedge
{
	int vex1;
	int vex2;
	int wight;
};
static int visited[MAXSIZE];
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
struct jihe * chuA()
{
	struct jihe *b;
	struct A *g;
	struct kedge **p;
	int i,j,k,quan;
	g=(struct A *)malloc(sizeof(struct A));
	printf("请输入顶点数，边数(空格隔开)\n");
	while(scanf("%d %d",&g->n,&g->e)!=2||g->n<=0||g->e<0)
	{
		printf("输入有误，请重新输入\n");
		fflush(stdin);
	}
	fflush(stdin);
	b=(struct jihe*)malloc(sizeof(struct jihe));
	g->dd=(char *)malloc(sizeof(char)*(g->n));
	g->bian=(int **)malloc(sizeof(int *)*(g->n));
	p=(struct kedge **)malloc(sizeof(struct kedge *)*g->e);
	for(i=0;i<g->n;i++)
	{
		g->bian[i]=(int *)malloc(sizeof(int)*(g->n));
		
	}
	for(i=0;i<g->e;i++)
		p[i]=(struct kedge *)malloc(sizeof(struct kedge));
	printf("请输入顶点(每行一个）\n");
	for(i=0;i<g->n;i++)
	{
		scanf("%c",&g->dd[i]);
		fflush(stdin);
	}
	printf("请输入边(每行一组)\n");
	for(i=0;i<g->n;i++)
		for(j=0;j<g->n;j++)
			g->bian[i][j]=0;
	for(i=0;i<g->e;i++)
	{
		while(scanf("%d,%d",&j,&k)!=2||j<0||k<0)
		{
			printf("输入有误请重新输入\n");
			fflush(stdin);
		}fflush(stdin);
		printf("\n请输入权值:");
		while(scanf("%d",&quan)!=1||quan<0)
		{
			printf("输入有误请重新输入\n");
			fflush(stdin);
		}fflush(stdin);
		g->bian[j][k]=quan;
		p[i]->vex1=j;
		p[i]->vex2=k;
		p[i]->wight=quan;
	}
	b->a=g;
	b->x=p;
	return b;
}
struct B *chuB(void)
{
	struct B *g;
	struct node *s;
	int i,j,k;
	g=(struct B *)malloc(sizeof(struct B));
	printf("请输入顶点数，边数(用空格隔开)\n");
	while(scanf("%d %d",&g->n,&g->e)!=2||g->n<=0||g->e<0)
	{
		printf("输入有误，请重新输入\n");
		fflush(stdin);
	}fflush(stdin);
	g->adlist=(struct vnode *)malloc(sizeof(struct vnode)*g->n);
	printf("请输入顶点(每行一个)\n");
	for(i=0;i<g->n;i++)
	{
		scanf("%c",&g->adlist[i].dd);
		fflush(stdin);
		g->adlist[i].firstnode=NULL;
	}
	printf("请输入边(每行一组)\n");
	for(i=0;i<g->e;i++)
	{
		while(scanf("%d,%d",&j,&k)!=2||j<0||k<0)
		{
			printf("输入有误，请重新输入\n");
			fflush(stdin);
		}fflush(stdin);
		s=(struct node *)malloc(sizeof(struct node));
		printf("\n请输入权值:");
		while(scanf("%d",&s->quan)!=1||s->quan<0)
		{
			printf("输入有误请重新输入\n");
			fflush(stdin);
		}fflush(stdin);;
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
	printf("已访问:%c\n",g->dd[i]);
	visited[i]=1;
	for(j=0;j<g->n;j++)
	{
		if(!visited[j]&&g->bian[i][j]!=0)
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
	printf("已访问:%c\n",g->dd[i]);
	visited[i]=1;
	enter(q,i);
	while(!kong(q))
	{
		i=out(q);
		for(j=0;j<g->n;j++)
		{
			if(!visited[j]&&g->bian[i][j]!=0)
			{
				printf("已访问:%c\n",g->dd[j]);
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
	printf("已访问:%c\n",g->adlist[i].dd);
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
	printf("已访问:%c\n",g->adlist[i].dd);
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
			printf("已访问:%c\n",g->adlist[i].dd);
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
struct jihe* free1(struct A *g,struct kedge **k)
{
	int i;
	free(g->dd);
	for(i=0;i<g->n;i++)
	{
		free(g->bian[i]);
		free(k[i]);
	}
	free(k);
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
void paixu(struct kedge **k,int n)
{
	int i,j,q=0,e;
	struct kedge *s;
	s=(struct kedge *)malloc(sizeof(struct kedge));
	for(i=0;i<n;i++)
	{
		e=i;
		for(j=i+1;j<n;j++)
		{
			if(k[e]->wight>=k[j]->wight)
				e=j;
		}
		if(i!=e)
		{
			s->vex1=k[i]->vex1;
			s->vex2=k[i]->vex2;
			s->wight=k[i]->wight;
			k[i]->vex1=k[e]->vex1;
			k[i]->vex2=k[e]->vex2;
			k[i]->wight=k[e]->wight;
			k[e]->vex1=s->vex1;
			k[e]->vex2=s->vex2;
			k[e]->wight=s->wight;			
		}
	}
}
void zuixiao(struct A *g,struct kedge **k)
{
	int i,j,m1,m2,sn1,sn2,p;
	int *s;
	s=(int *)malloc(sizeof(int)*g->n);
	for(i=0;i<g->n;i++)
		s[i]=i;
	paixu(k,g->e);
	p=0;
	for(i=0;i<g->e;i++)
	{
		m1=k[i]->vex1;
		m2=k[i]->vex2;
		sn1=s[m1];sn2=s[m2];
		if(sn1!=sn2)
		{
			printf("(%c,%c):%d\n",g->dd[m1],g->dd[m2],k[i]->wight);
			p++;
			if(p==g->n-1)
				break;
			for(j=0;j<g->n;j++)
			{
				if(s[j]==sn1)
					s[j]=sn2;
			}
		}
	}
}




void juzhen(void)
{
	struct jihe *g1;
	int mark,mark2=0;
	char xz;
	while(1)
	{
		printf("1)输入数据并建立图\n\n2)广度优先遍历\n\n3)深度优先遍历\n\n4)最小生成树\n\n0)退出\n\n请选择\n");
		xz=zqsr("12340");
		mark=0;
		switch (xz)
		{
			case '1':if(mark2==1)
					 {
						 g1=free1(g1->a,g1->x);
					 }
					 g1=chuA();mark2=1;break;
			case '2':bfs1(g1->a);break;
			case '3':dfs1(g1->a);break;
			case '4':zuixiao(g1->a,g1->x);break;
			case '0':mark=1;break;
		}
		system("pause");system("cls");
		if(mark==1)
			break;
	}
	free1(g1->a,g1->x);
}
void biao(void)
{
	struct B *g2;
	int mark,mark2=0;
	char xz;
	while(1)
	{
		printf("1)输入数据并建立图\n\n2)广度优先遍历\n\n3)深度优先遍历\n\n0)退出\n\n请选择\n");
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
		printf("1)邻接矩阵存储图\n\n2)邻接表存储图\n\n0)退出\n\n请选择\n");
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

