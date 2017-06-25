#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <conio.h>
#include <windows.h>
#define Hang 25
#define Lie 20
struct weizhi
{
	int x;
	int y;
};
void goto_xy(int x,int y){ //定位光标位置到指定坐标
HANDLE hOut;
COORD pos={x,y};
hOut = GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleCursorPosition(hOut,pos);
}
void shuchu(char **c)
{
	int i,j;
	printf("------------------------------------------\n");
	for(i=0;i<Hang;i++)
	{
		printf("|");
		for(j=0;j<Lie;j++)
			printf("%2c",c[i][j]);
		printf("|");
		printf("\n");
	}
	printf("------------------------------------------\n");
}
struct weizhi* shengcheng(char **c)
{
	int x;
	struct weizhi *p;
	p=(struct weizhi *)malloc(sizeof(struct weizhi));
	srand((unsigned int)time(0));
	x=rand()%(Lie-2);
	c[0][x]=4;
	c[0][x+1]=4;
	c[1][x]=4;
	c[1][x+1]=4;
	p->x=0;
	p->y=x;
	return p;
}
struct weizhi* Left(char **c,struct weizhi *p)
{
	if(p->y==0||c[p->x][p->y-1]==4||c[p->x+1][p->y-1]==4)
		return p;
	c[p->x][p->y-1]=c[p->x][p->y+1];
	c[p->x][p->y+1]=' ';
	c[p->x+1][p->y-1]=c[p->x+1][p->y+1];
	c[p->x+1][p->y+1]=' ';
	p->y--;
	return p;
}
struct weizhi* Right(char **c,struct weizhi *p)
{
	if(p->y+1==Lie-1||c[p->x][p->y+1]==4||c[p->x+1][p->y+1]==4)
		return p;
	c[p->x][p->y+2]=c[p->x][p->y];
	c[p->x][p->y]=' ';
	c[p->x+1][p->y+2]=c[p->x+1][p->y];
	c[p->x+1][p->y]=' ';
	p->y++;
	return p;
}

struct weizhi* down(char **c,struct weizhi *p)
{
	if(c[p->x+2][p->y]==4||c[p->x+2][p->y+1]==4||p->x+2==Hang)
	{
		free(p);
		return NULL;
	}
	c[p->x+2][p->y]=c[p->x][p->y];
	c[p->x][p->y]=' ';
	c[p->x+2][p->y+1]=c[p->x][p->y+1];
	c[p->x][p->y+1]=' ';
	p->x++;
	return p;
}

int main()
{
	int i,j;
	char x;
	struct weizhi *p;
	char **c;
	c=(char **)malloc(sizeof(char *)*Hang);
	for(i=0;i<Hang;i++)
	{
		c[i]=(char *)malloc(sizeof(char)*Lie);
		for(j=0;j<Lie;j++)
		{
			c[i][j]=' ';
		}
	}

	shuchu(c);
	p=shengcheng(c);

	for(;;)
	{
		fflush(stdin);
		if(kbhit())
		{
			x=_getch();
			if(x=='a')
			{
				p=Left(c,p);
				
					
					goto_xy(0,0);
					shuchu(c);
					
		
					
				
			}
			if(x=='d')
			{
				p=Right(c,p);
			
				
					goto_xy(0,0);
					shuchu(c);
					
				
			}
			continue;
		}
		p=down(c,p);
		if(p==NULL)
		{
			p=shengcheng(c);
		}
	
		goto_xy(0,0);
		shuchu(c);
		Sleep(500);
	}
	
			
		

	return 0;
}
	
