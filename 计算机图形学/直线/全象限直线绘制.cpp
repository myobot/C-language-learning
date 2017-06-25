#include<stdio.h>
#include <graphics.h> 
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
//#include<gl/glut.h>
void doubleone(int x0,int y0,int x1,int d,int upincre,int downincre,int color,int mark);
void doubletwo(int x0,int y0,int y1,int d,int leftincre,int rightincre,int color,int mark);
void allline(int x0,int y0,int x1,int y1,int color)
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
			doubleone(x0,y0,x1,d,upincre,downincre,color,1);
		}
		else
		{
			dx=x1-x0;dy=y1-y0;
			d=-dx-2*dy;
			downincre=-2*dx-2*dy;
			upincre=-2*dy;
			doubleone(x0,y0,x1,d,upincre,downincre,color,2);
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
			doubletwo(x0,y0,y1,d,leftincre,rightincre,color,1);
		}
		else
		{
			dx=x1-x0;dy=y1-y0;
			d=2*dx+dy;
			leftincre=2*dx+2*dy;
			rightincre=2*dx;
			doubletwo(x0,y0,y1,d,leftincre,rightincre,color,2);
		}
	}
}
void doubleone(int x0,int y0,int x1,int d,int upincre,int downincre,int color,int mark)
{
	int x,y;
	x=x0;y=y0;
	while(x<=x1)
	{
		putpixel(x,y,color); 
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
}
void doubletwo(int x0,int y0,int y1,int d,int leftincre,int rightincre,int color,int mark)
{
	int x,y;
	x=x0;y=y0;
	while(y<=y1)
	{
		putpixel(x,y,color);
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
}
void zuobiaoxi()
{
	int i,j;
	allline(-200,0,200,0,RED);
	allline(0,-200,0,200,RED);
	for(i=-200;i<=200;i+=10)
	{
		for(j=0;j<5;j++)
		{
			putpixel(i,j,RED);
			putpixel(j,i,RED);
		}
	}
}
int main()
{
	initgraph(640,480);
	setorigin(200,200);
	setaspectratio(1,-1);
	zuobiaoxi();
	allline(-100,-50,100,50,WHITE);
	allline(-50,-100,50,100,WHITE);
	allline(100,-50,-100,50,WHITE);
	allline(50,-100,-50,100,WHITE);

	getch();
	closegraph();
	return 0;
}

