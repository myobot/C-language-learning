#include<stdio.h>
int main()
{
	int x,y,o=0,j=0,isum1,isum2;
	double ping1,ping2;
	while(1);
	{
		scanf("%d",&x);
		if(x<=0)
		{
			break;
		}
		y=x%2;
		switch(y)
		{
			case(0):
			{
				o++;
				isum1+=x;
				break;
			}
			default:
				j++;
				isum2+=x;
		}
	}
	ping1=1.0*isum1/o;
	ping2=1.0*isum2/j;
	printf("����%d��ż��,%d��������ż��ƽ��ֵ%.1lf,����ƽ��ֵ%.1lf\n",o,j,ping1,ping2);
	return 0;
}
				


	

