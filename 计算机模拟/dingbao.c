#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int i,tm,z,z01,z02,z1,suiji;
	double s=1000,s1,huo=0,huo1;
	srand((unsigned int)time(0));
	printf("������һ��ʵ��Ԥ��������:");
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
		printf("����%d��ģ�⣬�õ����Ŷ�����Ϊ��%d��/��,ƽ����ʧ%.4fԪ�����%.4fԪ\n",tm,z01,s,huo);
	}
	else
	{
		printf("��ʧ�ͻ�����Ų�ͬ��\n");
		system("pause");
		printf("����%d��ģ��\n������ʧ������Ϊ��%d��/�죬ƽ����ʧ%.4fԪ\n������󶩱���Ϊ:%d��/�죬ƽ������Ϊ:%.4fԪ\n",tm,z01,s,z02,huo);
	}
	return 0;
}
		

		
