#include <stdio.h>
#include<time.h>
#include <math.h>
#include<graphics.h>
#include<conio.h>
#define	MAXLENGTH 3200
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

struct dian zhongzi;
int N=0;
struct dian * huaxian(void)
{
	struct dian *D;
	int i,n,ymin=1000000,ymax=-1000000,xmax=-10000000,xmin=100000000;


	printf("请输入共有几个点:");
	scanf("%d",&n);
	fflush(stdin);
	D=(struct dian *)malloc(sizeof(struct dian)*n);
	printf("请依次输入个点（x,y逗号隔开）每行一个\n");
	for(i=0;i<n;i++)
	{
		scanf("%d,%d",&D[i].x,&D[i].y);
		fflush(stdin);
	}
	N=n;
	printf("请输入种子点，确保在图形内部（x,y逗号隔开）\n");
	scanf("%d,%d",&zhongzi.x,&zhongzi.y);
	fflush(stdin);
	return D;
}
void tianchong(struct dian * D)
{
	struct dian stack[10000],nowdian,newdian;
	int i,j,top=0;
	int x1=0,x2=0;
	int qujian[MAXLENGTH][3];
	int num;
	for(i=0,j=1;i<N;i++,j++)
	{
		if(j==N)
			j=0;
		allline(D[i].x,D[i].y,D[j].x,D[j].y,GREEN);
	}
	free(D);
	stack[top++]=zhongzi;
	while(top!=0)
	{ 
		num=0;
		nowdian=stack[--top];
		newdian.y=nowdian.y;
		for(i=nowdian.x;;i++)
		{
			newdian.x=i;
			if(getpixel(newdian.x,newdian.y)!=GREEN)
			{
				putpixel(newdian.x,newdian.y,GREEN);
			}
			else
				break;
		}
		x2=i;
		for(i=nowdian.x-1;;i--)
		{
			newdian.x=i;
			if(getpixel(newdian.x,newdian.y)!=GREEN)
			{
				putpixel(newdian.x,newdian.y,GREEN);
			}
			else
				break;
		}
		x1=i;
		newdian.y++;
		qujian[num][0]=x1;
		qujian[num][1]=x1;
		qujian[num][2]=1;
		for(i=x1;i<=x2;i++)
		{
			newdian.x=i;
			if(getpixel(newdian.x,newdian.y)!=GREEN)
			{
				qujian[num][1]++;
			}
			else
			{
				qujian[++num][0]=i;
				qujian[num][1]=i;
				qujian[num][2]=1;
			}
		}
		newdian.y-=2;
		qujian[num][0]=x1;
		qujian[num][1]=x1;
		qujian[num][2]=-1;
		for(i=x1;i<=x2;i++)
		{
			newdian.x=i;
			if(getpixel(newdian.x,newdian.y)!=GREEN)
			{
				qujian[num][1]++;
			}
			else
			{
				qujian[++num][0]=i;
				qujian[num][1]=i;
				qujian[num][2]=-1;
			}
		}
		for(i=0;i<num;i++)
		{
			if(qujian[i][1]-qujian[i][0]>0)
			{
				newdian.x=qujian[i][0];
				newdian.y=qujian[i][2]+nowdian.y;
				stack[++top]=newdian;
			}
		}		
	}

}
int main()
{
	struct dian * D;
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