#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void doubleone(int x0,int y0,int x1,int dx,int dy,int e,int color,int mark);
void doubletwo(int x0,int y0,int y1,int dx,int dy,int e,int color,int mark);
void allline2(int x0,int y0,int x1,int y1,int color)
{
	double k;
	int x,y,dx,dy,e;
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
		dx=x1-x0;dy=y1-y0;
		e=-dx;
		if(k<=1&&k>=0)
		{
			doubleone(x0,y0,x1,dx,dy,e,color,1);
		}
		else
			doubleone(x0,y0,x1,dx,dy,e,color,2);
	}
	else
	{
		if(y0>y1)
		{
			x=x1;x1=x0;x0=x;
			y=y1;y1=y0;y0=y;
		}
		dx=x1-x0;dy=y1-y0;
		e=-dy;
		if(k>1)
		{
			doubletwo(x0,y0,y1,dx,dy,e,color,1);
		}
		else
			doubletwo(x0,y0,y1,dx,dy,e,color,2);
	}

}
void doubleone(int x0,int y0,int x1,int dx,int dy,int e,int color,int mark)
{
	int x,y;
	x=x0;y=y0;
	while(x<=x1)
	{
		putpixel(x,y,color);
	
		if(mark==1)
		{
			x++;
			e=e+2*dy;
			if(e>0)
			{
				y++;      
				e=e-2*dx;
			}
		}
		if(mark==2)
		{
			x++;
			e=e+2*dy;
			if(e>0)
			{
				y--;
				e=e-2*dx;
			}
		
		}
	}
}
void doubletwo(int x0,int y0,int y1,int dx,int dy,int e,int color,int mark)
{
	int x,y;
	x=x0;y=y0;
	while(y<=y1)
	{
		putpixel(x,y,color);
		y++;
		e=e+2*dx;
		if(e>0&&mark==1)
		{
			x++;
			e=e-2*dy;
		}
		if(e>0&&mark==2)
		{
			x--;
			e=e-2*dy;
		}


	}
}
void zuobiaoxi()
{
	int i,j;
	allline2(-200,0,200,0,RED);
	allline2(0,-200,0,200,RED);
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
/*	allline2(0,0,100,50,WHITE);
	allline2(0,0,50,100,WHITE);
	allline2(0,0,-100,50,WHITE);
	allline2(0,0,-50,100,WHITE);
	allline2(0,0,-100,-50,WHITE);
	allline2(0,0,-50,-100,WHITE);
	allline2(0,0,100,-50,WHITE);
	allline2(0,0,50,-100,WHITE);*/
	allline2(-100,-50,100,50,WHITE);
	allline2(-50,-100,50,100,WHITE);
	allline2(100,-50,-100,50,WHITE);
	allline2(50,-100,-50,100,WHITE);
	getch();
	closegraph();
	return 0;
}