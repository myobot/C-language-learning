#include "transform.h"
#define PAI 3.141592

/*  ���� ��ƽ��������
    ���� ��(x1,y1) (x2,y2) (x3,y3) ���������ε�����������
	           dx ��x������ƽ����
			   dy ��x������ƽ����
	����ֵ���޸ĺ�ĵ��x,y���꣬���ڲ��á����á��ķ�ʽ���ݲ���������ֱ���޸Ĳ���x,y����ֵ����

  */

void juzhenbianhuan(float T[3][3],float &x1,float &y1)
{
	int i,j;
	float p[3],sum,c[3];
	p[0]=x1;
	p[1]=y1;
	p[2]=1;
	for(i=0;i<3;i++)
	{
		sum=0;
		for(j=0;j<3;j++)
		{
			sum+=p[j]*T[j][i];
		}
		c[i]=sum;		//��Ҫ�Ѵ���ֵ������
	}
	x1=c[0];
	y1=c[1];
}
void juzhenxiangcheng(float T0[3][3],float T1[3][3],float T3[3][3])
{
	float sum;
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			sum=0;
			for(k=0;k<3;k++)
			{
				sum+=T0[i][k]*T1[k][j];
			}
			T3[i][j]=sum;
		}
	}
}




void translateTrangle(float &x1,float &y1,float & x2,float &y2,float &x3,float &y3,int dx,int dy)
{
	float T[3][3]={{1,0,0},{0,1,0},{dx,dy,1}};
	juzhenbianhuan(T,x1,y1);
	juzhenbianhuan(T,x2,y2);
	juzhenbianhuan(T,x3,y3);
	

}

/*  ���� ����������εļ������Ľ�������
    ���� ��(x1,y1) (x2,y2) (x3,y3) ���������ε�����������
	            sx x�������ű���
				sy y�������ű���
	����ֵ���޸ĺ�ĵ��x,y���꣬���ڲ��á����á��ķ�ʽ���ݲ���������ֱ���޸Ĳ���x,y����ֵ����

  */



void scaleTrangle(float &x1,float &y1,float & x2,float &y2,float &x3,float &y3,float sx,float sy)
{
	float ax=(float)(x1+x2+x3)/3,ay=(float)(y1+y2+y3)/3;
	float T[3][3]={{sx,0,0},{0,sy,0},{0,0,1}};
	float T3[3][3],T4[3][3],T1[3][3]={{1,0,0},{0,1,0},{-ax,-ay,1}},T2[3][3]={{1,0,0},{0,1,0},{ax,ay,1}};
	juzhenxiangcheng(T1,T,T3);
	juzhenxiangcheng(T3,T2,T4);

	juzhenbianhuan(T4,x1,y1);
	juzhenbianhuan(T4,x2,y2);
	juzhenbianhuan(T4,x3,y3);

}

/*  ���� ����������εļ������Ľ�����ת
    ���� ��(x1,y1) (x2,y2) (x3,y3) ���������ε�����������
	            tha ��ת�Ƕȣ�����Ƕ��Զȷ�ʽ�����������ǻ��ȣ����������Һ����ֱ�Ϊsin �� cos
	����ֵ���޸ĺ�ĵ��x,y���꣬���ڲ��á����á��ķ�ʽ���ݲ���������ֱ���޸Ĳ���x,y����ֵ����

  */
void rotateTrangle(float &x1,float &y1,float & x2,float &y2,float &x3,float &y3 ,int tha)
{
	float ax=(float)(x1+x2+x3)/3,ay=(float)(y1+y2+y3)/3;
	float Cos,Sin,a,b;
	Cos=cos((float)tha*PAI/180);
	Sin=sin((float)tha*PAI/180);
	a=ax-ax*Cos+ay*Sin;
	b=ay-ay*Cos-ax*Sin;
	float T3[3][3],T4[3][3];
	float T0[3][3]={{Cos,Sin,0},{-Sin,Cos,0},{0,0,1}},
		T1[3][3]={{1,0,0},{0,1,0},{-ax,-ay,1}},T2[3][3]={{1,0,0},{0,1,0},{ax,ay,1}};

	float T5[3][3]={{Cos,Sin,0},{-Sin,Cos,0},{a,b,1}};

	juzhenxiangcheng(T1,T0,T3);
	juzhenxiangcheng(T3,T2,T4);
	
	juzhenbianhuan(T4,x1,y1);
	juzhenbianhuan(T4,x2,y2);
	juzhenbianhuan(T4,x3,y3);


}