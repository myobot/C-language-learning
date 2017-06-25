#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<cstdlib>
#include<math.h>
#define P 3.1415926
#define N 15
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
struct jihe
{
	struct dian jianji[N+2], hongzha[N+2];
	int numberj, numberh;
};
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
struct jihe moni(void)
{
	int angle, i;
	struct Angle a;
	struct dian j1, j2, h1, h2;
	struct jihe j;
	j1.x = 0; j1.y = 50;
	h1.x = 80; h1.y = 0;
	j.numberh = 0;
	j.numberj = 0;
	j.jianji[j.numberj++] = j1;
	j.hongzha[j.numberh++] = h1;

	for (i = 0; i < N; i++)
	{
		if (distance(j1, h1) < 10)
		{
			break;
		}
		angle = rand() % 91;
		a = doublevertex(j1, h1);
		if(j1.y>h1.y&&j1.x<h1.x)
			j2 = minlater(j1,a,32,1);
		else if(j1.y>h1.y&&j1.x>h1.x)
			j2=minlater(j1,a,32,2);
		else if(j1.y<h1.y&&j1.x<h1.x)
			j2=minlater(j1,a,32,3);
		else
			j2=minlater(j1,a,32,4);
		h2 = minlater(h1, angle, 12);
		
		j.jianji[j.numberj++] = j2;
		
		j.hongzha[j.numberh++] = h2;
		j1 = j2;
		h1 = h2;
	}
	return j;
}

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
	jihe a;
	int i,j;
	srand((unsigned int)time(0));
	initgraph(1600,1000);
	setorigin(800,500);
	setaspectratio(3,-3);
	zuobiaoxi();
	a=moni();
	for(i=0,j=1;i<a.numberj-1;j++,i++)
	{
		allline((int)a.jianji[i].x,(int)a.jianji[i].y,(int)a.jianji[j].x,(int)a.jianji[j].y,WHITE);
		allline((int)a.hongzha[i].x,(int)a.hongzha[i].y,(int)a.hongzha[j].x,(int)a.hongzha[j].y,GREEN);
		Sleep(1000);
	}
	getch();
	closegraph();
	return 0;
}

