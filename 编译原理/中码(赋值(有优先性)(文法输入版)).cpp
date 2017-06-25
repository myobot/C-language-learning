/*----------------------------
------����------��ռΰ
------ʱ��------20160521
------����------����LR(1)���м�������ɣ��򵥸�ֵ���
˵����
	ʹ�õ��ķ���
		�������ķ�( �ӳ����� ).txt
	��
------------------------------*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSYMBOLLENGTH 15	//������󳤶�
#define MAXLENGTH 50		//����ʽ��󳤶�
#define WRONG -1			//�������λ��
#define END -1				//����ʽ������
#define STRINGEND '\0'		//�ַ�����β
#define STRINGCUT ' '		//���ʷָ���
#define MAXPROJECTSET 20	//��Ŀ������Ŀ�������
#define MAXSTATUS 50		//״̬�������
#define ENDSTATUS 0			//�ս�״̬
#define NOTENDSTATUS 1		//���ս�״̬
#define BEGINS	'$'			//����S' Ϊ $ ��
#define ACC -3				//���ܱ�־
#define GUIYUE -2			//��Լ��־
#define MAXSTACK 200		//����ջ�������
#define MAXSTRING 200		//����������󳤶�
#define MAX 100
#define EMPTY '0'
#define UNDEFINE -1
#define CANEMPTY 1		//���Ƴ���
#define CANNOTEMPTY 0	//�����Ƴ���
#define MAXNUM 50
#define UNVISITED 0		//ͼ��������δ����״̬
#define VISITED 1		//ͼ���������ѷ���״̬
#define MAXNUMBER 100	//�����м����ʱ������������
#define ERROR -1			//����

struct produce
{
	int **produceR;		//����ʽ�Ҳ�
	int *produceL;		//����ʽ��
	char **symbol;		//���з���
	int segmentation;	//���ս���-1
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
	int ps[MAXPROJECTSET][2];	//��Ŀ��	[0]����ʽλ�ã�[1]��λ��
	int n;						//����
	int mark;
	int FS[MAXPROJECTSET][MAXLENGTH];				//��ǰ��������
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





struct projectset CORE[MAXSTATUS];					//��
int CORENUMBER=0;									//����
struct projectset STATUS[MAXSTATUS];
int STATUSTRANSFORM[MAXSTATUS][MAXSTATUS][3];		//[0]����  [1]�����״̬   [2]����״̬��״̬
int STNUMBER[MAXSTATUS];

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
		printf("�ڴ治�㣬�޷������\n");
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
		printf("�ж�Ϊ�գ��޷�����!\n");
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
	printf("��������ս�������ͷ�������(���Ÿ���,����һ���ս��): ");
	while(scanf("%d,%d",&P->segmentation,&P->numberOFsym)!=2||P->segmentation<=0||P->numberOFsym<=0)
	{
		fflush(stdin);printf("��������ȷ����������������\n");
	}
	fflush(stdin);
	P->numberOFsym++;
	P->numberOFsym++;
	P->symbol = (char **)malloc(sizeof(char*)*P->numberOFsym);

	system("cls");
	printf("��������ս���ţ�ÿ��һ��(���һ������ ��ʼ��)\n");
	for (i = 1; i <= P->segmentation; i++)
	{

		P->symbol[i]=(char *)malloc(sizeof(char)*MAXSYMBOLLENGTH);
		gets(P->symbol[i]);
		fflush(stdin);
	}
	system("cls");
	printf("�������ս����:\n");
	for (i = P->segmentation + 1; i<P->numberOFsym - 1; i++)
	{
		P->symbol[i]=(char *)malloc(sizeof(char)*MAXSYMBOLLENGTH);
		gets(P->symbol[i]);
		fflush(stdin);

	}
	system("cls");

	P->symbol[i]=(char *)malloc(sizeof(char)*MAXSYMBOLLENGTH);
	P->symbol[i][0] = '#';		//������ #
	P->symbol[i][1]=STRINGEND;
	P->symbol[0]=(char *)malloc(sizeof(char)*MAXSYMBOLLENGTH);
	P->symbol[0][0] = '$';
	P->symbol[0][1]=STRINGEND;

	system("cls");
	printf("���������ʽ����: ");
	while(scanf("%d",&P->numberOFpro)!=1||P->numberOFpro<=0)
	{
		fflush(stdin);printf("��������ȷ����������������\n");
	}
	system("cls");
	fflush(stdin);

	P->numberOFpro++;
	P->produceR = (int **)malloc(sizeof(int *)*P->numberOFpro);
	P->produceL = (int *)malloc(sizeof(int)*P->numberOFpro);

	P->produceR[0] = (int *)malloc(sizeof(int)*MAXLENGTH);	//����S'->E
	P->produceL[0] = 0;
	P->produceR[0][0] = 1;
	P->produceR[0][1] = END;

	for (i = 1; i<P->numberOFpro; i++)
	{
		printf("���������ʽ:(���Ҳ���->����)(���� 0 ��ʾ)(ÿ������֮���ÿո����)\n");
		P->produceR[i] = (int *)malloc(sizeof(int)*MAXLENGTH);
		while (1)
		{
			place=0;
			gets(c);
			length=strlen(c);
			place=getword(c,word,place,length);

			if(location(P->symbol,word,P->numberOFsym)>P->segmentation)	//��һ�����Ƿ��ս��
			{
				printf("��������(����ʽ������ֻ��һ�����ս��),����������\n");
				continue;
			}
			P->produceL[i]=location(P->symbol,word,P->numberOFsym);

			place=getword(c,word,place,length);
			if(word[0]!='-'||word[1]!='>')		//û��->
			{
				printf("������������������:\n");
				continue;
			}
			
			mark=0;j=0;
			while(place!=length)				//���з��ű�����ķ���
			{
				place=getword(c,word,place,length);

				P->produceR[i][j]=location(P->symbol,word,P->numberOFsym);
				if(P->produceR[i][j]==WRONG)
				{
					printf("�˲���ʽ���зǷ����ţ�����������:\n");
					mark=1;
					break;
				}
				j++;
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
	int *E, *Efuzhu, i, j, *F, lofe, mark, mark2;		//lofe�յ�λ��
	char empty[2]={"0"};
	E = (int *)malloc(sizeof(int)*(P->segmentation + 1));
	Efuzhu = (int *)malloc(sizeof(int)*(P->segmentation + 1));
	F = (int *)malloc(sizeof(int)*(P->numberOFpro));
	lofe = location(P->symbol, empty, P->numberOFsym);
	for (i = 0; i<P->segmentation + 1; i++)
	{
		E[i] = UNDEFINE;						//���ս��mark
		Efuzhu[i] = 0;
	}
	for (i = 0; i<P->numberOFpro; i++)
	{
		F[i] = 1;							//����ʽmark
		Efuzhu[P->produceL[i]]++;
	}
	for (i = 0; i<P->numberOFpro; i++)
	{
		if (F[i] != 0)
		{
			j = 0;
			while (P->produceR[i][j] != END)	//����Ҳ������ս���Ҳ��ǿգ���ɾ���ò���ʽ
			{
				if (P->produceR[i][j] != lofe&&P->produceR[i][j]>P->segmentation)
				{
					F[i] = 0;
					Efuzhu[P->produceL[i]]--;
					break;
				}
				j++;
			}
			if (P->produceR[i][0] == lofe)		//�Ҳ�Ϊ�գ����󲿷��ս�����Ƴ��գ���ɾ��������Ϊ���ս���Ĳ���ʽ
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
					if (E[P->produceR[i][j]] == UNDEFINE)		//�������δ��
					{
						mark = 1;
					}
					j++;
				}
				if (mark == 0)		//���Ƴ���
				{
					E[P->produceL[i]] = CANEMPTY;		//��1
					for (j = 0; j<P->numberOFpro; j++)	//ɾ��������Ϊ�˷��ս���Ĳ���ʽ
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
				for (j = 0; j<P->segmentation + 1; j++)	//�����ɾ����ĳһ�����ս����δ��������0
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
		if (mark2 == 0)		//�������û���ڸı����
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
	for (i = 0; i<P->segmentation + 1; i++)			//��ÿ�����ս��
	{
		for (j = 0; j<P->numberOFpro; j++)			//��ÿ������ʽ
		{
			if (P->produceL[j] == i)				//���Ǹ÷��ս��	
			{
				k = 0;
				if (P->produceR[j][k] <= P->segmentation)	//����󲿵�һ�� �Ƿ��ս��
				{
					if (Empty[P->produceR[j][k]] == CANEMPTY)		//����󲿵�һ�����ս�������Ƴ���
					{

						s = (struct node *)malloc(sizeof(struct node));
						s->ldd = P->produceR[j][k];
						s->next = g->adlist[i].firstnode;		//����ͼ ���ս��first��������һ�����ս��first��
						g->adlist[i].firstnode = s;
						k++;
						while (P->produceR[j][k] != END)		//�鿴��������
						{
							if (P->produceR[j][k] <= P->segmentation&&Empty[P->produceR[j][k]] == CANEMPTY)	//�����Ϊ���ս�������Ƴ��� 
							{
								s = (struct node *)malloc(sizeof(struct node));
								s->ldd = P->produceR[j][k];
								s->next = g->adlist[i].firstnode;
								g->adlist[i].firstnode = s;
								k++;						//ֻ�����Ƴ��ղ����ɨ��
							}
							else if (P->produceR[j][k] <= P->segmentation&&Empty[P->produceR[j][k]] == CANNOTEMPTY)	//�����δ���ս���Ҳ����Ƴ��գ�������
							{
								s = (struct node *)malloc(sizeof(struct node));
								s->ldd = P->produceR[j][k];
								s->next = g->adlist[i].firstnode;
								g->adlist[i].firstnode = s;
								break;
							}
							else								//���Ϊ�ս����������
							{
								s = (struct node *)malloc(sizeof(struct node));
								s->ldd = P->produceR[j][k] + (P->segmentation + 1);					//ָ��ͼ�ж�Ӧ�ս��λ��
								s->next = g->adlist[i].firstnode;
								g->adlist[i].firstnode = s;
								break;
							}
						}
					}
					else								//�����һ���Ƿ��ս���Ҳ����Ƴ���
					{

						s = (struct node *)malloc(sizeof(struct node));
						s->ldd = P->produceR[j][k];
						s->next = g->adlist[i].firstnode;
						g->adlist[i].firstnode = s;

					}
				}
				else									//�����һ�����ս�������Կղ���ʽ��
				{
					if (P->produceR[j][k] != lofe)
					{
						s = (struct node *)malloc(sizeof(struct node));
						s->ldd = P->produceR[j][k] + (P->segmentation + 1);							//ָ��ͼ�ж�Ӧ�ս��λ��
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
	s->next = g->adlist[P->segmentation + 1].firstnode;				//S ��follow������ #
	g->adlist[P->segmentation + 1].firstnode = s;

	for (i = P->segmentation + 1; i<(P->segmentation + 1) * 2; i++)			//��ÿ�����ս����follow��λ�ã�
	{
		for (j = 0; j<P->numberOFpro; j++)								//��ÿ������ʽ
		{
			k = 0;
			while (P->produceR[j][k] != (i - FZ) && P->produceR[j][k] != END)		//�ҵ��ò���ʽ�Ҳ��ĸ÷��ս��
			{
				k++;
			}
			if (P->produceR[j][k] != END)								//��������÷��ս��
			{
				k++;
				if (P->produceR[j][k] == END)								//���ֱ�Ӿ���ĩβ
				{
					s = (struct node *)malloc(sizeof(struct node));
					s->ldd = P->produceL[j] + (P->segmentation + 1);			//���󲿷��ս����follow����ӵ��÷��ս����follow��
					s->next = g->adlist[i].firstnode;
					g->adlist[i].firstnode = s;
				}
				else													//����ĩβ
				{
					if (P->produceR[j][k] <= P->segmentation)				//��һ������Ƿ��ս��
					{
						if (Empty[P->produceR[j][k]] == CANEMPTY)					//�����һ���ս�����Ƴ���
						{
							s = (struct node *)malloc(sizeof(struct node));
							s->ldd = P->produceR[j][k];
							s->next = g->adlist[i].firstnode;				//����ͼ ���ս��follow���������ս��first��
							g->adlist[i].firstnode = s;
							k++;
							while (P->produceR[j][k] != END)				//ɨ��������ķ���
							{
								if (P->produceR[j][k] <= P->segmentation&&Empty[P->produceR[j][k]] == CANEMPTY)	//�����Ϊ���ս�������Ƴ��� 
								{
									s = (struct node *)malloc(sizeof(struct node));
									s->ldd = P->produceR[j][k];
									s->next = g->adlist[i].firstnode;
									g->adlist[i].firstnode = s;
									k++;
								}
								else if (P->produceR[j][k] <= P->segmentation&&Empty[P->produceR[j][k]] == CANNOTEMPTY)	//�����δ���ս���Ҳ����Ƴ��գ�������
								{
									s = (struct node *)malloc(sizeof(struct node));
									s->ldd = P->produceR[j][k];
									s->next = g->adlist[i].firstnode;
									g->adlist[i].firstnode = s;
									break;
								}
								else									//���Ϊ�ս����������
								{
									s = (struct node *)malloc(sizeof(struct node));
									s->ldd = P->produceR[j][k] + (P->segmentation + 1);					//ָ��ͼ�ж�Ӧ�ս��λ��
									s->next = g->adlist[i].firstnode;
									g->adlist[i].firstnode = s;
									break;
								}
							}
							if (P->produceR[j][k] == END)								//���ֱ������
							{
								s = (struct node *)malloc(sizeof(struct node));
								s->ldd = P->produceL[j] + (P->segmentation + 1);			//���󲿷��ս����follow����ӵ��÷��ս����follow��
								s->next = g->adlist[i].firstnode;
								g->adlist[i].firstnode = s;
							}
						}
						else											//�����һ���ս�������Ƴ���
						{
							s = (struct node *)malloc(sizeof(struct node));
							s->ldd = P->produceR[j][k];
							s->next = g->adlist[i].firstnode;				//����ͼ ���ս��follow�������˷��ս��first��
							g->adlist[i].firstnode = s;
						}
					}
					else											//�����һ�����ս��
					{
						s = (struct node *)malloc(sizeof(struct node));
						s->ldd = P->produceR[j][k] + (P->segmentation + 1);
						s->next = g->adlist[i].firstnode;					//����ͼ ���ս��follow���������ս��
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

struct picture * FreePicture(struct picture *g) //�ͷ�ͼ
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


struct EF CalculateF(struct produce *P)	//����
{
	struct picture *g;
	struct EF a;
	int i;
	char empty[2]={"0"};
	int lofe = location(P->symbol, empty, P->numberOFsym);
	g = (struct picture *)malloc(sizeof(struct picture));	//ͼ��ʼ��
	g->n = (P->segmentation + 1) + P->numberOFsym;
	g->adlist = (struct vnode *)malloc(sizeof(struct vnode)*g->n);
	for (i = 0; i<P->segmentation + 1; i++)	//First��
	{
		g->adlist[i].symbol = i;
		g->adlist[i].mark = 1;
		g->adlist[i].firstnode = NULL;
	}
	for (; i<P->segmentation + 1; i++)		//Follow��
	{
		g->adlist[i].symbol = i - (P->segmentation + 1);
		g->adlist[i].mark = 2;
		g->adlist[i].firstnode = NULL;
	}
	for (; i<g->n; i++)					//�ս����
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
void bijiao(int data[],int n)//���򣬱�֤��ǰ�����������򣬱��ں����Ƚϴ���
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

void insert(int x[],int &n,int a)	//�������ݣ���������򲻲��� ���������
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




void getfirst(int *a, int n, int **First, int *Empty,struct produce * P,int FS[MAXPROJECTSET][MAXLENGTH],int p,int n1,int &n2,int x[])	//�ĵ�first��
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
	if (i == n)	//��������Ƴ��� ���� ����S->��B,a ����ǰһ����ǰ�����������뵽����
	{
		for(start = 0;start<n1;start++)
		{
			insert(x,n2,FS[p][start]);
		}
		
	}
}

struct projectset CLOSURE(struct produce *P,struct projectset p, int **First, int *Empty)
{
	int i,j,k,e,n1=0,n2=p.n,mark,mark2;	//n1 ��¼ǰһ��ѭ�������еĸ���	n2��¼ѭ����ĸ���
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
		for(i=n1;i<n2;i++)							//���¼ӵĵط���ʼ
		{
			if(P->produceR[N.ps[i][0]][N.ps[i][1]]<=P->segmentation)
			{
				fnum = 0;
				j=N.ps[i][1];
				if(P->produceR[N.ps[i][0]][j] != END)		//��������� S->��B,a   ���ķ�����һ���ǽ�β����fuzhu���鲻���� fnum=0
				{
					j=N.ps[i][1]+1;
					while (P->produceR[N.ps[i][0]][j] != END)
					{
						fuzhu[fnum++] = P->produceR[N.ps[i][0]][j];
						j++;
					}
				}

				getfirst(fuzhu, fnum, First, Empty, P,N.FS,i,N.FSnum[i],fsn,firstseach);		//�õ�first����
						//(int *a, int n, int **First, int *Empty,struct produce * P,int FS[MAXPROJECTSET][MAXLENGTH],int p,int n1,int &n2,int x[])
				for(j=1;j<P->numberOFpro;j++)		//�ӵ�һ������ʽ��ʼ
				{
					mark2=0;
					if(P->produceL[j]==P->produceR[N.ps[i][0]][N.ps[i][1]])
					{
						for(k=0;k<N.n;k++)			//��������ӵĴ���
						{
							if(N.ps[k][0]==j&&N.ps[k][1]==0)
							{
								for(e=0;e<fsn;e++)
									insert(N.FS[k],N.FSnum[k],firstseach[e]);//���뵽��Ӧ��ǰ��������
								mark2=1;
								break;
							}
						}
						if(mark2==1)
							continue;										//����ظ����������
						N.ps[N.n][0]=j;				//������Ŀ��
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
		if(mark==0)								//���û���ٸı� ����ѭ��
			break;
	}
	return N;
}


struct projectset GO(struct produce *P, struct projectset I, int x, int status, int &place, int **First, int *Empty)	//I ǰһ����Ŀ��  x ����λ��  status ǰһ����Ŀ����״̬λ��  place ��һ����Ŀ����״̬λ��
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
		if (P->produceR[I.ps[i][0]][I.ps[i][1]] == x)		//�ҵ������x �� λ��
		{
			fuzhu[num++] = i;
		}
	}
	if (num == 0)											//û�з��ؿ�
		return J;
	else
	{
		for (i = 0; i<num; i++)								//���ҵ��ļ�����Ŀ��
		{
			J.ps[i][0] = I.ps[fuzhu[i]][0];
			J.ps[i][1] = I.ps[fuzhu[i]][1] + 1;
			for(j=0;j<I.FSnum[fuzhu[i]];j++)
				J.FS[i][j]=I.FS[fuzhu[i]][j];
			J.FSnum[i]=I.FSnum[fuzhu[i]];
			J.n++;
		}

		for (j = 0; j<CORENUMBER; j++)	//�˼��
		{
			if (CORE[j] == J)			//���������
			{
				position = j;
				mark = 1;
				break;
			}
		}
		if (position == 0)				//���û�кˣ��½���
		{
			position = CORENUMBER;
			CORE[CORENUMBER] = J;
		}
		place = position;			//��¼�˺˵�״̬λ��

		STATUSTRANSFORM[status][STNUMBER[status]][0] = x;			//���� ���� ��״̬ת�����Ӧλ��
		STATUSTRANSFORM[status][STNUMBER[status]][1] = position;	//����״̬

		for (i = 0; i < J.n; i++)
		{
			if (P->produceR[J.ps[i][0]][J.ps[i][1]] == -1 || P->produceR[J.ps[i][0]][J.ps[i][1]] == lo)			//������ս�״̬����Ϊ�ղ���ʽ 
			{
				STATUSTRANSFORM[status][STNUMBER[status]++][2] = ENDSTATUS;	//��־��Ϊ�ս�
				
				mark2 = 1;
				break;
			}
		}
		if (mark2 == 0)
		{
			STATUSTRANSFORM[status][STNUMBER[status]++][2] = NOTENDSTATUS;
			
		}
		if (mark == 0)				//������µĺ� ����հ�
		{
			J = CLOSURE(P, J,First,Empty);
			return J;
		}
		else					//���򷵻ؿ�	//�������		
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

	status = CORENUMBER;		//��ʼ����һ��״̬
	CORE[CORENUMBER] = a;
	CORE[CORENUMBER].mark = NOTENDSTATUS;
	b = CLOSURE(P, a,ef.First,ef.Empty);			//��CLOSURE��S'->.E��
	STATUS[CORENUMBER] = b;
		//��״̬���ж�  �ܷ��Լ
	mark=0;
	for (j = 0; j < STATUS[CORENUMBER].n; j++)
	{
		if (P->produceR[STATUS[CORENUMBER].ps[j][0]][STATUS[CORENUMBER].ps[j][1]] == -1|| P->produceR[STATUS[CORENUMBER].ps[j][0]][STATUS[CORENUMBER].ps[j][1]] == lo )			//������ս�״̬����Ϊ�ղ���ʽ 
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
			if (P->produceR[b.ps[0][0]][b.ps[0][1]] == -1)		//������ս�״̬ ����ѭ��
				continue;
		}
		for (i = 0; i < P->numberOFsym; i++)
		{
			if (i == lo)										//���Կղ���ʽ��go����
				continue;
			c = GO(P, b, i, status, place,ef.First,ef.Empty);
			if (c.n > 0)										//������صĲ��������
			{
				STATUS[CORENUMBER] = c;

				//��״̬���ж�
				mark=0;
				for (j = 0; j < STATUS[CORENUMBER].n; j++)
				{
					if (P->produceR[STATUS[CORENUMBER].ps[j][0]][STATUS[CORENUMBER].ps[j][1]] == -1|| P->produceR[STATUS[CORENUMBER].ps[j][0]][STATUS[CORENUMBER].ps[j][1]] == lo )			//������ս�״̬����Ϊ�ղ���ʽ 
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

int *** CalculateAnalysisTable(struct produce *P)			//�ƽ�	[0]ת�Ƶ���״̬[1]ת�Ƶ���״̬��״̬	��Լ   [0]ʹ�õĲ���ʽ [1]��־
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
		for (j = 0; j < P->numberOFsym; j++)		//���Ե�һ�� S'($)
		{
			analysistable[i][j] = (int *)malloc(sizeof(int) * 2);
			analysistable[i][j][0] = -1;
			analysistable[i][j][1] = -1;
		}
		if (STATUS[i].mark == ENDSTATUS)			//������״̬���ս�״̬��
		{
			for (j = 0; j < STNUMBER[i]; j++)
			{
				analysistable[i][STATUSTRANSFORM[i][j][0]][0] = STATUSTRANSFORM[i][j][1];
				analysistable[i][STATUSTRANSFORM[i][j][0]][1] = STATUSTRANSFORM[i][j][2];
			}
			n = 0; n2 = 0;
			for (j = 0; j < STATUS[i].n; j++)
			{
				if (P->produceR[STATUS[i].ps[j][0]][STATUS[i].ps[j][1]] == END || P->produceR[STATUS[i].ps[j][0]][STATUS[i].ps[j][1]] == lo)//����ǿɹ�Լ����ʽ����ղ���ʽ��������ǰ������λ����Ϊ��Լ
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
			for (j = 0; j < n2; j++)		//FOLLOW(A)��b=��
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
		else								//��������ս�״̬������Ӧλ����Ϊת��
		{
			for (j = 0; j < STNUMBER[i]; j++)
			{
				analysistable[i][STATUSTRANSFORM[i][j][0]][0] = STATUSTRANSFORM[i][j][1];
				analysistable[i][STATUSTRANSFORM[i][j][0]][1] = STATUSTRANSFORM[i][j][2];
			}
		}
	}
	for (i = 0; i < CORENUMBER; i++)				//�ҵ�����״̬
	{
		if (CORE[i].ps[0][0] == 0 && CORE[i].ps[0][1] == 1)
			break;
	}

	analysistable[i][lofe][0] = ACC;			//#��Ϊ����


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
		printf("״̬%d : \n",i);
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
			printf("��λ�ã�%d\n",CORE[i].ps[j][1]);
		}
		printf("}\n");
		for(j=0;j<STNUMBER[i];j++)
		{
			if(STATUSTRANSFORM[i][j][2]==ENDSTATUS)
				printf("(%s)->״̬%d (��ֹ״̬)\n",P->symbol[STATUSTRANSFORM[i][j][0]],STATUSTRANSFORM[i][j][1]);
			else
				printf("(%s)->״̬%d (����ֹ״̬)\n",P->symbol[STATUSTRANSFORM[i][j][0]],STATUSTRANSFORM[i][j][1]);
		}
	}
}

void PrintAnalysisTable(struct produce *P,int ***analysistable)
{
	int i,j;
	printf("%6s","״̬");
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

int StringPretreatment(char str[],char idtable[][MAXSYMBOLLENGTH],int &n)		//�ַ���Ԥ��������idtable
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
	if(str[length]!='#')			//��Ԥ���� �������βû��# ����#��
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

int ProductionFunction(FILE *fp,int Pnum,char idtable[][MAXSYMBOLLENGTH],int &nnumber,int &number,int p[3])	//p����λ��
{
	switch(Pnum)
	{
		case 1: emit(fp,p[1],p[0],0,1,idtable,nnumber);return 0;			//˳�� �ڶ��������ȳ�ջ
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
	int mark;		//1 ��place,0 ����place(+ - * ( ) =)
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
	int nnumber,inumber,p[3],n,number=0;	//nnumber��ǰ���еķ��Ÿ�����inumber��ʼ���еĸ�������������ķ��ţ�,number������Ÿ���

	int loend=location(P->symbol,begin,P->numberOFsym);
	int loempty=location(P->symbol,empty,P->numberOFsym);
	loid=location(P->symbol,ID,P->numberOFsym);

	FILE *fp;
	if((fp=fopen("Intermediate code.txt","w+"))==NULL)		
	{
		printf("���ļ�ʧ��!\n");
		return;
	}

	printf("������Ҫ�����Ĵ�(ÿ���������ÿո�������벻Ҫ����%d������)\n",MAXSTRING);
	gets(str);
	fflush(stdin);
	length=StringPretreatment(str,idtable,inumber);
	nnumber=inumber;




	stackofstatus[++top]=0;
	stackofsymbol[top].symbol=loend;
	printf("%-6s%7s             %5s     %10s     %10s     \n","����","״̬ջ","����ջ","���봮","ACTION");
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
				printf("����\n");
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
				printf("\n���봮�ڵ�%d���ַ�����\n",place);
				break;
			}
			if(analysistable[stackofstatus[top]][lo][0]==-1)
			{
					printf("\n���봮�ڵ�%d���ַ�����\n",place);
					break;
				}
			if(analysistable[stackofstatus[top]][lo][1]==GUIYUE)
			{
				
				printf("%11c%2c%2d",' ','R',analysistable[stackofstatus[top]][lo][0]);
				
					
				printf("  %s->",P->symbol[P->produceL[k]]);

				if(P->produceR[analysistable[stackofstatus[top]][lo][0]][0]!=loempty)		//����ǿղ���ʽ����������
				{
					j=0;
					while(P->produceR[k][j]!=-1)
					{
						printf("%s",P->symbol[P->produceR[k][j]]);
						j++;
					}
					printf("\n");
					n=0;
					for(i=0;i<j;i++)		//��ջ
					{
						if(stackofsymbol[top].mark==1)
							p[n++]=stackofsymbol[top].place;
						top--;
					}
				}
				else
					printf("��\n");

				if(analysistable[stackofstatus[top]][P->produceL[k]][0]==-1)
				{
					printf("\n���봮�ڵ�%d���ַ�����\n",place);
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
				printf("\n���봮�ڵ�%d���ַ�����\n",place);
				break;
			}
			if(analysistable[stackofstatus[ftop]][lo][0]==-1)
			{
				printf("\n���봮�ڵ�%d���ַ�����\n",place);
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
		puts("������������ȷѡ��:");
		xz=getchar();
		fflush(stdin);
	}
	return xz;
}

void menu(void)
{
	printf("\t\t\t\tLR(1)����\n\n");
	printf("1) ¼��LR(1)�ķ�\n\n2) ���¼���LR(1)�ķ�\n\n3) ���״̬ת����\n\n4) ���������\n\n5) ��������\n\n0) �˳�\n\n��ѡ��");
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
						printf("�ķ�δ���룬�޷����Ԥ�������\n");
						break;
					}
					PrintLR0(P);
					system("pause");system("cls");break;

			case '3':system("cls");
					if(P==NULL)
					{
						printf("�ķ�δ���룬�޷����Ԥ�������\n");
						break;
					}
					PrintStatusTransformTable(P);
					system("pause");system("cls");break;
					
			case '4':system("cls");
					if(analysistable==NULL)
					{
						printf("�ķ�δ���룬�޷����Ԥ�������\n");
						break;
					}
					if (analysistable == NULL)
					{
						printf("������ķ�����LR(1)�ķ����������Ԥ�������\n");
						break;
					}
					PrintAnalysisTable(P,analysistable);
					system("pause");system("cls");break;

			case '5':system("cls");
					if(P==NULL)
					{
						printf("�ķ�δ���룬�޷��������\n");
						break;
					}
					if (analysistable == NULL)
					{
						printf("������ķ�����LR(1)�ķ������ܷ���\n");
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
