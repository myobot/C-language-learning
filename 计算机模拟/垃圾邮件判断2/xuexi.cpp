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

struct biao * xuexi(struct biao *x,int ji,char *chp)
{
	int i,j,p=0,hash;
	char c[20]={'\0'};
	int fuzhu[1123];
	for(i=0,j=0;i<ji;i++,j++)
	{
		c[j]=chp[i];
		if(chp[i]==' ')
		{
			c[j]='\0';
			hash=hash_func(c,j-1);
			//未判断重复
			//每次学习都计算P
			fuzhu[p]=hash;
			x->n++;
			x->danci[hash].n++;
		
			j=-1;
			i++;
			while(chp[i]==' ')
				i++;
			i--;
		}
	}
	for(i=0;i<p;i++)
	{
		x->danci[fuzhu[p]].p=(double)x->danci[fuzhu[p]].n/x->n;
	}
	free(chp);
	return x;
}





int main()
{
	struct biao *good,*bad,*probabity;
	int i=0,sum=0,ji=0;


	int gj,bj;
	char c[20]={'\0'},*gchp;
	FILE *fp,*fp2;
	good=(struct biao *)malloc(sizeof(struct biao));
	bad=(struct biao *)malloc(sizeof(struct biao));
	probabity=(struct biao *)malloc(sizeof(struct biao));
	if((fp=fopen("biao.txt","r"))==NULL)		//126516个字母,14746个单词
	{
		printf("打开文件失败!\n");
		exit(1);
	}
	if(fread(&(*good),sizeof(struct biao),1,fp)!=1)
	{
		printf("读入文件失败\n");
		exit(1);
	}
	*bad=*good;
	*probabity=*good;
	good->n=0;
	bad->n=0;
	probabity->n=0;
	fclose(fp);
	if((fp2=fopen("good.txt","r"))==NULL)
	{
		printf("打开文件失败\n");
		exit(1);
	}
	if((fp2=fopen("goodbiao.txt","w"))==NULL)
	{
		printf("打开文件失败\n");
		exit(1);
	}
	gchp=duwenjian(gj,fp);
	good=xuexi(good,gj,gchp);
	if(fwrite(&(*good),sizeof(struct biao),1,fp2)!=1)
	{
		printf("写入文件失败\n");
		exit(1);
	}
	
	fclose(fp2);
	fclose(fp);
	if((fp2=fopen("bad.txt","r"))==NULL)
	{
		printf("打开文件失败\n");
		exit(1);
	}
	if((fp2=fopen("badbiao.txt","w"))==NULL)
	{
		printf("打开文件失败\n");
		exit(1);
	}
	gchp=duwenjian(bj,fp);
	bad=xuexi(bad,bj,gchp);
	if(fwrite(&(*bad),sizeof(struct biao),1,fp2)!=1)
	{
		printf("写入文件失败\n");
		exit(1);
	}
	
	fclose(fp2);
	fclose(fp);
	for(i=0;i<MAX_HASH;i++)
	{
		if(bad->danci[i].n==0&&good->danci[i].n==0)
			continue;
		else
		{
			probabity->danci[i].p=bad->danci[i].p/(bad->danci[i].p+good->danci[i].p);
			probabity->n++;
		}
	}
	if((fp2=fopen("probabitybiao.txt","w"))==NULL)
	{
		printf("打开文件失败\n");
		exit(1);
	}

	if(fwrite(&(*probabity),sizeof(struct biao),1,fp2)!=1)
	{
		printf("写入文件失败\n");
		exit(1);
	}

	fclose(fp2);
	free(good);
	free(bad);
	free(probabity);
	printf("学习完毕\n");
	return 0;
}


	


