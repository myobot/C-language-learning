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
		printf("���ļ�ʧ��\n");
		exit(1);
	}
	assign(fp);
	return 0;
}
void assign(FILE *fp)
{
	int j;
	struct seat sseat;
	printf("������ҪԤ������λ\n");
	scanf("%d",&j);
	fflush(stdin);
	fseek(fp,sizeof(struct seat)*(j-1),0);
	printf("��������������\n");
	gets(sseat.keren);
	sseat.biao='1';
	sseat.hao=j+47;
	fwrite(&sseat,sizeof(struct seat),1,fp);
}