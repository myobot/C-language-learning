#include<stdio.h>
int main()
{
	int m,n,ijie=1,isum=0,ii;
	printf("«Î ‰»Îm,n\n");
	printf("m=__\b\b\n");printf("n=__\b\b");
	scanf("%d %d",&m,&n);
	for(;m<=n;m++)
	{
		ijie=1;
		for(ii=1;ii<=m;ii++)
		{	
			ijie=ijie*ii;
		}
	isum=isum+ijie;

	}
	printf("%d\n",isum);
	return 0;
}