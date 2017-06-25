
#include "stdAfx.h"
#include "transform.h"
#include  "clip.h"



//定义2维空间内的点（x,y)
typedef struct Point2D  
{
	float x;
	float y;
}Point2D;
//定义三角形的三个点
Point2D a ,b,c ;

void drawTrangle(Point2D a,Point2D b,Point2D c)
{
	glClearColor(1.0f,1.0f,1.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0f,0.0f,0.0f);//设置点的颜色
    glLineWidth(5.0f);
	glBegin(GL_LINE_LOOP);//以点的方式绘制	
    
	glVertex2f(a.x,a.y);
	glVertex2f(b.x,b.y);
	glVertex2f(c.x,c.y);
 
	
	glEnd();//结束绘制
	glFlush();

}


void drawRect(int left,int right,int top ,int bottom)
{
	glColor3f(0.0f,0.0f,0.0f);//设置点的颜色
    glLineWidth(5.0f);
	glBegin(GL_LINE_LOOP);//以点的方式绘制	
    
    glVertex2i(left,top);
	glVertex2i(right,top);
	glVertex2i(right,bottom);
    glVertex2i(left,bottom);
	glEnd();//结束绘制
	glFlush();

}


void drawLine(int x1,int y1,int x2,int y2)
{

	
	glColor3f(1.0f,0.0f,0.0f);//设置点的颜色
    glLineWidth(5.0f);
	glBegin(GL_LINES);//以点的方式绘制	
    
	glVertex2i(x1,y1);
	glVertex2i(x2,y2);

 
	
	glEnd();//结束绘制
	glFlush();

}




//定义显示函数
void display()
{


  drawTrangle(a,b,c);

  drawRect(50,350,300,100);
	
}



//普通按键被按下时，调用此函数
void processNormalKeys(unsigned char key,int x,int y)
{
   key  = key|0x20;
  switch(key)
  {
  case 'a':
	  translateTrangle(a.x,a.y,b.x,b.y,c.x,c.y,-2,0);
	  drawTrangle(a,b,c);
	   drawRect(50,350,300,100);
  	break;
  case 'd':
	  translateTrangle(a.x,a.y,b.x,b.y,c.x,c.y,+2,0);
	  drawTrangle(a,b,c);
	   drawRect(50,350,300,100);
	  break;
  case 'w':
	   translateTrangle(a.x,a.y,b.x,b.y,c.x,c.y,0,2);
	  drawTrangle(a,b,c);
	   drawRect(50,350,300,100);
	  break;
  case 's':
	  translateTrangle(a.x,a.y,b.x,b.y,c.x,c.y,0,-2);
	  drawTrangle(a,b,c);
	   drawRect(50,350,300,100);
	  break;
  case 'f':
	  rotateTrangle(a.x,a.y,b.x,b.y,c.x,c.y,5);
	  drawTrangle(a,b,c);
	   drawRect(50,350,300,100);
	  break;
  case 'g':
	  rotateTrangle(a.x,a.y,b.x,b.y,c.x,c.y,-5);
	  drawTrangle(a,b,c);
	   drawRect(50,350,300,100);
	  break;
  case 'z':
	  scaleTrangle(a.x,a.y,b.x,b.y,c.x,c.y,1.1,1.1);
	  drawTrangle(a,b,c);
	   drawRect(50,350,300,100);
	  break;
  case 'x':
	  scaleTrangle(a.x,a.y,b.x,b.y,c.x,c.y,0.9,0.9);
	  drawTrangle(a,b,c);
	  drawRect(50,350,300,100);
	  break;
  case 'c':
	 
	 glClearColor(1.0f,1.0f,1.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	  Point2D t1,t2;
	  t1.x = a.x;
	  t1.y = a.y ;
	  t2.x = b.x;
	  t2.y = b.y ;
	
	if(clipLine(50,350,300,100,t1.x,t1.y ,t2.x,t2.y))
		  drawLine(t1.x,t1.y ,t2.x,t2.y);
	 
	t1.x = b.x;
	t1.y = b.y ;
	t2.x = c.x;
	t2.y = c.y ;
	
	if(clipLine(50,350,300,100,t1.x,t1.y ,t2.x,t2.y))
		  drawLine(t1.x,t1.y ,t2.x,t2.y);
	  
	t1.x = c.x;
	t1.y = c.y ;
	t2.x = a.x;
	t2.y = a.y ;
	
	if(clipLine(50,350,300,100,t1.x,t1.y ,t2.x,t2.y))
		drawLine(t1.x,t1.y ,t2.x,t2.y);
	  
	   drawRect(50,350,300,100);
	  
	  break;
 
  }
  	

}


void  main ()
{
	
//三角形三个点赋初值	
a.x = 50;
a.y = 50;
b.x = 10;
b.y = 350;
c.x = 350;
c.y = 350;

	
	
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	
	glutInitWindowPosition(600,400);
	
	glutInitWindowSize(400,400);
	
	glutCreateWindow("OpenGL");
    
	
	glutDisplayFunc(display); //设置显示函数
	

	glutKeyboardFunc(processNormalKeys);//设置键盘处理函数

	
	
	gluOrtho2D(0.0f,400.0f,0.0f,400.0f);
	
	glutMainLoop();
	
	
	
	
	
	
}