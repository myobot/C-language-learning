/*----------------------------
------作者------王占伟
------时间------20160521
------名称------基于LR(1)的中间代码生成，简单赋值语句
说明：
	使用的文法在
		优先性文法( 加乘运算 ).txt
	中
------------------------------*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSYMBOLLENGTH 15	//符号最大长度
#define MAXLENGTH 50		//产生式最大长度
#define WRONG -1			//错误符号位置
#define END -1				//产生式结束符
#define STRINGEND '\0'		//字符串结尾
#define STRINGCUT ' '		//单词分隔符
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
#define MAXNUMBER 100	//生成中间代码时所需最多符号数
#define ERROR -1			//错误

struct produce
{
	int **produceR;		//产生式右部
	int *produceL;		//产生式左部
	char **symbol;		//所有符号
	int segmentation;	//非终结数-1
	int numberOFpro;
	int numberOFsym;
};

struct EF
{
	int *Empty;
	int **First;
};

struct projectset
{
	int ps[MAXPROJECTSET][2];	//项目集	[0]产生式位置，[1]点位置
	int n;						//个数
	int mark;
	int FS[MAXPROJECTSET][MAXLENGTH];				//向前搜索符集
	int FSnum[MAXPROJECTSET];
	bool operator ==(const projectset &p1)
	{
		int i,j;
		if(n!=p1.n)
			return 0;
		for(i=0;i<n;i++)
		{
			if(ps[i][0]!=p1.ps[i][0]||ps[i][1]!=p1.ps[i][1])
				return 0;
			if(FSnum[i]!=p1.FSnum[i])
				return 0;
			for(j=0;j<FSnum[i];j++)
			{
				if(FS[i][j]!=p1.FS[i][j])
					return 0;
			}
		}
	

		return 1;
	}
};





struct projectset CORE[MAXSTATUS];					//核
int CORENUMBER=0;									//数量
struct projectset STATUS[MAXSTATUS];
int STATUSTRANSFORM[MAXSTATUS][MAXSTATUS][3];		//[0]符号  [1]移向的状态   [2]移向状态的状态
int STNUMBER[MAXSTATUS];

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
	int n, e;
};

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

int location(char **symbol,char *c,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(c,symbol[i])==0)
			return i;
	}
	return WRONG;
}
int getword(char *str,char word[MAXSYMBOLLENGTH],int place,int n)
{
	int i,j;

	for(i=place,j=0;i<=n;i++,j++)
	{
		word[j]=str[i];
		if(str[i]==STRINGCUT)
		{
			word[j]=STRINGEND;
			break;
		}
	}
	if(i==n+1)
	{
		word[j]=STRINGEND;
		return i-1;
	}
	return ++i;
}
void mygets(char c[])
{
	int i;
	fgets(c, MAXLENGTH, stdin);
	i = strlen(c);
	c[i-1] = '\0';
}
struct produce * ExpandInitialize(void)
{
	struct produce *P;
	int i, j, mark;
	int place,length;
	char word[MAXSYMBOLLENGTH];
	char c[MAXLENGTH];
	P = (struct produce *)malloc(sizeof(struct produce));
	printf("请输入非终结符总数和符号总数(逗号隔开,空算一个终结符): ");
	while(scanf("%d,%d",&P->segmentation,&P->numberOFsym)!=2||P->segmentation<=0||P->numberOFsym<=0)
	{
		fflush(stdin);printf("请输入正确总数，请重新输入\n");
	}
	fflush(stdin);
	P->numberOFsym++;
	P->numberOFsym++;
	P->symbol = (char **)malloc(sizeof(char*)*P->numberOFsym);

	system("cls");
	printf("请输入非终结符号，每行一个(请第一个输入 起始符)\n");
	for (i = 1; i <= P->segmentation; i++)
	{

		P->symbol[i]=(char *)malloc(sizeof(char)*MAXSYMBOLLENGTH);
		gets(P->symbol[i]);
		fflush(stdin);
	}
	system("cls");
	printf("请输入终结符号:\n");
	for (i = P->segmentation + 1; i<P->numberOFsym - 1; i++)
	{
		P->symbol[i]=(char *)malloc(sizeof(char)*MAXSYMBOLLENGTH);
		gets(P->symbol[i]);
		fflush(stdin);

	}
	system("cls");

	P->symbol[i]=(char *)malloc(sizeof(char)*MAXSYMBOLLENGTH);
	P->symbol[i][0] = '#';		//最后加上 #
	P->symbol[i][1]=STRINGEND;
	P->symbol[0]=(char *)malloc(sizeof(char)*MAXSYMBOLLENGTH);
	P->symbol[0][0] = '$';
	P->symbol[0][1]=STRINGEND;

	system("cls");
	printf("请输入产生式总数: ");
	while(scanf("%d",&P->numberOFpro)!=1||P->numberOFpro<=0)
	{
		fflush(stdin);printf("请输入正确总数，请重新输入\n");
	}
	system("cls");
	fflush(stdin);

	P->numberOFpro++;
	P->produceR = (int **)malloc(sizeof(int *)*P->numberOFpro);
	P->produceL = (int *)malloc(sizeof(int)*P->numberOFpro);

	P->produceR[0] = (int *)malloc(sizeof(int)*MAXLENGTH);	//扩充S'->E
	P->produceL[0] = 0;
	P->produceR[0][0] = 1;
	P->produceR[0][1] = END;

	for (i = 1; i<P->numberOFpro; i++)
	{
		printf("请输入产生式:(左右部用->隔开)(空用 0 表示)(每个符号之间用空格隔开)\n");
		P->produceR[i] = (int *)malloc(sizeof(int)*MAXLENGTH);
		while (1)
		{
			place=0;
			gets(c);
			length=strlen(c);
			place=getword(c,word,place,length);

			if(location(P->symbol,word,P->numberOFsym)>P->segmentation)	//第一个不是非终结符
			{
				printf("输入有误。(产生式左部有且只有一个非终结符),请重新输入\n");
				continue;
			}
			P->produceL[i]=location(P->symbol,word,P->numberOFsym);

			place=getword(c,word,place,length);
			if(word[0]!='-'||word[1]!='>')		//没有->
			{
				printf("输入有误，请重新输入:\n");
				continue;
			}
			
			mark=0;j=0;
			while(place!=length)				//含有符号表以外的符号
			{
				place=getword(c,word,place,length);

				P->produceR[i][j]=location(P->symbol,word,P->numberOFsym);
				if(P->produceR[i][j]==WRONG)
				{
					printf("此产生式含有非法符号，请重新输入:\n");
					mark=1;
					break;
				}
				j++;
			}
			if(mark==1)
				continue;
			P->produceR[i][j]=END;			//结尾置 -1
			break;
		}
		system("cls");
	}
	return P;
}

int * FindEmpty(struct produce *P)
{
	int *E, *Efuzhu, i, j, *F, lofe, mark, mark2;		//lofe空的位置
	char empty[2]={"0"};
	E = (int *)malloc(sizeof(int)*(P->segmentation + 1));
	Efuzhu = (int *)malloc(sizeof(int)*(P->segmentation + 1));
	F = (int *)malloc(sizeof(int)*(P->numberOFpro));
	lofe = location(P->symbol, empty, P->numberOFsym);
	for (i = 0; i<P->segmentation + 1; i++)
	{
		E[i] = UNDEFINE;						//非终结符mark
		Efuzhu[i] = 0;
	}
	for (i = 0; i<P->numberOFpro; i++)
	{
		F[i] = 1;							//产生式mark
		Efuzhu[P->produceL[i]]++;
	}
	for (i = 0; i<P->numberOFpro; i++)
	{
		if (F[i] != 0)
		{
			j = 0;
			while (P->produceR[i][j] != END)	//如果右部含有终结符且不是空，则删除该产生式
			{
				if (P->produceR[i][j] != lofe&&P->produceR[i][j]>P->segmentation)
				{
					F[i] = 0;
					Efuzhu[P->produceL[i]]--;
					break;
				}
				j++;
			}
			if (P->produceR[i][0] == lofe)		//右部为空，置左部非终结符能推出空，并删除所有左部为该终结符的产生式
			{
				F[i] = 0;
				Efuzhu[P->produceL[i]]--;
				E[P->produceL[i]] = CANEMPTY;
				for (j = 0; j<P->numberOFpro; j++)
				{
					if (F[j] != 0)
					{
						if (P->produceL[j] == P->produceL[i])
						{
							F[j] = 0;
							Efuzhu[P->produceL[j]]--;
						}
					}
				}
			}
		}
	}
	for (i = 0; i<P->segmentation + 1; i++)
	{
		if (Efuzhu[i] == 0)
			if (E[i] == UNDEFINE)
				E[i] = CANNOTEMPTY;
	}
	while (1)
	{
		mark2 = 0;
		for (i = 0; i<P->numberOFpro; i++)
		{
			if (F[i] == 1)
			{
				j = 0; mark = 0;
				while (P->produceR[i][j] != END)
				{
					if (E[P->produceR[i][j]] == CANNOTEMPTY)
					{
						F[i] = 0;
						Efuzhu[P->produceL[i]]--;
						mark = 1;
						break;
					}
					if (E[P->produceR[i][j]] == UNDEFINE)		//如果含有未定
					{
						mark = 1;
					}
					j++;
				}
				if (mark == 0)		//能推出空
				{
					E[P->produceL[i]] = CANEMPTY;		//置1
					for (j = 0; j<P->numberOFpro; j++)	//删除所有左部为此非终结符的产生式
					{
						if (F[j] != 0)
						{
							if (P->produceL[j] == P->produceL[i])
							{
								F[j] = 0;
								Efuzhu[P->produceL[j]]--;
							}
						}
					}
					mark2 = 1;
				}
				for (j = 0; j<P->segmentation + 1; j++)	//如果左部删光了某一个非终结符且未定，则置0
				{
					if (Efuzhu[j] == 0)
						if (E[j] == UNDEFINE)
						{
							E[j] = CANNOTEMPTY;
							mark2 = 1;
						}
				}
			}
		}
		if (mark2 == 0)		//如果数组没有在改变结束
			break;
	}
	free(F);
	free(Efuzhu);
	return E;
}

struct picture *BuildPictureOfFirst(struct picture *g, struct produce *P, int *Empty)	//first	
{
	char empty[2]={"0"};
	int i, j, k, lofe = location(P->symbol, empty, P->numberOFsym);

	struct node *s;
	for (i = 0; i<P->segmentation + 1; i++)			//对每个非终结符
	{
		for (j = 0; j<P->numberOFpro; j++)			//对每个产生式
		{
			if (P->produceL[j] == i)				//左部是该非终结符	
			{
				k = 0;
				if (P->produceR[j][k] <= P->segmentation)	//如果左部第一个 是非终结符
				{
					if (Empty[P->produceR[j][k]] == CANEMPTY)		//如果左部第一个非终结符且能推出空
					{

						s = (struct node *)malloc(sizeof(struct node));
						s->ldd = P->produceR[j][k];
						s->next = g->adlist[i].firstnode;		//建立图 该终结符first集包含第一个非终结符first集
						g->adlist[i].firstnode = s;
						k++;
						while (P->produceR[j][k] != END)		//查看接下来的
						{
							if (P->produceR[j][k] <= P->segmentation&&Empty[P->produceR[j][k]] == CANEMPTY)	//如果仍为非终结符且能推出空 
							{
								s = (struct node *)malloc(sizeof(struct node));
								s->ldd = P->produceR[j][k];
								s->next = g->adlist[i].firstnode;
								g->adlist[i].firstnode = s;
								k++;						//只有能推出空才向后扫描
							}
							else if (P->produceR[j][k] <= P->segmentation&&Empty[P->produceR[j][k]] == CANNOTEMPTY)	//如果仍未非终结符且不能推出空（跳出）
							{
								s = (struct node *)malloc(sizeof(struct node));
								s->ldd = P->produceR[j][k];
								s->next = g->adlist[i].firstnode;
								g->adlist[i].firstnode = s;
								break;
							}
							else								//如果为终结符（跳出）
							{
								s = (struct node *)malloc(sizeof(struct node));
								s->ldd = P->produceR[j][k] + (P->segmentation + 1);					//指向图中对应终结符位置
								s->next = g->adlist[i].firstnode;
								g->adlist[i].firstnode = s;
								break;
							}
						}
					}
					else								//如果第一个是非终结符且不能推出空
					{

						s = (struct node *)malloc(sizeof(struct node));
						s->ldd = P->produceR[j][k];
						s->next = g->adlist[i].firstnode;
						g->adlist[i].firstnode = s;

					}
				}
				else									//如果第一个是终结符（忽略空产生式）
				{
					if (P->produceR[j][k] != lofe)
					{
						s = (struct node *)malloc(sizeof(struct node));
						s->ldd = P->produceR[j][k] + (P->segmentation + 1);							//指向图中对应终结符位置
						s->next = g->adlist[i].firstnode;
						g->adlist[i].firstnode = s;
					}
				}
			}
		}
	}
	return g;
}

/*
struct picture *BuildPictureOfFollow(struct picture *g, struct produce *P, int *Empty)	//follow
{
	int i, j, k, lofe = location(P->symbol, EMPTY, P->numberOFsym);
	int FZ = P->segmentation + 1;
	struct node *s;

	s = (struct node *)malloc(sizeof(struct node));
	s->ldd = g->n - 1;
	s->next = g->adlist[P->segmentation + 1].firstnode;				//S 的follow集包含 #
	g->adlist[P->segmentation + 1].firstnode = s;

	for (i = P->segmentation + 1; i<(P->segmentation + 1) * 2; i++)			//对每个非终结符（follow集位置）
	{
		for (j = 0; j<P->numberOFpro; j++)								//对每个产生式
		{
			k = 0;
			while (P->produceR[j][k] != (i - FZ) && P->produceR[j][k] != END)		//找到该产生式右部的该非终结符
			{
				k++;
			}
			if (P->produceR[j][k] != END)								//如果包含该非终结符
			{
				k++;
				if (P->produceR[j][k] == END)								//如果直接就是末尾
				{
					s = (struct node *)malloc(sizeof(struct node));
					s->ldd = P->produceL[j] + (P->segmentation + 1);			//将左部非终结符的follow集添加到该非终结符的follow集
					s->next = g->adlist[i].firstnode;
					g->adlist[i].firstnode = s;
				}
				else													//不是末尾
				{
					if (P->produceR[j][k] <= P->segmentation)				//下一个如果是非终结符
					{
						if (Empty[P->produceR[j][k]] == CANEMPTY)					//如果下一非终结符能推出空
						{
							s = (struct node *)malloc(sizeof(struct node));
							s->ldd = P->produceR[j][k];
							s->next = g->adlist[i].firstnode;				//建立图 该终结符follow集包含此终结符first集
							g->adlist[i].firstnode = s;
							k++;
							while (P->produceR[j][k] != END)				//扫描接下来的符号
							{
								if (P->produceR[j][k] <= P->segmentation&&Empty[P->produceR[j][k]] == CANEMPTY)	//如果仍为非终结符且能推出空 
								{
									s = (struct node *)malloc(sizeof(struct node));
									s->ldd = P->produceR[j][k];
									s->next = g->adlist[i].firstnode;
									g->adlist[i].firstnode = s;
									k++;
								}
								else if (P->produceR[j][k] <= P->segmentation&&Empty[P->produceR[j][k]] == CANNOTEMPTY)	//如果仍未非终结符且不能推出空（跳出）
								{
									s = (struct node *)malloc(sizeof(struct node));
									s->ldd = P->produceR[j][k];
									s->next = g->adlist[i].firstnode;
									g->adlist[i].firstnode = s;
									break;
								}
								else									//如果为终结符（跳出）
								{
									s = (struct node *)malloc(sizeof(struct node));
									s->ldd = P->produceR[j][k] + (P->segmentation + 1);					//指向图中对应终结符位置
									s->next = g->adlist[i].firstnode;
									g->adlist[i].firstnode = s;
									break;
								}
							}
							if (P->produceR[j][k] == END)								//如果直到结束
							{
								s = (struct node *)malloc(sizeof(struct node));
								s->ldd = P->produceL[j] + (P->segmentation + 1);			//将左部非终结符的follow集添加到该非终结符的follow集
								s->next = g->adlist[i].firstnode;
								g->adlist[i].firstnode = s;
							}
						}
						else											//如果下一非终结符不能推出空
						{
							s = (struct node *)malloc(sizeof(struct node));
							s->ldd = P->produceR[j][k];
							s->next = g->adlist[i].firstnode;				//建立图 该终结符follow集包含此非终结符first集
							g->adlist[i].firstnode = s;
						}
					}
					else											//如果下一个是终结符
					{
						s = (struct node *)malloc(sizeof(struct node));
						s->ldd = P->produceR[j][k] + (P->segmentation + 1);
						s->next = g->adlist[i].firstnode;					//建立图 该终结符follow集包含此终结符
						g->adlist[i].firstnode = s;
					}
				}
			}
		}
	}
	return g;
}
*/

int visited[MAXNUM];

void DFSAL(struct picture *g, int i)
{
	struct node *p;
	visited[i] = 1;
	p = g->adlist[i].firstnode;
	while (p)
	{
		if (!visited[p->ldd])
			DFSAL(g, p->ldd);
		p = p->next;
	}
}

int **CalculateFirst(struct picture *g, struct produce * P)
{
	int i, j, k, **First;
	First = (int **)malloc(sizeof(int)*(P->segmentation + 1));
	for (i = 0; i<P->segmentation + 1; i++)
	{
		First[i] = (int *)malloc(sizeof(int)*P->numberOFsym);
		for (j = 0; j<P->numberOFsym; j++)
			First[i][j] = END;
	}

	for (i = 0; i<P->segmentation + 1; i++)
	{
		for (j = 0; j<g->n; j++)
			visited[j] = UNVISITED;
		DFSAL(g, i);
		for (j = (P->segmentation + 1) * 2, k = 0; j<g->n; j++)
		{
			if (visited[j] == VISITED)
			{
				First[i][k++] = g->adlist[j].symbol;
			}
		}
	}
	return First;
}

struct picture * FreePicture(struct picture *g) //释放图
{
	int i;
	struct node *p, *q;
	for (i = 0; i<g->n; i++)
	{
		p = g->adlist[i].firstnode;
		while (p)
		{
			q = p;
			p = p->next;
			free(q);
		}
	}
	free(g->adlist);
	free(g);
	return NULL;
}


struct EF CalculateF(struct produce *P)	//汇总
{
	struct picture *g;
	struct EF a;
	int i;
	char empty[2]={"0"};
	int lofe = location(P->symbol, empty, P->numberOFsym);
	g = (struct picture *)malloc(sizeof(struct picture));	//图初始化
	g->n = (P->segmentation + 1) + P->numberOFsym;
	g->adlist = (struct vnode *)malloc(sizeof(struct vnode)*g->n);
	for (i = 0; i<P->segmentation + 1; i++)	//First集
	{
		g->adlist[i].symbol = i;
		g->adlist[i].mark = 1;
		g->adlist[i].firstnode = NULL;
	}
	for (; i<P->segmentation + 1; i++)		//Follow集
	{
		g->adlist[i].symbol = i - (P->segmentation + 1);
		g->adlist[i].mark = 2;
		g->adlist[i].firstnode = NULL;
	}
	for (; i<g->n; i++)					//终结符集
	{
		g->adlist[i].symbol = i - (P->segmentation + 1);
		g->adlist[i].mark = 0;
		g->adlist[i].firstnode = NULL;
	}

	a.Empty = FindEmpty(P);
	g = BuildPictureOfFirst(g, P, a.Empty);

	a.First = CalculateFirst(g, P);

	g = FreePicture(g);

	return a;
}
void bijiao(int data[],int n)//排序，保证向前搜索符集有序，便于后续比较处理
{
	int i,j,k,swap;
	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(data[k]>data[j])
				k=j;
		}
		if(i!=k)
		{
			swap=data[i];
			data[i]=data[k];
			data[k]=swap;
		}
	}
}

void insert(int x[],int &n,int a)	//插入数据，如果存在则不插入 ，最后排序
{
	int i;
	for(i=0;i<n;i++)
	{
		if(x[i]==a)
			return;
	}
	x[n++]=a;
	bijiao(x,n);
}




void getfirst(int *a, int n, int **First, int *Empty,struct produce * P,int FS[MAXPROJECTSET][MAXLENGTH],int p,int n1,int &n2,int x[])	//的到first集
{
	int i=0,j,start;
	n2=0;
	for (i = 0; i < n; i++)
	{
		if (a[i] > P->segmentation)
		{
			insert(x,n2,a[i]);
			break;
		}
		else if(a[i]<=P->segmentation&&Empty[a[i]]== CANEMPTY)
		{
			j = 0;
			while (First[a[i]][j] != END)
			{
				insert(x,n2,First[a[i]][j]);
				j++;
			}
			break;
		}
		else
		{
			j = 0;
			while (First[a[i]][j] != END)
			{
				insert(x,n2,First[a[i]][j]);
				j++;
			}
		}
	}
	if (i == n)	//如果都能推出空 或者 形如S->·B,a ，则将前一个向前搜索符集加入到其中
	{
		for(start = 0;start<n1;start++)
		{
			insert(x,n2,FS[p][start]);
		}
		
	}
}

struct projectset CLOSURE(struct produce *P,struct projectset p, int **First, int *Empty)
{
	int i,j,k,e,n1=0,n2=p.n,mark,mark2;	//n1 记录前一次循环集合中的个数	n2记录循环后的个数
	int num=0;
	int firstseach[MAXLENGTH];
	int fsn;
	struct projectset N;
	int fuzhu[MAXLENGTH];
	int fnum;

	N=p;
	while(1)
	{
		mark=0;
		for(i=n1;i<n2;i++)							//从新加的地方开始
		{
			if(P->produceR[N.ps[i][0]][N.ps[i][1]]<=P->segmentation)
			{
				fnum = 0;
				j=N.ps[i][1];
				if(P->produceR[N.ps[i][0]][j] != END)		//如果是形如 S->·B,a   点后的符号下一个是结尾，则fuzhu数组不处理 fnum=0
				{
					j=N.ps[i][1]+1;
					while (P->produceR[N.ps[i][0]][j] != END)
					{
						fuzhu[fnum++] = P->produceR[N.ps[i][0]][j];
						j++;
					}
				}

				getfirst(fuzhu, fnum, First, Empty, P,N.FS,i,N.FSnum[i],fsn,firstseach);		//得到first符集
						//(int *a, int n, int **First, int *Empty,struct produce * P,int FS[MAXPROJECTSET][MAXLENGTH],int p,int n1,int &n2,int x[])
				for(j=1;j<P->numberOFpro;j++)		//从第一个产生式开始
				{
					mark2=0;
					if(P->produceL[j]==P->produceR[N.ps[i][0]][N.ps[i][1]])
					{
						for(k=0;k<N.n;k++)			//对于已添加的处理
						{
							if(N.ps[k][0]==j&&N.ps[k][1]==0)
							{
								for(e=0;e<fsn;e++)
									insert(N.FS[k],N.FSnum[k],firstseach[e]);//插入到对应向前搜索符集
								mark2=1;
								break;
							}
						}
						if(mark2==1)
							continue;										//如果重复，不再添加
						N.ps[N.n][0]=j;				//加入项目集
						N.ps[N.n][1]=0;
						N.FSnum[N.n]=0;
						for(e=0;e<fsn;e++)
							insert(N.FS[N.n],N.FSnum[N.n],firstseach[e]);
						N.n++;
						mark=1;
					}
				}
			}
		}
		n1=n2;
		n2=N.n;
		if(mark==0)								//如果没有再改变 跳出循环
			break;
	}
	return N;
}


struct projectset GO(struct produce *P, struct projectset I, int x, int status, int &place, int **First, int *Empty)	//I 前一个项目集  x 符号位置  status 前一个项目集的状态位置  place 下一个项目集的状态位置
{
	int i, j, mark = 0, mark2 = 0;
	int position = 0;
	int fuzhu[MAXLENGTH], num = 0;
	char empty[2]={"0"};
	int lo = location(P->symbol, empty, P->numberOFsym);
	struct projectset J;
	J.n = 0;
	for (i = 0; i<I.n; i++)
	{
		if (P->produceR[I.ps[i][0]][I.ps[i][1]] == x)		//找到点后是x 的 位置
		{
			fuzhu[num++] = i;
		}
	}
	if (num == 0)											//没有返回空
		return J;
	else
	{
		for (i = 0; i<num; i++)								//将找到的加入项目集
		{
			J.ps[i][0] = I.ps[fuzhu[i]][0];
			J.ps[i][1] = I.ps[fuzhu[i]][1] + 1;
			for(j=0;j<I.FSnum[fuzhu[i]];j++)
				J.FS[i][j]=I.FS[fuzhu[i]][j];
			J.FSnum[i]=I.FSnum[fuzhu[i]];
			J.n++;
		}

		for (j = 0; j<CORENUMBER; j++)	//核检查
		{
			if (CORE[j] == J)			//如果核已有
			{
				position = j;
				mark = 1;
				break;
			}
		}
		if (position == 0)				//如果没有核，新建核
		{
			position = CORENUMBER;
			CORE[CORENUMBER] = J;
		}
		place = position;			//记录此核的状态位置

		STATUSTRANSFORM[status][STNUMBER[status]][0] = x;			//填入 符号 到状态转换表对应位置
		STATUSTRANSFORM[status][STNUMBER[status]][1] = position;	//移向状态

		for (i = 0; i < J.n; i++)
		{
			if (P->produceR[J.ps[i][0]][J.ps[i][1]] == -1 || P->produceR[J.ps[i][0]][J.ps[i][1]] == lo)			//如果是终结状态或者为空产生式 
			{
				STATUSTRANSFORM[status][STNUMBER[status]++][2] = ENDSTATUS;	//标志设为终结
				
				mark2 = 1;
				break;
			}
		}
		if (mark2 == 0)
		{
			STATUSTRANSFORM[status][STNUMBER[status]++][2] = NOTENDSTATUS;
			
		}
		if (mark == 0)				//如果是新的核 则求闭包
		{
			J = CLOSURE(P, J,First,Empty);
			return J;
		}
		else					//否则返回空	//不再入队		
		{
			J.n = 0;
			return J;
		}
		
	}
}


void MakeStatusTransform(struct produce *P)
{
	struct projectset a, b, c;
	int i,j,mark, status, place;
	char empty[2]={"0"};
	char end[2]={"#"};
	int lo = location(P->symbol, empty, P->numberOFsym);
	int lofe=location(P->symbol, end, P->numberOFsym);
	struct queue *Q;
	struct EF ef;
	ef = CalculateF(P);
	Q = chushihua();
	a.ps[0][0] = 0;			// S'->.E
	a.ps[0][1] = 0;
	a.n = 1;
	a.FS[0][0]=lofe;
	a.FSnum[0]=1;

	status = CORENUMBER;		//初始化第一个状态
	CORE[CORENUMBER] = a;
	CORE[CORENUMBER].mark = NOTENDSTATUS;
	b = CLOSURE(P, a,ef.First,ef.Empty);			//求CLOSURE（S'->.E）
	STATUS[CORENUMBER] = b;
		//对状态的判断  能否归约
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
			if (i == lo)										//不对空产生式做go运算
				continue;
			c = GO(P, b, i, status, place,ef.First,ef.Empty);
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
	for (i = 0; i < P->segmentation + 1; i++)
	{
		free(ef.First[i]);
	}
	free(ef.Empty);
	free(ef.First);
}

int *** CalculateAnalysisTable(struct produce *P)			//移进	[0]转移到的状态[1]转移到的状态的状态	规约   [0]使用的产生式 [1]标志
{
	int i, j, k,p, ***analysistable;
	char empty[2]={"0"};
	char end[2]={"#"};
	int lofe = location(P->symbol, end, P->numberOFsym);
	int fuzhu[MAX], n, o;
	int fuzhu2[MAX], n2, o2;
	int lo = location(P->symbol, empty, P->numberOFsym);
	
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
				if (P->produceR[STATUS[i].ps[j][0]][STATUS[i].ps[j][1]] == END || P->produceR[STATUS[i].ps[j][0]][STATUS[i].ps[j][1]] == lo)//如果是可归约产生式，或空产生式，对其向前搜索符位置置为归约
				{
					k = 0;
					for(p=0;p<STATUS[i].FSnum[j];p++)
					{
						for (o = 0; o < n; o++)
						{
							if (fuzhu[o] == STATUS[i].FS[j][p])
							{
								return NULL;
							}
							fuzhu[n++] = STATUS[i].FS[j][p];
						}
						analysistable[i][STATUS[i].FS[j][p]][0] = STATUS[i].ps[j][0];
						analysistable[i][STATUS[i].FS[j][p]][1] = GUIYUE;
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


	return analysistable;
}

void PrintLR0(struct produce *P)
{
	int i,j;
	for(i=0;i<P->numberOFpro;i++)
	{
		printf("%s -> ",P->symbol[P->produceL[i]]);
		j=0;
		while(P->produceR[i][j]!=END)
			printf("%s ",P->symbol[P->produceR[i][j++]]);
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
			printf("\t%s -> ",P->symbol[P->produceL[CORE[i].ps[j][0]]]);
			k=0;
			while(P->produceR[CORE[i].ps[j][0]][k]!=-1)
			{
				printf("%s ",P->symbol[P->produceR[CORE[i].ps[j][0]][k]]);
				k++;
			}
			printf("点位置：%d\n",CORE[i].ps[j][1]);
		}
		printf("}\n");
		for(j=0;j<STNUMBER[i];j++)
		{
			if(STATUSTRANSFORM[i][j][2]==ENDSTATUS)
				printf("(%s)->状态%d (终止状态)\n",P->symbol[STATUSTRANSFORM[i][j][0]],STATUSTRANSFORM[i][j][1]);
			else
				printf("(%s)->状态%d (非终止状态)\n",P->symbol[STATUSTRANSFORM[i][j][0]],STATUSTRANSFORM[i][j][1]);
		}
	}
}

void PrintAnalysisTable(struct produce *P,int ***analysistable)
{
	int i,j;
	printf("%6s","状态");
	for(i=1;i<P->numberOFsym;i++)
	{
		printf("%4s",P->symbol[i]);
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
int lookup(char word[],char idtable[][MAXSYMBOLLENGTH],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(word,idtable[i])==0)
			return i;
	}
	return ERROR;
}

void emit(FILE *fp,int n1,int n2,int n3,int mark,char idtable[][MAXSYMBOLLENGTH],int n)
{
	switch (mark)
	{
		case 1:fprintf(fp,"%s = %s\n",idtable[n1],idtable[n2]);
			break;
		case 2:fprintf(fp,"%s = %s + %s\n",idtable[n1],idtable[n2],idtable[n3]);
			break;
		case 3:fprintf(fp,"%s = %s * %s\n",idtable[n1],idtable[n2],idtable[n3]);
			break;
		case 4:fprintf(fp,"%s = uminus %s\n",idtable[n1],idtable[n2]);
			break;
	}
}

int StringPretreatment(char str[],char idtable[][MAXSYMBOLLENGTH],int &n)		//字符串预处理，生成idtable
{
	int length,i=0,place=0,j,mark;
	char word[MAXSYMBOLLENGTH];
//	char Plus[2]={"+"},Multiply[2]={"*"},Minus[2]={"-"},Leftbrackets[2]={"("},Rightbrackets[2]={"("},Equal[2]={"="};
	char symbol[6][2]={{"+"},{"*"},{"-"},{"("},{")"},{"="}};
	length=strlen(str);
	while(place!=length)
	{
		mark=0;
		place=getword(str,word,place,length);
		for(j=0;j<6;j++)
		{
			if(strcmp(symbol[j],word)==0)
			{
				mark=1;
				break;
			}
		}
		if(mark==0)
			strcpy(idtable[i++],word);
	}
	n=i;
	if(str[length]!='#')			//串预处理 ，如果结尾没有# 加上#号
	{
		str[length++]=' ';
		str[length]='#';
		str[length+1]='\0';
	}
	return length;
}

int AdditionTemp(char idtable[][MAXSYMBOLLENGTH],int &n,int number)
{
	char string[MAXNUMBER];
	itoa(number,string,10);
	idtable[n][0]='t';
	idtable[n][1]='\0';
	strcat(idtable[n],string);
	n++;
	return n-1;
}

int ProductionFunction(FILE *fp,int Pnum,char idtable[][MAXSYMBOLLENGTH],int &nnumber,int &number,int p[3])	//p符号位置
{
	switch(Pnum)
	{
		case 1: emit(fp,p[1],p[0],0,1,idtable,nnumber);return 0;			//顺序 第二个数字先出栈
		case 2: p[2]=AdditionTemp(idtable,nnumber,number);
				number++;
				emit(fp,p[2],p[1],p[0],2,idtable,nnumber);return p[2];
		case 3:	p[2]=AdditionTemp(idtable,nnumber,number);
				number++;
				emit(fp,p[2],p[1],p[0],3,idtable,nnumber);return p[2];
		case 4: p[2]=AdditionTemp(idtable,nnumber,number);
				number++;
				emit(fp,p[2],p[0],0,4,idtable,nnumber);return p[2];
		case 5:	return p[0];
		case 6:	return p[0];
		case 7: return p[0];
		case 8: return p[0];
		default :return 0;
	}
}

struct sos
{
	int symbol;
	int place;
	int mark;		//1 含place,0 不含place(+ - * ( ) =)
};

void Analysis(struct produce *P, int ***analysistable)
{
	int stackofstatus[MAXSTACK],top=-1,ftop;
	struct sos stackofsymbol[MAXSTACK];
	char Symbol[6][2]={{"+"},{"*"},{"-"},{"("},{")"},{"="}};
	char ID[3]={"id"};
	int lu;
	int i,j,k,i1,length,place=0,lo,loid,mark;
	int buzhou=0;
	char str[MAXSTRING];
	char *c;

	char begin[2]={"#"},empty[2]={"0"};
	char word[MAXSYMBOLLENGTH];

	char idtable[MAXNUMBER][MAXSYMBOLLENGTH];
	int nnumber,inumber,p[3],n,number=0;	//nnumber当前表中的符号个数，inumber初始表中的个数（不算扩充的符号）,number扩充符号个数

	int loend=location(P->symbol,begin,P->numberOFsym);
	int loempty=location(P->symbol,empty,P->numberOFsym);
	loid=location(P->symbol,ID,P->numberOFsym);

	FILE *fp;
	if((fp=fopen("Intermediate code.txt","w+"))==NULL)		
	{
		printf("打开文件失败!\n");
		return;
	}

	printf("请输入要分析的串(每个单词请用空格隔开，请不要超过%d个符号)\n",MAXSTRING);
	gets(str);
	fflush(stdin);
	length=StringPretreatment(str,idtable,inumber);
	nnumber=inumber;




	stackofstatus[++top]=0;
	stackofsymbol[top].symbol=loend;
	printf("%-6s%7s             %5s     %10s     %10s     \n","步骤","状态栈","符号栈","输入串","ACTION");
	place=0;
	c=&str[place];
	place=getword(str,word,place,length);
	while(1)
	{
		if(STATUS[stackofstatus[top]].mark==ENDSTATUS)		
		{
			lu=lookup(word,idtable,inumber);
			if(lu!=ERROR)
			{
				lo=loid;
			}
			else
			{
				lo=location(P->symbol,word,P->numberOFsym);
			}

			k=analysistable[stackofstatus[top]][lo][0];
			if(k==ACC&&strcmp(word,begin)==0)
			{
				printf("%-6d",buzhou);
				for(i=0;i<=top;i++)
					printf("%2d",stackofstatus[i]);
				for(;i<10;i++)
					printf("  ");
				for(i=0;i<=top;i++)
					printf("%s",P->symbol[stackofsymbol[i].symbol]);
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
				printf("%s",P->symbol[stackofsymbol[i].symbol]);
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
				
					
				printf("  %s->",P->symbol[P->produceL[k]]);

				if(P->produceR[analysistable[stackofstatus[top]][lo][0]][0]!=loempty)		//如果是空产生式，不做处理
				{
					j=0;
					while(P->produceR[k][j]!=-1)
					{
						printf("%s",P->symbol[P->produceR[k][j]]);
						j++;
					}
					printf("\n");
					n=0;
					for(i=0;i<j;i++)		//出栈
					{
						if(stackofsymbol[top].mark==1)
							p[n++]=stackofsymbol[top].place;
						top--;
					}
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
				stackofsymbol[top].symbol=P->produceL[k];
				stackofsymbol[top].place=ProductionFunction(fp,k,idtable,nnumber,number,p);
				stackofsymbol[top].mark=1;
			}
			else
			{
				ftop=top;
				
				printf("%11c%2c%2d\n",' ','S',analysistable[stackofstatus[top]][lo][0]);

				stackofstatus[++top]=analysistable[stackofstatus[ftop]][lo][0];
				stackofsymbol[top].symbol=lo;
				for(i1=0,mark=0;i1<6;i1++)
				{
					if(strcmp(Symbol[i1],word)==0)
					{
						mark=1;
						break;
					}
				}
				if(mark==1)
				{
					stackofsymbol[top].mark=0;
				}
				else
				{
					stackofsymbol[top].place=lookup(word,idtable,inumber);
					stackofsymbol[top].mark=1;
				}
				c=&str[place];
				place=getword(str,word,place,length);
				
			}


		}
		else
		{
			ftop=top;

			lu=lookup(word,idtable,inumber);
			if(lu!=ERROR)
			{
				lo=loid;
			}
			else
			{
				lo=location(P->symbol,word,P->numberOFsym);
			}


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
				printf("%s",P->symbol[stackofsymbol[i].symbol]);
			for(;i<=10;i++)
				printf(" ");
			printf("    %5s",c);
			printf("%11c%2c%2d\n",' ','S',analysistable[stackofstatus[top]][lo][0]);

			stackofstatus[++top]=analysistable[stackofstatus[ftop]][lo][0];
			stackofsymbol[top].symbol=lo;

			for(i1=0,mark=0;i1<6;i1++)
			{
				if(strcmp(Symbol[i1],word)==0)
				{
					mark=1;
					break;
				}
			}
			if(mark==1)
			{
				stackofsymbol[top].mark=0;
			}
			else
			{
				stackofsymbol[top].place=lookup(word,idtable,inumber);
				stackofsymbol[top].mark=1;
			}
			c=&str[place];
			place=getword(str,word,place,length);
		}
		buzhou++;
	}
	fclose(fp);
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
	printf("\t\t\t\tLR(1)分析\n\n");
	printf("1) 录入LR(1)文法\n\n2) 输出录入的LR(1)文法\n\n3) 输出状态转换表\n\n4) 输出分析表\n\n5) 分析句子\n\n0) 退出\n\n请选择：");
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
					if (analysistable == NULL)
					{
						printf("输入的文法不是LR(1)文法，不能输出预测分析表\n");
						break;
					}
					PrintAnalysisTable(P,analysistable);
					system("pause");system("cls");break;

			case '5':system("cls");
					if(P==NULL)
					{
						printf("文法未输入，无法输出分析\n");
						break;
					}
					if (analysistable == NULL)
					{
						printf("输入的文法不是LR(1)文法，不能分析\n");
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
