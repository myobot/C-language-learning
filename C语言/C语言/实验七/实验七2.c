#include<stdio.h>
int isum(int n);
int main()
{
	int x;
	printf("������Ҫ�����ǰn���\n");
	scanf("%d",&x);
	printf("%d\n",isum(x));
	return 0;
}
int isum(int n)
{
	int sum=0;
	if(n>0)
		sum=n+isum(n-1);
	return sum;
}