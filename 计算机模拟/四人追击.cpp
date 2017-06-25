#include<stdio.h>
#include <graphics.h> 
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#define P 3.1415926
#define N 500
void doubleone(int x0,int y0,int x1,int d,int upincre,int downincre,int color,int mark);
void doubletwo(int x0,int y0,int y1,int d,int leftincre,int rightincre,int color,int mark);
struct dian
{
	double x, y;

};
struct Angle
{
	double Cos, Sin;
};
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
	allline(-400,0,400,0,RED);
	allline(0,-400,0,400,RED);
	for(i=-400;i<=400;i+=10)
	{
		for(j=0;j<5;j++)
		{
			putpixel(i,j,RED);
			putpixel(j,i,RED);
		}
	}
}

double distance(struct dian p1, struct dian p2)
{
	double dis;
	dis = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
	return dis;
}
struct dian minlater(struct dian p, int angle, int speed)
{
	double x, y;
	struct dian a;
	x = speed*cos(angle*P/180);
	y = speed*sin(angle*P/180);
	a.x = p.x + x;
	a.y = p.y - y;
	return a;
}
struct dian minlater(struct dian p, struct Angle ang, int speed,int mark)
{
	double x, y;
	struct dian a;
	x = speed*ang.Cos;
	y = speed*ang.Sin;
	
	if(mark==1)
	{
		a.x = p.x + x;
		a.y = p.y - y;
	}
	else if(mark==2)
	{
		a.x = p.x-x;
		a.y=p.y-y;
	}
	else if(mark==3)
	{
		a.x=p.x+x;
		a.y=p.y+y;
	}
	else
	{
		a.x=p.x-x;
		a.y=p.y+y;
	}
	return a;
}
struct Angle doublevertex(struct dian x1, struct dian x2)
{
	double cos, sin;
	double dis;
	struct Angle a;
	dis = distance(x1, x2);
	cos = fabs(x1.x - x2.x) / dis;
	sin = fabs(x1.y - x2.y) / dis;
	a.Cos = cos;
	a.Sin = sin;
	return a;
}
struct dian zhuiji(struct dian p1,struct dian p2,int speed,int color)
{
	struct dian next;
	struct Angle a;
	a=doublevertex(p1,p2);
	if(p1.x<p2.x&&p1.y>p2.y)
		next=minlater(p1,a,speed,1);
	else if(p1.x>p2.x&&p1.y>p2.y)
		next=minlater(p1,a,speed,2);
	else if(p1.x<p2.x&&p1.y<p2.y)
		next=minlater(p1,a,speed,3);
	else
		next=minlater(p1,a,speed,4);

	allline((int)p1.x,(int)p1.y,(int)next.x,(int)next.y,color);


	return next;

}

int main()
{
	int i;
	struct dian d[8],n[4];
	srand((unsigned int)time(0));
	initgraph(1000,800);
	setorigin(500,400);
	setaspectratio(1,-1);
	zuobiaoxi();
	d[0].x=-200;
	d[0].y=200;
	d[1].x=200;
	d[1].y=200;
	d[2].x=200;
	d[2].y=-200;
	d[3].x=-200;
	d[3].y=-200;
	d[4].x=-100;
	d[4].y=100;
	d[5].x=100;
	d[5].y=100;
	d[6].x=100;
	d[6].y=-100;
	d[7].x=-100;
	d[7].y=-100;
	for(i=0;i<N;i++)
	{
		if(distance(d[0],d[1])<=0.01)
			break;
/*		n[0]=zhuiji(d[0],d[1]);
		n[1]=zhuiji(d[1],d[2]);
		n[2]=zhuiji(d[2],d[3]);
		n[3]=zhuiji(d[3],d[0]);

		allline((int)d[0].x,(int)d[0].y,(int)n[0].x,(int)n[0].y,WHITE);
		allline((int)d[1].x,(int)d[1].y,(int)n[1].x,(int)n[1].y,WHITE);
		allline((int)d[2].x,(int)d[2].y,(int)n[2].x,(int)n[2].y,WHITE);
		allline((int)d[3].x,(int)d[3].y,(int)n[3].x,(int)n[3].y,WHITE);*/
		d[0]=zhuiji(d[0],d[7],2,GREEN);
		d[1]=zhuiji(d[1],d[6],2,GREEN);
		d[2]=zhuiji(d[2],d[5],2,GREEN);
		d[3]=zhuiji(d[3],d[4],2,GREEN);
		d[4]=zhuiji(d[4],d[5],1,WHITE);
		d[5]=zhuiji(d[5],d[6],1,WHITE);
		d[6]=zhuiji(d[6],d[7],1,WHITE);
		d[7]=zhuiji(d[7],d[4],1,WHITE);

		Sleep(50);
		
	}
	getch();
	closegraph();
	return 0;
}
		