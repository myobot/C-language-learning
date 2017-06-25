#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
int main()
{
	int i=0,k1=0,k2=0,k3=0,yb[N],sz[N];
	double E,E1;
	srand((unsigned int)time(0));
	for(i=0;i<N;i++)
	{
		yb[i]=rand()%10;
		sz[i]=-1;
		if(yb[i]<5)
		{
			sz[i]=rand()%6;
			if(sz[i]<3) 
			{
				k1++;
			}
			else if(sz[i]<5)
			{
				k2++;
			}
			else
				k3++;
		}
		else
			k1++;
	}
	printf("%9s%13s%9s%13s%13s%2s%2s%2s\n","实验序号","投硬币结果","指示正确","指示不正确","投骰子结果","0","1","2");
	for(i=0;i<N;i++)
	{
		printf("%9d",i+1);
		if(yb[i]<5)
		{
			printf("%13s%9s%13s","正","对","");
		}
		else
		{
			printf("%13s%9s%13s","反","","不对");
		}
		if(sz[i]==-1)
		{
			printf("%13s%2s%2s%2s"," ","*"," "," ");
		}
		else if(sz[i]<3)
		{
			printf("%13d%2s%2s%2s",sz[i]+1,"*"," "," ");
		}
		else if(sz[i]<5)
		{
			printf("%13d%2s%2s%2s",sz[i]+1," ","*"," ");
		}
		else
			printf("%13d%2s%2s%2s",sz[i]+1," "," ","*");
		printf("\n");
	}
	printf("经过%d天模拟共打掉敌人%d座炮台\n",N,k2+k3*2);
	E=(k2+k3)/20.0;
	E1=k2/20.0+(k3/20.0)*2;
	printf("有效设计比率:%2.3f\n%d次射击平均每次毁伤敌人的火炮数:%2.3f\n",E,N,E1);
	return 0;
}
