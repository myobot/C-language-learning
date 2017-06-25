//�����:2.5/�� ���ӷѣ�300 ���ܷ� 0.9/��/��  ȱ����ʧ�� 1.8/��
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
		z=zrand();						//��֪��Ϊʲô��һ�����
		while(i<1)						//iΪ�����жϣ�i=1Ϊ1����
		{
			z=zrand();					//���ָ��ֲ�
			ealyday=i;					//����ǰһ���ʱ��
			i+=z;						//���½���ʱ��
			if(mark!=-1)				//mark!=1˵���ж���
			{
				mark-=z;				//mark-����ѭ������ʱ��
			}
			if(mark<=0&&mark!=-1)		//mark<=0&&mark!=-1˵�����
			{
				kucun+=dhl;				//����ӿ��
				mark=-1;				//��mark=-1
			}
			if(i-ealyday>=0.0334)		//�����ǰ���һһ��ʱ
			{	
				kc[day]=kucun*(int)((i-ealyday)*30);	//������Щ��Ŀ���
				day++;					//�������һ
			}
			m=mrand();					//��ɱ�������
			kucun=kucun-m;				//����ȥ
			if(kucun<0)					
				sum+=-1.0*kucun*1.8;	//���С�����Ǽ���ȱ����ʧ	
		
			if(kucun<L&&mark==-1)		//���С������޶Ȳ���û�ж���ʱ������
			{
				mark=((double)rand()/RAND_MAX)/2+0.5;  //mark=0.5~1����
				dhl=S-kucun;
				sum+=(double)dhl*2.5+300;
			}
			
			
		}
		for(k=0;k<day;k++)
		{
			skucun+=kc[k];			//����30���ܿ���
		}
		pkucun=(double)skucun/30;	//����ÿ��ƽ����
		sum+=pkucun*0.9;			//���㱣�ܷ�
		skucun=0;					//�ܿ�����������
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
		printf("��%d�ַ���ģ��120�£�ƽ��ÿ����ʧ%.3lfԪ\n",i+1,sum[i]/(120));
	}
	min=zuixiao(sum);
	printf("��%d�ַ�������\n",min+1);
	return 0;
}

				


