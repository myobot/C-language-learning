#include<cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int crand()			//�˿�����
{
	int i;
	i=20+rand()%31;
	return i;
}
int xrand()			//�³�����
{
	int i;
	i=3+rand()%5;
	return i;
}
int xtrand()
{
	return 1+rand()%7;
}
int strand()
{
	return 4+rand()%9;
}
int daodarand(int t)///���ɷֲ�������
{
	int i;
	i=0.4*t;
	return i;
}
int qrand()			//��������ʱ��
{
	return 30+rand()%4;
}
int main()
{
	int i,sum=0,neng[25],buneng[25],shijian[25],c,x,daoda,qiche,st,xt,tsum,j;
	for(i=0;i<25;i++)
	{
		tsum=0;
		neng[i]=0;
		buneng[i]=0;
		shijian[i]=0;
		qiche=qrand();
		c=crand();		//�ϳ�����
		x=xrand();		//�³�����
		
		for(j=0;j<x;j++)
		{
			xt=xtrand();
			tsum+=xt;
		}
		daoda=daodarand(qiche+tsum/60);

		shijian[i]+=tsum;
		c-=x;
		neng[i]=50-c;
		if(neng[i]>daoda)
			buneng[i]=0;
		else
			buneng[i]=daoda-neng[i];

		for(j=0;j<neng[i];j++)
		{
			st=strand();
			tsum+=st;
		}
		shijian[i]+=tsum;
	}
	printf("����25�η���,�õ���������\n");
	printf("%10s%12s%12s%12s\n","��������","��������","����������","�ȴ���ʱ��");
	for(i=0;i<25;i++)
	{
		printf("%10d%12d%12d%10ds\n",i+1,neng[i],buneng[i],shijian[i]);
		sum+=neng[i];
	}

	printf("�ܹ��ϳ�����:%2d\n",sum);
	return 0;
}
		


	


