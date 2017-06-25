/*
------����------��ռΰ
------ʱ��------20160505
------����------LR(0)�ķ�����
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<set>

using std::set;
using std::set<int>;

#define MAXLENGTH 20		//����ʽ��󳤶�
#define WRONG -1			//�������λ��
#define END -1				//����ʽ������
#define MAXPROJECTSET 20	//��Ŀ������Ŀ�������
#define MAXSTATUS 50		//״̬�������
#define ENDSTATUS 0			//�ս�״̬
#define NOTENDSTATUS 1		//���ս�״̬
#define BEGINS	'$'			//����S' Ϊ $ ��
#define ACC -3				//���ܱ�־
#define GUIYUE -2			//��Լ��־
#define MAXSTACK 200		//����ջ�������
#define MAXSTRING 200		//����������󳤶�
struct produce
{
	int **produceR;		//����ʽ�Ҳ�
	int *produceL;		//����ʽ��
	char *symbol;		//���з���
	int segmentation;	//���ս���-1
	int numberOFpro;
	int numberOFsym;
};

struct projectset
{
	int ps[MAXPROJECTSET][2];	//��Ŀ��	[0]����ʽλ�ã�[1]��λ��
	int n;						//����
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


struct projectset CORE[MAXSTATUS];					//��
int CORENUMBER=0;									//����
int STATUSTRANSFORM[MAXSTATUS][MAXSTATUS][3];		//[0]����  [1]�����״̬   [2]����״̬��״̬
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
	printf("��������ս�������ͷ�������(���Ÿ���,����һ���ս��): ");
	while(scanf("%d,%d",&P->segmentation,&P->numberOFsym)!=2||P->segmentation<=0||P->numberOFsym<=0)
	{
		fflush(stdin);printf("��������ȷ����������������\n");
	}
	fflush(stdin);
	P->numberOFsym++;
	P->numberOFsym++;
	P->symbol=(char *)malloc(sizeof(char)*P->numberOFsym);
	system("cls");
	printf("��������ս���ţ�ÿ��һ��(���һ������ ��ʼ��)\n");
	for(i=1;i<=P->segmentation;i++)
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
	P->symbol[0]='$';
	system("cls");
	printf("���������ʽ����: ");
	while(scanf("%d",&P->numberOFpro)!=1||P->numberOFpro<=0)
	{
		fflush(stdin);printf("��������ȷ����������������\n");
	}
	system("cls");
	fflush(stdin);
	P->numberOFpro++;
	P->produceR=(int **)malloc(sizeof(int *)*P->numberOFpro);
	P->produceL=(int *)malloc(sizeof(int)*P->numberOFpro);

	P->produceR[0]=(int *)malloc(sizeof(int)*MAXLENGTH);	//����S'->E
	P->produceL[0]=0;
	P->produceR[0][0]=1;
	P->produceR[0][1]=END;

	for(i=1;i<P->numberOFpro;i++)
	{
		printf("���������ʽ:(���Ҳ���->����)(���� 0 ��ʾ)\n");
		P->produceR[i]=(int *)malloc(sizeof(int)*MAXLENGTH);
		while(1)
		{
			gets(c);
			if(c[1]!='-'||c[2]!='>')
			{
				printf("������������������:\n");
				continue;
			}
			if(location(P->symbol,c[0],P->numberOFsym)>P->segmentation)
			{
				printf("��������(����ʽ������ֻ��һ�����ս��),����������\n");
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
					printf("�˲���ʽ���зǷ����ţ�����������:\n");
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
	int i,j,k,n1=0,n2=p.n,mark,mark2;	//n1 ��¼ǰһ��ѭ�������еĸ���	n2��¼ѭ����ĸ���
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
		for(i=n1;i<n2;i++)							//���¼ӵĵط���ʼ
		{
			if(P->produceR[N.ps[i][0]][N.ps[i][1]]<=P->segmentation)
			{
				for(j=1;j<P->numberOFpro;j++)		//�ӵ�һ������ʽ��ʼ
				{
					mark2=0;
					if(P->produceL[j]==P->produceR[N.ps[i][0]][N.ps[i][1]])
					{
						for(k=0;k<num;k++)			//�ų�����ӵ�
						{
							if(N.ps[k][0]==j&&N.ps[k][1]==0)
							{
								mark2=1;
								break;
							}
						}
						if(mark2==1)
							continue;
						N.ps[num][0]=j;				//������Ŀ��
						N.ps[num++][1]=0;
						mark=1;
					}
				}
			}
		}
		n1=n2;
		n2=num;
		if(mark==0)								//���û���ٸı� ����ѭ��
			break;
	}
	N.n=num;
	return N;
}


struct projectset GO(struct produce *P,struct projectset I,int x,int status,int &place)	//I ǰһ����Ŀ��  x ����λ��  status ǰһ����Ŀ����״̬λ��  place ��һ����Ŀ����״̬λ��
{
	int i,j,mark=0;
	int position=0;
	int fuzhu[MAXLENGTH],num=0;
	struct projectset J;
	J.n=0;
	for(i=0;i<I.n;i++)
	{
		if(P->produceR[I.ps[i][0]][I.ps[i][1]]==x)		//�ҵ������x �� λ��
		{
			fuzhu[num++]=i;
		}
	}
	if(num==0)											//û�з��ؿ�
		return J;
	else
	{
		for(i=0;i<num;i++)								//���ҵ��ļ�����Ŀ��
		{
			J.ps[i][0]=I.ps[fuzhu[i]][0];
			J.ps[i][1]=I.ps[fuzhu[i]][1]+1;
			J.n++;
		}

		for(j=0;j<CORENUMBER;j++)	//�˼��
		{
			if(CORE[j]==J)			//���������
			{
				position=j;
				mark=1;			
				break;
			}
		}
		if(position==0)				//���û�кˣ��½���
		{
			position=CORENUMBER;
			CORE[CORENUMBER++]=J;
		}
		

		STATUSTRANSFORM[status][STNUMBER[status]][0]=x;			//���� ���� ��״̬ת�����Ӧλ��
		STATUSTRANSFORM[status][STNUMBER[status]][1]=position;	//����״̬

		if(P->produceR[J.ps[0][0]][J.ps[0][1]]==-1)				//������ս�״̬
		{
			STATUSTRANSFORM[status][STNUMBER[status]++][2]=ENDSTATUS;	//��־��Ϊ�ս�
			CORE[position].mark=ENDSTATUS;
		}
		else
		{
			STATUSTRANSFORM[status][STNUMBER[status]++][2]=NOTENDSTATUS;
			CORE[position].mark=NOTENDSTATUS;
		}
		if(mark==0)				//������µĺ� ����հ�
			J=CLOSURE(P,J);										
		else					//���򷵻ؿ�	//�������		
		{	
			J.n=0;	
			return J;			
		}
		place=position;			//��¼�˺˵�״̬λ��
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
	
	status=CORENUMBER;		//��ʼ����һ��״̬
	CORE[CORENUMBER++]=a;

	b=CLOSURE(P,a);			//��CLOSURE��S'->.E��
	rudui(Q,b,status);
	
	while(!kong(Q))
	{
		chudui(Q,b,status);
		if(b.n==1)
		{
			if(P->produceR[b.ps[0][0]][b.ps[0][1]]==-1)		//������ս�״̬ ����ѭ��
				continue;
		}
		for(i=0;i<P->numberOFsym;i++)
		{
			c=GO(P,b,i,status,place);
			if(c.n>0)										//������صĲ��������
				rudui(Q,c,place);
		}
	}
}

int *** CalculateAnalysisTable(struct produce *P)			//�ƽ�	[0]ת�Ƶ���״̬[1]ת�Ƶ���״̬��״̬	��Լ   [0]ʹ�õĲ���ʽ [1]��־
{
	int i,j,***analysistable;
	int lofe=location(P->symbol,'#',P->numberOFsym);
	analysistable=(int ***)malloc(sizeof(int **)*CORENUMBER);
	for(i=0;i<CORENUMBER;i++)
	{
		analysistable[i]=(int **)malloc(sizeof(int*)*P->numberOFsym-1);
		for(j=1;j<P->numberOFsym;j++)		//���Ե�һ�� S'($)
		{
			analysistable[i][j]=(int *)malloc(sizeof(int)*2);
			analysistable[i][j][0]=-1;
			analysistable[i][j][1]=-1;
		}
		if(CORE[i].mark==ENDSTATUS)			//������״̬���ս�״̬�������з��Ŷ���Ϊ��Լ
		{
			for(j=P->segmentation+1;j<P->numberOFsym;j++)
			{
				analysistable[i][j][0]=CORE[i].ps[0][0];
				analysistable[i][j][1]=GUIYUE;			//��־
			}
		}
		else								//��������ս�״̬������Ӧλ����Ϊת��
		{
			for(j=0;j<STNUMBER[i];j++)
			{
				analysistable[i][STATUSTRANSFORM[i][j][0]][0]=STATUSTRANSFORM[i][j][1];
				analysistable[i][STATUSTRANSFORM[i][j][0]][1]=STATUSTRANSFORM[i][j][2];
			}
		}
	}
	for(i=0;i<CORENUMBER;i++)				//�ҵ�����״̬
	{
		if(CORE[i].ps[0][0]==0&&CORE[i].ps[0][1]==1)
			break;
	}
	for(j=1;j<P->numberOFsym-1;j++)			//���³�ʼ������״̬
	{
		analysistable[i][j][0]=-1;
		analysistable[i][j][1]=-1;
	}
	analysistable[i][lofe][0]=ACC;			//#��Ϊ����
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
		printf("״̬%d : \n",i);
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
			printf("��λ�ã�%d\n",CORE[i].ps[j][1]);
		}
		printf("}\n");
		for(j=0;j<STNUMBER[i];j++)
		{
			if(STATUSTRANSFORM[i][j][2]==ENDSTATUS)
				printf("(%c)->״̬%d (��ֹ״̬)\n",P->symbol[STATUSTRANSFORM[i][j][0]],STATUSTRANSFORM[i][j][1]);
			else
				printf("(%c)->״̬%d (����ֹ״̬)\n",P->symbol[STATUSTRANSFORM[i][j][0]],STATUSTRANSFORM[i][j][1]);
		}
	}
}

void PrintAnalysisTable(struct produce *P,int ***analysistable)
{
	int i,j;
	printf("%6s","״̬");
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
	printf("������Ҫ�����Ĵ�(�벻Ҫ����%d��)\n",MAXSTRING);
	gets(str);
	fflush(stdin);
	length=strlen(str);
	if(str[length]!='#')			//��Ԥ���� �������βû��# ����#��
	{
		str[length]='#';
		str[length+1]='\0';
	}
	stackofstatus[++top]=0;
	stackofsymbol[top]=lofe;
	printf("%-6s%7s             %5s     %10s     %10s     \n","����","״̬ջ","����ջ","���봮","ACTION");
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
				printf("����\n");
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
			for(i=0;i<j;i++)		//��ջ
				top--;

			if(analysistable[stackofstatus[top]][P->produceL[k]][0]==-1)
			{
				printf("���봮�����޷�����\n");
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
				printf("���봮�����޷�����\n");
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
		puts("������������ȷѡ��:");
		xz=getchar();
		fflush(stdin);
	}
	return xz;
}

void menu(void)
{
	printf("\t\t\t\tLR(0)����\n\n");
	printf("1) ¼��LR(0)�ķ�\n\n2) ���¼���LR(0)�ķ�\n\n3) ���״̬ת����\n\n4) ���������\n\n5) ��������\n\n0) �˳�\n\n��ѡ��");
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
					PrintAnalysisTable(P,analysistable);
					system("pause");system("cls");break;

			case '5':system("cls");
					if(P==NULL)
					{
						printf("�ķ�δ���룬�޷����Ԥ�������\n");
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
