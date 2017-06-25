#include <stdio.h>
#include<time.h>
#include <math.h>
#include<graphics.h>
#include<conio.h>
//#define JBS 20
int JBS=0;
struct AET
{
	double x;
	int ymax;
	double Dk;
	struct AET *next;
};
struct dian
{
	int x;
	int y;
};
struct AET *chushihua(void)
{
	struct dian *D;
	struct AET *tong,*p,*N;
	int i,j,n,ymin=1000000,ymax=-1000000,ym,xmax=-10000000,xmin=100000000;
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
	JBS=xmax-xmin;
	tong=(struct AET *)malloc(sizeof(struct AET)*(ymax-ymin));
	for(i=0;i<ymax-ymin;i++)
		tong[i].next=NULL;
	for(i=0,j=1;i<n;i++,j++)
	{
		if(j==n)
			j=0;
		N=(struct AET *)malloc(sizeof(struct AET));
		if(D[i].y<D[j].y)
		{
			N->x=D[i].x;
			N->ymax=D[j].y;
			ym=D[i].y;
		}
		else
		{
			N->x=D[j].x;
			N->ymax=D[i].y;
			ym=D[j].y;
		}
		if(D[i].y-D[j].y!=0)
			N->Dk=(double)(D[i].x-D[j].x)/(D[i].y-D[j].y);
		else
			N->Dk=(double)(D[i].x-D[j].x)*1000000;
		p=&tong[ym-ymin];
		while(p)
		{
			if(p->next==NULL)
			{
				N->next=p->next;
				p->next=N;
				break;
			}
			if(N->x<p->next->x||(N->x==p->next->x&&N->Dk<p->next->Dk))
			{
				N->next=p->next;
				p->next=N;
				break;
			}
			if((N->x>p->next->x&&p->next->next==NULL)||(N->x>p->next->x&&N->x<p->next->next->x)||(N->x==p->next->x&&N->Dk>p->next->Dk))
			{
				N->next=p->next->next;
				p->next->next=N;
				break;
			}
			p=p->next;
		}
		
	}
	tong[0].x=ymin;
	tong[0].ymax=ymax;
	return tong;
}
void Swap(struct AET *p1,struct AET *p2)
{
	struct AET swap;
	swap.x=p1->x;
	swap.ymax=p1->ymax;
	swap.Dk=p1->Dk;
	p1->x=p2->x;
	p1->ymax=p2->ymax;
	p1->Dk=p2->Dk;
	p2->x=swap.x;
	p2->ymax=swap.ymax;
	p2->Dk=swap.Dk;
}
void Sort(struct AET *head)
{
	struct AET *k,*p,*q,*f;
	p=head;
	while(p)
	{
		q=p->next;
		f=q;k=p;
		while(q)
		{
			if(k->x>q->x)
				k=q;
			q=q->next;
		}
		if(k->next!=f)
		{
			Swap(p,k);
		}
		p=p->next;
	}
}
struct AET *copy(struct AET *H)
{
	struct AET *P,*Q,*F=NULL,*A;
	int i=0;
	P=H;
	A=F;
	while(P)
	{
		i++;
		F=(struct AET *)malloc(sizeof(struct AET));
		F->x=P->x;
		F->Dk=P->Dk;
		F->ymax=P->ymax;
		F->next=NULL;
		if(i==1)
		{
			Q=F;
			A=F;
		}
		else
			Q->next=F;
		P=P->next;
	}
	return A;
}
void tianchong(const struct AET *tong,int COLOR)
{
	int i,j,k;
	struct AET *L,*P,*Q,*E,*W;
	double d=0;

	for(k=0;k<JBS;k++)
	{
		L=(struct AET *)malloc(sizeof(struct AET));
		L->next=NULL;
		for(i=(int)tong[0].x;i<(int)tong[0].ymax;i++)
		{
			W=copy(tong[i-(int)tong[0].x].next);
			E=L;
			while(E->next)
				E=E->next;
			E->next=W;
			P=L;
			while(P->next)
			{
				if(P->next->ymax==i)
				{
					Q=P->next;
					P->next=Q->next;
					free(Q);
				}
				else
					P=P->next;
			}
			Sort(L->next);
			P=L->next;
		
				while(P)
				{
					for(j=(int)P->x+k;j<(int)P->next->x;j+=JBS)
					{
						putpixel(j,i,COLOR);
					}
					
					P->x=(P->x+P->Dk);
					
					P->next->x=(P->next->x+P->next->Dk);

					P=P->next->next;
				}
		}
		while(L)
		{
			P=L->next;
			free(L);
			L=P;
		}	
		Sleep(40);
	}
	
}


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
	struct AET *tong,*Q,*P;
	int i;

	tong=chushihua();

	initgraph(640,480);
	setorigin(200,200);
	setaspectratio(1,-1);
	zuobiaoxi();

	tianchong(tong,RED);

	for(i=0;i<tong[0].ymax-tong[0].x;i++)
	{
		P=tong[i].next;
		while(P)
		{
			Q=P->next;
			free(P);
			P=Q;
		}
	}

	free(tong);

	getch();
	closegraph();
	return 0;
}