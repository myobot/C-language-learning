#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char zqsr(char *c);
struct tree
{
	int shu;						//小于祖先，放左边，大于放右边
	int num;
	struct tree *father;
	struct tree *leftson;
	struct tree *rightson;
};
struct stack2
{
	struct tree *x;
	int mark;
};
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
struct tree *chutree(void)
{
	struct tree *root;
	int x;
	printf("请输入第一个数，作为树根:\n");
	scanf("%d",&x);
	fflush(stdin);
	root=(struct tree *)malloc(sizeof(struct tree));
	if(root==NULL)
	{
		printf("内存不足，初始化失败!\n");
		return NULL;
	}
	else
	{   
		root->shu=x;
		root->num=1;
		root->father=NULL;
		root->leftson=NULL;
		root->rightson=NULL;
	}
	return root;
}
void shuchu(struct tree *root, int x)
{
	int i;
	if(root!=NULL)
	{
		for(i=0;i<x;i++)
			printf("\t");
		printf("%d (%d个)\n",root->shu,root->num);
		shuchu(root->leftson,x+1);
		shuchu(root->rightson,x+1);
	}
}
int charu(struct tree *root)
{
	struct tree *p,*New;
	int mark=0;
	int x;
	printf("请输入要插入的数:\n");
	scanf("%d",&x);
	fflush(stdin);
	p=root;
	for(;;)
	{
		if(x<p->shu)
		{
			if(p->leftson==NULL)
			{
				mark=1;
				break;
			}
			p=p->leftson;
		}
		else if(x>p->shu)
		{
			if(p->rightson==NULL)
			{
				mark=2;
				break;
			}
			p=p->rightson;
		}
		else
		{
			mark=3;
			break;
		}
	}
	if(mark==1||mark==2)
	{
		New=(struct tree *)malloc(sizeof(struct tree));
		if(New==NULL)
		{
			printf("内存不足，插入失败!\n");
			return 0;
		}
		New->rightson=NULL;
		New->leftson=NULL;
		New->shu=x;
		New->num=1;
		if(mark==1)
			p->leftson=New;
		else
			p->rightson=New;
		New->father=p;
	}
	else
	{
		p->num++;
	}
	return 1;
}
struct tree *zhikong(struct tree *root)
{
	if(root!=NULL)
	{
		zhikong(root->leftson);
		zhikong(root->rightson);
		free(root);
	}
	return NULL;
}
void shuchu2(struct tree *root)
{
	if(root!=NULL)
	{
		shuchu2(root->leftson);
		printf("%4d",root->shu);
		shuchu2(root->rightson);
		
	}
}
int shuchu3(struct tree *root)
{
	struct tree *stack[1000],*p;
	int top,d=0,i;
	top=-1;
	p=root;
	if(root==NULL)
		return 0;
	else
	{
		while(p!=NULL||top!=-1)
		{
			while(p!=NULL)
			{

				stack[++top]=p;
				d++;
				p=p->leftson;
			};
			if(top==-1)
				return 1;
			else
			{
				p=stack[top--];
				for(i=0;i<d;i++)
					printf("\t");
				printf("%d\n",p->shu);
				d--;
				p=p->rightson;
			}
		}
	}
	return 1;
}
int shuchu4(struct tree *root)
{
	int top;
	struct stack2 Stack[1000];
	struct tree *p;
	if(root==NULL)
		return 0;
	else
	{
		p=root;
		top=-1;
		while(top!=-1||p!=NULL)
		{	
			while(p)
			{
				Stack[++top].x=p;
				Stack[top].mark=1;
				p=p->leftson;
			}
			if(top==-1)
				return 0;
			else
			{
				while(Stack[top].mark==2)
				{
					p=Stack[top--].x;
					printf("%d",p->shu);
				}
				p=Stack[top].x;
				Stack[top].mark=2;
				p=p->rightson;
			}
		}
	}
	return 1;
}
int main()
{
	int mark;
	char xz;
	struct tree *root;
	for(;;)
	{
		mark=0;
		printf("1)初始化树\n\n2)插入元素\n\n3)输出树\n\n4)置空树\n\n5)顺序输出\n\n0)退出\n");
		xz=zqsr("123450");
		switch (xz)
		{
			case '1':root=chutree();break;
			case '2':charu(root);break;
			case '3':shuchu(root,0);break;
			case '4':root=zhikong(root);break;
			case '5':shuchu4(root);break;
			case '0':mark=1;break;
		}
		system("pause");
		system("cls");
		if(mark==1)
			break;
	}
	return 0;
}

