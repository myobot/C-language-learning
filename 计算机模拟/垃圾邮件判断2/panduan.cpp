#include<cstdlib>
#include<cstdio>
# define MAX_HASH 1123
struct Danci 
{
	char d[20];
	double p;
	int n;
};
struct biao
{
	struct Danci danci[MAX_HASH];
	int n;
};
unsigned int hash_func(char *str, int len)
{
     register unsigned int sum = 0; 
     register unsigned int h = 0;
     register unsigned short *p = (unsigned short *)str;
     register unsigned short *s = (unsigned short *)str;

     while(p - s < len) 
     {
          register unsigned short a = *(p++) * (p-s);
          sum += sum ^ a; 
          h += a;
     }
     return ((sum << 16) | h) % MAX_HASH;
}

char *duwenjian(int &ji,FILE *fp)
{
	char *chp,ch1;
	int j=0,i;
	while(1)
	{
		if((fscanf(fp,"%c",&ch1))==1)
		{
			j++;
		//	printf("%c",ch1);
		}
		else
			break;
	}
	j++;
	chp=(char *)malloc(sizeof(char)*j);
	if(chp==NULL)
	{
		printf("内存不足\n");
		exit(1);
	}
	rewind(fp);
	for(i=0;i<j;i++)
	{
		if((fscanf(fp,"%c",&chp[i]))!=1)
			break;
	}
	ji=j;
	return chp;
}
double *saomiao(struct biao *x,int ji,int &sum,char *chp)
{
	int i,j,hash;
	char c[20]={'\0'};
	int f=0;
	double *p;
	p=(double *)malloc(sizeof(double)*100);
	for(i=0,j=0;i<ji;i++,j++)
	{
		c[j]=chp[i];
		if(chp[i]==' ')
		{
			c[j]='\0';
			hash=hash_func(c,j-1);
			//未判断重复
			//每次学习都计算P
			p[f]=x->danci[hash].p;
		}

		j=-1;
		i++;
		while(chp[i]==' ')
			i++;
		i--;
	}
	free(chp);
	sum=f;
	return p;
}

int main()
{
	struct biao *probabity;
	int i=0,ji=0,sum=0;
	double *p,P1,P2,P3;
	char *chp;
	FILE *fp,*fp2;
	probabity=(struct biao *)malloc(sizeof(struct biao));
	if((fp=fopen("probabitybiao.txt","r"))==NULL)		
	{
		printf("打开文件1失败!\n");
		exit(1);
	}
	if((fp2=fopen("panduan.txt","r"))==NULL)
	{
		printf("打开文件2失败\n");
		exit(1);
	}
	if(fread(&(*probabity),sizeof(struct biao),1,fp)!=1)
	{
		printf("读入文件失败\n");
		exit(1);
	}
	chp=duwenjian(ji,fp);
	p=saomiao(probabity,ji,sum,chp);
	for(i=0;i<sum;i++)
	{
		P1*=p[i];
		P2+=p[i];
	}
	P3=P1/P2;
	printf("是垃圾邮件的概率为:%.3lf\n");
	return 0;
}
	

	
