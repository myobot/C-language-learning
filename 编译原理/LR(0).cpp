/*
------作者------王占伟
------时间------20160505
------名称------LR(0)文法分析
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<set>

using std::set;
using std::set<int>;

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
	P->symbol=(char *)malloc(sizeof(char)*P->numberOFsym);
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
	int i,j,mark=0;
	int position=0;
	int fuzhu[MAXLENGTH],num=0;
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
			CORE[CORENUMBER++]=J;
		}
		

		STATUSTRANSFORM[status][STNUMBER[status]][0]=x;			//填入 符号 到状态转换表对应位置
		STATUSTRANSFORM[status][STNUMBER[status]][1]=position;	//移向状态

		if(P->produceR[J.ps[0][0]][J.ps[0][1]]==-1)				//如果是终结状态
		{
			STATUSTRANSFORM[status][STNUMBER[status]++][2]=ENDSTATUS;	//标志设为终结
			CORE[position].mark=ENDSTATUS;
		}
		else
		{
			STATUSTRANSFORM[status][STNUMBER[status]++][2]=NOTENDSTATUS;
			CORE[position].mark=NOTENDSTATUS;
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
	struct projectset a,b,c;
	int i,status,place;
	struct queue *Q;
	Q=chushihua();
	a.ps[0][0]=0;			// S'->.E
	a.ps[0][1]=0;
	a.n=1;
	
	status=CORENUMBER;		//初始化第一个状态
	CORE[CORENUMBER++]=a;

	b=CLOSURE(P,a);			//求CLOSURE（S'->.E）
	rudui(Q,b,status);
	
	while(!kong(Q))
	{
		chudui(Q,b,status);
		if(b.n==1)
		{
			if(P->produceR[b.ps[0][0]][b.ps[0][1]]==-1)		//如果是终结状态 重新循环
				continue;
		}
		for(i=0;i<P->numberOFsym;i++)
		{
			c=GO(P,b,i,status,place);
			if(c.n>0)										//如果返回的不空则入队
				rudui(Q,c,place);
		}
	}
}

int *** CalculateAnalysisTable(struct produce *P)			//移进	[0]转移到的状态[1]转移到的状态的状态	规约   [0]使用的产生式 [1]标志
{
	int i,j,***analysistable;
	int lofe=location(P->symbol,'#',P->numberOFsym);
	analysistable=(int ***)malloc(sizeof(int **)*CORENUMBER);
	for(i=0;i<CORENUMBER;i++)
	{
		analysistable[i]=(int **)malloc(sizeof(int*)*P->numberOFsym-1);
		for(j=1;j<P->numberOFsym;j++)		//忽略第一个 S'($)
		{
			analysistable[i][j]=(int *)malloc(sizeof(int)*2);
			analysistable[i][j][0]=-1;
			analysistable[i][j][1]=-1;
		}
		if(CORE[i].mark==ENDSTATUS)			//如果这个状态是终结状态，将所有符号都置为规约
		{
			for(j=P->segmentation+1;j<P->numberOFsym;j++)
			{
				analysistable[i][j][0]=CORE[i].ps[0][0];
				analysistable[i][j][1]=GUIYUE;			//标志
			}
		}
		else								//如果不是终结状态，将对应位置置为转移
		{
			for(j=0;j<STNUMBER[i];j++)
			{
				analysistable[i][STATUSTRANSFORM[i][j][0]][0]=STATUSTRANSFORM[i][j][1];
				analysistable[i][STATUSTRANSFORM[i][j][0]][1]=STATUSTRANSFORM[i][j][2];
			}
		}
	}
	for(i=0;i<CORENUMBER;i++)				//找到结束状态
	{
		if(CORE[i].ps[0][0]==0&&CORE[i].ps[0][1]==1)
			break;
	}
	for(j=1;j<P->numberOFsym-1;j++)			//重新初始化结束状态
	{
		analysistable[i][j][0]=-1;
		analysistable[i][j][1]=-1;
	}
	analysistable[i][lofe][0]=ACC;			//#置为接受
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
		if(CORE[stackofstatus[top]].mark==ENDSTATUS)
		{
			k=analysistable[stackofstatus[top]][lofe][0];
			if(k==ACC&&top==1)
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
			printf("%11c%2c%2d",' ','R',analysistable[stackofstatus[top]][lofe][0]);
			
			printf("  %c->",P->symbol[P->produceL[k]]);


			j=0;
			while(P->produceR[k][j]!=-1)
			{
				printf("%c",P->symbol[P->produceR[k][j]]);
				j++;
			}
			printf("\n");
			for(i=0;i<j;i++)		//出栈
				top--;

			if(analysistable[stackofstatus[top]][P->produceL[k]][0]==-1)
			{
				printf("输入串有误，无法分析\n");
				break;
			}

			ftop=top;
			stackofstatus[++top]=analysistable[stackofstatus[top]][P->produceL[k]][0];
			stackofsymbol[top]=P->produceL[k];
		}
		else
		{
			ftop=top;
			lo=location(P->symbol,str[place],P->numberOFsym);
			if(analysistable[stackofstatus[ftop]][lo][0]==-1)
			{
				printf("输入串有误，无法分析\n");
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
	printf("\t\t\t\tLR(0)分析\n\n");
	printf("1) 录入LR(0)文法\n\n2) 输出录入的LR(0)文法\n\n3) 输出状态转换表\n\n4) 输出分析表\n\n5) 分析句子\n\n0) 退出\n\n请选择：");
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
