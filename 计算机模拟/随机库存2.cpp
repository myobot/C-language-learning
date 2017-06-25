//订货费:2.5/件 附加费：300 保管费 0.9/件/月  缺货损失费 1.8/件
#include<cstdio>
#include<cstdlib>
#include<time.h>
#include<math.h>
int mrand()
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
double zrand()
{
	double r,zhishu;
	r=(double)rand()/RAND_MAX;
	zhishu=-0.1*log(1-r);				
	return zhishu;
}
double moni(int L,int S)
{
	int j,m,kc[30],dhl,kucun=40,k,skucun=0,day;
	double i,z,mark=-1,ealyday;
	double sum=0,pkucun;
	for(j=0;j<120;j++)
	{
		i=0;day=0;
		z=zrand();						//不知道为什么第一个数不对
		while(i<1)						//i为月数判断，i=1为1个月
		{
			z=zrand();					//生成指数分布
			ealyday=i;					//保存前一天的时间
			i+=z;						//跟新今天时间
			if(mark!=-1)				//mark!=1说明有订货
			{
				mark-=z;				//mark-本次循环经历时间
			}
			if(mark<=0&&mark!=-1)		//mark<=0&&mark!=-1说明货到了
			{
				kucun+=dhl;				//到货加库存
				mark=-1;				//置mark=-1
			}
			if(i-ealyday>=0.0334)		//今天减前天大一一天时
			{	
				kc[day]=kucun*(int)((i-ealyday)*30);	//计算这些天的库存量
				day++;					//计数器加一
			}
			m=mrand();					//生成本次需货量
			kucun=kucun-m;				//库存减去
			if(kucun<0)					
				sum+=-1.0*kucun*1.8;	//库存小于零是计算缺货损失	
			
			if(kucun<L&&mark==-1)		//库存小于最低限度并且没有订货时，订货
			{
				mark=((double)rand()/RAND_MAX)/2+0.5;  //mark=0.5~1个月
				dhl=S-kucun;
				sum+=(double)dhl*2.5+300;
			}
			
			
		}
		for(k=0;k<day;k++)
		{
			skucun+=kc[k];			//计算30天总库存量
		}
		pkucun=(double)skucun/30;	//计算每天平均库存
		sum+=pkucun*0.9;			//计算保管费
		skucun=0;					//总库存计数器置零
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

				



