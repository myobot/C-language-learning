#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
#define MAXSIZE 100
struct node
{
	int weight;
	int parent,lchild,rchild;
};
struct huffman
{
	char **bm;
	struct node *ht;
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
struct huffman *huffmancoding(int *w,int n)
{
	struct huffman *huf;
	struct node *ht,*p;
	char **hc,*cd;
	int i,j,f,m,m1,m2,x1,x2,start;
	if(n==0)
		return NULL;
	m=2*n-1;
	ht=(struct node *)malloc(sizeof(struct node)*m);
	for(p=ht,i=0;i<n;i++,p++,w++)
	{
		(*p).weight=*w;
		(*p).parent=-1;
		(*p).lchild=-1;
		(*p).rchild=-1;
	}
	for(;i<m;i++,p++)
	{
		(*p).weight=0;
		(*p).lchild=-1;
		(*p).rchild=-1;
		(*p).parent=-1;
	}
	for(i=n;i<m;i++)
	{
		m1=m2=MAX;
		x1=x2=0;
		for(j=0;j<i;j++)
		{
			if(ht[j].parent==-1&&ht[j].weight<m1)
			{
				m2=m1;x2=x1;m1=ht[j].weight;x1=j;
			}
			else if(ht[j].parent==-1&&ht[j].weight<m2)
			{
				m2=ht[j].weight;x2=j;
			}
		}
		ht[x1].parent=i;ht[x2].parent=i;
		ht[i].lchild=x1;ht[i].rchild=x2;
		ht[i].weight=m1+m2;
	}
	hc=(char **)malloc(sizeof(char *)*n);
	cd=(char *)malloc(sizeof(char)*n);
	cd[n-1]='\0';
	for(i=0;i<n;i++)
	{
		start=n-1;
		f=ht[i].parent;
		for(j=i;f!=-1;j=f,f=ht[f].parent)
		{
			if(ht[f].lchild==j)
				cd[--start]='0';
			else
				cd[--start]='1';
		}
		hc[i]=(char *)malloc((n-start)*sizeof(char));
		strcpy(hc[i],&cd[start]);
	}
	free(cd);
	huf=(struct huffman *)malloc(sizeof(struct huffman));
	huf->bm=hc;
	huf->ht=ht;
	return huf;
}
void print(char **bm,int n,char *zifu)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%c :%s\n",zifu[i],bm[i]);
	}
}
void bianma(char **bm,int n,char *zifu)
{
	int i,j,k;
	char x[MAXSIZE],c[MAX];
	c[0]='\0';
	printf("请输入明码:\n");
	gets(x);
	fflush(stdin);
	j=strlen(x);
	for(i=0;i<j;i++)
	{
		for(k=0;k<n;k++)
		{
			if(x[i]==zifu[k])
				break;
		}
		if(k<n)
		{
			strcat(c,bm[k]);
		}
		else
		{
			printf("明码有误！\n");
			return;
		}
	}
	printf("密码为:\n");
	printf("%s\n",c);
}
void yima(struct node *ht,int n,char *zifu)
{
	int i,j,k,p=0;
	char x[MAX],c[MAXSIZE];
	printf("请输入密码:\n");
	gets(x);
	c[0]='\0';
	fflush(stdin);
	j=strlen(x);
	k=n*2-2;
	for(i=0;i<j;i++)
	{
		if(x[i]=='0')
		{
			k=ht[k].lchild;
		}
		if(x[i]=='1')
		{
			k=ht[k].rchild;
		}
		if(ht[k].lchild==-1&&ht[k].rchild==-1)
		{
			c[p]=zifu[k];
			p++;
			k=n*2-2;
		}
	}
	printf("明码为:\n");
	c[p]='\0';
	printf("%s\n",c);
}

int main()
{
	char *zifu,xz;
	int *w,n,i,mark;
	struct huffman *huf;
	printf("字符数:\n");
	scanf("%d",&n);
	fflush(stdin);
	if(n<=0)
		return 0;
	else
	{
		zifu=(char *)malloc(sizeof(char)*n);
		w=(int *)malloc(sizeof(int)*n);
		printf("请输入各个字符的权重(频率)(空格隔开)\n");
		for(i=0;i<n;i++)
		{
			scanf("%d",&w[i]);
		}
		fflush(stdin);
		printf("请输入各个字符（不要隔开)\n");
		gets(zifu);
		huf=huffmancoding(w,n);
		print(huf->bm,n,zifu);
		printf("\n");
		system("pause");
		system("cls");
		for(;;)
		{
			mark=0;
			printf("1)编码\n\n2)译码\n\n3)查看码表\n\n0)退出\n\n请选择:\n");
			xz=zqsr("1230");
			switch(xz)
			{
				case '1':system("cls");bianma(huf->bm,n,zifu);break;
				case '2':system("cls");yima(huf->ht,n,zifu);break;
				case '3':system("cls");print(huf->bm,n,zifu);break;
				case '0':mark=1;break;
			}
			if(mark==1)
				break;
			system("pause");
			system("cls");
		}
		return 0;
	}
}
