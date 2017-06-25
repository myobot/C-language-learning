#include<stdio.h>
int main()
{
	int x[10]={1,2,3,4,5,6,7,8,9,10},i,j,k,m;
	for(i=0;i<10;i++)
		printf("%3d",x[i]);
	printf("\n请输入要移动的位数\n");
	scanf("%d",&m);
	if(m>10)
	{
		m=m%10;
	}
	for(i=0;i<m;i++)
	{
		k=x[9];
		for(j=9;j>=0;j--)
		{
			x[j]=x[j-1];
		}
		x[0]=k;
	}
	printf("移动后的数列为\n");
	for(i=0;i<10;i++)
		printf("%3d",x[i]);
	printf("\n");
	return 0;
}



