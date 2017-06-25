#include<stdio.h>
int main()
{
	int x[10]={1,2,3,4,5,6,7,8,9,10},i,j,m,x1[10];
	for(i=0;i<10;i++)
		printf("%4d",x[i]);
	printf("\n");
	printf("请输入要移动的m位\n");
	scanf("%d",&m);
	if(m>10)
		m=m%10;
	for(i=0;i<m;i++)
	{
		x1[i]=x[10-m+i];
	}
	for(i=9-m;i>=0;i--)
	{
		x[i+m]=x[i];
	}
	for(i=0;i<m;i++)
	{
		x[i]=x1[i];
	}
	for(i=0;i<10;i++)
		printf("%4d",x[i]);
	printf("\n");
	return 0;
}