

#include "Line.h"
void doubleone(int x0,int y0,int x1,int d,int upincre,int downincre,int mark);
void doubletwo(int x0,int y0,int y1,int d,int leftincre,int rightincre,int mark);
void allline(int x0,int y0,int x1,int y1)
{
	double k;
	int dx,dy,d,upincre,downincre,rightincre,leftincre,x,y;
	dx=x0-x1;
	dy=y0-y1;
	k=(double)dy/dx;
	if(k>=-1&&k<=1)
	{
		if(x0>x1)
		{
			x=x1;x1=x0;x0=x;
			y=y1;y1=y0;y0=y;
		}
		if(k<=1&&k>=0)
		{
			dx=x1-x0;dy=y1-y0;
			d=dx-2*dy;
			upincre=2*dx-2*dy;
			downincre=-2*dy;
			doubleone(x0,y0,x1,d,upincre,downincre,1);
		}
		else
		{
			dx=x1-x0;dy=y1-y0;
			d=-dx-2*dy;
			downincre=-2*dx-2*dy;
			upincre=-2*dy;
			doubleone(x0,y0,x1,d,upincre,downincre,2);
		}
	}
	else
	{
		if(y0>y1)
		{
			x=x1;x1=x0;x0=x;
			y=y1;y1=y0;y0=y;
		}
		if(k>1)
		{
			dx=x1-x0;dy=y1-y0;
			d=2*dx-dy;
			rightincre=2*dx-2*dy;
			leftincre=2*dx;
			doubletwo(x0,y0,y1,d,leftincre,rightincre,1);
		}
		else
		{
			dx=x1-x0;dy=y1-y0;
			d=2*dx+dy;
			leftincre=2*dx+2*dy;
			rightincre=2*dx;
			doubletwo(x0,y0,y1,d,leftincre,rightincre,2);
		}
	}
}
void doubleone(int x0,int y0,int x1,int d,int upincre,int downincre,int mark)
{
	glColor3f(0.0f,1.0f,0.0f);//设置点的颜色
	glBegin(GL_POINTS);//以点的方式绘制
	int x,y;
	x=x0;y=y0;
	while(x<=x1)
	{
		glVertex2i(x,y);
		x++;
		switch (mark)
		{
			case 1:if(d<0)
				   {
					   y++;d+=upincre;
				   }
					else
						d+=downincre;
					break;
			case 2:if(d<0)
					   d+=upincre;
				   else
				   {
					   y--;d+=downincre;
				   }
				   break;
		}
	}
	glEnd();//结束绘制
	glFlush();
}
void doubletwo(int x0,int y0,int y1,int d,int leftincre,int rightincre,int mark)
{
	glColor3f(0.0f,1.0f,0.0f);//设置点的颜色
	glBegin(GL_POINTS);//以点的方式绘制	
	int x,y;
	x=x0;y=y0;
	while(y<=y1)
	{
		glVertex2i(x,y);
		y++;
		switch (mark)
		{
			case 1:if(d>0)
				   {
					   x++;
					   d+=rightincre;
				   }
				   else
					   d+=leftincre;
				   break;
			case 2:if(d>0)
					   d+=rightincre;
				   else
				   {
					   x--;
					   d+=leftincre;
				   }
				   break;
		}
	}
	glEnd();//结束绘制
	glFlush();
}

void drawLineBresenham(int x1 ,int y1,int x2,int y2)

{
 
	allline(x1,y1,x2,y2);
	
	
}

