#include<stdio.h>
int main()
{
	int a,b,c,i=0,flag=0,d;
	printf("请输入三个数\n");
	scanf("%d %d %d",&a,&b,&c);
	while(flag!=3)
	{
		i++;
		if(a==i)
		{
			printf("%d ",a);
			flag++;
		}
		if(b==i)
		{
			printf("%d ",b);
			flag++;
		}
		if(c==i)
		{
			printf("%d ",c);
			flag++;
		}	
	}
	printf("\n");
	return 0;
}