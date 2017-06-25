#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	double a,b;
	int m=0,n,i;
	srand((unsigned int)time(0));
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a=((double)rand()/RAND_MAX)*2.0;
		if(a*a<3)
		{
			m++;
		}
	}
	b=m/(n*1.0);
	printf("%lf\n",b*2);
	return 0;
}