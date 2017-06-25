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
	int mark;						//mark记录是否经过左子树
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
void dxianxu(struct tree *root, int x)
{
	int i;
	if(root!=NULL)
	{
		for(i=0;i<x;i++)
			printf("\t");
		printf("%d (%d个)\n",root->shu,root->num);
		dxianxu(root->leftson,x+1);
		dxianxu(root->rightson,x+1);
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
void dzhongxu(struct tree *root)
{
	if(root!=NULL)
	{
		dzhongxu(root->leftson);
		printf("%4d",root->shu);
		dzhongxu(root->rightson);
		
	}
}
int fzhongxu(struct tree *root)
{
	struct tree *stack[1000],*p;
	int top;
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
				p=p->leftson;
			};
			if(top==-1)
				return 1;
			else
			{
				p=stack[top--];
				printf("%d\n",p->shu);
				p=p->rightson;
			}
		}
	}
	printf("\n");
	return 1;
}
int fhouxu(struct tree *root)
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
				Stack[++top].x=p;					//入栈
				Stack[top].mark=1;					//左子树已经过；
				p=p->leftson;
			}										//直到无左子树
			while(Stack[top].mark==2)				//如果遍历过右子树，出栈输出;循环直到只遍历过左子树
			{
				p=Stack[top--].x;					
				printf("%4d",p->shu);
			}
			if (top == -1)							//如果上一步将栈出空，t跳出
				break;
			p=Stack[top].x;							//取栈顶元素
			Stack[top].mark=2;						//置已经遍历过右子树
			p=p->rightson;							//遍历右子树
		}
	}
	printf("\n");
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
		printf("1)初始化树\n\n2)插入元素\n\n3)输出树\n\n4)置空树\n\n5)后序输出\n\n6)中序输出\n\n0)退出\n");
		xz=zqsr("1234560");
		switch (xz)
		{
			case '1':root=chutree();break;
			case '2':charu(root);break;
			case '3':dxianxu(root,0);break;
			case '4':root=zhikong(root);break;
			case '5':fhouxu(root);break;
			case '6':fzhongxu(root);break;
			case '0':mark=1;break;
		}
		system("pause");
		system("cls");
		if(mark==1)
			break;
	}
	return 0;
}

