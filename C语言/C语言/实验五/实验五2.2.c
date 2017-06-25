#include<stdio.h>
#define N 100
int main()
{
	int ix[N],i,j,k,n,p,z=0,f=0;
	printf("请输入数据,输入‘0’结束输入。\n");
	for(i=0;i<N;i++)
	{
		scanf("%d",&ix[i]);
		while ((scanf("%d", &ix[i]) != 1))
		{
			while (getchar() == '\n')
				continue;
			printf("  不是数字请重新输入\n");
			scanf("%d", &ix[i]);
		}
		if(ix[i]==0)
		{
			break;
		}
	}
	n=i-1;
	p=n;
	for(i=0;i<=n;i++)
	{
		if(ix[i]<0)
		{
			for(k=p;k>i;k--)
			{
				if(ix[k]>0)
				{
					p=k;
					break;
				}
			}
			j=ix[i];
			ix[i]=ix[p];
			ix[k]=j;
		}
	}
	for(i=0;i<n;i++)
	{
		if(ix[i]>0)
			z++;
		if(ix[i]<0)
			break;
	}
	f=n-z+1;
	for(i=0;i<=n;i++)
		printf("%4d",ix[i]);
	printf("一共有%d个正数%d负数.\n",z,f);
	return 0;
}



