

#include "circle.h"

void CirclePoint(int centerX,int centerY,int x,int y)
{
	glColor3f(0.0f,1.0f,0.0f);
	glBegin(GL_POINTS);
	glVertex2i(x+centerX,y+centerY);		//ƽ��centerX,centerY
	glVertex2i(y+centerX,x+centerY);
	glVertex2i(-y+centerX,x+centerY);
	glVertex2i(-x+centerX,y+centerY);
	glVertex2i(-x+centerX,-y+centerY);
	glVertex2i(-y+centerX,-x+centerY);
	glVertex2i(y+centerX,-x+centerY);
	glVertex2i(x+centerX,-y+centerY);
	glEnd();
	glFlush();
}
void drawCircleBresenham(int centerX,int centerY,float r)

{
//	glTranslated((double) centerX, (double) centerY, 0.0);
   
	
    /*�˴���д����Բ����* �������ص���ɫΪ glVertex2i(x,y)*/
	int x,y,d;
	x=0;y=r;d=1-r;					//Բ�Ĳ���
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
