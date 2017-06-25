#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#define MAX_HASH 1123
using namespace std;
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
int main()
{
	struct biao *chushi;
	int i=0,j,sum=0,p,ji=0;
	int hash;
	int fuzhu[1000];
	char c[20]={'\0'},*chp,ch1;
	FILE *fp,*fp2;
	chushi=(struct biao * )malloc(sizeof(struct biao));
	for(i=0;i<MAX_HASH;i++)
	{
		for(j=0;j<20;j++)
			chushi->danci[i].d[j]='\0';
		chushi->danci[i].p=0;
		chushi->danci[i].n=0;
	}
	chushi->n=0;
	if((fp=fopen("danci2.txt","r"))==NULL)		//126516个字母,14746个单词
	{
		printf("打开文件失败!\n");
		exit(1);
	}
	while(1)
	{
		if((fscanf(fp,"%c",&ch1))==1)
		{
			ji++;
		//	printf("%c",ch1);
		}
		else
			break;
	}
	chp=(char *)malloc(sizeof(char)*ji);
	if(chp==NULL)
	{
		printf("内存不足\n");
		exit(1);
	}
	rewind(fp);
	for(i=0;i<ji;i++)
	{
		if((fscanf(fp,"%c",&chp[i]))!=1)
			break;
	}
	for(i=0,j=0;i<ji;i++,j++)
	{
		c[j]=chp[i];
		if(chp[i]==' '||chp[i]==',')
		{
			c[j]='\0';
			hash=hash_func(c,j-1);
			if(strcmp(chushi->danci[hash].d,c)==0)
				sum++;
			else
			{
				for(p=0;p<=j;p++)
				{
					chushi->danci[hash].d[p]=c[p];
				}
				fuzhu[chushi->n]=hash;
				chushi->n=chushi->n+1;
			}
		/*	for(i1=0;i1<j;i1++)
			{
				c[i1]='\0';
			}
		*/
			j=-1;
			i++;
			while(chp[i]==' ')
				i++;
			i--;
		}	
	}
	for(i=0;i<chushi->n;i++)
	{
		cout <<chushi->danci[fuzhu[i]].d<<endl;
	}
	fclose(fp);
	if((fp2=fopen("biao.txt","w"))==NULL)		//126516个字母,14746个单词
	{
		printf("打开文件失败!\n");
		exit(1);
	}
	if(fwrite(&(*chushi),sizeof(struct biao),1,fp2)!=1)
	{
		printf("写入文件失败\n");
		exit(1);
	}

	fclose(fp2);
	
	free(chp);
	free(chushi);


	return 0;
}


