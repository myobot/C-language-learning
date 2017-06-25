#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXVALUE 1000
#define SMAX 1000
#define CMAX 100
struct node
{
	int x;
	struct node *next;
};
struct tree
{
	int weight;
	char fu;
	struct node *z;				//��¼�����ԭ�����е�λ�ã��ڽ���ʱ������ߵ�0��ջ���ұߵ�1��ջ
	struct tree *left,*right;
};
struct huffman
{
	char **bm;
	char *zifu;
	int n;
	struct tree *hroot;
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
struct huffman maketree(int m[],int n,char a[])
{
	int i,j,n2,x1,x2,k;
	int p1=MAXVALUE,p2=MAXVALUE;
	int **stack,*top;
	struct tree **sen;
	struct tree *bt;
	struct node *c;
	struct huffman ha;
	sen=(struct tree **)malloc(sizeof(struct tree *)*n);	//��ɭ��
	stack=(int **)malloc(sizeof(int*)*n);					//n��ջ
	top=(int *)malloc(sizeof(int)*n);						//n��top���
	ha.bm=(char **)malloc(sizeof(char*)*n);
	ha.zifu=(char *)malloc(sizeof(char)*n);
	for(i=0;i<n;i++)
	{
		ha.bm[i]=(char *)malloc(sizeof(char)*n);
		stack[i]=(int *)malloc(sizeof(int)*n);
		top[i]=-1;
		sen[i]=(struct tree *)malloc(sizeof(struct tree));
		sen[i]->z=(struct node *)malloc(sizeof(struct node));
		sen[i]->weight=m[i];
		sen[i]->fu=a[i];
		sen[i]->z->x=i;
		sen[i]->z->next=NULL;
		sen[i]->left=NULL;
		sen[i]->right=NULL;
	}
	n2=n;
	for(i=0;i<n-1;i++)
	{
		x1=x2=0;
		p1=p2=MAXVALUE;
		for(j=0;j<n;j++)									//����С�ʹ�С
		{
			if(sen[j]!=NULL&&sen[j]->weight<p1)				//ѭ����֮ǰ�ĸ���ָNULL
			{
				x2=x1;p2=p1;x1=j;p1=sen[j]->weight;
			}
			else if(sen[j]!=NULL&&sen[j]->weight<p2)
			{
				x2=j;p2=sen[j]->weight;
			}
		}
		bt=(struct tree *)malloc(sizeof(struct tree));		//��������
		bt->left=sen[x1];									//��С�����
		c=sen[x1]->z;										//c��ȡ��С�������н��λ��
		while(c)
		{
			stack[c->x][++top[c->x]]=0;						//��Ӧջ��0��
			c=c->next;
		}
		bt->right=sen[x2];					
		c=sen[x2]->z;
		while(c)
		{
			stack[c->x][++top[c->x]]=1;
			c=c->next;
		}
		c=sen[x2]->z;										//�������������Ľ��λ��
		while(c->next)
		{
			c=c->next;
		}
		c->next=sen[x1]->z;
		bt->z=sen[x2]->z;									//���Ӻ�ĸ����½��ĸ�
		bt->weight=sen[x1]->weight+sen[x2]->weight;			//�½�����Ȩ�ؼ���
		sen[x2]=NULL;										//��Сָ��ָNULL
		sen[x1]=bt;											//�½���������Сָ��λ��
	}
	for(i=0;i<n;i++)										//�������
	{
		k=0;
		printf("�ַ�%c ����Ϊ: ",a[i]);
		while(top[i]!=-1)
		{
			j=stack[i][top[i]--];
			ha.bm[i][k]=j+'0';
			k++;
			printf("%d",j);
		}
		ha.bm[i][k]='\0';
		ha.zifu[i]=a[i];
		printf("\n");
		free(stack[i]);										//�ͷ�һ��ջ
	}
	ha.hroot=sen[x1];
	ha.n=n;
	free(top);												//�ͷ�top
	free(stack);											//�ͷŶ���ջ
	return ha;												//sen û�б��ͷ�
}
struct huffman *makehuffman(void)
{
	int *m,n,i;
	char *a;
	struct huffman *ha;
	ha=(struct huffman *)malloc(sizeof(struct huffman));
	printf("�ַ�����");
	scanf("%d",&n);
	fflush(stdin);
	m=(int *)malloc(sizeof(int)*n);
	a=(char *)malloc(sizeof(char)*n);
	printf("����������ַ�Ȩ�أ�Ƶ�ʣ�(�ո����):\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&m[i]);
	}
	printf("����������ַ�(��Ҫ�ÿո����):\n");
	fflush(stdin);
	gets(a);
	*ha=maketree(m,n,a);
	return ha;
}
void jiema(struct tree *root,int n)
{
	int i,m,k=0;
	char c[CMAX],x[SMAX];
	struct tree *bt;
	printf("����������:\n");
	gets(x);
	fflush(stdin);
	m=strlen(x);
	bt=root;
	for(i=0;i<m;i++)
	{	
		if(x[i]=='0')
			bt=bt->left;
		else if(x[i]=='1')
			bt=bt->right;
		else
		{
			printf("��������\n");
			return;
		}
		if(bt->left==NULL&&bt->right==NULL)
		{
			c[k]=bt->fu;
			k++;
			bt=root;
		}
	}
	c[k]='\0';
	printf("����Ϊ: %s\n",c);
	
}
void bianma(char **bm,char *zifu,int n)
{
	int i,j,m;
	char x[SMAX],c[CMAX];
	x[0]='\0';
	printf("����������:\n");
	gets(c);
	fflush(stdin);
	m=strlen(c);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(zifu[j]==c[i])
				break;
		}
		if (j < n)
		{
			strcat(x, bm[j]);
		}
		else
		{
			printf("��������!\n");
			return;
		}
	}
	printf("����Ϊ: %s\n",x);
}
void mabiao(char **bm,char *zifu,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%c ����Ϊ: ",zifu[i]);
		printf("%s\n",bm[i]);
	}
}
int main()
{
	struct huffman *hu;
	int mark;
	char xz;
	for(;;)
	{
		mark=0;
		printf("1)������������\n\n2)����\n\n3)����\n\n4)������\n\n0)�˳�\n\n��ѡ��:\n");
		xz=zqsr("12340");
		system("cls");
		switch(xz)
		{
			case '1':hu=makehuffman();system("pause");system("cls");break;
			case '2':bianma(hu->bm,hu->zifu,hu->n);system("pause");system("cls");break;
			case '3':jiema(hu->hroot,hu->n);system("pause");system("cls");break;
			case '4':mabiao(hu->bm,hu->zifu,hu->n);system("pause");system("cls");break;
			case '0':mark=1;break;
		}
		if(mark==1)
			break;
	}
	return 0;
}



	