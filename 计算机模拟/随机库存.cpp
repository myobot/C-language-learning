//订货费:2.5/件 附加费：300 保管费 0.9/件/月  缺货损失费 1.8/件
#include<cstdio>
#include<cstdlib>
#include<time.h>
int zrand()
{
	double rate;
	rate=(double)rand()/RAND_MAX;
	if(rate<=0.167)
		return 1;
	else if(rate<=0.5)
		return 2;
	else if(rate<=0.833)
		return 3;
	else 
		return 4;
}

double moni(int L,int S)
{
	int i,j,z,mark=-1,kc[10],dhl,kucun=40,k,skucun=0;
	double sum=0,pkucun;
	for(j=0;j<120;j++)
	{
		for(i=0;i<10;i++)
		{
			if(mark!=-1)
				mark--;
			if(mark==0)
			{
				kucun+=dhl;
				mark=-1;
			}
			z=zrand();
			kucun=kucun-z;
			if(kucun<0)
				sum+=-1.0*kucun*1.8;
			kc[i]=kucun;
			if(kucun<L&&mark==-1)
			{
				mark=rand()%6+5;
				dhl=S-kucun;
				sum+=(double)dhl*2.5+300;
			}
		}
		for(k=0;k<10;k++)
		{
			skucun+=kc[k];
		}
		pkucun=(double)skucun/10;
		sum+=pkucun*0.9;
		skucun=0;
	}
	return sum;
}
int zuixiao(double sum[9])
{
	double min=1000000000;
	int i,m;
	for(i=0;i<9;i++)
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
	double sum[9];
	srand((unsigned int)time(0));
	sum[0]=moni(20,40);
	sum[1]=moni(20,60);
	sum[2]=moni(20,80);
	sum[3]=moni(20,100);
	sum[4]=moni(40,60);
	sum[5]=moni(40,80);
	sum[6]=moni(40,100);
	sum[7]=moni(60,80);
	sum[8]=moni(60,100);
	for(i=0;i<9;i++)
	{
		printf("第%d种方案模拟120月，平均每月损失%.3lf元\n",i+1,sum[i]/(120));
	}
	min=zuixiao(sum);
	printf("第%d种方案最优\n",min+1);
	return 0;
}

				



