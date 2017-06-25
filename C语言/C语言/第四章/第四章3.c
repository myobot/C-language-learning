#include<stdio.h>
#define N 10
int main()
{
	int x[N][N]={{0},{0}},i,j,k;
	for(i=0;i<N;i++)
	{
		x[i][0]=1;
		x[i][i]=1;
		for(j=1;j<=i-1;j++)
		{
			x[i][j]=x[i-1][j-1]+x[i-1][j];
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N-i;j++)
			printf("  ");
		for(j=0;j<N;j++)
		{
			if(x[i][j]!=0)
			{
				printf("%4d",x[i][j]);
			}
				
		}
		printf("\n");
	}
	return 0;
}