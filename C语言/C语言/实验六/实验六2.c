#include<stdio.h>
int yue(int x,int y);
int main()
{
	int x,y,i;
	printf("��������������\n");
	scanf("%d %d",&x,&y);
	if(x<y)
	{
		i=x;
		x=y;
		y=i;
	}
	printf("���Լ��Ϊ%d����С������Ϊ%d\n",yue(x,y),x*y/yue(x,y));
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