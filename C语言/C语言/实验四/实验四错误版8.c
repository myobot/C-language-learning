#include<stdio.h>

int main()
{
	int n,ix,ifen=2,imu=1;
 	double isum=0;
	printf("������Ҫ�����N��\n");
	scanf("%d",&n);
	for(ix=1;ix<=n;ix++)
	{
		isum=isum+1.0*ifen/imu;
		ifen=ifen+imu;
		imu=ifen;
	}
	printf("%.2lf\n",isum);
	return 0;
}