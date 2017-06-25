#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <conio.h>
#include <windows.h>
#define N 4
#define M 16
char zqsr(char *c)
{
	char xz;
	xz=getchar();
	fflush(stdin);
	while(strchr(c,xz)==NULL)
	{
		puts("请重新输入正确选项:");
		xz=getchar();
		fflush(stdin);
	}
	return xz;
}
int shengcheng(int qipan[N][N])
{
	int i,j,k,a,b,c,q;
	int p[M][2];
	srand((unsigned)time(0));
	for(i=0,k=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(qipan[i][j]==0)
			{
				p[k][0]=i;
				p[k][1]=j;
				k++;
			}
		}
	}
	if(k==0)
		return 0;
	else
	{
		c=rand()%k;
		a=p[c][0];
		b=p[c][1];
		q=rand()%10;
		if(q<6)
			qipan[a][b]=2;
		else
			qipan[a][b]=4;
		return 1;
	}
}
int up(int qipan[N][N])
{
	int i,j,a,l,mark,mark2=0,mark3;
	int fuzhu[N],f;
	int fuzhu2[N];
	for(i=0,mark3=0;i<N;i++)
	{
		f=0;j=0;
		for(l=0;l<N;l++)
		{
			fuzhu[l]=0;
			fuzhu2[l]=qipan[l][i];
		}
		while(qipan[j][i]==0)					//找到第一个不是空的位置
		{
			j++;
		}
		for(mark=0;j<N-1;)
		{
			a=j+1;
			if(a>=N)
				break;
			while(qipan[a][i]==0)				//找到第二个不是空的位置
			{
				a++;
			}
			if(a>=N)
				break;
			if(qipan[j][i]==qipan[a][i])		//判断相等否
			{
				qipan[j][i]+=qipan[a][i];
				qipan[a][i]=0;
				mark=1;
			}	
			if(mark==1)							//如果前面加过就从a下一个开始
				j=a+1;
			else
				j=a;							//如果没有从a开始
			while(qipan[j][i]==0)				//找下一个
			{
				j++;
			}	
		}
		for(l=0;l<N;l++)					//补齐
		{
			if(qipan[l][i]!=0)
			{
				fuzhu[f]=qipan[l][i];
				f++;
			}
		}
		for(l=0;l<N;l++)
		{
			qipan[l][i]=fuzhu[l];
			if(fuzhu2[l]!=fuzhu[l])
				mark3=1;
		}
		if(mark3==1)
			mark2++;
	}
	if(mark2!=0)
		return 1;
	else
		return 0;
}
int left(int qipan[N][N])
{
	int i,j,a,l,mark,mark2=0,mark3;
	int fuzhu[N],f;
	int fuzhu2[N];
	for(i=0,mark3=0;i<N;i++)
	{
		f=0;j=0;
		for(l=0;l<N;l++)
		{
			fuzhu[l]=0;
			fuzhu2[l]=qipan[i][l];
		}
		while(qipan[i][j]==0)
		{
			j++;
		}
		for(mark=0;j<N-1;)
		{
			
			a=j+1;
			if(a>=N)
				break;
			while(qipan[i][a]==0)
			{
				a++;
			}
			if(a>=N)
				break;
			if(qipan[i][j]==qipan[i][a])
			{
				qipan[i][j]+=qipan[i][a];
				qipan[i][a]=0;
				mark=1;
			}
			if(mark==1)
				j=a+1;
			else
				j=a;
			while(qipan[i][j]==0)
			{
				j++;
			}	
		}
		for(l=0;l<N;l++)
		{
			if(qipan[i][l]!=0)
			{
				fuzhu[f]=qipan[i][l];
				f++;
			}
		}
		for(l=0;l<N;l++)
		{
			qipan[i][l]=fuzhu[l];
			if(fuzhu2[l]!=fuzhu[l])
				mark3=1;
		}
		if(mark3!=0)
			mark2++;
	}
	if(mark2!=0)
		return 1;
	else
		return 0;
}
int down(int qipan[N][N])
{
	int i,j,a,o,l,mark,mark2=0,mark3;
	int fuzhu[N],fuzhu2[N],f,e;
	for(i=0,mark3=0;i<N;i++)
	{
		f=0;j=N-1;e=0;
		for(l=0;l<N;l++)
			fuzhu[l]=0;
		for(l=N-1;l>=0;l--)
		{
			fuzhu2[e]=qipan[l][i];e++;
		}
		while(qipan[j][i]==0)					
			j--;
		for(mark=0;j>=0;)
		{
			a=j-1;
			if(a<0)
				break;
			while(qipan[a][i]==0)
			{
				a--;
			}
			if(a<0)
				break;
			if(qipan[j][i]==qipan[a][i])
			{
				qipan[j][i]+=qipan[a][i];
				qipan[a][i]=0;
				mark=1;
			}
			if(mark==1)
				j=a-1;
			else
				j=a;
			while(qipan[j][i]==0)
				j--;
		}
		for(l=N-1;l>=0;l--)					
		{
			if(qipan[l][i]!=0)
			{
				fuzhu[f]=qipan[l][i];
				f++;
			}
		}
		for(l=0,o=N-1;l<N;o--,l++)
		{
			qipan[o][i]=fuzhu[l];
			if(fuzhu2[l]!=fuzhu[l])
				mark3=1;
		}
		if(mark3!=0)
			mark2++;
	}
	if(mark2!=0)
		return 1;
	else
		return 0;
}
int right(int qipan[N][N])
{
	int i,j,a,o,l,mark,mark2=0,mark3;
	int fuzhu[N],fuzhu2[N],f,e;
	for(i=0;i<N;i++)
	{
		f=0;j=N-1;e=0;
		for(l=0,mark3=0;l<N;l++)
			fuzhu[l]=0;
		for(l=N-1;l>=0;l--)
		{
			fuzhu2[e]=qipan[i][l];
			e++;
		}
		while(qipan[i][j]==0)
			j--;
		for(mark=0;j>=0;)
		{
			a=j-1;
			if(a<0)
				break;
			while(qipan[i][a]==0)
			{
				a--;
			}
			if(a<0)
				break;
			if(qipan[i][j]==qipan[i][a])
			{
				qipan[i][j]+=qipan[i][a];
				qipan[i][a]=0;
				mark=1;
			}
			if(mark==1)
				j=a-1;
			else
				j=a;
			while(qipan[i][j]==0)
				j--;
		}
		for(l=N-1;l>=0;l--)
		{
			if(qipan[i][l]!=0)
			{
				fuzhu[f]=qipan[i][l];
				f++;
			}
		}
		for(l=0,o=N-1;l<N;o--,l++)
		{
			qipan[i][o]=fuzhu[l];
			if(fuzhu2[l]!=fuzhu[l])
				mark3=1;
		}
		if(mark3!=0)
			mark2++;
	}
	if(mark2!=0)
		return 1;
	else
		return 0;
}
void color(const unsigned short color1)
{       
	if(color1>=0&&color1<=15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void caiseshuzi(int x)
{
	printf("| ");
	switch (x)
	{
		case 2:color(1);break;
		case 4:color(2);break;
		case 8:color(3);break;
		case 16:color(4);break;
		case 32:color(5);break;
		case 64:color(13);break;
		case 128:color(7);break;
		case 256:color(8);break;
		case 512:color(6);break;
		case 1024:color(10);break;
		case 2048:color(14);break;
	}
	printf("%4d ",x);
	color(15);
}

void printqipan(int qipan[N][N])
{
	int i,j;
	printf("-----------------------------\n");

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("|      ");
		printf("|\n");
		for(j=0;j<N;j++)
		{
			if(qipan[i][j]!=0)
				caiseshuzi(qipan[i][j]);
			else
				printf("|      ");
		}
		printf("|\n");
		for(j=0;j<N;j++)
			printf("|      ");
		printf("|\n");
		printf("-----------------------------\n");
	}
	printf("	w上\n");
	printf("a左		d右\n");
	printf("	s下\n1 重新开始\n2 结束游戏\n");
}
int jiance(int qipan[N][N])
{
	int i,j,k=0,shang,xia,zuo,you;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			shang=i-1;
			xia=i+1;
			zuo=j-1;
			you=j+1;
			if(shang>=0)
			{
				if(qipan[i][j]==qipan[shang][j])
				{
					k++;break;
				}
			}
			if(xia<N)
			{
				if(qipan[i][j]==qipan[xia][j])
				{
					k++;break;
				}
			}
			if(zuo>=0)
			{
				if(qipan[i][j]==qipan[i][zuo])
				{
					k++;break;
				}
			}
			if(you<N)
			{
				if(qipan[i][j]==qipan[i][you])
				{
					k++;break;
				}
			}
			if(qipan[i][j]==0)
			{
				k++;break;
			}

		}
		if(k>0)
			break;
	}
	if(k>0)
		return 1;
	else
		return 0;
}
int ying(int qipan[N][N])
{
	int i,j,k=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(qipan[i][j]==2048)
			{
				k++;
				break;
			}
		}
		if(k>0)
			break;
	}
	if(k!=0)
		return 1;
	else
		return 0;
}
int m2048(void)
{
	int i,j,qipan[N][N],mark,mark2;
	char x;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			qipan[i][j]=0;
		}
	}
	shengcheng(qipan);
	shengcheng(qipan);
	printqipan(qipan);
	for(;;)
	{
		mark=0,mark2=0;
		x=_getch();
		fflush(stdin);
		while(strchr("wasd12",x)==NULL)
		{
			x=_getch();
			fflush(stdin);
		}
		switch(x)
		{
			case 'w':if(up(qipan)==0)
						 mark=1;
						break;
			case 'a':if(left(qipan)==0)
						mark=1;
						break;
			case 's':if(down(qipan)==0)
						mark=1;
						break;
			case 'd':if(right(qipan)==0)
						mark=1;
						break;
			case '1':mark2=1;break;
			case '2':mark2=2;break;
		}
		if(mark==0&&mark2==0)
		{
			if(shengcheng(qipan)==0&&jiance(qipan)==0)
				break;
		}
		if(mark!=0&&mark2==0)
		{
			if(jiance(qipan)==0)
				break;
		}
		if(mark2!=0)
			break;
		system("cls");
		printqipan(qipan);
		if(ying(qipan)==1)
		{
			mark2=3;
			break;
		}
		
	}
	if(mark2==0)
	{
		printf("你输了!\n");system("pause");
		return 0;
	}
	if(mark2==3)
	{
		printf("你赢了!\n");system("pause");
		return 0;
	}
	if(mark2==1)
	{
		system("cls");
		return 1;
	}
	else
	{
		system("cls");
		return 2;
	}
}
int main()
{
	int mark;
	char xz;
	for(;;)
	{
		mark=m2048();
		if(mark==0)
		{
			printf("1）重新开始\n\n2）结束游戏\n\n请选择:\n");
			xz=zqsr("12");
			if(xz=='1')
			{
				system("cls");
				continue;
			}
			else
				break;
		}
		if(mark==1)
		{
			system("cls");
			continue;
		}
		else
			break;
	}
	printf("再见\n");
	system("pause");
	return 0;
}
		

	
		
	
