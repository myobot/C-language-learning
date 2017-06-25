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
	struct node *z;				//记录结点在原数组中的位置，在建立时所有左边的0入栈，右边的1入栈
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
		puts("请重新输入正确选项:");
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
	sen=(struct tree **)malloc(sizeof(struct tree *)*n);	//根森林
	stack=(int **)malloc(sizeof(int*)*n);					//n个栈
	top=(int *)malloc(sizeof(int)*n);						//n个top标记
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
		for(j=0;j<n;j++)									//找最小和次小
		{
			if(sen[j]!=NULL&&sen[j]->weight<p1)				//循环后之前的根会指NULL
			{
				x2=x1;p2=p1;x1=j;p1=sen[j]->weight;
			}
			else if(sen[j]!=NULL&&sen[j]->weight<p2)
			{
				x2=j;p2=sen[j]->weight;
			}
		}
		bt=(struct tree *)malloc(sizeof(struct tree));		//建立树根
		bt->left=sen[x1];									//最小放左边
		c=sen[x1]->z;										//c读取最小数的所有结点位置
		while(c)
		{
			stack[c->x][++top[c->x]]=0;						//对应栈如0；
			c=c->next;
		}
		bt->right=sen[x2];					
		c=sen[x2]->z;
		while(c)
		{
			stack[c->x][++top[c->x]]=1;
			c=c->next;
		}
		c=sen[x2]->z;										//连接两个子树的结点位置
		while(c->next)
		{
			c=c->next;
		}
		c->next=sen[x1]->z;
		bt->z=sen[x2]->z;									//连接后的赋给新建的根
		bt->weight=sen[x1]->weight+sen[x2]->weight;			//新建根的权重计算
		sen[x2]=NULL;										//次小指针指NULL
		sen[x1]=bt;											//新建根赋给最小指针位置
	}
	for(i=0;i<n;i++)										//输出编码
	{
		k=0;
		printf("字符%c 编码为: ",a[i]);
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
		free(stack[i]);										//释放一级栈
	}
	ha.hroot=sen[x1];
	ha.n=n;
	free(top);												//释放top
	free(stack);											//释放二级栈
	return ha;												//sen 没有被释放
}
struct huffman *makehuffman(void)
{
	int *m,n,i;
	char *a;
	struct huffman *ha;
	ha=(struct huffman *)malloc(sizeof(struct huffman));
	printf("字符数：");
	scanf("%d",&n);
	fflush(stdin);
	m=(int *)malloc(sizeof(int)*n);
	a=(char *)malloc(sizeof(char)*n);
	printf("请输入各个字符权重（频率）(空格隔开):\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&m[i]);
	}
	printf("请输入各个字符(不要用空格隔开):\n");
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
	printf("请输入密码:\n");
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
			printf("密码有误\n");
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
	printf("明码为: %s\n",c);
	
}
void bianma(char **bm,char *zifu,int n)
{
	int i,j,m;
	char x[SMAX],c[CMAX];
	x[0]='\0';
	printf("请输入明码:\n");
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
			printf("明码有误!\n");
			return;
		}
	}
	printf("密码为: %s\n",x);
}
void mabiao(char **bm,char *zifu,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%c 编码为: ",zifu[i]);
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
		printf("1)构建哈夫曼树\n\n2)编码\n\n3)译码\n\n4)输出码表\n\n0)退出\n\n请选择:\n");
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



	