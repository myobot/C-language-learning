#include<stdio.h>
#define N 100
int main()
{
	int ix[N],i,j,k,n,p,z=0,f=0;
	printf("����������,���롮0���������롣\n");
	for(i=0;i<N;i++)
	{
		scanf("%d",&ix[i]);
		while ((scanf("%d", &ix[i]) != 1))
		{
			while (getchar() == '\n')
				continue;
			printf("  ������������������\n");
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
	printf("һ����%d������%d����.\n",z,f);
	return 0;
}



