#include  "glut.h"
#include<stdio.h>
void init()
{
	glClearColor(0.0,0.0,0.0,0.0);	//背景清除颜色


}
/*void mouse(int button,int state,int x,int y)
{
/*	int button,state,x,y;
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor4f(0.2,0.6,1.0,1.0);		//图形绘制颜色
	glRotatef(40.0,-40.0,-20.0,1.0);	//设置旋转
	glutWireTeapot(0.5);		//绘制线模型模式茶壶
		
		glFlush();		//完成绘制
	if(button==0)
		printf("左键\n");
	else
		printf("右键\n");
	if(state==0)
		printf("按下\n");
	else
		printf("弹开\n");
	printf("%d,%d\n",x,y);


}*/

void display1(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(0.2,0.6,1.0,1.0);
	glBegin(GL_LINES);
		glVertex2f(0.1,0.1);
		glVertex2f(0.2,0.0);
		glVertex2f(0.3,0.1);
		glVertex2f(0.4,0.2);
		glVertex2f(0.5,0.3);
		glVertex2f(-0.4,0.4);
	glEnd();
	
		
	glFlush();		//完成绘制
}
void display2(void)
{
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor4f(0.2,0.6,1.0,1.0);
	glBegin(GL_LINE_STRIP);
		glVertex2f(0.1,0.1);
		glVertex2f(0.2,0.0);
		glVertex2f(0.3,0.1);
		glVertex2f(0.4,0.2);
		glVertex2f(0.5,0.3);
		glVertex2f(-0.4,0.4);
	glEnd();
	
		
	glFlush();
}
void display3()
{
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor4f(1.0,1.0,1.0,1.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(0.1,0.1);
		glVertex2f(0.2,0.0);
		glVertex2f(0.3,0.1);
		glVertex2f(0.4,0.2);
		glVertex2f(0.5,0.3);
		glVertex2f(-0.4,0.4);
	glEnd();
	
		
	glFlush();
}
void display4(void)
{
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor4f(1.0,1.0,1.0,1.0);
    glBegin(GL_POLYGON);
		glVertex2f(-0.5, -0.5);
		glVertex2f(-0.5, 0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.5, -0.5);
	glEnd();

	
		
	glFlush();
}
void display5(void)
{
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor4f(1.0,1.0,1.0,1.0);
    glBegin(GL_QUADS);
		glVertex2f(-0.2, -0.1);
		glVertex2f(-0.1, -0.3);
		glVertex2f(-0.5, -0.4);
		glVertex2f(-0.3, -0.5);
		glVertex2f(0.3,0.1);
		glVertex2f(0.4,0.2);
		glVertex2f(0.5,0.3);
		glVertex2f(-0.4,0.4);
	glEnd();

	
		
	glFlush();
}
void display6(void)
{
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor4f(1.0,1.0,1.0,1.0);
    glBegin(GL_QUAD_STRIP);
		glVertex2f(-0.2, -0.1);
		glVertex2f(-0.1, -0.3);
		glVertex2f(-0.5, -0.4);
		glVertex2f(-0.3, -0.5);
		glVertex2f(0.3,0.1);
		glVertex2f(0.4,0.2);
		glVertex2f(0.5,0.3);
		glVertex2f(-0.4,0.4);
	glEnd();

	
		
	glFlush();
}
void display7(void)
{
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor4f(1.0,1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
		glVertex2f(-0.2, -0.1);
		glVertex2f(-0.1, -0.3);
		glVertex2f(-0.5, -0.4);
		glVertex2f(0.4,0.2);
		glVertex2f(0.5,0.3);
		glVertex2f(-0.4,0.4);
	glEnd();


	glFlush();
}
void display8(void)
{
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor4f(1.0,1.0,1.0,1.0);
    glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(-0.2, -0.1);
		glVertex2f(-0.1, -0.3);
		glVertex2f(-0.5, -0.4);
		glVertex2f(0.4,0.2);
		glVertex2f(0.5,0.3);
		glVertex2f(-0.4,0.4);
	glEnd();


	glFlush();
}
void display9(void)
{
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor4f(1.0,1.0,1.0,1.0);
    glBegin(GL_TRIANGLE_FAN);
		glVertex2f(-0.2, -0.1);
		glVertex2f(-0.1, -0.3);
		glVertex2f(-0.5, -0.4);
		glVertex2f(0.4,0.2);
		glVertex2f(0.5,0.3);
		glVertex2f(-0.4,0.4);
	glEnd();


	glFlush();
}
extern void APIENTRY glutKeyboardFunc(void (*func)(unsigned char key, int x, int y));

int main(int argc, char** argv)
{
	glutInitWindowSize(800,800);	//设置窗口大小
	glutInitWindowPosition(60,60);	//设置窗口显示位置
	glutCreateWindow("WireTeapot");//设置窗口标题

	glutDisplayFunc(display9);
	init();	
	glutMainLoop();		
	return 0;
}

