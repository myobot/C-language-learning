#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
int main()
{
	int i=0,k1=0,k2=0,k3=0,yb[N],sz[N];
	double E,E1;
	srand((unsigned int)time(0));
	for(i=0;i<N;i++)
	{
		yb[i]=rand()%10;
		sz[i]=-1;
		if(yb[i]<5)
		{
			sz[i]=rand()%6;
			if(sz[i]<3) 
			{
				k1++;
			}
			else if(sz[i]<5)
			{
				k2++;
			}
			else
				k3++;
		}
		else
			k1++;
	}
	printf("%9s%13s%9s%13s%13s%2s%2s%2s\n","ʵ�����","ͶӲ�ҽ��","ָʾ��ȷ","ָʾ����ȷ","Ͷ���ӽ��","0","1","2");
	for(i=0;i<N;i++)
	{
		printf("%9d",i+1);
		if(yb[i]<5)
		{
			printf("%13s%9s%13s","��","��","");
		}
		else
		{
			printf("%13s%9s%13s","��","","����");
		}
		if(sz[i]==-1)
		{
			printf("%13s%2s%2s%2s"," ","*"," "," ");
		}
		else if(sz[i]<3)
		{
			printf("%13d%2s%2s%2s",sz[i]+1,"*"," "," ");
		}
		else if(sz[i]<5)
		{
			printf("%13d%2s%2s%2s",sz[i]+1," ","*"," ");
		}
		else
			printf("%13d%2s%2s%2s",sz[i]+1," "," ","*");
		printf("\n");
	}
	printf("����%d��ģ�⹲�������%d����̨\n",N,k2+k3*2);
	E=(k2+k3)/20.0;
	E1=k2/20.0+(k3/20.0)*2;
	printf("��Ч��Ʊ���:%2.3f\n%d�����ƽ��ÿ�λ��˵��˵Ļ�����:%2.3f\n",E,N,E1);
	return 0;
}
