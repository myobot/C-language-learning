#include<stdio.h>
int main()
{
	int x,y;
	printf("ÇëÊäÈëXµÄÖµX=__\b\b");
	scanf("%d",&x);
	if(x<=2)
	{
		y=x*x+2*x-1;
	}
	else
	{
		y=x*x-2*x-1;
	}
	printf("Y=%d\n",y);
	return 0;
}