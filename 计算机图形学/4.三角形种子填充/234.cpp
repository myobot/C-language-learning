
#include "stdAfx.h"
#include "Line.h"

/*以下常量定义鼠标状态，目前之后两个状态，分别是鼠标左键被按下，
   和默认正常状态，没有任何按键被按下
*/
#define  MOUSE_LEFT_BUTTION_DOWN 0X0001  //定义鼠标状
#define MOUSE_NORMAL 0x0000
//定义鼠标状态
int  mouse_state = MOUSE_NORMAL;

//定义2维空间内的点（x,y)
typedef struct Point2D  
{
	int x;
	int y;
}Point2D;

//定义鼠标开始位置和结束位置
Point2D  mouseStartPos,mouseEndPos;  

Point2D pointBuffer[3];
int pointCount=0;


//定义显示函数
void display()
{
	
	glClearColor(1.0f,1.0f,1.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
   printf("%d\n",mouse_state);
	if(mouse_state == MOUSE_LEFT_BUTTION_DOWN)
	{
		//drawLineBresenham(mouseStartPos.x,mouseStartPos.y,mouseEndPos.x,mouseEndPos.y);
	
	}

    glFlush();
	printf("call display\n");
	
}





//鼠标处理函数
void mouseHandler(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		switch(state)
		{
		case GLUT_UP:

				glColor3f(1.0f,0.0f,0.0f);//设置点的颜色
				glBegin(GL_POINTS);//以点的方式绘制	
				glVertex2i(x,y);
				glEnd();//结束绘制
				glFlush();
	
              pointBuffer[pointCount].x=x;
			  pointBuffer[pointCount].y=y;
			  pointCount++;

              if (pointCount==3)
			  {
				 fillTriangle( pointBuffer[0].x,pointBuffer[0].y,pointBuffer[1].x,pointBuffer[1].y,pointBuffer[2].x,pointBuffer[2].y);
				  
				  pointCount=0;
			  
			  }
			  

			
				mouse_state = MOUSE_NORMAL;
			break;
		case GLUT_DOWN:
		
			printf("mosue down\n");
			mouseStartPos.x = x; //记录鼠标开始位置
			mouseStartPos.y = y;
			mouse_state = MOUSE_LEFT_BUTTION_DOWN;

			break;

		default:
			break;
		}
		
		break;
		case GLUT_RIGHT_BUTTON:
			break;
		case GLUT_MIDDLE_BUTTON:
			break;
			
		default:
			break;
	}
	
}

//鼠标按下并且移动时候，调用此函数
void mouseMotionHandler(int x,int y)
{
	//记录鼠标结束位置
	mouseEndPos.x = x;
	mouseEndPos.y = y;

	if(mouse_state == MOUSE_LEFT_BUTTION_DOWN)
	{
		drawLineBresenham(mouseStartPos.x,mouseStartPos.y,
			mouseEndPos.x,mouseEndPos.y);
		
	}

 
}

void mousePassiveHandler(int x,int y)
{


	


}

void  main ()
{
	
   

	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	
	glutInitWindowPosition(600,400);
	
	glutInitWindowSize(400,400);
	
	glutCreateWindow("OpenGL");
    
	
	glutDisplayFunc(display); //设置显示函数
	
    glutMouseFunc(mouseHandler); //设置鼠标处理函数

	glutMotionFunc(mouseMotionHandler);//当鼠标按下并移动时候，会调用此函数

    glutPassiveMotionFunc(mousePassiveHandler);
	
	
	gluOrtho2D(0.0f,400.0f,400.0f,0.0f);
	
	glutMainLoop();
	
	
	
	
	
	
}