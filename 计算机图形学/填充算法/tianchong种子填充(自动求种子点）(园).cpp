#include <stdio.h>
#include<time.h>
#include <math.h>
#include<graphics.h>
#include<conio.h>
#define MAXVERTEX 100000
void doubleone(int x0,int y0,int x1,int d,int upincre,int downincre,int color,int mark);
void doubletwo(int x0,int y0,int y1,int d,int leftincre,int rightincre,int color,int mark);
struct dian
{
	int x;
	int y;
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
void Randshuzu(int Rand[])
{
	int i,j,k,r;
	int set[4],fuzhu[4];
	for(i=0;i<4;i++)
	{
		set[i]=i;
	}
	k=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(set[j]!=-1)
				fuzhu[k++]=i;
		}
		r=rand()%4;
		Rand[i]=set[fuzhu[r]];
		set[fuzhu[r]]=-1;
	}
}

void CirclePoint(int centerX,int centerY,int x,int y)
{

	putpixel(x+centerX,y+centerY,GREEN);		//平移centerX,centerY
	putpixel(y+centerX,x+centerY,GREEN);
	putpixel(-y+centerX,x+centerY,GREEN);
	putpixel(-x+centerX,y+centerY,GREEN);
	putpixel(-x+centerX,-y+centerY,GREEN);
	putpixel(-y+centerX,-x+centerY,GREEN);
	putpixel(y+centerX,-x+centerY,GREEN);
	putpixel(x+centerX,-y+centerY,GREEN);
	
}
void drawCircleBresenham(int centerX,int centerY,int r)

{
//	glTranslated((double) centerX, (double) centerY, 0.0);
   
	
    /*此处填写绘制圆代码* 设置像素点颜色为 glVertex2i(x,y)*/
	int x,y,d;
	x=0;y=r;d=1-r;					//圆心不动
	while(x<=y)
	{
		CirclePoint(centerX,centerY,x,y);
		if(d<0)
			d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			y--;
		}
		x++;
	}


	
    printf("(%d,%d) r=%f\n",centerX,centerY,r);
	
	
	
}
int N=0;
int r;
struct dian huaxian(void)
{
	struct dian D;


	printf("请依次输入圆心\n");
	scanf("%d,%d",&D.x,&D.y);
	fflush(stdin);
	printf("请输入半径\n");
	scanf("%d",&r);

	
	return D;
}
void tianchong(struct dian D)
{
	struct dian stack[MAXVERTEX],nowdian,newdian;
	struct dian zhongzi;
	
	zhongzi.x=D.x;
	zhongzi.y=D.y;
	int top=0;
	drawCircleBresenham(D.x,D.y,r);

	stack[top++]=zhongzi;
	while(top!=0)
	{
		nowdian=stack[--top];
		putpixel(nowdian.x,nowdian.y,GREEN);

		newdian=nowdian;
		newdian.x++;
		if(getpixel(newdian.x,newdian.y)!=GREEN)
			stack[top++]=newdian;
	
		newdian=nowdian;
		newdian.y++;
		if(getpixel(newdian.x,newdian.y)!=GREEN)
			stack[top++]=newdian;
			
	
		newdian=nowdian;
		newdian.x--;
		if(getpixel(newdian.x,newdian.y)!=GREEN)
			stack[top++]=newdian;
		
		newdian=nowdian;
		newdian.y--;
		if(getpixel(newdian.x,newdian.y)!=GREEN)
			stack[top++]=newdian;
				
		
	}

}
int main()
{
	struct dian D;
	D=huaxian();
	srand((unsigned int)time(0));
	initgraph(640,480);
	setorigin(200,200);
	setaspectratio(1,-1);
	zuobiaoxi();
	tianchong(D);
	getch();
	closegraph();
	return 0;
}