#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 100
struct tree
{
	char data;
	struct tree *right,*left;
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
void creattree(struct tree **bt,char str[])
{
	char ch;
	static int i=0;
	ch=str[i++];
	if(ch=='.')
	{
		*bt=NULL;
	}
	else
	{
		(*bt)=(struct tree *)malloc(sizeof(struct tree));
		(*bt)->data=ch;
		creattree(&((*bt)->left),str);
		creattree(&((*bt)->right),str);
	}
}
struct tree *creattree2(char str[])
{
	struct tree *stack[maxsize],*bt,*root,*q;
	int top=-1,i=0,mark=0;
	char ch;
	ch=str[i];
	if(ch=='.')									//第一个是.说明树空
		return NULL;
	else
	{	
		for(;;)						
		{
			while(bt)					
			{
				ch=str[i++];										//取str元素
				if(ch=='.')
				{
					bt=NULL;										//.bt指向空
					q->left=bt;										//q为bt双亲，先序先建立左子树
					break;											//跳出循环
				}
				bt=(struct tree *)malloc(sizeof(struct tree));		//不为.申请内存
				bt->data=ch;										//赋值
				if(mark!=0)											//mark=0是第一次进入
				{
					q->left=bt;										//如果不是第一次进入，q为bt双亲，其左子树指向bt；
				}
				else												//第一次进入后改变mark
					mark=1;
				if(i==1)											//第一次进入赋root初值，指向树根；
				{
					root=bt;
				}
				q=bt;												//q指向bt，下一次循环q为bt双亲;
				stack[++top]=bt;									//bt 入栈；
				bt=bt->left;										//bt指向bt的左子树；
			}
			for(;;)													//遇到.左子树指向NULL
			{	
				bt=stack[top--];									//出栈
				q=bt;												//q指向出栈结点bt;
				bt=bt->right;
				ch=str[i++];										//检测下一个str值
				if(ch=='.')											//.置空右子树
				{
					bt=NULL;
					q->right=bt;
				}
				else												//非.
				{
					bt=(struct tree *)malloc(sizeof(struct tree));	//建立结点
					bt->data=ch;									//赋值
					stack[++top]=bt;								//入栈
					q->right=bt;									//连接
					q=bt;mark=1;									//q指向bt,以供下一次连接 mark=1 已经不是第一次进入了
					break;											//跳出循环,
				}
				if(top==-1)											//如果栈空跳出
					break;
			}														//否则，继续检测下一个是否不是 .
			if(bt==NULL&&top==-1)									
				break;												//栈空且bt==NULL树建立完毕跳出
		}
		
	}
	return root;													//返回根节点；
}
void xshuchu(struct tree *root)
{
	if(root!=NULL)
	{
		printf("%2c",root->data);
		xshuchu(root->left);
		xshuchu(root->right);
	}
}
void zshuchu(struct tree *root)
{
	if(root!=NULL)
	{
		zshuchu(root->left);
		printf("%2c",root->data);
		zshuchu(root->right);
	}
}
void hshuchu(struct tree *root)
{
	if(root!=NULL)
	{
		hshuchu(root->left);
		hshuchu(root->right);
		printf("%2c",root->data);
	}
}
void yezi(struct tree *root)
{
	if(root!=NULL)
	{
		if(root->left==NULL&&root->right==NULL)
		{
			printf("%2c",root->data);
		}
		yezi(root->left);
		yezi(root->right);
	}
}
int jiedian(struct tree *root)
{
	int sum=0;
	if(root!=NULL)
	{
		sum++;
		sum+=jiedian(root->left);
		sum+=jiedian(root->right);
	}
	return sum;
}
void fdyezi(struct tree *root)
{
	struct tree *stack[maxsize],*bt;
	int top=-1,i=0;
	bt=root;
	if(bt==NULL)
		return;
	for(;;)
	{
		while(bt)
		{
			if(bt->left==NULL&&bt->right==NULL)
				printf("%2c",bt->data);
			stack[++top]=bt;
			bt=bt->left;
		}
		bt=stack[top--];
		bt=bt->right;
		if(bt==NULL&&top==-1)
			break;
	}
}
struct tree * shifang(struct tree *root)
{
	if(root!=NULL)
	{
		shifang(root->left);
		shifang(root->right);
		free(root);
	}
	return NULL;
}
int main()
{
	struct tree *root;
/*	struct tree **bt;*/
	int mark,sum=0;
	char xz,str[maxsize];
	for(;;)
	{
		mark=0;		
		printf("1)输入线序扩展序列并建立二叉树(非递归)\n\n2)递归先序遍历输出\n\n3)递归中序遍历输出\n\n4)递归后序遍历输出\n\n5)递归输出叶子结点\n\n6)递归统计结点数\n\n7)非递归输出叶子结点\n\n8)置空树\n\n9)输入线序扩展序列并建立二叉树(递归)\n\n0)退出\n\n请选择:\n\n");
		xz=zqsr("1234567890");
		switch(xz)
		{
			case '1':printf("请输入线序扩展序列'.'代表空\n");gets(str);fflush(stdin);
					root=creattree2(str);break;
			case '2':xshuchu(root);printf("\n");break;
			case '3':zshuchu(root);printf("\n");break;
			case '4':hshuchu(root);printf("\n");break;
			case '5':yezi(root);printf("\n");break;
			case '6':sum=jiedian(root);
					printf("共 %d 个结点\n",sum);break;
			case '7':fdyezi(root);printf("\n");break;
			case '8':root=shifang(root);
			case '9':printf("请输入线序扩展序列'.'代表空\n");gets(str);fflush(stdin);
					creattree(&root,str);break;
			case '0':mark=1;shifang(root);break;
		}
		system("pause");
		system("cls");
		if(mark==1)
			break;
	}
	return 0;
}