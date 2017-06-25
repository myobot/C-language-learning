#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<time.h>
double moni(int P,int Q)
{
	int i,kucun=115,mark=-1,xuqiu,mark2=0;
	double sum=0;
	for(i=0;i<1800;i++)
	{
		if(mark!=-1)
			mark--;
		if(mark==0)
		{
			kucun+=Q;
			mark=-1;
		}
		xuqiu=rand()%100;
		kucun-=xuqiu;
		if(kucun<0)
		{
		//	mark2++;
		//	if(mark2==1)
				sum+=-1.0*kucun*1.8;
		//	else
		//		sum+=-1.0*xuqiu*1.8;
		}

		else
		{
		//	mark2=0;
			sum+=0.75*kucun;
		}
		if(kucun<=P&&mark==-1)
		{
			sum+=750+Q*2.0;
			mark=3;
		}
	}
	return sum;
}
zuixiao(double sum[5])
{
	double min=1000000000;
	int i,m;
	for(i=0;i<5;i++)
	{
		if(sum[i]<min)
		{
			m=i;
			min=sum[i];
		}
	}
	return m;
}
			

int main()
{
	int i,min;
	double sum[5];
	srand((unsigned int)time(0));
	sum[0]=moni(125,150);
	sum[1]=moni(125,250);
	sum[2]=moni(150,250);
	sum[3]=moni(175,250);
	sum[4]=moni(175,300);
	for(i=0;i<5;i++)
	{
		printf("第%d种方案模拟180天，平均每天损失%.3lf元\n",i+1,sum[i]/1800);
	}
	min=zuixiao(sum);
	printf("第%d天最优\n",min+1);
	return 0;
}
		


