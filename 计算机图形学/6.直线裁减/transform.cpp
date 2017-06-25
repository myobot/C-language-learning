#include "transform.h"
#define PAI 3.141592

/*  名称 ：平移三角形
    参数 ：(x1,y1) (x2,y2) (x3,y3) 构成三角形的三个点坐标
	           dx 沿x轴正向平移量
			   dy 沿x轴纵向平移量
	返回值：修改后的点的x,y坐标，由于采用“引用”的方式传递参数，所以直接修改参数x,y的数值即可

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
		c[i]=sum;		//需要把传入值做副本
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

/*  名称 ：针对三角形的几何中心进行缩放
    参数 ：(x1,y1) (x2,y2) (x3,y3) 构成三角形的三个点坐标
	            sx x方向缩放比例
				sy y方向缩放比例
	返回值：修改后的点的x,y坐标，由于采用“引用”的方式传递参数，所以直接修改参数x,y的数值即可

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

/*  名称 ：针对三角形的几何中心进行旋转
    参数 ：(x1,y1) (x2,y2) (x3,y3) 构成三角形的三个点坐标
	            tha 旋转角度，这里角度以度方式给出，而不是弧度，求正、余弦函数分别为sin 和 cos
	返回值：修改后的点的x,y坐标，由于采用“引用”的方式传递参数，所以直接修改参数x,y的数值即可

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