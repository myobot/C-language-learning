

#include "circle.h"


void drawCircleBresenham(int centerX,int centerY,float r)

{
    glColor3f(0.0f,1.0f,0.0f);//���õ����ɫ
    glBegin(GL_POINTS);//�Ե�ķ�ʽ����	
	
    /*�˴���д����Բ����* �������ص���ɫΪ glVertex2i(x,y)*/
	
    printf("(%d,%d) r=%f\n",centerX,centerY,r);
	
	glEnd();//��������
	
}
