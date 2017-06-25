
#include<stdio.h>
int isprime(int n);
int main()
{
	int x;
	printf("ÇëÊäÒ»¸öÊı×Ö\n");
	scanf("%d",&x);
	printf("%d\n",isprime(x));
	return 0;
}
int isprime(int n)
{
	int i,j;
	for(i=2,j=0;i<n;i++)
	{
		if(n%i==0)
		{
			j++;
			return 0;
		}
	}
	if(j==0)
		return 1;
}
