#include<stdio.h>
long jie(int x);
int main()
{
	int x,i;
	long sum=0;
	printf("������Ҫ�����ǰn���(��С��13)\n");
	scanf("%d",&x);
	for(i=1;i<=x;i++)
	{
		sum+=jie(i);
	}
	printf("%ld\n",sum);
	return 0;
}
long jie(int x)
{
	long jiecheng=1;
	if(x>0)
		jiecheng=x*jie(x-1);
	return jiecheng;
}
