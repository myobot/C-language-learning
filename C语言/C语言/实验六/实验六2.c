#include<stdio.h>
int yue(int x,int y);
int main()
{
	int x,y,i;
	printf("请输入两个数字\n");
	scanf("%d %d",&x,&y);
	if(x<y)
	{
		i=x;
		x=y;
		y=i;
	}
	printf("最大公约数为%d，最小公倍数为%d\n",yue(x,y),x*y/yue(x,y));
}
int yue(int x,int y)
{
	int i;
	while(1)
	{
		i=x%y;
		if(i==0)
			return y;
		else
		{
			x=y;
			y=i;
		}

	}
}