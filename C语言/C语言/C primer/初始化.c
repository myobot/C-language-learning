#include<stdio.h>
#include<stdlib.h>
struct seat
{
	char hao;
	char biao;
	char keren[20];
};
int main()
{
	struct seat seats[12];
	int i;
	FILE *fp;	
	if((fp=fopen("seat.txt","r+"))==NULL)
	{
		printf("打开文件失败\n");
		exit(1);
	}
	rewind(fp);
	for(i=0;i<12;i++)
	{
		seats[i].hao=i+'1';
		seats[i].biao='0';
		seats[i].keren[0]='0';
	}
	fwrite(&seats[0],sizeof(struct seat),12,fp);
	fclose(fp);
	return 0;
}
	