#include<stdio.h>
int main()
{
	int i,ia,ib,ic,n,m;
	for(i=100;i<=999;i++)
	{
		ia=i%10;
		ib=(i%100-ia)/10;
		ic=(i-ib*10-ia)/100;
		if(i==ia*ia*ia+ib*ib*ib+ic*ic*ic)
			printf("%4d",i);
	}
	printf("\n");
	return 0;
}
