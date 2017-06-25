#include "clip.h"





/*  名称 ：裁减直线
    参数 ：(x1,y1) (x2,y2) (x3,y3) 构成直线的两个点坐标
         
  
	       left right top bottom 分别为矩形裁减框的上下左右4个边界



          left
		   |----------------|top 补充:如左图 裁减框右上角坐标为(right, top);
		   |                |
		   |                |
		   |                |
   bottom  |----------------|
	                      right
	   
	  
		返回值：修改后的点的x,y坐标，由于采用“引用”的方式传递参数，所以直接修改参数x,y的数值即可
                返回为裁减之后直线两点坐标
  
        return的返回值  0:直线在裁减框外，被舍弃
		                1:直线完全在裁减框内，或者与裁减框有交点,保留

*/



float TBnode(float x1,float y1,float x2,float y2,float ny)
{
	if(y1-y2!=0)
		return ((ny-y2)/(y1-y2))*(x1-x2)+x2;
	else
		return 10000000;
}
float LRnode(float x1,float y1,float x2,float y2,float nx)
{
	if(x1-x2!=0)
		return ((nx-x2)/(x1-x2))*(y1-y2)+y2;
	else
		return 10000000;
}
void VertexCode(float x,float y,int left ,int right,int top ,int bottom,int c[4])
{
	if(y>top)
		c[0]=1;
	else
		c[0]=0;
	if(y<bottom)
		c[1]=1;
	else
		c[1]=0;
	if(x>right)
		c[2]=1;
	else
		c[2]=0;
	if(x<left)
		c[3]=1;
	else
		c[3]=0;
}
int huo(int c1[4],int c2[4])
{
	int i;
	for(i=0;i<4;i++)
	{
		if(c1[i]==1||c2[i]==1)
			return 0;
	}
	return 1;
}
int yu(int c1[4],int c2[4])
{
	int i;
	for(i=0;i<4;i++)
	{
		if(c1[i]==1&&c2[i]==1)
			return 1;
	}
	return 0;
}
void swapc(int code1[4],int code2[4])
{
	int i,temp;
	for(i=0;i<4;i++)
	{
		temp=code1[i];
		code1[i]=code2[i];
		code2[i]=temp;
	}
}
void swapv(float &x1,float &y1,float &x2,float &y2)
{
	float temp;
	temp=x1;
	x1=x2;
	x2=temp;

	temp=y1;
	y1=y2;
	y2=temp;

}
int findlow(int c[4])
{
	int i;
	for(i=3;i>=0;i--)
	{
		if(c[i]==1)
			return i;
	}
	return -1;
}
int clipLine(int left ,int right,int top ,int bottom,float &x1,float &y1,float &x2,float &y2)
{

	int code1[4],code2[4],i;
	int nei[4]={0,0,0,0};
	VertexCode(x1,y1,left,right,top,bottom,code1);
	VertexCode(x2,y2,left,right,top,bottom,code2);
	while(1)
	{
		if(huo(code1,code2))
			return 1;
		if(yu(code1,code2))
			return 0;
		if(huo(code1,nei))
		{
			swapc(code1,code2);
			swapv(x1,y1,x2,y2);
		}
		i=findlow(code1);
		switch (i)
		{
			case 0:	x1=TBnode(x1,y1,x2,y2,(float)top);
					y1=(float)top;
					VertexCode(x1,y1,left,right,top,bottom,code1);
					break;
			case 1: x1=TBnode(x1,y1,x2,y2,(float)bottom);
					y1=(float)bottom;
					VertexCode(x1,y1,left,right,top,bottom,code1);
					break;
			case 2: y1=LRnode(x1,y1,x2,y2,(float)right);
					x1=(float)right;
					VertexCode(x1,y1,left,right,top,bottom,code1);
					break;
			case 3:	y1=LRnode(x1,y1,x2,y2,(float)left);
					x1=(float)left;
					VertexCode(x1,y1,left,right,top,bottom,code1);
					break;
		}
	}

}