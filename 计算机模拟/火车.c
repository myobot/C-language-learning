#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
struct vertex
{
	double x,y;
};
struct vertex zhengtai()
{
	double r1,r2,u,v,w,X;
	struct vertex p;
	while(1)
	{
		r1=(double)rand()/RAND_MAX;
		r2=(double)rand()/RAND_MAX;
		u=2.0*r1-1;
		v=2.0*r2-1;
		w=u*u+v*v;
		if(w>1)
			continue;
		else
			break;
	}
	X=u*(sqrt((-1*log(w))/w));
	p.x=X*2+30;
	p.y=v*(sqrt((-1*log(w))/w));
	
	return p;
}

int main()
{
	int i,n,hc,r,th,tr,m=0;
	double gailv;
	struct vertex z;
	srand((unsigned int)time(0));
	printf("请输入模拟天数:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		hc=rand()%10+1;
		r=rand()%10+1;
		if(hc<=7)
			th=0;
		else if(hc<=9)
			th=5;
		else
			th=10;

		if(r<=3)
			tr=28;
		else if(r<=7)
			tr=30;
		else if(r<=9)
			tr=32;
		else
			tr=34;
		z=zhengtai();
		th=th+z.x;
		if(tr<=th)
			m++;
	}
	gailv=((double)m/n)*100;
	printf("经模拟%d天，他能赶上火车的天数为:%d天\n他能赶上火车的概率为%.1lf%",n,m,gailv);
	return 0;
}