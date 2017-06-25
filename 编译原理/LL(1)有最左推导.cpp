/*
------����------��ռΰ
------ʱ��------20160505
------����------LL(1)�ķ�����(������������Ƶ�)
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

#define MAXLENGTH 20	//����ʽ��󳤶�
#define MAXNUM 50		//ͼ���������С
#define UNVISITED 0		//ͼ��������δ����״̬
#define VISITED 1		//ͼ���������ѷ���״̬
#define END -1			//����ʽ������
#define UNDEFINE -1		//δ���������Ƴ��յķ��ս����
#define WRONG -1		//�������λ��
#define EMPTY '0'		//�ղ���ʽ
#define CANEMPTY 1		//���Ƴ���
#define CANNOTEMPTY 0	//�����Ƴ���
#define NO -1			//�޲���ʽ��Ԥ�������
#define STACKLENGTH 1000		//����ջ��󳤶�
#define STRINGMAXLENGTH 1000	//����������󳤶�
#define START 0			//��ʼ������λ��
#define STRINGEND '\0'

int location(char *symbol,char c,int n);//���ط���λ��
struct produce * initialize(void);		//��ʼ���ķ�
int * FindEmpty(struct produce *P);		//�ҵ������˳��յķ��ս��
struct picture *BuildPictureOfFirst(struct picture *g,struct produce *P,int *Empty);		//����First��	ͼ
struct picture *BuildPictureOfFollow(struct picture *g,struct produce *P,int *Empty);		//����Follow��	ͼ 
void DFSAL(struct B *g,int i);			//������ȱ���
int **CalculateFirst(struct B *g,struct produce * P);	//����first��
int **CalculateFollow(struct B *g,struct produce * P);	//����follow��
int **CalculateSelect(int **First,int **Follow,struct produce *P);	//����Select��
int **CalculateSelectForecastTable(int **Select,struct produce*P);	//����Ԥ������� ForecastTable
struct picture * FreePicture(struct picture *g);		//�ͷ�ͼ��ռ�ڴ�
struct EFFSF *Calculate(struct produce *P);				//����

void PrintLL1(struct produce *P);				//����ķ�
void PrintEmpty(struct produce *P,int *E);		//����ܷ��Ƴ���
void PrintFirst(struct produce *P,int **First,int *Empty);	//���First��
void PrintFollow(struct produce *P,int **Follow);//���Follow��
void PrintSelect(struct produce *P,int **Select);//���Select��
void PrintForecastTable(struct produce *P,int **ForecastTable);	//�������Ԥ���

char zqsr(char *c);							//�������ѡ����ȷ��
void menu(void);							//�˵�

struct node
{
	int ldd;
	struct node *next;
};
struct vnode
{
	int symbol;
	int mark;			//0 �ս�� 1 First 2 Follow 
	struct node *firstnode;
};
struct picture
{
	struct vnode *adlist;
	int n,e;
};

struct produce
{
	int **produceR;		//����ʽ�Ҳ�
	int *produceL;		//����ʽ��
	char *symbol;		//���з���
	int segmentation;	//���ս���-1
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
struct produce * initialize(void)
{
	struct produce *P;
	int i,j,l,mark;
	char c[MAXLENGTH];
	P=(struct produce *)malloc(sizeof(struct produce));
	printf("��������ս�������ͷ�������(���Ÿ���,����һ���ս��): ");
	while(scanf("%d,%d",&P->segmentation,&P->numberOFsym)!=2||P->segmentation<=0||P->numberOFsym<=0)
	{
		fflush(stdin);printf("��������ȷ����������������\n");
	}
	fflush(stdin);
	P->segmentation--;
	P->numberOFsym++;
	P->symbol=(char *)malloc(sizeof(char)*P->numberOFsym);
	system("cls");
	printf("��������ս���ţ�ÿ��һ��(���һ������ ��ʼ��)\n");
	for(i=0;i<=P->segmentation;i++)
	{
		
		scanf("%c",&P->symbol[i]);
		fflush(stdin);	
	}
	system("cls");
	printf("�������ս����:\n");
	for(i=P->segmentation+1;i<P->numberOFsym-1;i++)
	{
		scanf("%c",&P->symbol[i]);
		fflush(stdin);
	
	}
	system("cls");
	P->symbol[i]='#';		//������ #
	system("cls");
	printf("���������ʽ����: ");
	while(scanf("%d",&P->numberOFpro)!=1||P->numberOFpro<=0)
	{
		fflush(stdin);printf("��������ȷ����������������\n");
	}
	system("cls");
	fflush(stdin);
	P->produceR=(int **)malloc(sizeof(int *)*P->numberOFpro);
	P->produceL=(int *)malloc(sizeof(int)*P->numberOFpro);
	
	for(i=0;i<P->numberOFpro;i++)
	{
		printf("���������ʽ:(���Ҳ���->����)(���� 0 ��ʾ)\n");
		P->produceR[i]=(int *)malloc(sizeof(int)*MAXLENGTH);
		while(1)							//������
		{	
			gets(c);
			if(c[1]!='-'||c[2]!='>')		//û��->
			{
				printf("������������������:\n");
				continue;
			}
			if(location(P->symbol,c[0],P->numberOFsym)>P->segmentation)	//��һ�����Ƿ��ս��
			{
				printf("��������(����ʽ������ֻ��һ�����ս��),����������\n");
				continue;
			}
			P->produceL[i]=location(P->symbol,c[0],P->numberOFsym);
			l=strlen(c)-3;
			mark=0;
			for(j=0;j<l;j++)				//���з��ű�����ķ���
			{
				P->produceR[i][j]=location(P->symbol,c[j+3],P->numberOFsym);
				if(P->produceR[i][j]==WRONG)
				{
					printf("�˲���ʽ���зǷ����ţ�����������:\n");
					mark=1;
					break;
				}
			}
			if(mark==1)
				continue;
			P->produceR[i][j]=END;			//��β�� -1
			break;
		}
		system("cls");
	}
	return P;
}



int * FindEmpty(struct produce *P)
{	
	int *E,*Efuzhu,i,j,*F,lofe,mark,mark2;		//lofe�յ�λ��
	E=(int *)malloc(sizeof(int)*(P->segmentation+1));
	Efuzhu=(int *)malloc(sizeof(int)*(P->segmentation+1));
	F=(int *)malloc(sizeof(int)*(P->numberOFpro));
	lofe=location(P->symbol,EMPTY,P->numberOFsym);
	for(i=0;i<P->segmentation+1;i++)
	{
		E[i]=UNDEFINE;						//���ս��mark
		Efuzhu[i]=0;
	}
	for(i=0;i<P->numberOFpro;i++)
	{
		F[i]=1;							//����ʽmark
		Efuzhu[P->produceL[i]]++;
	}
	for(i=0;i<P->numberOFpro;i++)
	{
		if(F[i]!=0)
		{
			j=0;
			while(P->produceR[i][j]!=END)	//����Ҳ������ս���Ҳ��ǿգ���ɾ���ò���ʽ
			{	
				if(P->produceR[i][j]!=lofe&&P->produceR[i][j]>P->segmentation)	
				{
					F[i]=0;
					Efuzhu[P->produceL[i]]--;
					break;
				}
				j++;
			}
			if(P->produceR[i][0]==lofe)		//�Ҳ�Ϊ�գ����󲿷��ս�����Ƴ��գ���ɾ��������Ϊ���ս���Ĳ���ʽ
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
					if(E[P->produceR[i][j]]==UNDEFINE)		//�������δ��
					{
						mark=1;
					}
					j++;
				}
				if(mark==0)		//���Ƴ���
				{
					E[P->produceL[i]]=CANEMPTY;		//��1
					for(j=0;j<P->numberOFpro;j++)	//ɾ��������Ϊ�˷��ս���Ĳ���ʽ
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
				for(j=0;j<P->segmentation+1;j++)	//�����ɾ����ĳһ�����ս����δ��������0
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
		if(mark2==0)		//�������û���ڸı����
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
	for(i=0;i<P->segmentation+1;i++)			//��ÿ�����ս��
	{	
		for(j=0;j<P->numberOFpro;j++)			//��ÿ������ʽ
		{
			if(P->produceL[j]==i)				//���Ǹ÷��ս��	
			{	
				k=0;
				if(P->produceR[j][k]<=P->segmentation)	//����󲿵�һ�� �Ƿ��ս��
				{
					if(Empty[P->produceR[j][k]]==CANEMPTY)		//����󲿵�һ�����ս�������Ƴ���
					{
						
						s=(struct node *)malloc(sizeof(struct node));
						s->ldd=P->produceR[j][k];		
						s->next=g->adlist[i].firstnode;		//����ͼ ���ս��first��������һ�����ս��first��
						g->adlist[i].firstnode=s;
						k++;
						while(P->produceR[j][k]!=END)		//�鿴��������
						{
							if(P->produceR[j][k]<=P->segmentation&&Empty[P->produceR[j][k]]==CANEMPTY)	//�����Ϊ���ս�������Ƴ��� 
							{
								s=(struct node *)malloc(sizeof(struct node));
								s->ldd=P->produceR[j][k];
								s->next=g->adlist[i].firstnode;	
								g->adlist[i].firstnode=s;
								k++;						//ֻ�����Ƴ��ղ����ɨ��
							}
							else if(P->produceR[j][k]<=P->segmentation&&Empty[P->produceR[j][k]]==CANNOTEMPTY)	//�����δ���ս���Ҳ����Ƴ��գ�������
							{	
								s=(struct node *)malloc(sizeof(struct node));
								s->ldd=P->produceR[j][k];
								s->next=g->adlist[i].firstnode;	
								g->adlist[i].firstnode=s;
								break;
							}
							else								//���Ϊ�ս����������
							{
								s=(struct node *)malloc(sizeof(struct node));
								s->ldd=P->produceR[j][k]+(P->segmentation+1);					//ָ��ͼ�ж�Ӧ�ս��λ��
								s->next=g->adlist[i].firstnode;	
								g->adlist[i].firstnode=s;
								break;
							}
						}
					}
					else								//�����һ���Ƿ��ս���Ҳ����Ƴ���
					{
				
						s=(struct node *)malloc(sizeof(struct node));
						s->ldd=P->produceR[j][k];
						s->next=g->adlist[i].firstnode;	
						g->adlist[i].firstnode=s;
						
					}
				}
				else									//�����һ�����ս�������Կղ���ʽ��
				{
					if(P->produceR[j][k]!=lofe)
					{
						s=(struct node *)malloc(sizeof(struct node));
						s->ldd=P->produceR[j][k]+(P->segmentation+1);							//ָ��ͼ�ж�Ӧ�ս��λ��
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
	s->next=g->adlist[P->segmentation+1].firstnode;				//S ��follow������ #
	g->adlist[P->segmentation+1].firstnode=s;

	for(i=P->segmentation+1;i<(P->segmentation+1)*2;i++)			//��ÿ�����ս����follow��λ�ã�
	{	
		for(j=0;j<P->numberOFpro;j++)								//��ÿ������ʽ
		{
			k=0;
			while(P->produceR[j][k]!=(i-FZ)&&P->produceR[j][k]!=END)		//�ҵ��ò���ʽ�Ҳ��ĸ÷��ս��
			{
				k++;
			}
			if(P->produceR[j][k]!=END)								//��������÷��ս��
			{
				k++;
				if(P->produceR[j][k]==END)								//���ֱ�Ӿ���ĩβ
				{
					s=(struct node *)malloc(sizeof(struct node));	
					s->ldd=P->produceL[j]+(P->segmentation+1);			//���󲿷��ս����follow����ӵ��÷��ս����follow��
					s->next=g->adlist[i].firstnode;	
					g->adlist[i].firstnode=s;
				}
				else													//����ĩβ
				{
					if(P->produceR[j][k]<=P->segmentation)				//��һ������Ƿ��ս��
					{
						if(Empty[P->produceR[j][k]]==CANEMPTY)					//�����һ���ս�����Ƴ���
						{
							s=(struct node *)malloc(sizeof(struct node));
							s->ldd=P->produceR[j][k];		
							s->next=g->adlist[i].firstnode;				//����ͼ ���ս��follow���������ս��first��
							g->adlist[i].firstnode=s;
							k++;
							while(P->produceR[j][k]!=END)				//ɨ��������ķ���
							{
								if(P->produceR[j][k]<=P->segmentation&&Empty[P->produceR[j][k]]==CANEMPTY)	//�����Ϊ���ս�������Ƴ��� 
								{
									s=(struct node *)malloc(sizeof(struct node));
									s->ldd=P->produceR[j][k];
									s->next=g->adlist[i].firstnode;	
									g->adlist[i].firstnode=s;
									k++;
								}
								else if(P->produceR[j][k]<=P->segmentation&&Empty[P->produceR[j][k]]==CANNOTEMPTY)	//�����δ���ս���Ҳ����Ƴ��գ�������
								{	
									s=(struct node *)malloc(sizeof(struct node));
									s->ldd=P->produceR[j][k];
									s->next=g->adlist[i].firstnode;	
									g->adlist[i].firstnode=s;
									break;
								}
								else									//���Ϊ�ս����������
								{
									s=(struct node *)malloc(sizeof(struct node));
									s->ldd=P->produceR[j][k]+(P->segmentation+1);					//ָ��ͼ�ж�Ӧ�ս��λ��
									s->next=g->adlist[i].firstnode;	
									g->adlist[i].firstnode=s;
									break;
								}
							}
							if(P->produceR[j][k]==END)								//���ֱ������
							{
								s=(struct node *)malloc(sizeof(struct node));	
								s->ldd=P->produceL[j]+(P->segmentation+1);			//���󲿷��ս����follow����ӵ��÷��ս����follow��
								s->next=g->adlist[i].firstnode;	
								g->adlist[i].firstnode=s;
							}
						}
						else											//�����һ���ս�������Ƴ���
						{
							s=(struct node *)malloc(sizeof(struct node));
							s->ldd=P->produceR[j][k];		
							s->next=g->adlist[i].firstnode;				//����ͼ ���ս��follow�������˷��ս��first��
							g->adlist[i].firstnode=s;
						}
					}
					else											//�����һ�����ս��
					{
						s=(struct node *)malloc(sizeof(struct node));
						s->ldd=P->produceR[j][k]+(P->segmentation+1);		
						s->next=g->adlist[i].firstnode;					//����ͼ ���ս��follow���������ս��
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

	set<int> s;					//use set(STL����)
	set<int>::iterator p;

	Select=(int **)malloc(sizeof(int *)*P->numberOFpro);
	lofe=location(P->symbol,EMPTY,P->numberOFsym);
	for(i=0;i<P->numberOFpro;i++)
	{
		Select[i]=(int *)malloc(sizeof(int)*P->numberOFsym);
		j=0;
		if(P->produceR[i][j]<=P->segmentation)				//�����һ���Ƿ��ս��
		{
			if(Empty[P->produceR[i][j]]==CANEMPTY)			//�����һ�����Ƴ���
			{
				k=0;
				while(First[P->produceR[i][j]][k]!=-1)
				{
					s.insert(First[P->produceR[i][j]][k]);
					k++;
				}
				j++;
				while(P->produceR[i][j]!=END)				//ɨ��������ķ���
				{
					if(P->produceR[i][j]<=P->segmentation&&Empty[P->produceR[i][j]]==CANEMPTY)	//�����Ϊ���ս�������Ƴ��� 
					{
						k=0;
						while(First[P->produceR[i][j]][k]!=-1)
						{
							s.insert(First[P->produceR[i][j]][k]);
							k++;
						}
						j++;
					}
					else if(P->produceR[i][j]<=P->segmentation&&Empty[P->produceR[i][j]]==CANNOTEMPTY)	//�����δ���ս���Ҳ����Ƴ��գ�������
					{	
						k=0;
						while(First[P->produceR[i][j]][k]!=-1)
						{
							s.insert(First[P->produceR[i][j]][k]);
							k++;
						}
						break;
					}
					else								//���Ϊ�ս����������
					{
						s.insert(P->produceR[i][j]);
						break;
					}
				}
				if(P->produceR[i][j]==END)											//���ֱ������
				{
					k=0;
					while(Follow[P->produceL[i]][k]!=-1)
					{
						s.insert(Follow[P->produceL[i]][k]);
						k++;
					}
				}
				
			}
			else																//�����һ���ս�������Ƴ���
			{	
				k=0;
				while(First[P->produceR[i][j]][k]!=-1)
				{
					s.insert(First[P->produceR[i][j]][k]);
					k++;
				}
				
			}
		}
		else if(P->produceR[i][j]>P->segmentation&&P->produceR[i][j]!=lofe)		//�����һ�����ս���Ҳ��ǿղ���ʽ
		{
			s.insert(P->produceR[i][j]);
		}
		else																	//�����һ���ղ���ʽ
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
		Select[i][k]=END;	//��β��־
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
	for(i=0;i<P->segmentation+1;i++)		//����ÿ�����ս��
	{
		length=0;						
		for(j=0;j<P->numberOFpro;j++)		//����ÿ������ʽ
		{
			if(P->produceL[j]==i)			//�����ʽ�󲿵��ڸ÷��ս��
			{
				k=0;
				while(Select[j][k]!=-1)		//����Ӧ����ʽ��Select�� ���뵽fuzhu������
				{
					for(e=0;e<length;e++)	//ÿ��һ������飬�Ƿ����ظ�
					{
						if(fuzhu[e]==Select[j][k])	//������ظ�
						{
							mark=1;				//�ñ�־Ϊ1
							break;				//����ѭ��
						}
					}
					fuzhu[length++]=Select[j][k++];	//���û���ظ����뵽fuzhu������
					if(mark==1)					//ֻҪ��־λ��Ϊ1����˵������LL(1)�ķ�
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
		for(i=0;i<P->segmentation+1;i++)			//Ԥ����ʼ�� ��Ϊ-1(NO)
		{	
			ForecastTable[i]=(int *)malloc(sizeof(int)*lnum);
			for(j=0;j<lnum;j++)
				ForecastTable[i][j]=NO;

		}
		for(i=0;i<P->numberOFpro;i++)				//����ÿ������ʽ
		{
			k=0;
			while(Select[i][k]!=-1)					//��Select�еķ��Ŷ�Ӧ���뵽Ԥ�����
			{
				ForecastTable[P->produceL[i]][Select[i][k]-FZ]=i;	//��ΪSelect�е��ս���Ƕ�Ӧ���ű��λ�ã�������Ҫ��ȥǰ����ս������
				k++;
			}
		}
		return ForecastTable;
	}
	else
		return NULL;
}
		




struct picture * FreePicture(struct picture *g) //�ͷ�ͼ
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
struct EFFSF *Calculate(struct produce *P)	//����
{
	struct EFFSF *H;
	struct picture *g;

	int i;
	int lofe=location(P->symbol,EMPTY,P->numberOFsym);
	g=(struct picture *)malloc(sizeof(struct picture));	//ͼ��ʼ��
	g->n=(P->segmentation+1)+P->numberOFsym;
	g->adlist=(struct vnode *)malloc(sizeof(struct vnode)*g->n);
	for(i=0;i<P->segmentation+1;i++)	//First��
	{
		g->adlist[i].symbol=i;
		g->adlist[i].mark=1;
		g->adlist[i].firstnode=NULL;
	}
	for(;i<P->segmentation+1;i++)		//Follow��
	{
		g->adlist[i].symbol=i-(P->segmentation+1);
		g->adlist[i].mark=2;
		g->adlist[i].firstnode=NULL;
	}
	for(;i<g->n;i++)					//�ս����
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
		printf("%c->",P->symbol[P->produceL[i]]);
		j=0;
		while(P->produceR[i][j]!=END)
			printf("%c",P->symbol[P->produceR[i][j++]]);
		printf("\n");
	}
}					

void PrintEmpty(struct produce *P,int *E)
{
	int i;
	for(i=0;i<P->segmentation+1;i++)
	{
		printf("%c: ",P->symbol[i]);
		if(E[i]==1)
			printf("%s\n","��");
		else
			printf("%s\n","�ǿ�");
	}
	
}

void PrintFirst(struct produce *P,int **First,int *Empty)
{
	int i,j;
	for(i=0,j=0;i<P->segmentation+1;i++)
	{
		j=0;
		printf("First(%c): { ",P->symbol[i]);
		while(First[i][j]!=END)
		{
			printf("%c ",P->symbol[First[i][j]]);
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
		printf("Follow(%c): { ",P->symbol[i]);
		while(Follow[i][j]!=END)
		{
			printf("%c ",P->symbol[Follow[i][j]]);
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
		printf("Select(%c->",P->symbol[P->produceL[i]]);
		while(P->produceR[i][j]!=END)
		{
			printf("%c",P->symbol[P->produceR[i][j]]);
			j++;
		}
		printf("): { ");
		j=0;
		while(Select[i][j]!=END)
		{
			printf("%c ",P->symbol[Select[i][j]]);
			j++;
		}
		printf("}\n");
	}
}

void PrintForecastTable(struct produce *P,int **ForecastTable)
{
	int i,j,k,s=P->numberOFsym-P->segmentation-1,num;
	char fuzhu[MAXLENGTH];
	printf("%-9c",' ');
	for(i=P->segmentation+1;i<P->numberOFsym;i++)
	{
		printf("%-9c",P->symbol[i]);
	}
	printf("\n");
	for(i=0;i<P->segmentation+1;i++)
	{
		printf("%-9c",P->symbol[i]);
		num=0;
		for(j=0;j<s;j++)
		{
			if(ForecastTable[i][j]!=-1)
			{
				k=0;
				fuzhu[num++]='-';
				fuzhu[num++]='>';
				while(P->produceR[ForecastTable[i][j]][k]!=-1)
				{
					fuzhu[num++]=P->symbol[P->produceR[ForecastTable[i][j]][k]];
					k++;
				}
				fuzhu[num]='\0';
				printf("%-9s",fuzhu);
				num=0;
			}
			else
				printf("%-9c",' ');
		}
		printf("\n");
	}
}

void Forecast(int **ForecastTable,struct produce *P)
{
	char str[STRINGMAXLENGTH],pro[MAXLENGTH],*c=str,fuzhu[MAXLENGTH];
	char LL[1000],s[1000];
	int n=0,n2=0;
	int top=0,j,k,num,stack[STACKLENGTH],loend,lo,i=0,fnum;
	int stringlength,place=0;
	int FZ=P->segmentation+1;
	printf("������Ҫ�����Ĵ�\n");
	fflush(stdin);
	gets(str);
	fflush(stdin);
	stringlength=strlen(str);
	if(str[stringlength]!='#')			//��Ԥ���� �������βû��# ����#��
	{
		str[stringlength]='#';
		str[stringlength+1]='\0';
	}
	loend=location(P->symbol,'#',P->numberOFsym);	//��¼#���ڷ��ű��е�λ��

	stack[top++]=loend;					//#����ջ
	stack[top++]=START;					//��ʼ����ջ
	LL[n++]=P->symbol[START];
	printf("%-10s%-8s%16s%26s\n","����","����ջ","ʣ�����봮","�Ƶ����ò���ʽ��ƥ��");
	while(str[place]!='#'||stack[top-1]!=loend)		//����������Ŵ�Ϊ # �ҷ���ջ Ϊ # ʱ����ѭ��
	{
		k=stack[--top];						//��ջһ������
		if(P->symbol[k]=='0')				//�����ջ�ķ����� ��  ��ֱ������ѭ��
		{
			continue;
		}
		
		printf("%-10d",i+1);
		fnum=0;
		for(j=0;j<=top;j++)
			fuzhu[fnum++]=P->symbol[stack[j]];
		fuzhu[fnum]='\0';
		printf("%-8s%16s",fuzhu,c);
		
		lo=location(P->symbol,str[place],P->numberOFsym);
		if(lo==-1)									//���Ų����ڷ��ű�  ���������� ������
		{	
			printf("\n�����%d�����������޷�ƥ��Ԥ��\n",place+1);
			printf("������\n");
			return;
		}
		if(k>P->segmentation)		//�����ջ�������ս��
		{
			if(P->symbol[k]==str[place])	//�����ջ�����뵱ǰ������� ��ƥ�� ��Ӧ���� ��ǰ����λ������
			{
				s[n2++]=str[place];
				printf("%18c ��ƥ��\n",str[place]);
				place++;
				c++;
			}
			else							//�������
			{
				printf("\n�����%d�����������޷�ƥ��Ԥ��\n",place+1);
				printf("������\n");
				return;
			}
		}
		else								
		{
			if(ForecastTable[k][lo-FZ]==-1)	//���Ԥ����Ӧλ��Ϊ -1 �򲻽���
			{
				printf("\n�����%d�����������޷�ƥ��Ԥ��\n",place+1);
				return ;
			}
			else							//Ԥ���Ϊ -1
			{
				LL[n++]='=';
				LL[n++]='>';
				num=0;j=0;
				while(P->produceR[ForecastTable[k][lo-FZ]][j]!=-1)		//��Ԥ����в���ʽ�Ҳ��ķ��� �浽������
				{
					pro[num++]=P->symbol[P->produceR[ForecastTable[k][lo-FZ]][j]];
					
					j++;
				}
				pro[num]=STRINGEND;			//���Ͻ�β
				printf("%18c-> %s\n",P->symbol[k],pro);	//�������ʽ
			
				for(j=num-1;j>=0;j--)		//������ջ
				{
					lo=location(P->symbol,pro[j],P->numberOFsym);
					stack[top++]=lo;
				}
				for(j=0;j<n2;j++)
					LL[n++]=s[j];
				for(j=top-1;j>=1;j--)
				{
					if(P->symbol[stack[j]]!='0')
						LL[n++]=P->symbol[stack[j]];
				}
			}
		}
		i++;

	}
	LL[n++]='\0';
	printf("%-10d%-8c%16c%18s\n",i,P->symbol[stack[0]],str[place],"����");
	printf("�����Ƶ���\n");
	printf("%s\n",LL);

}



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

void menu(void)
{
	printf("\t\t\t\tLL(1)�ķ�����\n\n");
	printf("1) ¼��LL(1)�ķ�\n\n2) ���¼���LL(1)�ķ�\n\n3) �жϸ����ս���ܷ��Ƴ���\n\n4) ���First��\n\n5) ���Follow��\n\n6) ���Select��\n\n7) ���Ԥ�������\n\n8) ��������\n\n0) �˳�\n\n��ѡ��");
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
						free(P->symbol);
						for(i=0;i<P->numberOFpro;i++)
						{
							free(P->produceR[i]);
						}
						free(P->produceR);
						free(P);
					}
					P=initialize();
					H=Calculate(P);
					system("pause");system("cls");break;

			case '2':system("cls");
					if(P==NULL)
					{
						printf("�ķ�δ¼�룬�޷���ʾ������ķ�\n����¼���ķ�\n");
						system("pause");system("cls");
						break;
					}
					PrintLL1(P);
					system("pause");system("cls");break;

			case '3':system("cls");
					if(H==NULL)
					{
						printf("�ķ�δ¼�룬�޷��жϷ��ս���Ƿ����Ƴ���\n����¼���ķ�\n");
						system("pause");system("cls");
						break;
					}
					
					
					PrintEmpty(P,H->Empty);
				
					system("pause");system("cls");break;
					
			case '4':system("cls");
					if(H==NULL)
					{
						printf("�ķ�δ¼�룬�޷����First��\n����¼���ķ�\n");
						system("pause");system("cls");
						break;
					}
					PrintFirst(P,H->First,H->Empty);
					system("pause");system("cls");break;

			case '5':system("cls");
					if(H==NULL)
					{
						printf("�ķ�δ¼�룬�޷��ж����Follow��\n����¼���ķ�\n");
						system("pause");system("cls");
						break;
					}
					PrintFollow(P,H->Follow);
					system("pause");system("cls");break;

			case '6':system("cls");
					if(H==NULL)
					{
						printf("�ķ�δ¼�룬�޷����Select��\n����¼���ķ�\n");
						system("pause");system("cls");
						break;
					}
					PrintSelect(P,H->Select);
					system("pause");system("cls");break;

			case '7':system("cls");
					if(H->ForecastTable==NULL)
					{
						printf("���ķ�����LL(1)�ķ����޷����Ԥ�������\n");
						system("pause");system("cls");
						break;
					}
					PrintForecastTable(P,H->ForecastTable);
					system("pause");system("cls");break;

			case'8':system("cls");
					if(P==NULL)
					{
						printf("�ķ�δ¼�룬�޷�����\n����¼���ķ�\n");
						break;
					}
					if(H->ForecastTable==NULL)
					{
						printf("���ķ�����LL(1)�ķ����޷�����Ԥ�����\n");
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
		free(P->symbol);
		for(i=0;i<P->numberOFpro;i++)
		{
			free(P->produceR[i]);
		}
		free(P->produceR);
		free(P);
	}
	return 0;
}

