#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct seat
{
	char hao;
	char biao;
	char keren[20];
};
struct hangban
{
	char hhao[4];
	struct seat seats[12];
};
int main()
{
	struct hangban hang[4];
	int i,j;
	FILE *fp;
	if((fp=fopen("seat2.txt","r+"))==NULL)
	{
		puts("打开文件失败!");
		exit(1);
	}
	strcpy(hang[0].hhao,"102");
	strcpy(hang[1].hhao,"311");
	strcpy(hang[2].hhao,"444");
	strcpy(hang[3].hhao,"519");
	for(i=0;i<4;i++)
	{
		for(j=0;j<12;j++)
		{
			hang[i].seats[j].hao=j+49;
			hang[i].seats[j].biao='0';
			hang[i].seats[j].keren[0]='0';
		}
	}
	rewind(fp);
	fwrite(&hang[0],sizeof(struct hangban),4,fp);
	fclose(fp);
	return 0;
}

