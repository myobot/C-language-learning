#include "clip.h"





/*  ���� ���ü�ֱ��
    ���� ��(x1,y1) (x2,y2) (x3,y3) ����ֱ�ߵ�����������
         
  
	       left right top bottom �ֱ�Ϊ���βü������������4���߽�



          left
		   |----------------|top ����:����ͼ �ü������Ͻ�����Ϊ(right, top);
		   |                |
		   |                |
		   |                |
   bottom  |----------------|
	                      right
	   
	  
		����ֵ���޸ĺ�ĵ��x,y���꣬���ڲ��á����á��ķ�ʽ���ݲ���������ֱ���޸Ĳ���x,y����ֵ����
                ����Ϊ�ü�֮��ֱ����������
  
        return�ķ���ֵ  0:ֱ���ڲü����⣬������
		                1:ֱ����ȫ�ڲü����ڣ�������ü����н���,����

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