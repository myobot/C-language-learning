#include<stdio.h>
int main()
{
	int x,n,i,j,a,b;
	double isum=0;
	printf("«Î ‰»Îx∫Õn\n");
	scanf("%d %d",&x,&n);
	for(i=1;i<=n;i++)
	{
/*		for(j=1,a=1;j<=2*i;j++)
		{
			a*=x;
		}*/
		for(j=1,b=1,a=x;j<=(2*i-1);j++)
		{
			b*=j;
			a*=x;
		}
		isum+=1.0*a/b;
	}
	printf("%.1lf\n",isum);
	return 0;
}