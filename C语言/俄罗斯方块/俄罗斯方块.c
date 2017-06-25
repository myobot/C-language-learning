#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <conio.h>
#include <windows.h>
#define H 25
#define L 20
struct weizhi
{
	int x;
	int y;
};
void shuchu(char c[H][L])
{
	int i,j;
	printf("------------------------------------------\n");
	for(i=0;i<H;i++)
	{
		printf("|");
		for(j=0;j<L;j++)
		{
			printf("%2c",c[i][j]);
		}
		printf("|");
		printf("\n");
	}
	printf("------------------------------------------\n");
}
struct weizhi shengcheng(char c[H][L])
{
	int x;
	struct weizhi p;
	srand((unsigned int)time(0));
	x=rand()%(L-2);
	c[0][x]=4;
	c[0][x+1]=4;
	c[1][x]=4;
	c[1][x+1]=4;
	p->x=x;
	p->y=0;
	return p;
}
struct weizhi Left(char c[H][L],struct weizhi p)
{
	if(x==0)
		return p;
	c[p->x-1][p->y]=c[p->x+1][p->y];
	c[p->x+1][p->y]=' ';
	c[p->x-1][p->y+1]=c[p->x+1][p->y+1];
	c[p->x+1][p->y+1]=' ';
	p->x--;
	return p;
}
struct weizhi Right(char c[H][L],struct weizhi p)
{
	if(x+1==L-1)
		return p;
	c[p->x+2][p->y]=c[p->x][p->y];
	c[p->x][p->y]=' ';
	c[p->x+2][p->y+1]=c[p->x][p->y+1];
	c[p->x][p->y+1]=' ';
	p->x++;
	return p;
}

struct weizhi down(char c[H][L],struct weizhi p)
{
	if(c[p->x][p->y+2]==4||c[p->x+1][p->y+2]==4)
		return NULL;
	c[p->x][p->y+2]==c[p->x][p->y];
	c[p->x][p->y]=' ';
	c[p->x+1][p->y+2]=c[p->x+1][p->y];
	c[p->x+1][p->y];
	p->y++;
	return p;
}

int main()
{
	int i,j;
	struct weizhi p;
	char c[H][L];
	for(i=0;i<H;i++)
	{
		for(j=0;j<L;j++)
		{
			c[i][j]=' ';
		}
	}
	shuchu(c);
	p=shengcheng(c);

	for(;;)
	{
		x=_getch();
		fflush(stdin);

	return 0;
}
	
