#include<stdio.h>
int main()
{
	int x[4]={1,16,56,0},i,j,k,p;
	for(i=0;i<3;i++)
		printf("%4d",x[i]);
	printf("\n请输入一个数\n");
	scanf("%d",&k);
	for(i=0;i<3;i++)
	{
		if(k<x[i])
		{
			p=x[3];
			for(j=3;j>i;j--)
			{
				x[j]=x[j-1];
				x[j-1]=p;
			}
			x[i]=k;
			break;
		}
	}
	if(k>x[2])
		x[3]=k;
	for(i=0;i<4;i++)
		printf("%4d",x[i]);
	printf("\n");
	return 0;
}

	