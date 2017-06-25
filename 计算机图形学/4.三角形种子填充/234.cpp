
#include "stdAfx.h"
#include "Line.h"

/*���³����������״̬��Ŀǰ֮������״̬���ֱ��������������£�
   ��Ĭ������״̬��û���κΰ���������
*/
#define  MOUSE_LEFT_BUTTION_DOWN 0X0001  //�������״
#define MOUSE_NORMAL 0x0000
//�������״̬
int  mouse_state = MOUSE_NORMAL;

//����2ά�ռ��ڵĵ㣨x,y)
typedef struct Point2D  
{
	int x;
	int y;
}Point2D;

//������꿪ʼλ�úͽ���λ��
Point2D  mouseStartPos,mouseEndPos;  

Point2D pointBuffer[3];
int pointCount=0;


//������ʾ����
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





//��괦����
void mouseHandler(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		switch(state)
		{
		case GLUT_UP:

				glColor3f(1.0f,0.0f,0.0f);//���õ����ɫ
				glBegin(GL_POINTS);//�Ե�ķ�ʽ����	
				glVertex2i(x,y);
				glEnd();//��������
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
			mouseStartPos.x = x; //��¼��꿪ʼλ��
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

//��갴�²����ƶ�ʱ�򣬵��ô˺���
void mouseMotionHandler(int x,int y)
{
	//��¼������λ��
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
    
	
	glutDisplayFunc(display); //������ʾ����
	
    glutMouseFunc(mouseHandler); //������괦����

	glutMotionFunc(mouseMotionHandler);//����갴�²��ƶ�ʱ�򣬻���ô˺���

    glutPassiveMotionFunc(mousePassiveHandler);
	
	
	gluOrtho2D(0.0f,400.0f,400.0f,0.0f);
	
	glutMainLoop();
	
	
	
	
	
	
}