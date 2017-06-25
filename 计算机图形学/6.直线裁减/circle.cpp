

#include "circle.h"


void drawCircleBresenham(int centerX,int centerY,float r)

{
    glColor3f(0.0f,1.0f,0.0f);//设置点的颜色
    glBegin(GL_POINTS);//以点的方式绘制	
	
    /*此处填写绘制圆代码* 设置像素点颜色为 glVertex2i(x,y)*/
	
    printf("(%d,%d) r=%f\n",centerX,centerY,r);
	
	glEnd();//结束绘制
	
}
