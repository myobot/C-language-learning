#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ix[100][100],ii,ij,n,i=0;
	printf("请输入矩阵的阶数:");
	scanf("%d",&n);
	printf("\n");
	printf("请输入正确的矩阵\n");
	for(ii=0;ii<n;ii++)
	{
		for(ij=0;ij<n;ij++)
		{
			scanf("%d",&ix[ii][ij]);
		}
	}
	for(ii=0;ii<n;ii++)
	{
		for(ij=0;ij<ii;ij++)
		{
			if(ix[ii][ij]!=0)
			{
				i++;
				break;
			}
		}
		for(ij=n-1;ij>ii;ij--);
		{
			if(ix[ii][ij]!=0)
			{
				i++;
				break;
			}
		}
	}
	if(i==1)
	{
		printf("NO\n");
	}
	if(i==0||i>=2)
	{
		printf("YES\n");
	}
	return 0;
}

