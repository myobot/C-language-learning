

#include "Line.h"
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
struct AET *chushihua(int x1,int y1,int x2,int y2,int x3,int y3)
{
	struct dian *D;
	struct AET *tong,*p,*N;
	int i,j,n=3,ymin=1000000,ymax=-1000000,ym;


	D=(struct dian *)malloc(sizeof(struct dian)*n);
	
	D[0].x=x1;
	D[0].y=y1;
	D[1].x=x2;
	D[1].y=y2;
	D[2].x=x3;
	D[2].y=y3;

	for(i=0;i<n;i++)
	{
		if(ymax<D[i].y)
			ymax=D[i].y;
		if(ymin>D[i].y)
			ymin=D[i].y;
	}
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

void tianchong(struct AET *tong)
{
	glColor3f(0.0f,1.0f,0.0f);//设置点的颜色
    glBegin(GL_LINES);//以点的方式绘制	
	int i,j;
	struct AET *L,*P,*Q,*E;
	double d=0;
	L=(struct AET *)malloc(sizeof(struct AET));
	L->next=NULL;
	for(i=(int)tong[0].x;i<(int)tong[0].ymax;i++)
	{
		P=&tong[i-(int)tong[0].x];
		E=L;
		while(E->next)
			E=E->next;
		E->next=P->next;
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
			for(j=(int)P->x;j<(int)P->next->x;j++)
			{
				glVertex2i(j,i);
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

	glEnd();//结束绘制
	glFlush();
}

void drawLineBresenham(int x1 ,int y1,int x2,int y2)

{
    glColor3f(0.0f,1.0f,0.0f);//设置点的颜色
    glBegin(GL_LINES);//以点的方式绘制	
 
    glVertex2i(x1,y1);
	glVertex2i(x2,y2);

	glEnd();//结束绘制
	glFlush();
	
}



/*填充三角形，传入参数为三角三个点的坐标*/

void fillTriangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
	struct AET *tong,*P,*Q;
	int i;
	
	tong=chushihua(x1,y1,x2,y2,x3,y3);
	tianchong(tong);
	free(tong);

}
