#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 15
int main()
{
	int a[N],i,j,k,x,p;
	srand((unsigned)time(0));
	for(i=0;i<N;i++)
	{
		a[i]=rand()%50;
		printf("%4d",a[i]);
	}
	x=a[0];
	k=0;			//空位置标记
	p=0;			//正向标记
	for(j=N-1;j>=1;j--)
	{
		if(a[j]<x)
		{
			a[k]=a[j];
			k=j;
			for(i=p;i<10;i++)
			{
				if(a[i]>x)
				{
					a[k]=a[i];
					p=i;
					k=i;
					break;	//每次只找一个
				}
				if(i==j)
				{
					p=i;
					break;
				}
			}
		}
		if(p==j)			//正向标记和J相等即找完
			break;
	}
	a[k]=x;
	printf("\n");
	system("pause");	
	printf("\n\n");
	for(i=0;i<N;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
	return 0;
}