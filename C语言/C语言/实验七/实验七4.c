#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100
void xuanpai(int x[],int n);
int main()
{
	int x[N],i,j;
	srand((unsigned)time(0));
	for(i=0;i<N;i++)
	{
		x[i]=rand()%100;
		printf("%4d",x[i]);
	}
	xuanpai(x,N);
	printf("\n\n\n\n");
	for(i=0;i<N;i++)
		printf("%4d",x[i]);
	printf("\n");
	return 0;
}
void xuanpai(int x[],int n)
{
	int i,j,k,p;
	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(x[k]>x[j])
			{
				k=j;
			}
		}
		if(k!=i)
		{
			p=x[i];
			x[i]=x[k];
			x[k]=p;
		}
	}
}

