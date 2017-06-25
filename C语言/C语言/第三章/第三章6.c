#include<stdio.h>	
int
main()
{
	double isum=0,x;
	int n,i;
	printf("请输入要计算的前n项和\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			x=(2.0*(double)i/(2.0*i-1))*-1;
		}
		else
			x=2.0*i/(2.0*i-1);
		isum+=x;
	}
	printf("%.1lf\n",isum);
	return 0;
}
