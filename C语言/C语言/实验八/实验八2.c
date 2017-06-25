#include <stdio.h>
int main()
{
	int *x,x1[12],i,p;
	x=x1;
	printf("ÇëÊäÈë10¸öÊı");
	for(i=0;i<12;i++)
	{
		scanf("%d",x);
		x++;
	}
	x=x-12;
	for(i=1;i<=12;i++)
	{
		printf("%4d",*x);
		x++;
		if(i%4==0)
			printf("\n");
	}
	return 0;
}
