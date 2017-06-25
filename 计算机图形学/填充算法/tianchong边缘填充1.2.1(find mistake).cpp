#include <stdio.h>
#include<time.h>
#include <math.h>
#include<graphics.h>
#include<conio.h>
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

int Xmax,Xmin,Ymax,Ymin,N;

int dele[1000],Num=0;		//忽略点集合

struct dian * huaxian(void)
{
	struct dian *D;
	int i,n,ymin=1000000,ymax=-1000000,xmax=-10000000,xmin=100000000;
	int x0,x1,x2;

	printf("请输入共有几个点:");
	scanf("%d",&n);
	fflush(stdin);
	D=(struct dian *)malloc(sizeof(struct dian)*n);
	printf("请依次输入个点（逗号隔开）每行一个\n");
	for(i=0;i<n;i++)
	{
		scanf("%d,%d",&D[i].x,&D[i].y);
		fflush(stdin);
	}
	for(i=0;i<n;i++)
	{
		if(ymax<D[i].y)
			ymax=D[i].y;
		if(ymin>D[i].y)
			ymin=D[i].y;
		if(xmax<D[i].x)
			xmax=D[i].x;
		if(xmin>D[i].x)
			xmin=D[i].x;
	}
	for(x0=n-1,x1=0,x2=1;x1<n;x1++,x0++,x2++)
	{
	
		if(x0==n)
			x0=0;
		if(x2==n)
			x2=0;
		
		if((D[x0].y<D[x1].y&&D[x2].y<D[x1].y)||(D[x0].y>D[x1].y&&D[x2].y>D[x1].y))	//找出忽略点 这个点的y要么都大于前一个点的y和下一个点的y，要么都小于
		{
			dele[Num++]=x1;
		}

		
	}
	Xmax=xmax;
	Xmin=xmin;
	Ymax=ymax;
	Ymin=ymin;
	N=n;
	return D;
}

void tianchong(struct dian * D)
{
	int x,y,mark=0,i,j,k,l=1,mark2=0;
	for(i=0,j=1;i<N;i++,j++)
	{
		if(j==N)
			j=0;
		allline(D[i].x,D[i].y,D[j].x,D[j].y,GREEN);
	}
	for(y=Ymin+1;y<Ymax;y++)
	{
		
		for(x=Xmin;x<=Xmax;x++)
		{
			if(l==0)
			{
				if(getpixel(x,y)==GREEN)
					continue;
				else
					l=1;
			}
			mark2=0;
			for(k=0;k<Num;k++)
			{
				if(x==D[dele[k]].x&&y==D[dele[k]].y)
				{
					mark2=1;break;
				}
			}
			//斜率小于1/ 每行有偶数个点相连,导致错误	
			
		
		

			if(getpixel(x,y)==GREEN&&mark2==0)
			{
			
				if(mark==1)
					mark=0;
				else
					mark=1;
				l=0;
			}

			if(mark==1)
			{
				putpixel(x,y,GREEN);
			}
		}
		Sleep(100);
	}
	free(D);
}
int main()
{
	struct dian * D;
	D=huaxian();
	initgraph(640,480);
	setorigin(200,200);
	setaspectratio(1,-1);
	zuobiaoxi();
	tianchong(D);
	getch();
	closegraph();
	return 0;
}
