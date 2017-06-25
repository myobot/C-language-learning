#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int i,tm,z,z01,z02,z1,suiji;
	double s=1000,s1,huo=0,huo1;
	srand((unsigned int)time(0));
	printf("请输入一轮实验预定的天数:");
	scanf("%d",&tm);
	for(z=200;z<=250;z+=10)
	{
		s1=0;huo1=0;
		for(i=0;i<tm;i++)
		{	
			suiji=rand()%100;
			if(suiji<10)
			{
				z1=200;
			}
			else if(suiji<30)
				z1=210;
			else if(suiji<70)
				z1=220;
			else if(suiji<85)
				z1=230;
			else if(suiji<95)
				z1=240;
			else
				z1=250;
			if(z>z1)
			{
				s1+=(z-z1)*0.2;
				huo1+=z1*0.5-(z-z1)*0.2;
			}
			else
			{
				s1+=(z1-z)*0.5;
				huo1+=z*0.5;
			}
			
		}
		if(s1/(tm*1.0)<s)
		{
			s=s1/(tm*1.0);z01=z;
		}
		if(huo1/(tm*1.0)>huo)
		{
			huo=huo1/(tm*1.0);z02=z;
		}
	}
	if(z01==z02)
	{
		printf("经过%d天模拟，得到最优订报量为：%d份/天,平均损失%.4f元，获得%.4f元\n",tm,z01,s,huo);
	}
	else
	{
		printf("损失和获得最优不同！\n");
		system("pause");
		printf("经过%d天模拟\n最少损失订报量为：%d份/天，平均损失%.4f元\n最大利润订报量为:%d份/天，平均利润为:%.4f元\n",tm,z01,s,z02,huo);
	}
	return 0;
}
		

		
