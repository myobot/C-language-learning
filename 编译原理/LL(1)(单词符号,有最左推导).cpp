/*
------作者------王占伟
------时间------20160505
------名称------LL(1)文法分析(支持单词串符号，输出有最左推导)
*/
#ifdef WIN32
#pragma warning (disable: 4514 4786)
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<set>
using std::set;
using std::set<int>;

#define MAXSYMBOLLENGTH 15	//符号最大长度
#define MAXLENGTH 20		//产生式最大长度
#define MAXNUM 50			//图辅助数组大小
#define UNVISITED 0			//图辅助数组未访问状态
#define VISITED 1			//图辅助数组已访问状态
#define END -1				//产生式结束符
#define UNDEFINE -1			//未定（找能推出空的非终结符）
#define WRONG -1			//错误符号位置
#define EMPTY '0'			//空产生式
#define CANEMPTY 1			//能推出空
#define CANNOTEMPTY 0		//不能推出空
#define NO -1				//无产生式（预测分析表）
#define STACKLENGTH 1000		//分析栈最大长度
#define STRINGMAXLENGTH 1000	//待分析串最大长度
#define START 0			//起始符所在位置
#define STRINGEND '\0'		//字符串结尾
#define STRINGCUT ' '		//单词分隔符

int location(char *symbol,char c,int n);//返回符号位置
struct produce * initialize(void);		//初始化文法
int * FindEmpty(struct produce *P);		//找到可以退出空的非终结符
struct picture *BuildPictureOfFirst(struct picture *g,struct produce *P,int *Empty);		//建立First集	图
struct picture *BuildPictureOfFollow(struct picture *g,struct produce *P,int *Empty);		//建立Follow集	图 
void DFSAL(struct B *g,int i);			//深度优先遍历
int **CalculateFirst(struct B *g,struct produce * P);	//计算first集
int **CalculateFollow(struct B *g,struct produce * P);	//计算follow集
int **CalculateSelect(int **First,int **Follow,struct produce *P);	//计算Select集
int **CalculateSelectForecastTable(int **Select,struct produce*P);	//计算预测分析表 ForecastTable
struct picture * FreePicture(struct picture *g);		//释放图所占内存
struct EFFSF *Calculate(struct produce *P);				//汇总

void PrintLL1(struct produce *P);				//输出文法
void PrintEmpty(struct produce *P,int *E);		//输出能否推出空
void PrintFirst(struct produce *P,int **First,int *Empty);	//输出First集
void PrintFollow(struct produce *P,int **Follow);//输出Follow集
void PrintSelect(struct produce *P,int **Select);//输出Select集
void PrintForecastTable(struct produce *P,int **ForecastTable);	//输出分析预测表

char zqsr(char *c);							//检测输入选项正确否
void menu(void);							//菜单

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
	char **symbol;		//所有符号
	int segmentation;	//非终结数-1
	int numberOFpro;
	int numberOFsym;
};

struct EFFSF
{
	int *Empty;
	int **First;
	int **Follow;
	int **Select;
	int **ForecastTable;
};

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
struct produce * initialize(void)
{
	struct produce *P;
	int i,j,mark;
	int place,length;
	char word[MAXSYMBOLLENGTH];
	char c[MAXLENGTH];
	P=(struct produce *)malloc(sizeof(struct produce));
	printf("请输入非终结符总数和符号总数(逗号隔开,空算一个终结符): ");
	while(scanf("%d,%d",&P->segmentation,&P->numberOFsym)!=2||P->segmentation<=0||P->numberOFsym<=0)
	{
		fflush(stdin);printf("请输入正确总数，请重新输入\n");
	}
	fflush(stdin);
	P->segmentation--;
	P->numberOFsym++;
	P->symbol=(char **)malloc(sizeof(char *)*P->numberOFsym);
	system("cls");
	printf("请输入非终结符号，每行一个(请第一个输入 起始符)\n");
	for(i=0;i<=P->segmentation;i++)
	{

		P->symbol[i]=(char *)malloc(sizeof(char)*MAXSYMBOLLENGTH);
		gets(P->symbol[i]);
		fflush(stdin);	
	}
	system("cls");
	printf("请输入终结符号:\n");
	for(i=P->segmentation+1;i<P->numberOFsym-1;i++)
	{
		P->symbol[i]=(char *)malloc(sizeof(char)*MAXSYMBOLLENGTH);
		gets(P->symbol[i]);
		fflush(stdin);
	
	}
	system("cls");
	P->symbol[i]=(char *)malloc(sizeof(char)*MAXSYMBOLLENGTH);
	P->symbol[i][0]='#';		//最后加上 #
	P->symbol[i][1]='\0';
	system("cls");
	printf("请输入产生式总数: ");
	while(scanf("%d",&P->numberOFpro)!=1||P->numberOFpro<=0)
	{
		fflush(stdin);printf("请输入正确总数，请重新输入\n");
	}
	system("cls");
	fflush(stdin);
	P->produceR=(int **)malloc(sizeof(int *)*P->numberOFpro);
	P->produceL=(int *)malloc(sizeof(int)*P->numberOFpro);
	
	for(i=0;i<P->numberOFpro;i++)
	{
		printf("请输入产生式:(左右部用->隔开)(空用 0 表示,每个符号之间用%c隔开)\n",STRINGCUT);
		P->produceR[i]=(int *)malloc(sizeof(int)*MAXLENGTH);
		
		while(1)							//检查错误
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
	int *E,*Efuzhu,i,j,*F,lofe,mark,mark2;		//lofe空的位置
	char empty[2]={"0"};
	E=(int *)malloc(sizeof(int)*(P->segmentation+1));
	Efuzhu=(int *)malloc(sizeof(int)*(P->segmentation+1));
	F=(int *)malloc(sizeof(int)*(P->numberOFpro));
	lofe=location(P->symbol,empty,P->numberOFsym);

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
	int i,j,k,lofe;
	char empty[2]={"0"};
	struct node *s;
	lofe=location(P->symbol,empty,P->numberOFsym);

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
	int i,j,k,lofe;
	int FZ=P->segmentation+1;
	char empty[2]={"0"};
	struct node *s;
	lofe=location(P->symbol,empty,P->numberOFsym);

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

int **CalculateFirst(struct picture *g,struct produce * P)
{
	int i,j,k,**First;
	First=(int **)malloc(sizeof(int)*(P->segmentation+1));
	for(i=0;i<P->segmentation+1;i++)
	{
		First[i]=(int *)malloc(sizeof(int)*P->numberOFsym);
		for(j=0;j<P->numberOFsym;j++)
			First[i][j]=END;
	}
	
	for(i=0;i<P->segmentation+1;i++)
	{
		for(j=0;j<g->n;j++)
			visited[j]=UNVISITED;
		DFSAL(g,i);
		for(j=(P->segmentation+1)*2,k=0;j<g->n;j++)
		{
			if(visited[j]==VISITED)
			{
				First[i][k++]=g->adlist[j].symbol;
			}
		}
	}
	return First;
}

int **CalculateFollow(struct picture *g,struct produce * P)
{
	int i,j,k,**Follow;
	int FZ=P->segmentation+1;
	Follow=(int **)malloc(sizeof(int)*(P->segmentation+1));
	for(i=0;i<P->segmentation+1;i++)
	{
		Follow[i]=(int *)malloc(sizeof(int)*P->numberOFsym);
		for(j=0;j<P->numberOFsym;j++)
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
int **CalculateSelect(int *Empty,int **First,int **Follow,struct produce *P)
{
	int i,j,k,lofe,**Select;
	char empty[2]={"0"};
	set<int> s;					//use set(STL集合)
	set<int>::iterator p;

	Select=(int **)malloc(sizeof(int *)*P->numberOFpro);
	lofe=location(P->symbol,empty,P->numberOFsym);

	for(i=0;i<P->numberOFpro;i++)
	{
		Select[i]=(int *)malloc(sizeof(int)*P->numberOFsym);
		j=0;
		if(P->produceR[i][j]<=P->segmentation)				//如果第一个是非终结符
		{
			if(Empty[P->produceR[i][j]]==CANEMPTY)			//如果第一个能推出空
			{
				k=0;
				while(First[P->produceR[i][j]][k]!=-1)
				{
					s.insert(First[P->produceR[i][j]][k]);
					k++;
				}
				j++;
				while(P->produceR[i][j]!=END)				//扫描接下来的符号
				{
					if(P->produceR[i][j]<=P->segmentation&&Empty[P->produceR[i][j]]==CANEMPTY)	//如果仍为非终结符且能推出空 
					{
						k=0;
						while(First[P->produceR[i][j]][k]!=-1)
						{
							s.insert(First[P->produceR[i][j]][k]);
							k++;
						}
						j++;
					}
					else if(P->produceR[i][j]<=P->segmentation&&Empty[P->produceR[i][j]]==CANNOTEMPTY)	//如果仍未非终结符且不能推出空（跳出）
					{	
						k=0;
						while(First[P->produceR[i][j]][k]!=-1)
						{
							s.insert(First[P->produceR[i][j]][k]);
							k++;
						}
						break;
					}
					else								//如果为终结符（跳出）
					{
						s.insert(P->produceR[i][j]);
						break;
					}
				}
				if(P->produceR[i][j]==END)											//如果直到结束
				{
					k=0;
					while(Follow[P->produceL[i]][k]!=-1)
					{
						s.insert(Follow[P->produceL[i]][k]);
						k++;
					}
				}
				
			}
			else																//如果下一非终结符不能推出空
			{	
				k=0;
				while(First[P->produceR[i][j]][k]!=-1)
				{
					s.insert(First[P->produceR[i][j]][k]);
					k++;
				}
				
			}
		}
		else if(P->produceR[i][j]>P->segmentation&&P->produceR[i][j]!=lofe)		//如果下一个是终结符且不是空产生式
		{
			s.insert(P->produceR[i][j]);
		}
		else																	//如果下一个空产生式
		{
			k=0;
			while(Follow[P->produceL[i]][k]!=-1)
			{
				s.insert(Follow[P->produceL[i]][k]);
				k++;
			}
		}
		for(k=0,p=s.begin();p!=s.end();p++,k++)
		{
			Select[i][k]=*p;
		}
		Select[i][k]=END;	//结尾标志
		s.clear();
	}
	return Select;
}
int judge(int **Select,struct produce *P)
{
	int i,j,k,e,mark;
	int fuzhu[MAXLENGTH],length=0;
	for(i=0;i<MAXLENGTH;i++)
		fuzhu[i]=-2;
	mark=0;
	for(i=0;i<P->segmentation+1;i++)		//对于每个非终结符
	{
		length=0;						
		for(j=0;j<P->numberOFpro;j++)		//对于每个产生式
		{
			if(P->produceL[j]==i)			//如产生式左部等于该非终结符
			{
				k=0;
				while(Select[j][k]!=-1)		//将对应产生式的Select集 加入到fuzhu数组中
				{
					for(e=0;e<length;e++)	//每加一个都检查，是否有重复
					{
						if(fuzhu[e]==Select[j][k])	//如果有重复
						{
							mark=1;				//置标志为1
							break;				//跳出循环
						}
					}
					fuzhu[length++]=Select[j][k++];	//如果没有重复加入到fuzhu数组中
					if(mark==1)					//只要标志位变为1，就说明不是LL(1)文法
						break;
				}
				if(mark==1)
					break;
			}
			
		}
		if(mark==1)
			break;
	}
	if(mark==1)
		return 0;
	else
		return 1;
}



	
int **CalculateSelectForecastTable(int **Select,struct produce*P)
{
	int i,j,k,**ForecastTable;
	int lnum=P->numberOFsym-P->segmentation-1;
	int FZ=P->segmentation+1;
	if(judge(Select,P)==1)
	{
		ForecastTable=(int **)malloc(sizeof(int *)*(P->segmentation+1));
		for(i=0;i<P->segmentation+1;i++)			//预测表初始化 都为-1(NO)
		{	
			ForecastTable[i]=(int *)malloc(sizeof(int)*lnum);
			for(j=0;j<lnum;j++)
				ForecastTable[i][j]=NO;

		}
		for(i=0;i<P->numberOFpro;i++)				//对于每个产生式
		{
			k=0;
			while(Select[i][k]!=-1)					//将Select中的符号对应加入到预测表中
			{
				ForecastTable[P->produceL[i]][Select[i][k]-FZ]=i;	//因为Select中的终结符是对应符号表的位置，所以需要减去前面的终结符长度
				k++;
			}
		}
		return ForecastTable;
	}
	else
		return NULL;
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
struct EFFSF *Calculate(struct produce *P)	//汇总
{
	struct EFFSF *H;
	struct picture *g;
	char empty[2]={"0"};
	int i;
	int lofe=location(P->symbol,empty,P->numberOFsym);
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

	H=(struct EFFSF *)malloc(sizeof(struct EFFSF));
	H->Empty=FindEmpty(P);	
	g=BuildPictureOfFirst(g,P,H->Empty);
	g=BuildPictureOfFollow(g,P,H->Empty);

	H->First=CalculateFirst(g,P);
	H->Follow=CalculateFollow(g,P);
	H->Select=CalculateSelect(H->Empty,H->First,H->Follow,P);
	H->ForecastTable=CalculateSelectForecastTable(H->Select,P);
	g=FreePicture(g);
	return H;
}
					

void PrintLL1(struct produce *P)
{
	int i,j;
	for(i=0;i<P->numberOFpro;i++)
	{
		printf("%s->",P->symbol[P->produceL[i]]);
		j=0;
		while(P->produceR[i][j]!=END)
			printf("%s",P->symbol[P->produceR[i][j++]]);
		printf("\n");
	}
}					

void PrintEmpty(struct produce *P,int *E)
{
	int i;
	for(i=0;i<P->segmentation+1;i++)
	{
		printf("%s: ",P->symbol[i]);
		if(E[i]==1)
			printf("%s\n","空");
		else
			printf("%s\n","非空");
	}
	
}

void PrintFirst(struct produce *P,int **First,int *Empty)
{
	int i,j;
	for(i=0,j=0;i<P->segmentation+1;i++)
	{
		j=0;
		printf("First(%s): { ",P->symbol[i]);
		while(First[i][j]!=END)
		{
			printf("%s ",P->symbol[First[i][j]]);
			j++;
		}
		if(Empty[i]==1)
			printf("%c ",'0');
		printf("}\n");
	}


}

void PrintFollow(struct produce *P,int **Follow)
{
	int i,j;
	for(i=0,j=0;i<P->segmentation+1;i++)
	{
		j=0;
		printf("Follow(%s): { ",P->symbol[i]);
		while(Follow[i][j]!=END)
		{
			printf("%s ",P->symbol[Follow[i][j]]);
			j++;
		}
		printf("}\n");
	}

}

void PrintSelect(struct produce *P,int **Select)
{
	int i,j;
	for(i=0,j=0;i<P->numberOFpro;i++)
	{
		j=0;
		printf("Select(%s->",P->symbol[P->produceL[i]]);
		while(P->produceR[i][j]!=END)
		{
			printf("%s",P->symbol[P->produceR[i][j]]);
			j++;
		}
		printf("): { ");
		j=0;
		while(Select[i][j]!=END)
		{
			printf("%s ",P->symbol[Select[i][j]]);
			j++;
		}
		printf("}\n");
	}
}

void PrintForecastTable(struct produce *P,int **ForecastTable)
{
	int i,j,k,s=P->numberOFsym-P->segmentation-1,num;
	char fuzhu[MAXLENGTH+2]={"\0"};
	char space[2]={" "};
	char jiantou[3]={"->"};
	printf("%-9c",' ');
	for(i=P->segmentation+1;i<P->numberOFsym;i++)
	{
		printf("%-9s",P->symbol[i]);
	}
	printf("\n");
	for(i=0;i<P->segmentation+1;i++)
	{
		printf("%-9s",P->symbol[i]);
		num=0;
		for(j=0;j<s;j++)
		{
			if(ForecastTable[i][j]!=-1)
			{
				k=0;
				strcat(fuzhu,jiantou);
				while(P->produceR[ForecastTable[i][j]][k]!=-1)
				{
					strcat(fuzhu,P->symbol[P->produceR[ForecastTable[i][j]][k]]);
					k++;
				}
				printf("%-9s",fuzhu);
				fuzhu[0]='\0';
			}
			else
				printf("%-9c",' ');
		}
		printf("\n");
	}
}

void Forecast(int **ForecastTable,struct produce *P)
{
	char str[STRINGMAXLENGTH],*c=str;
	int top=0,j,k,num,stack[STACKLENGTH],loend,lo,i=0,danci=1;
	char begin[2]={"#"},empty[2]={"0"};
	char word[MAXSYMBOLLENGTH];
	char LL[10000],s[10000];
	int n=0,n1=0;
	int stringlength,place=0,pro[MAXLENGTH];
	int FZ=P->segmentation+1;
	printf("请输入要分析的串(每个单词用%c隔开)\n",STRINGCUT);
	fflush(stdin);
	gets(str);
	fflush(stdin);
	stringlength=strlen(str);
	if(str[stringlength-1]!='#')			//串预处理 ，如果结尾没有# 加上#号
	{
		str[stringlength++]=' ';
		str[stringlength]='#';
		str[stringlength+1]='\0';
	}
	loend=location(P->symbol,begin,P->numberOFsym);	//记录#号在符号表中的位置

	stack[top++]=loend;					//#先入栈
	stack[top++]=START;					//起始符入栈
	j=0;
	while(P->symbol[START][j]!='\0')
		LL[n++]=P->symbol[START][j++];
	LL[n++]=' ';
	printf("推导所用产生式或匹配\n");
	place=getword(str,word,place,stringlength);

	while(strcmp(word,begin)!=0||stack[top-1]!=loend)		//当待输入符号串为 # 且符号栈 为 # 时跳出循环
	{
		k=stack[--top];						//出栈一个符号
		if(strcmp(P->symbol[k],empty)==0)				//如果出栈的符号是 空  则直接重新循环
		{
			continue;
		}
		
		lo=location(P->symbol,word,P->numberOFsym);

		if(lo==-1)									//符号不属于符号表  则输入有误 不接受
		{	
			printf("\n输入第%d个符号有误，无法匹配预测\n",danci);
			printf("不接受\n");
			return;
		}
		if(k>P->segmentation)		//如果出栈符号是终结符
		{
			if(strcmp(P->symbol[k],word)==0)	//如果出栈符号与当前符号相等 则匹配 对应符号 当前符号位置下移
			{
				j=0;
				while(word[j]!='\0')
					s[n1++]=word[j++];
				s[n1++]=' ';
				printf("%18s 已匹配\n",word);
				place=getword(str,word,place,stringlength);
				danci++;
			}
			else							//如果不等
			{
				printf("\n输入第%d个符号有误，无法匹配预测\n",danci);
				printf("不接受\n");
				return;
			}
		}
		else								
		{
			if(ForecastTable[k][lo-FZ]==-1)	//如果预测表对应位置为 -1 则不接受
			{
				printf("\n输入第%d个符号有误，无法匹配预测\n",danci);
				return ;
			}
			else							//预测表不为 -1
			{	
				LL[n++]='=';
				LL[n++]='>';
				printf("%-2s-> ",P->symbol[k]);	//输出产生式
				num=0;j=0;
				while(P->produceR[ForecastTable[k][lo-FZ]][j]!=-1)		//将预测表中产生式右部的符号 存到数组中
				{
					pro[num++]=P->produceR[ForecastTable[k][lo-FZ]][j];
					printf("%s ",P->symbol[P->produceR[ForecastTable[k][lo-FZ]][j]]);
					j++;
				}
				printf("\n");
			
				for(j=num-1;j>=0;j--)		//倒序入栈
				{
					stack[top++]=pro[j];
				}
				
				for(j=0;j<n1;j++)
					LL[n++]=s[j];

				for(j=top-1;j>=1;j--)
				{
					if(P->symbol[stack[j]][0]!='0')
					{
						k=0;
						while(P->symbol[stack[j]][k]!='\0')
							LL[n++]=P->symbol[stack[j]][k++];
						LL[n++]=' ';
					}
				}
			}
		}
		i++;

	}
	printf("接受\n");
	LL[n++]='\0';
	printf("最左推导：\n");
	printf("%s\n",LL);

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
	printf("\t\t\t\tLL(1)文法分析\n\n");
	printf("1) 录入LL(1)文法\n\n2) 输出录入的LL(1)文法\n\n3) 判断各非终结符能否推出空\n\n4) 输出First集\n\n5) 输出Follow集\n\n6) 输出Select集\n\n7) 输出预测分析表\n\n8) 分析句子\n\n0) 退出\n\n请选择：");
}

int main()
{
	int i,flag;
	struct produce *P=NULL;
	struct EFFSF *H=NULL;
	char c[MAXLENGTH]={"123456780"};
	char xz;
	while(1)
	{
		flag=0;
		menu();
		xz=zqsr(c);
		switch(xz)
		{
			case '1':system("cls");
				
					if(H!=NULL)
					{
						free(H->Empty);
						for(i=0;i<P->segmentation+1;i++)
						{
							free(H->First[i]);
							free(H->Follow[i]);
						}
						for(i=0;i<P->numberOFpro;i++)
							free(H->Select[i]);
						
						free(H->First);
						free(H->Follow);
						free(H->Select);
						free(H);
					}
					if(P!=NULL)
					{
						free(P->produceL);
					
						for(i=0;i<P->numberOFsym;i++)
							free(P->symbol[i]);
						for(i=0;i<P->numberOFpro;i++)
						{
							free(P->produceR[i]);
						}
						free(P->symbol);
						free(P->produceR);
						free(P);
					}
					P=initialize();
					H=Calculate(P);
					system("pause");system("cls");break;

			case '2':system("cls");
					if(P==NULL)
					{
						printf("文法未录入，无法显示输入的文法\n请先录入文法\n");
						system("pause");system("cls");
						break;
					}
					PrintLL1(P);
					system("pause");system("cls");break;

			case '3':system("cls");
					if(H==NULL)
					{
						printf("文法未录入，无法判断非终结符是否能推出空\n请先录入文法\n");
						system("pause");system("cls");
						break;
					}
					
					
					PrintEmpty(P,H->Empty);
				
					system("pause");system("cls");break;
					
			case '4':system("cls");
					if(H==NULL)
					{
						printf("文法未录入，无法输出First集\n请先录入文法\n");
						system("pause");system("cls");
						break;
					}
					PrintFirst(P,H->First,H->Empty);
					system("pause");system("cls");break;

			case '5':system("cls");
					if(H==NULL)
					{
						printf("文法未录入，无法判断输出Follow集\n请先录入文法\n");
						system("pause");system("cls");
						break;
					}
					PrintFollow(P,H->Follow);
					system("pause");system("cls");break;

			case '6':system("cls");
					if(H==NULL)
					{
						printf("文法未录入，无法输出Select集\n请先录入文法\n");
						system("pause");system("cls");
						break;
					}
					PrintSelect(P,H->Select);
					system("pause");system("cls");break;

			case '7':system("cls");
					if(H->ForecastTable==NULL)
					{
						printf("此文法不是LL(1)文法，无法输出预测分析表\n");
						system("pause");system("cls");
						break;
					}
					PrintForecastTable(P,H->ForecastTable);
					system("pause");system("cls");break;

			case'8':system("cls");
					if(P==NULL)
					{
						printf("文法未录入，无法分析\n请先录入文法\n");
						break;
					}
					if(H->ForecastTable==NULL)
					{
						printf("此文法不是LL(1)文法，无法进行预测分析\n");
						system("pause");system("cls");
						break;
					}
					Forecast(H->ForecastTable,P);
					system("pause");system("cls");break;
		
			case '0':flag++;break;
		}
		if(flag>0)
			break;
	}
	if(H!=NULL)
	{
		free(H->Empty);
		for(i=0;i<P->segmentation+1;i++)
		{
			free(H->First[i]);
			free(H->Follow[i]);
		}
		for(i=0;i<P->numberOFpro;i++)
			free(H->Select[i]);
		
		free(H->First);
		free(H->Follow);
		free(H->Select);
		free(H);
	}
	if(P!=NULL)
	{
		free(P->produceL);
		
		for(i=0;i<P->numberOFsym;i++)
			free(P->symbol[i]);
		for(i=0;i<P->numberOFpro;i++)
		{
			free(P->produceR[i]);
		}
		free(P->symbol);
		free(P->produceR);
		free(P);
	}
	return 0;
}

