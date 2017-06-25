#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
void assign(FILE *fp);
struct seat
{
	char hao;
	char biao;
	char keren[20];
};
int main()
{
	FILE *fp;
	if((fp=fopen("seat.txt","r+"))==NULL)
	{
		printf("打开文件失败\n");
		exit(1);
	}
	assign(fp);
	return 0;
}
void assign(FILE *fp)
{
	int j;
	struct seat sseat;
	printf("请输入要预定的座位\n");
	scanf("%d",&j);
	fflush(stdin);
	fseek(fp,sizeof(struct seat)*(j-1),0);
	printf("请输入您的姓名\n");
	gets(sseat.keren);
	sseat.biao='1';
	sseat.hao=j+47;
	fwrite(&sseat,sizeof(struct seat),1,fp);
}