#include<cstdio>
#include<cmath>
#include<cstdlib>
//  y(x0)=y0;
//	yn+1=yn+f(tn,yn)*yn*h;
//	tn=a,a+h,a+2h.....b
double ola(double h,double a,double b,double y0)
{
	double yn,y,i;
	yn=y0;
	printf("%10s%10s\n","x(n)","y(n)");
	for(i=a;i<b;i+=h)
	{
		y=yn+(-0.9/(1+2*i)*yn*h);
	
		printf("%10.5lf%10.5lf\n",i,yn);
		yn=y;
	}
	printf("%10.5lf%10.5lf\n",i,y);
	return y;
}
double olag(double h,double a,double b,double y0)
{
	double yn,y1,y,i;
	yn=y0;
	printf("%10s%10s\n","x(n)","y(n)");
	for(i=a;i<b;i+=h)
	{
		y=yn+(-0.9/(1+2*i)*yn*h);
		y1=yn+1.0/2*h*((-0.9/(1+2*i)*yn)+(-0.9/(1+2*(i+h))*y));
		printf("%10.5lf%10.5lf\n",i,yn);
		yn=y1;
	}
	printf("%10.5lf%10.5lf\n",i,y1);
	return y1;
}
int main()
{
	double y,y1;
	printf("欧拉\n");
	y=ola(0.02,0,0.10,1);
	printf("改进欧拉\n");
	y1=olag(0.02,0,0.10,1);
	return 0;
}
