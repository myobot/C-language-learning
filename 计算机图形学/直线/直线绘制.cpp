#include<iostream>
#include<GL\glut.h>
#include<time.h>
#include<cstdlib>
#include<math.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}


void drawLineBresenham(int x1 ,int y1,int x2,int y2)

{
    glColor3f(1.0f,1.0f,0.0f);//设置点的颜色
    glBegin(GL_POINTS);//以点的方式绘制 
	
	int x = x1;
	int y = y1;
    
    int adx = abs(x2-x1);
	int ady = abs(y2-y1);
    int xIncre = x2>x1?1:-1;
    int yIncre = y2>y1?1:-1;
    
	int e = 0;
	
	if(adx>ady)
	{
		e = -adx;
		for(int i = 0 ;i<adx;i++)
		{
			glVertex2i(x,y);
            
			e = e + 2 * ady;
			x = x+xIncre;
			
			if(e>0)
			{
				
				y = y+yIncre;
				e = e - 2*adx;
			}
			
		}
		
	} //adx<=ady
	else
	{
		e = -ady;
		for(int j = 0 ;j<ady;j++)
		{
			glVertex2i(x,y);
            
			e = e + 2 * adx;
			y = y+yIncre;
			
			if(e>0)
			{
				
				x = x+xIncre;
				e = e - 2*ady;
			}
			
		}
		
	}
	
	
	
	
	glEnd();//结束绘制
	glFlush();
	
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawLineBresenham(2,2,50,50);
}
int main(int arge,char** argv)
{



	glutInit(&arge, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	system("pause");
	return 0;

}