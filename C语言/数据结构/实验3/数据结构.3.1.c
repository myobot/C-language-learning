#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
struct stack
{
	double shu;
	struct stack *next;
};
struct stack2
{
	char fu;
	int level;
	struct stack2 *next;
};
struct stack * chushihua(void)
{
	struct stack *p;
	p=(struct stack *)malloc(sizeof(struct stack));
	p->next=NULL;
	return p;
}
struct stack2 * chushihua2(void)
{
	struct stack2 *p,*p2;
	p=(struct stack2 *)malloc(sizeof(struct stack2));
	p->next=NULL;
	p2=(struct stack2 *)malloc(sizeof(struct stack2));
	p2->fu='#';
	p2->level=-2;
	p->next=p2;
	p2->next=NULL;
	return p;
}
int kong(struct stack *top)
{
	return top->next==NULL;
}
int kong2(struct stack2 *top2)
{
	return top2->next==NULL;
}
void push(struct stack *top,double s)
{
	struct stack *New;
	New=(struct stack *)malloc(sizeof(struct stack));
	New->shu=s;
	New->next=top->next;
	top->next=New;
}
void push2(struct stack2 *top2,char f,int level)
{
	struct stack2 *New;
	New=(struct stack2 *)malloc(sizeof(struct stack2));
	if(f=='(')
	{
		New->fu=f;
		New->level=-1;										//( 进栈level变低
	}
	else
	{
		New->fu=f;
		New->level=level-1;									//进栈level 降低1
	}
	New->next=top2->next;
	top2->next=New;
}
int out(struct stack *top,double *yi,double *er)
{
	struct stack *p,*p2;
	if(kong(top))
		return 0;
	else
	{
		p=top->next;
		*yi=p->shu;
		top->next=p->next;
		free(p);
		p2=top->next;
		*er=p2->shu;
		top->next=p2->next;
		free(p2);
	}
	return 1;
}
int out2(struct stack2 *top2,char *f)
{
	struct stack2 *p;
	if(kong2(top2))
		return 0;
	else
	{
		p=top2->next;
		*f=p->fu;
		top2->next=p->next;
		free(p);
	}
	return 1;
}
double chengfang(double *yi,double *er)
{
	double daan=1;
	int i;
	for(i=0;i<*er;i++)
	{
		daan=daan*(*yi);
	}
	return daan;
}
double jisuan(double *yi,double *er,char *fu)
{
	double daan;
	switch(*fu)
	{
		case '+':daan=*er+(*yi);break;
		case '-':daan=*er-(*yi);break;
		case '*':daan=*er*(*yi);break;
		case '/':daan=*er/(*yi);break;
		case '^':daan=chengfang(er,yi);break;
	//	case '%':daan=*er%*yi;break;                 //double 不能取余。
	}
	return daan;
}

int main()
{
	int i=0,j,k,mark,js,level;
	double shu[2],xiaoshu,sum;
	char fu,bds[50],c[2],*huanchong,p;
	struct stack *top;
	struct stack2 *top2;
	printf("请输入要计算的表达式:\n");
	gets(bds);
	c[0]='#';
	c[1]='\0';
	huanchong=&p;
	strcat(bds,c);
	top=(struct stack *)malloc(sizeof(struct stack));
	top2=(struct stack2 *)malloc(sizeof(struct stack2));
	top=chushihua();
	top2=chushihua2();
	while(1)
	{	
		sum=0;mark=0;js=0;
		while(bds[i]>=48&&bds[i]<=57||bds[i]==46)
		{
			if(bds[i]=='.')
			{
				mark++;i++;continue;
			}
			if(mark==0)
			{
				j=bds[i]-48;
				sum=sum*10+j;
			}
			if(mark==1)
			{
				js++;
				j=bds[i]-48;
				xiaoshu=(double)j;
				for(k=0;k<js;k++)
				{
					xiaoshu=xiaoshu/10;
				}
				sum=sum+xiaoshu;
			}
			if(mark>1)
			{
				printf("表达式有误!程序结束\n");
				return 0;
			}
			i++;
		}
		if(sum!=0)
		{
			push(top,sum);
		}
		fu=bds[i];
		switch(fu)
		{
			case '+':level=1;break;
			case '-':level=3;break;					//加法中有减法先算减法
			case '*':level=5;break;
			case '/':level=7;break;					//有除法先算除法
	//		case '%':level=7;break;		
			case '^':level=9;break;
			case '(':level=10;break;					
			case ')':level=-1;break;
			case '#':level=-2;break;
			default:printf("表达式输入有误！程序结束\n");return 0;
		}
		if(level>top2->next->level)
		{
			push2(top2,fu,level);
		}
		if(level==top2->next->level)
		{
			out2(top2,huanchong);
		}
		if(level<top2->next->level)
		{
			while(level<top2->next->level)
			{
				out2(top2,huanchong);
				out(top,&shu[0],&shu[1]);
				sum=jisuan(&shu[0],&shu[1],huanchong);
				push(top,sum);
			}
			if(level==top2->next->level)
			{
				out2(top2,huanchong);
			}
			if(fu!=')'&&top2->next!=NULL)
			{
				if(level>top2->next->level)
					push2(top2,fu,level);
			}
		}
		if(bds[++i]=='\0')
			break;
	}
	if(top->next->next!=NULL||top2->next!=NULL)			//有一个满足就表明表达式有误
	{
		printf("表达式有误，程序结束\n");return 0;
	}
	else
	{
		printf("答案为:%4lf\n",top->next->shu);
	}
	return 0;
}


				
		







	
