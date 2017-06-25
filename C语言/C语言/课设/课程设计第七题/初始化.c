#include<stdio.h>
#include<time.h>
#include<stdlib.h>
struct qichexinxi
{
	char chepaihao[16];
	time_t jinru;
	char jinrusj[40];
	time_t likai;
	char likaisj[40];
	int jifei;
};
struct qiche
{
	int mark;
	int chewei;
	struct qichexinxi xinxi;
};
int main()
{	
	FILE *fp;
	struct qiche qqiche[20];
	int i,sum;
	if((fp=fopen("qiche.txt","r+"))==NULL)
	{
		puts("打开文件失败!");
		exit(1);
	}
	for(i=0;i<20;i++)
	{
		qqiche[i].mark=0;
		qqiche[i].chewei=i+1;
		qqiche[i].xinxi.chepaihao[0]='\0';
		qqiche[i].xinxi.jifei=0;
	}
	sum=0;
	fseek(fp,0L,0);
	fscanf(fp,"%d",&sum);
	fseek(fp,sizeof(int),0);
	fwrite(&qqiche[0],sizeof(struct qiche),20,fp);
	return 0;
}
