#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
struct jihe
{
	struct A *a;
	struct kedge **x;
	int mark;
};
struct jihe2
{
	struct B *a;
	struct kedge **x;
	int mark;
};
struct A
{
	char *dd;
	int **bian;
	int n,e;
};
struct node
{
	int ldd;					//连接顶点
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
struct closedge
{
	int adjvex;
	int lowcost;
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
struct jihe * chuA(void)
{
	struct jihe *b;
	struct A *g;
	struct kedge **p;
	int i,j,k,quan,mark;
	char mark2;
	g=(struct A *)malloc(sizeof(struct A));
	printf("1)无向图\n\n2)有向图\n");
	mark2=zqsr("12");
	mark=mark2-48;
	system("cls");
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
		printf("请输入权值:");
		while(scanf("%d",&quan)!=1||quan<0)
		{
			printf("输入有误请重新输入\n");
			fflush(stdin);
		}fflush(stdin);
		printf("\n");
		g->bian[j][k]=quan;
		if(mark==1)
			g->bian[k][j]=quan;
		p[i]->vex1=j;
		p[i]->vex2=k;
		p[i]->wight=quan;
	}
	b->a=g;
	b->x=p;
	b->mark=mark;
	return b;
}
struct jihe2 *chuB(void)
{
	struct jihe2 *b;
	struct kedge **p;
	struct B *g;
	struct node *s;
	int i,j,k,mark,quan;
	char mark2;
	g=(struct B *)malloc(sizeof(struct B));
	printf("1)无向图\n\n2)有向图\n");
	mark2=zqsr("12");
	mark=mark2-48;
	system("cls");
	printf("请输入顶点数，边数(用空格隔开)\n");
	while(scanf("%d %d",&g->n,&g->e)!=2||g->n<=0||g->e<0)
	{
		printf("输入有误，请重新输入\n");
		fflush(stdin);
	}fflush(stdin);
	g->adlist=(struct vnode *)malloc(sizeof(struct vnode)*g->n);
	p=(struct kedge **)malloc(sizeof(struct kedge *)*g->e);
	for(i=0;i<g->e;i++)
		p[i]=(struct kedge *)malloc(sizeof(struct kedge));
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
		printf("请输入权值:");
		while(scanf("%d",&quan)!=1||quan<0)
		{
			printf("输入有误请重新输入\n");
			fflush(stdin);
		}fflush(stdin);
		printf("\n");
		s->ldd=k;
		s->quan=quan;
		s->next=g->adlist[j].firstnode;
		g->adlist[j].firstnode=s;
		
		if(mark==1)
		{
			s=(struct node *)malloc(sizeof(struct node));
			s->quan=quan;
			s->ldd=j;
			s->next=g->adlist[k].firstnode;	
			g->adlist[k].firstnode=s;
		}

		p[i]->vex1=j;
		p[i]->vex2=k;
		p[i]->wight=quan;
	}
	b=(struct jihe2 *)malloc(sizeof(struct jihe2));
	b->a=g;
	b->x=p;
	b->mark=mark;
	return b;
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
	if(g==NULL)
		return;
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
	if(g==NULL)
		return;
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
	}
	for(i=0;i<g->e;i++)
		free(k[i]);
	free(k);
	free(g->bian);
	free(g);
	return NULL;
}
struct jihe* free2(struct B *g,struct kedge **k)
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
	for(i=0;i<g->e;i++)
		free(k[i]);
	free(k);
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
void kruskal(struct A *g,struct kedge **k)
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
	free(s);
}
void prim(struct A *g,int v)
{
	struct closedge *form;
	int i,j,k,mincost;
	form=(struct closedge *)malloc(sizeof(struct closedge)*g->n);
	for(i=0;i<g->n;i++)
	{
		if(g->bian[v][i]!=0)
		{
			form[i].adjvex=v;
			form[i].lowcost=g->bian[v][i];
		}
		else
		{
			form[i].lowcost=2147483647;
		}
	}	
	form[v].lowcost=0;
	for(i=0;i<g->n-1;i++)
	{
		for(j=0;j<g->n;j++)
		{
			if(form[j].lowcost!=0)
			{
				k=j;
				break;
			}
		}
		mincost=form[k].lowcost;
		for(j=k;j<g->n;j++)
		{
			if(form[j].lowcost!=0&&mincost>form[j].lowcost)
			{
				mincost=form[j].lowcost;
				k=j;
			}
		}
		printf("(%c,%c):%d\n",g->dd[form[k].adjvex],g->dd[k],g->bian[form[k].adjvex][k]);
		form[k].lowcost=0;
		for(j=0;j<g->n;j++)
		{
			if(form[j].lowcost!=0&&g->bian[k][j]!=0&&g->bian[k][j]<form[j].lowcost)
			{
				form[j].lowcost=g->bian[k][j];
				form[j].adjvex=k;
			}
		}
	}
	free(form);
}
void zuixiao(struct A *g,struct kedge **k)
{
	char xz;
	printf("1)克鲁斯卡尔\n\n2)普利姆\n\n");
	xz=zqsr("12");
	if(xz=='1')
		kruskal(g,k);
	else
		prim(g,0);
}

void dispath(int *dist,int *path,int *set,int v,struct A *g)
{
	int i,k,top=-1;
	int stack[100];
/*	for(i=0;i<g->n;i++)
	{
		if(set[i]==1&&i!=v)
		{
			k=i;
			printf("从 %c 到 %c 的最短路径为:\n",g->dd[v],g->dd[i]);
			while(k!=v)
			{
				printf("%c<-",g->dd[k]);
				k=path[k];
			}
			printf("%c",g->dd[v]);
			printf("\n路径长度为:%d\n",dist[i]);
		}
		if(i!=v)
			printf("%c 和 %c 之间不存在路径\n\n",g->dd[v],g->dd[i]);
	}*/
	for(i=0;i<g->n;i++)
	{
		if(i!=v&&set[i]==1)
		{
			k=i;
			printf("从 %c 到 %c 的最短路径为:\n",g->dd[v],g->dd[i]);
			while(k!=v)
			{
				stack[++top]=k;
				k=path[k];
			}
			printf("%c->",g->dd[v]);
			while(top)
			{
				printf("%c->",g->dd[stack[top--]]);
			}
			printf("%c",g->dd[stack[top--]]);
			printf("\n路径长度为:%d\n\n",dist[i]);
		}
		if(i!=v&&set[i]!=1)
			printf("%c 和 %c 之间不存在路径\n\n",g->dd[v],g->dd[i]);
	}
}

void zuiduan(struct A *g)
{
	int i,j,k,p,min;
	char dd;
	int *dist,*path,*set;
	dist=(int *)malloc(sizeof(int)*g->n);
	path=(int *)malloc(sizeof(int)*g->n);
	set=(int *)malloc(sizeof(int)*g->n);
	printf("请输入要求顶点:\n");
	while(scanf("%c",&dd)!=1)
	{
		printf("输入有误,请重新输入\n");
		fflush(stdin);
	}
	fflush(stdin);
	for(k=0;k<g->n;k++)
	{
		if(g->dd[k]==dd)
			break;
	}
	if(k<g->n)
	{
		for(i=0;i<g->n;i++)
		{
			if(g->bian[k][i]!=0)
			{
				dist[i]=g->bian[k][i];
				path[i]=k;
			}
			else
			{
				dist[i]=2147483647;
				path[i]=-1;
			}
			set[i]=0;
		}
		set[k]=1;
		for(i=0;i<g->n-1;i++)
		{
			min=2147483647;
			for(j=0;j<g->n;j++)
			{
				if(set[j]==0&&path[j]!=-1&&min>dist[j])
				{
					p=j;
					min=dist[j];
				}
			}
			set[p]=1;
			for(j=0;j<g->n;j++)
			{
				if(set[j]==0&&g->bian[p][j]!=0&&g->bian[p][j]+dist[p]<dist[j])
				{
					dist[j]=g->bian[p][j]+dist[p];
					path[j]=p;
				}
			}
		}
		dispath(dist,path,set,k,g);
	}
	else
		printf("输入顶点有误\n");
	free(dist);
	free(path);
	free(set);
}


int *topsort(struct A *g)
{
	int i,j,k,p=0;
	int *indegree,*sort;
	indegree=(int *)malloc(sizeof(int)*g->n);
	sort=(int *)malloc(sizeof(int)*g->n);
	for(i=0;i<g->n;i++)
	{
		indegree[i]=0;
		for(j=0;j<g->n;j++)
		{
			if(g->bian[j][i]!=0)
				indegree[i]++;
		}
	}
	for(i=0;i<g->n;i++)
	{
		for(j=0;j<g->n;j++)
		{
			if(indegree[j]==0)
				break;
		}
		if(j>=g->n)
		{
			return NULL;
		}
		for(k=0;k<g->n;k++)
		{
			if(g->bian[j][k]!=0)
			{
				if(indegree[k]!=-1)
					indegree[k]--;
			}
		}
	
		indegree[j]=-1;
		sort[p]=j;
		p++;
	}
	free(indegree);
	return sort;
}

void printtop(struct A *g)
{
	int i;
	int *s;
	s=topsort(g);
	if(s==NULL)
	{
		printf("此图有环！无法拓扑排序\n");
	}
	else
	{
		printf("拓扑排序后顺序如下:\n");
		for(i=0;i<g->n;i++)
		{
			printf("%c  ",g->dd[s[i]]);
		}
		printf("\n");
	}
	free(s);
}

void guanjian(struct A *g)
{
	int i,j,e,l;
	int *ve,*vl,*sort;
	sort=(int *)malloc(sizeof(int)*g->n);
	ve=(int *)malloc(sizeof(int)*g->n);
	vl=(int *)malloc(sizeof(int)*g->n);
	for(i=0;i<g->n;i++)
	{
		ve[i]=0;
	}
	sort=topsort(g);
	for(i=0;i<g->n;i++)
	{
		for(j=0;j<g->n;j++)
		{
			if(g->bian[sort[i]][j]!=0&&ve[sort[i]]+g->bian[sort[i]][j]>ve[j])
				ve[j]=ve[sort[i]]+g->bian[sort[i]][j];
		}
	}
	for(i=0;i<g->n;i++)
	{
		vl[i]=ve[g->n-1];
	}
	for(i=g->n-2;i>=0;i--)
	{
		for(j=0;j<g->n;j++)
		{
			if(g->bian[sort[i]][j]!=0&&vl[j]-g->bian[sort[i]][j]<vl[sort[i]])
				vl[sort[i]]=vl[j]-g->bian[sort[i]][j];
		}
	}
	for(i=0;i<g->n;i++)
	{
		for(j=0;j<g->n;j++)
		{
			if(g->bian[sort[i]][j]!=0)
			{
				e=ve[sort[i]];
				l=vl[j]-g->bian[sort[i]][j];
				if(e==l)
				{
					printf("(%c,%c),e=%-3d,l=%-3d,权=%d\n",g->dd[sort[i]],g->dd[j],e,l,g->bian[sort[i]][j]);
				}
			}
		}
	}
}

void juzhen(void)
{
	struct jihe *g1=NULL;
	int mark,mark2=0;
	char xz;
	while(1)
	{
		if(g1==NULL)
		{
			printf("1)输入数据并建立图\n\n0)退出\n\n请选择\n");
			xz=zqsr("10");
		}
		else
		{
			printf("1)广度优先遍历\n\n2)深度优先遍历\n\n3)最小生成树\n\n4)最短路径\n\n5)拓扑排序\n\n6)关键路径\n\n0)退出\n\n请选择\n");
			xz=zqsr("1234560");
			if(xz!='0')
				xz=xz+1;
		}
		mark=0;
		switch (xz)
		{
			case '1':if(mark2==1)
					 {
						 free1(g1->a,g1->x);
						 free(g1);
						 g1=NULL;
					 }
					 g1=chuA();mark2=1;break;
			case '2':bfs1(g1->a);break;
			case '3':dfs1(g1->a);break;
			case '4':if(g1->mark==1)
					 {
						 zuixiao(g1->a,g1->x);
					 }
					 else
					 {
						 printf("有向图无法找到最小生成树\n");
					 }
					 break;
			case '5':zuiduan(g1->a);break;
			case '6':if(g1->mark==2)
					 {
						 printtop(g1->a);
					 }
					else
					{
						printf("无向图无法拓扑排序\n");
					}
					break;
			case '7':guanjian(g1->a);break;
			case '0':mark=1;break;
		}
		system("pause");system("cls");
		if(mark==1)
			break;
	}
	if(g1!=NULL)
	{
		free1(g1->a,g1->x);
		free(g1);
	}
}
void kruskal2(struct B *g,struct kedge **k)
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
			printf("(%c,%c):%d\n",g->adlist[m1].dd,g->adlist[m2].dd,k[i]->wight);
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
	free(s);
}
void prim2(struct B *g,int v)
{
	struct closedge *form;
	struct node *p;
	int i,j,k,mincost;
	form=(struct closedge *)malloc(sizeof(struct closedge)*g->n);
	for(i=0;i<g->n;i++)
	{
		form[i].lowcost=2147483647;
	}
	form[v].lowcost=0;
	p=g->adlist[v].firstnode;
	while(p)
	{
		form[p->ldd].adjvex=v;
		form[p->ldd].lowcost=p->quan;
		p=p->next;
	}
	for(i=0;i<g->n-1;i++)
	{
		for(j=0;j<g->n;j++)
		{
			if(form[j].lowcost!=0)
			{
				k=j;
				break;
			}
		}
		mincost=form[k].lowcost;
		for(j=k;j<g->n;j++)
		{
			if(form[j].lowcost!=0&&mincost>form[j].lowcost)
			{
				k=j;
				mincost=form[j].lowcost;
			}
		}
		p=g->adlist[form[k].adjvex].firstnode;
		while(p)
		{
			if(p->ldd==g->adlist[k].dd-48)
				break;
			p=p->next;
		}
		printf("(%c,%c):%d\n",g->adlist[form[k].adjvex].dd,g->adlist[k].dd,p->quan);
		form[k].lowcost=0;
		p=g->adlist[k].firstnode;
		while(p)
		{
			if(form[p->ldd].lowcost!=0&&form[p->ldd].lowcost>p->quan)
			{
				form[p->ldd].adjvex=k;
				form[p->ldd].lowcost=p->quan;
			}
			p=p->next;
		}
	}
	free(form);
}
void zuixiao2(struct B *g,struct kedge **k)
{
	char xz;
	printf("1)克鲁斯卡尔\n2)普利姆\n");
	xz=zqsr("12");
	if(xz=='1')
		kruskal2(g,k);
	else
		prim2(g,0);
}

void dispath2(int *dist,int *path,int *set,int v,struct B *g)
{
	int i,k,top=-1;
	int stack[100];
	for(i=0;i<g->n;i++)
	{
		if(i!=v&&set[i]==1)
		{
			k=i;
			printf("从 %c 到 %c 的最短路径为:\n",g->adlist[v].dd,g->adlist[i].dd);
			while(k!=v)
			{
				stack[++top]=k;
				k=path[k];
			}
			printf("%c->",g->adlist[v].dd);
			while(top)
			{
				printf("%c->",g->adlist[stack[top--]].dd);
			}
			printf("%c",g->adlist[stack[top--]].dd);
			printf("\n路径长度为:%d\n\n",dist[i]);
		}
		if(i!=v&&set[i]!=1)
			printf("%c 和 %c 之间不存在路径\n\n",g->adlist[v].dd,g->adlist[i].dd);
	}
}

void zuiduan2(struct B *g)
{
	int i,j,k,min,n;
	char dd;
	struct node *p;
	int *dist,*path,*set;
	dist=(int *)malloc(sizeof(int)*g->n);
	path=(int *)malloc(sizeof(int)*g->n);
	set=(int *)malloc(sizeof(int)*g->n);
	printf("请输入要求顶点:\n");
	while(scanf("%c",&dd)!=1)
	{
		printf("输入有误,请重新输入\n");
		fflush(stdin);
	}fflush(stdin);
	for(k=0;k<g->n;k++)
	{
		if(g->adlist[k].dd==dd)
			break;
	}
	if(k<g->n)
	{
		for(i=0;i<g->n;i++)
		{
			set[i]=0;
			dist[i]=2147483647;
			path[i]=-1;
		}
		p=g->adlist[k].firstnode;
		while(p)
		{
			dist[p->ldd]=p->quan;
			path[p->ldd]=k;
			p=p->next;
		}
		set[k]=1;
		for(i=0;i<g->n-1;i++)
		{
			min=2147483647;
			for(j=0;j<g->n;j++)
			{
				if(set[j]!=1&&min>dist[j])
				{
					min=dist[j];
					n=j;
				}
			}
			set[n]=1;
			p=g->adlist[n].firstnode;
			while(p)
			{
				if(set[p->ldd]!=1&&dist[n]+p->quan<dist[p->ldd])
				{
					path[p->ldd]=n;
					dist[p->ldd]=dist[n]+p->quan;
				}
				p=p->next;
			}
		}
		dispath2(dist,path,set,k,g);
	}
	else
	{
		printf("输入顶点有误\n");
	}
	free(dist);
	free(set);
	free(path);
}

int *topsort2(struct B *g)
{
	int i,j,p=0;
	int *indegree,*sort;
	struct node *q;
	indegree=(int *)malloc(sizeof(int)*g->n);
	sort=(int *)malloc(sizeof(int)*g->n);
	for(i=0;i<g->n;i++)
		indegree[i]=0;
	for(i=0;i<g->n;i++)
	{
		q=g->adlist[i].firstnode;
		while(q)
		{
			indegree[q->ldd]++;
			q=q->next;
		}
	}
	for(i=0;i<g->n;i++)
	{
		for(j=0;i<g->n;j++)
		{
			if(indegree[j]==0)
				break;
		}
		if(j>=g->n)
		{
			return NULL;
		}
		q=g->adlist[j].firstnode;
		while(q)
		{
			if(indegree[q->ldd]!=-1)
			{
				indegree[q->ldd]--;
			}
			q=q->next;
		}
		indegree[j]=-1;
		sort[p]=j;
		p++;
	}
	free(indegree);
	return sort;
}

int *topsort3(struct B *g)
{
	int i,p=0,top=-1;
	int *indegree,*sort,*stack;
	struct node *q;
	indegree=(int *)malloc(sizeof(int)*g->n);
	sort=(int *)malloc(sizeof(int)*g->n);
	stack=(int *)malloc(sizeof(int)*g->n);
	for(i=0;i<g->n;i++)
		indegree[i]=0;
	for(i=0;i<g->n;i++)
	{
		q=g->adlist[i].firstnode;
		while(q)
		{
			indegree[q->ldd]++;
			q=q->next;
		}
	}
	for(i=0;i<g->n;i++)
	{
		if(indegree[i]==0)
		{
			stack[++top]=i;
		}
	}
	while(top>=0)
	{
		sort[p]=stack[top--];
		q=g->adlist[sort[p]].firstnode;
		p++;
		while(q)
		{
			indegree[q->ldd]--;
			if(indegree[q->ldd]==0)
				stack[++top]=q->ldd;
			q=q->next;
		}
	}
	if(p==g->n)
		return sort;
	else
		return NULL;
}


int *topsort4(struct B *g)
{
	int i,p=0,front=0,rear=0;
	int *indegree,*sort,*queue;
	struct node *q;
	indegree=(int *)malloc(sizeof(int)*g->n);
	sort=(int *)malloc(sizeof(int)*g->n);
	queue=(int *)malloc(sizeof(int)*g->n+1);
	for(i=0;i<g->n;i++)
		indegree[i]=0;
	for(i=0;i<g->n;i++)
	{
		q=g->adlist[i].firstnode;
		while(q)
		{
			indegree[q->ldd]++;
			q=q->next;
		}
	}
	for(i=0;i<g->n;i++)
	{
		if(indegree[i]==0)
		{
			queue[rear]=i;
			rear=(rear+1)%(g->n+1);
		}
	}
	while(front!=rear)
	{
		sort[p]=queue[front];
		front=(front+1)%(g->n+1);
		q=g->adlist[sort[p]].firstnode;
		p++;
		while(q)
		{
			indegree[q->ldd]--;
			if(indegree[q->ldd]==0)
			{
				queue[rear]=q->ldd;
				rear=(rear+1)%(g->n+1);
			}
			q=q->next;
		}
	}
	if(p==g->n)
		return sort;
	else
		return NULL;
}			




void printtop2(struct B *g)
{
	int i;
	int *s;
	char xz;
	printf("1)顺序优先拓扑排序\n\n2)深度优先拓扑排序\n\n3)广度优先拓扑排序\n\n");
	xz=zqsr("123");
	switch(xz)
	{
		case '1':s=topsort2(g);break;
		case '2':s=topsort3(g);break;
		case '3':s=topsort4(g);break;
	}
	if(s==NULL)
	{
		printf("此图有环！无法拓扑排序\n");
	}
	else
	{
		printf("拓扑排序后顺序如下:\n");
		for(i=0;i<g->n;i++)
		{
			printf("%c  ",g->adlist[s[i]].dd);
		}
		printf("\n");
	}
	free(s);
}


void guanjian2(struct B *g)
{
	int i,k,e,l;
	int *ve,*vl,*sort;
	struct node *p;
	sort=(int *)malloc(sizeof(int)*g->n);
	ve=(int *)malloc(sizeof(int)*g->n);
	vl=(int *)malloc(sizeof(int)*g->n);
	for(i=0;i<g->n;i++)
	{
		ve[i]=0;
	}
	sort=topsort3(g);
	for(i=0;i<g->n;i++)
	{
		p=g->adlist[sort[i]].firstnode;
		while(p)
		{
			k=p->ldd;
			if(ve[sort[i]]+p->quan>ve[k])
			{
				ve[k]=ve[sort[i]]+p->quan;
			}
			p=p->next;
		}
	}
	for(i=0;i<g->n;i++)
	{
		vl[i]=ve[g->n-1];
	}
	for(i=g->n-2;i>=0;i--)
	{
		p=g->adlist[sort[i]].firstnode;
		while(p!=NULL)
		{
			k=p->ldd;
			if(vl[k]-p->quan<vl[sort[i]])
			{
				vl[sort[i]]=vl[k]-p->quan;
			}
			p=p->next;
		}
	}
	for(i=0;i<g->n;i++)
	{
		p=g->adlist[sort[i]].firstnode;
		while(p)
		{
			k=p->ldd;
			e=ve[sort[i]];
			l=vl[k]-p->quan;
			if(e==l)
				printf("(%c,%c),e=%-3d,l=%-3d,权=%d\n",g->adlist[sort[i]].dd,g->adlist[k].dd,e,l,p->quan);
			p=p->next;
		}
	}
}


void biao(void)
{
	struct jihe2 *g2=NULL;
	int mark,mark2=0;
	char xz;
	while(1)
	{
		if(g2==NULL)
		{
			printf("1)输入数据并建立图\n\n0)退出\n\n请选择\n");
			xz=zqsr("10");
		}
		else
		{
			printf("1)广度优先遍历\n\n2)深度优先遍历\n\n3)最小生成树\n\n4)最短路径\n\n5)拓扑排序\n\n6)关键路径\n\n0)退出\n\n请选择\n");
			xz=zqsr("1234560");
			if(xz!='0')
				xz=xz+1;
		}
		mark=0;
		switch (xz)
		{
			case '1':if(mark2==1)
					 {
						 free2(g2->a,g2->x);
						 free(g2);
						 g2=NULL;
					 }
					 g2=chuB();mark2=1;break;
			case '2':bfs2(g2->a);break;
			case '3':dfs2(g2->a);break;
			case '4':if(g2->mark==1)
					 {
						zuixiao2(g2->a,g2->x);
					 }
				 	 else
					 {
						 printf("有向图无法找到最小生成树\n");
					 }
					 break;
			case '5':zuiduan2(g2->a);break;
			case '6':if(g2->mark==2)
					 {
						 printtop2(g2->a);
					 }
					else
					{
						printf("无向图无法拓扑排序\n");
					}
					break;
			case '7':guanjian2(g2->a);break;
			case '0':mark=1;break;
		}

		system("pause");system("cls");
		if(mark==1)
			break;
	}
	if(g2!=NULL)
	{
		free2(g2->a,g2->x);
		free(g2);
	}
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
		system("cls");
		if(mark==1)
			break;
	}
	return 0;
}

