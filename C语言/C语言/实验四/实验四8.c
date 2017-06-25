#include<stdio.h>

int main()
{
	int n,ix,ifen=2,imu=1,ifen2=0;
 	double isum=0;
	printf("请输入要计算的N项\n");
	scanf("%d",&n);
	for(ix=1;ix<=n;ix++)
	{
		isum=isum+1.0*ifen/imu;
		ifen2=ifen;
		ifen=ifen+imu;
		imu=ifen2;
	}
	printf("%.2lf\n",isum);
	return 0;
}