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
		puts("������������ȷѡ��:");
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
	if(ch=='.')									//��һ����.˵������
		return NULL;
	else
	{	
		for(;;)						
		{
			while(bt)					
			{
				ch=str[i++];										//ȡstrԪ��
				if(ch=='.')
				{
					bt=NULL;										//.btָ���
					q->left=bt;										//qΪbt˫�ף������Ƚ���������
					break;											//����ѭ��
				}
				bt=(struct tree *)malloc(sizeof(struct tree));		//��Ϊ.�����ڴ�
				bt->data=ch;										//��ֵ
				if(mark!=0)											//mark=0�ǵ�һ�ν���
				{
					q->left=bt;										//������ǵ�һ�ν��룬qΪbt˫�ף���������ָ��bt��
				}
				else												//��һ�ν����ı�mark
					mark=1;
				if(i==1)											//��һ�ν��븳root��ֵ��ָ��������
				{
					root=bt;
				}
				q=bt;												//qָ��bt����һ��ѭ��qΪbt˫��;
				stack[++top]=bt;									//bt ��ջ��
				bt=bt->left;										//btָ��bt����������
			}
			for(;;)													//����.������ָ��NULL
			{	
				bt=stack[top--];									//��ջ
				q=bt;												//qָ���ջ���bt;
				bt=bt->right;
				ch=str[i++];										//�����һ��strֵ
				if(ch=='.')											//.�ÿ�������
				{
					bt=NULL;
					q->right=bt;
				}
				else												//��.
				{
					bt=(struct tree *)malloc(sizeof(struct tree));	//�������
					bt->data=ch;									//��ֵ
					stack[++top]=bt;								//��ջ
					q->right=bt;									//����
					q=bt;mark=1;									//qָ��bt,�Թ���һ������ mark=1 �Ѿ����ǵ�һ�ν�����
					break;											//����ѭ��,
				}
				if(top==-1)											//���ջ������
					break;
			}														//���򣬼��������һ���Ƿ��� .
			if(bt==NULL&&top==-1)									
				break;												//ջ����bt==NULL�������������
		}
		
	}
	return root;													//���ظ��ڵ㣻
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
		printf("1)����������չ���в�����������(�ǵݹ�)\n\n2)�ݹ�����������\n\n3)�ݹ�����������\n\n4)�ݹ����������\n\n5)�ݹ����Ҷ�ӽ��\n\n6)�ݹ�ͳ�ƽ����\n\n7)�ǵݹ����Ҷ�ӽ��\n\n8)�ÿ���\n\n9)����������չ���в�����������(�ݹ�)\n\n0)�˳�\n\n��ѡ��:\n\n");
		xz=zqsr("1234567890");
		switch(xz)
		{
			case '1':printf("������������չ����'.'�����\n");gets(str);fflush(stdin);
					root=creattree2(str);break;
			case '2':xshuchu(root);printf("\n");break;
			case '3':zshuchu(root);printf("\n");break;
			case '4':hshuchu(root);printf("\n");break;
			case '5':yezi(root);printf("\n");break;
			case '6':sum=jiedian(root);
					printf("�� %d �����\n",sum);break;
			case '7':fdyezi(root);printf("\n");break;
			case '8':root=shifang(root);
			case '9':printf("������������չ����'.'�����\n");gets(str);fflush(stdin);
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