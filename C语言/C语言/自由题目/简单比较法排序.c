#include<stdio.h>
#define N 3
int
main()
{
	int ix[N],ik,n,ii,ij,a,ip;
	printf("请输入%d个数\n",N);
	for(ii=0;ii<N;ii++)
	{
		scanf("%d",&ix[ii]);
	}

		for(ii=0;ii<N-1;ii++)
		{
			ik=ii;
			for(ij=ii+1;ij<N;ij++)
			{
				if(ix[ik]>ix[ij])
				{
					ik=ij;
				}
			}
			if(ik!=ii)
			{
				n=ix[ii];
				ix[ii]=ix[ik];
				ix[ik]=n;
			}
		}
		printf("排好序的顺序为:\n");
		for(ii=0;ii<N;ii++)
		{
			printf("%4d",ix[ii]);
		}
	printf("\n");
	return 0;
}
			