/*
------作者------王占伟
------时间------20160519
------名称------SLR(1)文法分析(包含空产生)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAXLENGTH 20		//产生式最大长度
#define WRONG -1			//错误符号位置
#define END -1				//产生式结束符
#define MAXPROJECTSET 20	//项目集中项目最多数量
#define MAXSTATUS 50		//状态最多数量
#define ENDSTATUS 0			//终结状态
#define NOTENDSTATUS 1		//非终结状态
#define BEGINS	'$'			//扩充S' 为 $ 符
#define ACC -3				//接受标志
#define GUIYUE -2			//规约标志
#define MAXSTACK 200		//分析栈最大容量
#define MAXSTRING 200		//待分析串最大长度
#define MAX 100
#define EMPTY '0'
#define UNDEFINE -1
#define CANEMPTY 1		//能推出空
#define CANNOTEMPTY 0	//不能推出空
#define MAXNUM 50
#define UNVISITED 0		//图辅助数组未访问状态
#define VISITED 1		//图辅助数组已访问状态

int * FindEmpty(struct produce *P);		//找到可以退出空的非终结符
struct picture *BuildPictureOfFirst(struct picture *g,struct produce *P,int *Empty);		//建立First集	图
struct picture *BuildPictureOfFollow(struct picture *g,struct produce *P,int *Empty);		//建立Follow集	图 
void DFSAL(struct B *g,int i);			//深度优先遍历
int **CalculateFirst(struct B *g,struct produce * P);	//计算first集
int **CalculateFollow(struct B *g,struct produce * P);	//计算follow集

struct node
{
	int ldd;
	struct node *next;
};
struct vnode
{
	int symbol;
	int mark;			//0 终结符 1 First 2 Follow 
	struct node *firstnode;
};
struct picture
{
	struct vnode *adlist;
	int n,e;
};


struct produce
{
	int **produceR;		//产生式右部
	int *produceL;		//产生式左部
	char *symbol;		//所有符号
	int segmentation;	//非终结数-1
	int numberOFpro;
	int numberOFsym;
};

struct projectset
{
	int ps[MAXPROJECTSET][2];	//项目集	[0]产生式位置，[1]点位置
	int n;						//个数
	int mark;
	bool operator ==(const projectset &p1)
	{
		int i;
		if(n!=p1.n)
			return 0;
		for(i=0;i<n;i++)
		{
			if(ps[i][0]!=p1.ps[i][0]||ps[i][1]!=p1.ps[i][1])
				return 0;
		}
		return 1;
	}
};


struct projectset CORE[MAXSTATUS];					//核
int CORENUMBER=0;									//数量
struct projectset STATUS[MAXSTATUS];
int STATUSTRANSFORM[MAXSTATUS][MAXSTATUS][3];		//[0]符号  [1]移向的状态   [2]移向状态的状态
int STNUMBER[MAXSTATUS];


struct data
{
	struct projectset proset;
	int status;
	struct data *next;
};
struct queue
{
	struct data *front;
	struct data *rear;
};
struct queue * chushihua(void)
{
	struct data *p;
	struct queue *Q;
	p=(struct data *)malloc(sizeof(struct data));
	Q=(struct queue *)malloc(sizeof(struct queue));
	p->next=NULL;
	Q->front=p;
	Q->rear=p;
	return Q;
}
int kong(struct queue *Q)
{
	return Q->front==Q->rear;
}
int rudui(struct queue *Q,struct projectset x,int status)
{
	struct data *New;
	New=(struct data *)malloc(sizeof(struct data));
	if(New==NULL)
	{
		printf("内存不足，无法再入队\n");
		return 0;
	}
	New->proset=x;
	New->status=status;
	Q->rear->next=New;
	New->next=NULL;
	Q->rear=New;
	return 1;
}
int chudui(struct queue *Q,struct projectset &x,int &status)
{
	struct data *p;
	if(kong(Q))
	{
		printf("列队为空，无法出队!\n");
		return 0;
	}
	p=Q->front->next;
	x=p->proset;
	status=p->status;
	Q->front->next=p->next;
	if (p == Q->rear)
		Q->rear = Q->front;
	free(p);
	return 1;
}

int location(char *symbol,char c,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(c==symbol[i])
			return i;
	}
	return WRONG;
}

struct produce * ExpandInitialize(void)
{
	struct produce *P;
	int i,j,l,mark;
	char c[MAXLENGTH];
	P=(struct produce *)malloc(sizeof(struct produce));
	printf("请输入非终结符总数和符号总数(逗号隔开,空算一个终结符): ");
	while(scanf("%d,%d",&P->segmentation,&P->numberOFsym)!=2||P->segmentation<=0||P->numberOFsym<=0)
	{
		fflush(stdin);printf("请输入正确总数，请重新输入\n");
	}
	fflush(stdin);
	P->numberOFsym++;
	P->numberOFsym++;
	P->numberOFsym++;
	P->symbol=(char *)malloc(sizeof(char)*P->numberOFsym);
	P->numberOFsym--;
	system("cls");
	printf("请输入非终结符号，每行一个(请第一个输入 起始符)\n");
	for(i=1;i<=P->segmentation;i++)
	{
		
		scanf("%c",&P->symbol[i]);
		fflush(stdin);	
	}
	system("cls");
	printf("请输入终结符号:\n");
	for(i=P->segmentation+1;i<P->numberOFsym-1;i++)
	{
		scanf("%c",&P->symbol[i]);
		fflush(stdin);
	
	}
	system("cls");
	P->symbol[i]='#';		//最后加上 #
	P->symbol[i+1]='0';
	P->symbol[0]='$';
	system("cls");
	printf("请输入产生式总数: ");
	while(scanf("%d",&P->numberOFpro)!=1||P->numberOFpro<=0)
	{
		fflush(stdin);printf("请输入正确总数，请重新输入\n");
	}
	system("cls");
	fflush(stdin);
	P->numberOFpro++;
	P->produceR=(int **)malloc(sizeof(int *)*P->numberOFpro);
	P->produceL=(int *)malloc(sizeof(int)*P->numberOFpro);

	P->produceR[0]=(int *)malloc(sizeof(int)*MAXLENGTH);	//扩充S'->E
	P->produceL[0]=0;
	P->produceR[0][0]=1;
	P->produceR[0][1]=END;

	for(i=1;i<P->numberOFpro;i++)
	{
		printf("请输入产生式:(左右部用->隔开)(空用 0 表示)\n");
		P->produceR[i]=(int *)malloc(sizeof(int)*MAXLENGTH);
		while(1)
		{
			gets(c);
			if(c[1]!='-'||c[2]!='>')
			{
				printf("输入有误，请重新输入:\n");
				continue;
			}
			if(location(P->symbol,c[0],P->numberOFsym)>P->segmentation)
			{
				printf("输入有误。(产生式左部有且只有一个非终结符),请重新输入\n");
				continue;
			}
			P->produceL[i]=location(P->symbol,c[0],P->numberOFsym);
			l=strlen(c)-3;
			mark=0;
			for(j=0;j<l;j++)
			{
				P->produceR[i][j]=location(P->symbol,c[j+3],P->numberOFsym);
				if(P->produceR[i][j]==WRONG)
				{
					printf("此产生式含有非法符号，请重新输入:\n");
					mark=1;
					break;
				}
			}
			if(mark==1)
				continue;
			P->produceR[i][j]=END;
			break;
		}
		system("cls");
	}
	return P;
}
int * FindEmpty(struct produce *P)
{	
	int *E,*Efuzhu,i,j,*F,lofe,mark,mark2;		//lofe空的位置
	E=(int *)malloc(sizeof(int)*(P->segmentation+1));
	Efuzhu=(int *)malloc(sizeof(int)*(P->segmentation+1));
	F=(int *)malloc(sizeof(int)*(P->numberOFpro));
	lofe=location(P->symbol,EMPTY,P->numberOFsym);
	for(i=0;i<P->segmentation+1;i++)
	{
		E[i]=UNDEFINE;						//非终结符mark
		Efuzhu[i]=0;
	}
	for(i=0;i<P->numberOFpro;i++)
	{
		F[i]=1;							//产生式mark
		Efuzhu[P->produceL[i]]++;
	}
	for(i=0;i<P->numberOFpro;i++)
	{
		if(F[i]!=0)
		{
			j=0;
			while(P->produceR[i][j]!=END)	//如果右部含有终结符且不是空，则删除该产生式
			{	
				if(P->produceR[i][j]!=lofe&&P->produceR[i][j]>P->segmentation)	
				{
					F[i]=0;
					Efuzhu[P->produceL[i]]--;
					break;
				}
				j++;
			}
			if(P->produceR[i][0]==lofe)		//右部为空，置左部非终结符能推出空，并删除所有左部为该终结符的产生式
			{
				F[i]=0;	
				Efuzhu[P->produceL[i]]--;
				E[P->produceL[i]]=CANEMPTY;
				for(j=0;j<P->numberOFpro;j++)
				{
					if(F[j]!=0)
					{
						if(P->produceL[j]==P->produceL[i])
						{
							F[j]=0;
							Efuzhu[P->produceL[j]]--;
						}
					}
				}
			}
		}
	}
	for(i=0;i<P->segmentation+1;i++)
	{
		if(Efuzhu[i]==0)
			if(E[i]==UNDEFINE)
				E[i]=CANNOTEMPTY;
	}
	while(1)
	{
		mark2=0;
		for(i=0;i<P->numberOFpro;i++)
		{
			if(F[i]==1)
			{
				j=0;mark=0;
				while(P->produceR[i][j]!=END)	
				{	
					if(E[P->produceR[i][j]]==CANNOTEMPTY)
					{
						F[i]=0;	
						Efuzhu[P->produceL[i]]--;
						mark=1;
						break;
					}
					if(E[P->produceR[i][j]]==UNDEFINE)		//如果含有未定
					{
						mark=1;
					}
					j++;
				}
				if(mark==0)		//能推出空
				{
					E[P->produceL[i]]=CANEMPTY;		//置1
					for(j=0;j<P->numberOFpro;j++)	//删除所有左部为此非终结符的产生式
					{
						if(F[j]!=0)
						{
							if(P->produceL[j]==P->produceL[i])
							{
								F[j]=0;
								Efuzhu[P->produceL[j]]--;
							}
						}
					}
					mark2=1;
				}
				for(j=0;j<P->segmentation+1;j++)	//如果左部删光了某一个非终结符且未定，则置0
				{
					if(Efuzhu[j]==0)
						if(E[j]==UNDEFINE)
						{
							E[j]=CANNOTEMPTY;
							mark2=1;
						}
				}
			}
		}
		if(mark2==0)		//如果数组没有在改变结束
			break;
	}
	free(F);
	free(Efuzhu);
	return E;
}

struct picture *BuildPictureOfFirst(struct picture *g,struct produce *P,int *Empty)	//first	
{
	int i,j,k,lofe=location(P->symbol,EMPTY,P->numberOFsym);
	struct node *s;
	for(i=0;i<P->segmentation+1;i++)			//对每个非终结符
	{	
		for(j=0;j<P->numberOFpro;j++)			//对每个产生式
		{
			if(P->produceL[j]==i)				//左部是该非终结符	
			{	
				k=0;
				if(P->produceR[j][k]<=P->segmentation)	//如果左部第一个 是非终结符
				{
					if(Empty[P->produceR[j][k]]==CANEMPTY)		//如果左部第一个非终结符且能推出空
					{
						
						s=(struct node *)malloc(sizeof(struct node));
						s->ldd=P->produceR[j][k];		
						s->next=g->adlist[i].firstnode;		//建立图 该终结符first集包含第一个非终结符first集
						g->adlist[i].firstnode=s;
						k++;
						while(P->produceR[j][k]!=END)		//查看接下来的
						{
							if(P->produceR[j][k]<=P->segmentation&&Empty[P->produceR[j][k]]==CANEMPTY)	//如果仍为非终结符且能推出空 
							{
								s=(struct node *)malloc(sizeof(struct node));
								s->ldd=P->produceR[j][k];
								s->next=g->adlist[i].firstnode;	
								g->adlist[i].firstnode=s;
								k++;						//只有能推出空才向后扫描
							}
							else if(P->produceR[j][k]<=P->segmentation&&Empty[P->produceR[j][k]]==CANNOTEMPTY)	//如果仍未非终结符且不能推出空（跳出）
							{	
								s=(struct node *)malloc(sizeof(struct node));
								s->ldd=P->produceR[j][k];
								s->next=g->adlist[i].firstnode;	
								g->adlist[i].firstnode=s;
								break;
							}
							else								//如果为终结符（跳出）
							{
								s=(struct node *)malloc(sizeof(struct node));
								s->ldd=P->produceR[j][k]+(P->segmentation+1);					//指向图中对应终结符位置
								s->next=g->adlist[i].firstnode;	
								g->adlist[i].firstnode=s;
								break;
							}
						}
					}
					else								//如果第一个是非终结符且不能推出空
					{
				
						s=(struct node *)malloc(sizeof(struct node));
						s->ldd=P->produceR[j][k];
						s->next=g->adlist[i].firstnode;	
						g->adlist[i].firstnode=s;
						
					}
				}
				else									//如果第一个是终结符（忽略空产生式）
				{
					if(P->produceR[j][k]!=lofe)
					{
						s=(struct node *)malloc(sizeof(struct node));
						s->ldd=P->produceR[j][k]+(P->segmentation+1);							//指向图中对应终结符位置
						s->next=g->adlist[i].firstnode;	
						g->adlist[i].firstnode=s;
					}
				}
			}
		}
	}
	return g;
}

struct picture *BuildPictureOfFollow(struct picture *g,struct produce *P,int *Empty)	//follow
{
	int i,j,k,lofe=location(P->symbol,EMPTY,P->numberOFsym);
	int FZ=P->segmentation+1;
	struct node *s;

	s=(struct node *)malloc(sizeof(struct node));
	s->ldd=g->n-1;		
	s->next=g->adlist[P->segmentation+1].firstnode;				//S 的follow集包含 #
	g->adlist[P->segmentation+1].firstnode=s;

	for(i=P->segmentation+1;i<(P->segmentation+1)*2;i++)			//对每个非终结符（follow集位置）
	{	
		for(j=0;j<P->numberOFpro;j++)								//对每个产生式
		{
			k=0;
			while(P->produceR[j][k]!=(i-FZ)&&P->produceR[j][k]!=END)		//找到该产生式右部的该非终结符
			{
				k++;
			}
			if(P->produceR[j][k]!=END)								//如果包含该非终结符
			{
				k++;
				if(P->produceR[j][k]==END)								//如果直接就是末尾
				{
					s=(struct node *)malloc(sizeof(struct node));	
					s->ldd=P->produceL[j]+(P->segmentation+1);			//将左部非终结符的follow集添加到该非终结符的follow集
					s->next=g->adlist[i].firstnode;	
					g->adlist[i].firstnode=s;
				}
				else													//不是末尾
				{
					if(P->produceR[j][k]<=P->segmentation)				//下一个如果是非终结符
					{
						if(Empty[P->produceR[j][k]]==CANEMPTY)					//如果下一非终结符能推出空
						{
							s=(struct node *)malloc(sizeof(struct node));
							s->ldd=P->produceR[j][k];		
							s->next=g->adlist[i].firstnode;				//建立图 该终结符follow集包含此终结符first集
							g->adlist[i].firstnode=s;
							k++;
							while(P->produceR[j][k]!=END)				//扫描接下来的符号
							{
								if(P->produceR[j][k]<=P->segmentation&&Empty[P->produceR[j][k]]==CANEMPTY)	//如果仍为非终结符且能推出空 
								{
									s=(struct node *)malloc(sizeof(struct node));
									s->ldd=P->produceR[j][k];
									s->next=g->adlist[i].firstnode;	
									g->adlist[i].firstnode=s;
									k++;
								}
								else if(P->produceR[j][k]<=P->segmentation&&Empty[P->produceR[j][k]]==CANNOTEMPTY)	//如果仍未非终结符且不能推出空（跳出）
								{	
									s=(struct node *)malloc(sizeof(struct node));
									s->ldd=P->produceR[j][k];
									s->next=g->adlist[i].firstnode;	
									g->adlist[i].firstnode=s;
									break;
								}
								else									//如果为终结符（跳出）
								{
									s=(struct node *)malloc(sizeof(struct node));
									s->ldd=P->produceR[j][k]+(P->segmentation+1);					//指向图中对应终结符位置
									s->next=g->adlist[i].firstnode;	
									g->adlist[i].firstnode=s;
									break;
								}
							}
							if(P->produceR[j][k]==END)								//如果直到结束
							{
								s=(struct node *)malloc(sizeof(struct node));	
								s->ldd=P->produceL[j]+(P->segmentation+1);			//将左部非终结符的follow集添加到该非终结符的follow集
								s->next=g->adlist[i].firstnode;	
								g->adlist[i].firstnode=s;
							}
						}
						else											//如果下一非终结符不能推出空
						{
							s=(struct node *)malloc(sizeof(struct node));
							s->ldd=P->produceR[j][k];		
							s->next=g->adlist[i].firstnode;				//建立图 该终结符follow集包含此非终结符first集
							g->adlist[i].firstnode=s;
						}
					}
					else											//如果下一个是终结符
					{
						s=(struct node *)malloc(sizeof(struct node));
						s->ldd=P->produceR[j][k]+(P->segmentation+1);		
						s->next=g->adlist[i].firstnode;					//建立图 该终结符follow集包含此终结符
						g->adlist[i].firstnode=s;
					}
				}
			}
		}
	}
	return g;
}


int visited[MAXNUM];

void DFSAL(struct picture *g,int i)
{
	struct node *p;
	visited[i]=1;
	p=g->adlist[i].firstnode;
	while(p)
	{
		if(!visited[p->ldd])
			DFSAL(g,p->ldd);
		p=p->next;
	}
}



int **CalculateFollow(struct picture *g,struct produce * P)
{
	int i,j,k,**Follow;
	int FZ=P->segmentation+1;
	Follow=(int **)malloc(sizeof(int)*(P->segmentation+1));
	for(i=0;i<P->segmentation+1;i++)
	{
		Follow[i]=(int *)malloc(sizeof(int)*P->numberOFsym);
		for(j=1;j<P->numberOFsym;j++)
			Follow[i][j]=END;
	}
	for(i=P->segmentation+1;i<(P->segmentation+1)*2;i++)
	{
		for(j=0;j<g->n;j++)
			visited[j]=UNVISITED;
		DFSAL(g,i);
		for(j=(P->segmentation+1)*2,k=0;j<g->n;j++)
		{
			if(visited[j]==VISITED)
			{
				Follow[i-FZ][k++]=g->adlist[j].symbol;
			}
		}
	}
	return Follow;
}

struct picture * FreePicture(struct picture *g) //释放图
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
int **CalculateF(struct produce *P)	//汇总
{
	int *Empty;
	int **FOLLOW;
	struct picture *g;

	int i;
	int lofe=location(P->symbol,EMPTY,P->numberOFsym);
	g=(struct picture *)malloc(sizeof(struct picture));	//图初始化
	g->n=(P->segmentation+1)+P->numberOFsym;
	g->adlist=(struct vnode *)malloc(sizeof(struct vnode)*g->n);
	for(i=0;i<P->segmentation+1;i++)	//First集
	{
		g->adlist[i].symbol=i;
		g->adlist[i].mark=1;
		g->adlist[i].firstnode=NULL;
	}
	for(;i<P->segmentation+1;i++)		//Follow集
	{
		g->adlist[i].symbol=i-(P->segmentation+1);
		g->adlist[i].mark=2;
		g->adlist[i].firstnode=NULL;
	}
	for(;i<g->n;i++)					//终结符集
	{
		g->adlist[i].symbol=i-(P->segmentation+1);
		g->adlist[i].mark=0;
		g->adlist[i].firstnode=NULL;
	}

	Empty=FindEmpty(P);	
	g=BuildPictureOfFirst(g,P,Empty);
	g=BuildPictureOfFollow(g,P,Empty);

	
	FOLLOW=CalculateFollow(g,P);

	g=FreePicture(g);
	return FOLLOW;
}
struct projectset CLOSURE(struct produce *P,struct projectset p)
{
	int i,j,k,n1=0,n2=p.n,mark,mark2;	//n1 记录前一次循环集合中的个数	n2记录循环后的个数
	int num=0;
	struct projectset N;
	for(i=0;i<p.n;i++)
	{
		N.ps[num][0]=p.ps[i][0];
		N.ps[num++][1]=p.ps[i][1];
	}
	while(1)
	{
		mark=0;
		for(i=n1;i<n2;i++)							//从新加的地方开始
		{
			if(P->produceR[N.ps[i][0]][N.ps[i][1]]<=P->segmentation)
			{
				for(j=1;j<P->numberOFpro;j++)		//从第一个产生式开始
				{
					mark2=0;
					if(P->produceL[j]==P->produceR[N.ps[i][0]][N.ps[i][1]])
					{
						for(k=0;k<num;k++)			//排除已添加的
						{
							if(N.ps[k][0]==j&&N.ps[k][1]==0)
							{
								mark2=1;
								break;
							}
						}
						if(mark2==1)
							continue;
						N.ps[num][0]=j;				//加入项目集
						N.ps[num++][1]=0;
						mark=1;
					}
				}
			}
		}
		n1=n2;
		n2=num;
		if(mark==0)								//如果没有再改变 跳出循环
			break;
	}
	N.n=num;
	return N;
}


struct projectset GO(struct produce *P,struct projectset I,int x,int status,int &place)	//I 前一个项目集  x 符号位置  status 前一个项目集的状态位置  place 下一个项目集的状态位置
{
	int i, j, mark = 0, mark2 = 0;
	int position=0;
	int fuzhu[MAXLENGTH],num=0;
	int lo = location(P->symbol, '0', P->numberOFsym);
	struct projectset J;
	J.n=0;
	for(i=0;i<I.n;i++)
	{
		if(P->produceR[I.ps[i][0]][I.ps[i][1]]==x)		//找到点后是x 的 位置
		{
			fuzhu[num++]=i;
		}
	}
	if(num==0)											//没有返回空
		return J;
	else
	{
		for(i=0;i<num;i++)								//将找到的加入项目集
		{
			J.ps[i][0]=I.ps[fuzhu[i]][0];
			J.ps[i][1]=I.ps[fuzhu[i]][1]+1;
			J.n++;
		}

		for(j=0;j<CORENUMBER;j++)	//核检查
		{
			if(CORE[j]==J)			//如果核已有
			{
				position=j;
				mark=1;			
				break;
			}
		}
		if(position==0)				//如果没有核，新建核
		{
			position=CORENUMBER;
			CORE[CORENUMBER]=J;
		}
		

		STATUSTRANSFORM[status][STNUMBER[status]][0]=x;			//填入 符号 到状态转换表对应位置
		STATUSTRANSFORM[status][STNUMBER[status]][1]=position;	//移向状态

		for (i = 0; i < J.n; i++)
		{
			if (P->produceR[J.ps[i][0]][J.ps[i][1]] == -1|| P->produceR[J.ps[i][0]][J.ps[i][1]] == lo )			//如果是终结状态或者为空产生式 
			{
				STATUSTRANSFORM[status][STNUMBER[status]++][2] = ENDSTATUS;	//标志设为终结		
				mark2 = 1;
				break;
			}
		}
		if(mark2==0)
		{
			STATUSTRANSFORM[status][STNUMBER[status]++][2]=NOTENDSTATUS;
			
		}
		if(mark==0)				//如果是新的核 则求闭包
			J=CLOSURE(P,J);										
		else					//否则返回空	//不再入队		
		{	
			J.n=0;	
			return J;			
		}
		place=position;			//记录此核的状态位置
		return J;
	}
}


void MakeStatusTransform(struct produce *P)
{
	struct projectset a, b, c;
	int i,j, status, place,mark;
	int lo = location(P->symbol, '0', P->numberOFsym);
	struct queue *Q;
	Q = chushihua();
	a.ps[0][0] = 0;			// S'->.E
	a.ps[0][1] = 0;
	a.n = 1;

	status = CORENUMBER;		//初始化第一个状态
	CORE[CORENUMBER] = a;
	b = CLOSURE(P, a);			//求CLOSURE（S'->.E）
	STATUS[CORENUMBER] = b;
	//对状态的判断
	mark=0;
	for (j = 0; j < STATUS[CORENUMBER].n; j++)
	{
		if (P->produceR[STATUS[CORENUMBER].ps[j][0]][STATUS[CORENUMBER].ps[j][1]] == -1|| P->produceR[STATUS[CORENUMBER].ps[j][0]][STATUS[CORENUMBER].ps[j][1]] == lo )			//如果是终结状态或者为空产生式 
		{
			STATUS[CORENUMBER].mark=ENDSTATUS;
			mark = 1;
			break;
		}
	}
	if(mark==0)
		STATUS[CORENUMBER].mark=NOTENDSTATUS;
	CORENUMBER++;

	rudui(Q, b, status);

	while (!kong(Q))
	{
		chudui(Q, b, status);
		if (b.n == 1)
		{
			if (P->produceR[b.ps[0][0]][b.ps[0][1]] == -1)		//如果是终结状态 重新循环
				continue;
		}
		for (i = 0; i < P->numberOFsym; i++)
		{
			if (i == lo)									//不对空产生式做go运算
				continue;
			c = GO(P, b, i, status, place);
			if (c.n > 0)										//如果返回的不空则入队
			{
				STATUS[CORENUMBER] = c;
				//对状态的判断
				mark=0;
				for (j = 0; j < STATUS[CORENUMBER].n; j++)
				{
					if (P->produceR[STATUS[CORENUMBER].ps[j][0]][STATUS[CORENUMBER].ps[j][1]] == -1|| P->produceR[STATUS[CORENUMBER].ps[j][0]][STATUS[CORENUMBER].ps[j][1]] == lo )			//如果是终结状态或者为空产生式 
					{
						STATUS[CORENUMBER].mark=ENDSTATUS;
						mark = 1;
						break;
					}
				}
				if(mark==0)
					STATUS[CORENUMBER].mark=NOTENDSTATUS;
				CORENUMBER++;

				rudui(Q, c, place);
			}

		}
	}
}

int *** CalculateAnalysisTable(struct produce *P)			//移进	[0]转移到的状态[1]转移到的状态的状态	规约   [0]使用的产生式 [1]标志
{
	int i, j, k, ***analysistable;
	int lofe = location(P->symbol, '#', P->numberOFsym);
	int **FOLLOW;
	int fuzhu[MAX], n, o;
	int fuzhu2[MAX], n2, o2;
	int lo = location(P->symbol, '0', P->numberOFsym);
	FOLLOW = CalculateF(P);
	analysistable = (int ***)malloc(sizeof(int **)*CORENUMBER);
	for (i = 0; i < CORENUMBER; i++)
	{
		analysistable[i] = (int **)malloc(sizeof(int*)*P->numberOFsym - 1);
		for (j = 0; j < P->numberOFsym; j++)		//忽略第一个 S'($)
		{
			analysistable[i][j] = (int *)malloc(sizeof(int) * 2);
			analysistable[i][j][0] = -1;
			analysistable[i][j][1] = -1;
		}
		if (STATUS[i].mark == ENDSTATUS)			//如果这个状态是终结状态，
		{
			for (j = 0; j < STNUMBER[i]; j++)
			{
				analysistable[i][STATUSTRANSFORM[i][j][0]][0] = STATUSTRANSFORM[i][j][1];
				analysistable[i][STATUSTRANSFORM[i][j][0]][1] = STATUSTRANSFORM[i][j][2];
			}
			n = 0; n2 = 0;
			for (j = 0; j < STATUS[i].n; j++)
			{
				if (P->produceR[STATUS[i].ps[j][0]][STATUS[i].ps[j][1]] == END || P->produceR[STATUS[i].ps[j][0]][STATUS[i].ps[j][1]] == lo)
				{
					k = 0;
					while (FOLLOW[P->produceL[STATUS[i].ps[j][0]]][k] != END)
					{
						for (o = 0; o < n; o++)
						{
							if (fuzhu[o] == FOLLOW[P->produceL[STATUS[i].ps[j][0]]][k])
							{
								return NULL;
							}
							fuzhu[n++] = FOLLOW[P->produceL[STATUS[i].ps[j][0]]][k];
						}
						analysistable[i][FOLLOW[P->produceL[STATUS[i].ps[j][0]]][k]][0] = STATUS[i].ps[j][0];
						analysistable[i][FOLLOW[P->produceL[STATUS[i].ps[j][0]]][k]][1] = GUIYUE;
						k++;
					}
				}
				else
					fuzhu2[n2++] = j;
			}
			for (j = 0; j < n2; j++)		//FOLLOW(A)∩b=空
			{
				o2 = P->produceR[STATUS[i].ps[j][0]][STATUS[i].ps[j][1] + 1];
				for (k = 0; k < n; k++)
				{
					if (o2 == fuzhu[k])
					{
						return NULL;
					}
				}

			}
		}
		else								//如果不是终结状态，将对应位置置为转移
		{
			for (j = 0; j < STNUMBER[i]; j++)
			{
				analysistable[i][STATUSTRANSFORM[i][j][0]][0] = STATUSTRANSFORM[i][j][1];
				analysistable[i][STATUSTRANSFORM[i][j][0]][1] = STATUSTRANSFORM[i][j][2];
			}
		}
	}
	for (i = 0; i < CORENUMBER; i++)				//找到结束状态
	{
		if (CORE[i].ps[0][0] == 0 && CORE[i].ps[0][1] == 1)
			break;
	}

	analysistable[i][lofe][0] = ACC;			//#置为接受
	
	for(i=0;i<P->segmentation+1;i++)
	{
		free(FOLLOW[i]);
	}
	free(FOLLOW);


	return analysistable;
}

void PrintLR0(struct produce *P)
{
	int i,j;
	for(i=0;i<P->numberOFpro;i++)
	{
		printf("%c->",P->symbol[P->produceL[i]]);
		j=0;
		while(P->produceR[i][j]!=END)
			printf("%c",P->symbol[P->produceR[i][j++]]);
		printf("\n");
	}
}

void PrintStatusTransformTable(struct produce *P)
{
	int i,j,k;
	for(i=0;i<CORENUMBER;i++)
	{
		printf("状态%d : \n",i);
		printf("{\n");
		for(j=0;j<CORE[i].n;j++)
		{
			printf("\t%c->",P->symbol[P->produceL[CORE[i].ps[j][0]]]);
			k=0;
			while(P->produceR[CORE[i].ps[j][0]][k]!=-1)
			{
				printf("%c",P->symbol[P->produceR[CORE[i].ps[j][0]][k]]);
				k++;
			}
			printf("点位置：%d\n",CORE[i].ps[j][1]);
		}
		printf("}\n");
		for(j=0;j<STNUMBER[i];j++)
		{
			if(STATUSTRANSFORM[i][j][2]==ENDSTATUS)
				printf("(%c)->状态%d (终止状态)\n",P->symbol[STATUSTRANSFORM[i][j][0]],STATUSTRANSFORM[i][j][1]);
			else
				printf("(%c)->状态%d (非终止状态)\n",P->symbol[STATUSTRANSFORM[i][j][0]],STATUSTRANSFORM[i][j][1]);
		}
	}
}

void PrintAnalysisTable(struct produce *P,int ***analysistable)
{
	int i,j;
	printf("%6s","状态");
	for(i=1;i<P->numberOFsym;i++)
	{
		printf("%4c",P->symbol[i]);
		printf("    ");
	}
	printf("\n");
	for(i=0;i<CORENUMBER;i++)
	{
		printf("%6d",i);
		for(j=1;j<P->numberOFsym;j++)
		{
			if(analysistable[i][j][0]==ACC)
				printf("%4s","acc");
			else
			{
				printf("  ");
				
				if(analysistable[i][j][1]==GUIYUE)
				{
					printf("%c%2d%3c",'R',analysistable[i][j][0],' ');
				}
				
				else
				{
					if(analysistable[i][j][0]>=0)
					{
						printf("%c%2d(%d)",'S',analysistable[i][j][0],analysistable[i][j][1]);
					}
					else
						printf("%6c",' ');
				}
			}
			
		}
		printf("\n");
	}
}

void Analysis(struct produce *P, int ***analysistable)
{
	int stackofstatus[MAXSTACK],stackofsymbol[MAXSTACK],top=-1,ftop;
	int i,j,k,lofe=location(P->symbol,'#',P->numberOFsym),length,place=0,lo;
	int buzhou=0;
	int loempty=location(P->symbol,'0',P->numberOFsym);
	char str[MAXSTRING];

	char *c=str;
	printf("请输入要分析的串(请不要超过%d个)\n",MAXSTRING);
	gets(str);
	fflush(stdin);
	length=strlen(str);
	if(str[length]!='#')			//串预处理 ，如果结尾没有# 加上#号
	{
		str[length]='#';
		str[length+1]='\0';
	}
	stackofstatus[++top]=0;
	stackofsymbol[top]=lofe;
	printf("%-6s%7s             %5s     %10s     %10s     \n","步骤","状态栈","符号栈","输入串","ACTION");
	while(1)
	{
		if(STATUS[stackofstatus[top]].mark==ENDSTATUS)		
		{
			lo=location(P->symbol,str[place],P->numberOFsym);
			k=analysistable[stackofstatus[top]][lo][0];
			if(k==ACC&&str[place]=='#')
			{
				printf("%-6d",buzhou);
				for(i=0;i<=top;i++)
					printf("%2d",stackofstatus[i]);
				for(;i<10;i++)
					printf("  ");
				for(i=0;i<=top;i++)
					printf("%c",P->symbol[stackofsymbol[i]]);
				for(;i<=10;i++)
					printf(" ");
				printf("    %5s",c);
				printf("%15s\n","acc");
				printf("接受\n");
				break;
			}
			printf("%-6d",buzhou);
			for(i=0;i<=top;i++)
				printf("%2d",stackofstatus[i]);
			for(;i<10;i++)
				printf("  ");
			for(i=0;i<=top;i++)
				printf("%c",P->symbol[stackofsymbol[i]]);
			for(;i<=10;i++)
				printf(" ");
			printf("    %5s",c);
			
			if(lo==WRONG)
			{
				printf("\n输入串第第%d个字符有误\n",place);
				break;
			}
			if(analysistable[stackofstatus[top]][lo][0]==-1)
			{
					printf("\n输入串第第%d个字符有误\n",place);
					break;
				}
			if(analysistable[stackofstatus[top]][lo][1]==GUIYUE)
			{
				
				printf("%11c%2c%2d",' ','R',analysistable[stackofstatus[top]][lo][0]);
				
					
				printf("  %c->",P->symbol[P->produceL[k]]);

				if(P->produceR[analysistable[stackofstatus[top]][lo][0]][0]!=loempty)		//如果是空产生式，不做处理
				{
					j=0;
					while(P->produceR[k][j]!=-1)
					{
						printf("%c",P->symbol[P->produceR[k][j]]);
						j++;
					}
					printf("\n");
					for(i=0;i<j;i++)		//出栈
						top--;
				}
				else
					printf("空\n");

				if(analysistable[stackofstatus[top]][P->produceL[k]][0]==-1)
				{
					printf("\n输入串第第%d个字符有误\n",place);
					break;
				}

				ftop=top;
				stackofstatus[++top]=analysistable[stackofstatus[top]][P->produceL[k]][0];
				stackofsymbol[top]=P->produceL[k];
			}
			else
			{
				ftop=top;
				
				printf("%11c%2c%2d\n",' ','S',analysistable[stackofstatus[top]][lo][0]);

				stackofstatus[++top]=analysistable[stackofstatus[ftop]][lo][0];
				stackofsymbol[top]=lo;
				place++;
				c++;
			}


		}
		else
		{
			ftop=top;
			lo=location(P->symbol,str[place],P->numberOFsym);
			if(lo==WRONG)
			{
				printf("\n输入串第第%d个字符有误\n",place);
				break;
			}
			if(analysistable[stackofstatus[ftop]][lo][0]==-1)
			{
				printf("\n输入串第第%d个字符有误\n",place);
				break;
			}
			printf("%-6d",buzhou);
			for(i=0;i<=top;i++)
				printf("%2d",stackofstatus[i]);
			for(;i<10;i++)
				printf("  ");
			for(i=0;i<=top;i++)
				printf("%c",P->symbol[stackofsymbol[i]]);
			for(;i<=10;i++)
				printf(" ");
			printf("    %5s",c);
			printf("%11c%2c%2d\n",' ','S',analysistable[stackofstatus[top]][lo][0]);

			stackofstatus[++top]=analysistable[stackofstatus[ftop]][lo][0];
			stackofsymbol[top]=lo;
			place++;
			c++;
		}
		buzhou++;
	}
}
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

void menu(void)
{
	printf("\t\t\t\tSLR(1)分析\n\n");
	printf("1) 录入SLR(1)文法\n\n2) 输出录入的SLR(1)文法\n\n3) 输出状态转换表\n\n4) 输出分析表\n\n5) 分析句子\n\n0) 退出\n\n请选择：");
}
int main()
{
	int i,j,flag,temp;
	int ***analysistable=NULL;
	struct produce *P=NULL;
	char c[MAXLENGTH]={"123450"};
	char xz;
	while(1)
	{
		flag=0;
		menu();
		xz=zqsr(c);
		switch(xz)
		{
			case '1':system("cls");

					if(P!=NULL)
					{
						temp=P->numberOFsym;
						free(P->produceL);
					
						for(i=0;i<P->numberOFpro;i++)
						{
							free(P->produceR[i]);
						}
						free(P->symbol);
						free(P->produceR);
						free(P);
						P=NULL;
					}
					if(analysistable!=NULL)
					{
						for(i=0;i<CORENUMBER;i++)
						{
							for(j=1;j<temp;j++)
							{
								free(analysistable[i][j]);
							}
						}
						free(analysistable);
						analysistable=NULL;
					}
					P=ExpandInitialize();
					MakeStatusTransform(P);
					analysistable=CalculateAnalysisTable(P);
					system("pause");system("cls");break;
			case '2':system("cls");
					if(P==NULL)
					{
						printf("文法未输入，无法输出预测分析表\n");
						break;
					}
					PrintLR0(P);
					system("pause");system("cls");break;

			case '3':system("cls");
					if(P==NULL)
					{
						printf("文法未输入，无法输出预测分析表\n");
						break;
					}
					PrintStatusTransformTable(P);
					system("pause");system("cls");break;
					
			case '4':system("cls");
					if(analysistable==NULL)
					{
						printf("文法未输入，无法输出预测分析表\n");
						break;
					}
					PrintAnalysisTable(P,analysistable);
					system("pause");system("cls");break;

			case '5':system("cls");
					if(P==NULL)
					{
						printf("文法未输入，无法输出预测分析表\n");
						break;
					}
					Analysis(P,analysistable);
					system("pause");system("cls");break;
			
			case '0':flag++;break;
		}
		if(flag>0)
			break;
	}
	if(P!=NULL)
	{
		temp=P->numberOFsym;
		free(P->produceL);
		free(P->symbol);
		for(i=0;i<P->numberOFpro;i++)
		{
			free(P->produceR[i]);
		}
		free(P->produceR);
		free(P);
	}
	if(analysistable!=NULL)
	{
		for(i=0;i<CORENUMBER;i++)
		{
			for(j=1;j<temp;j++)
			{
				free(analysistable[i][j]);
			}
		}
		free(analysistable);
	}
	return 0;
}
