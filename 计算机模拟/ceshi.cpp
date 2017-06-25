#include<iostream>
#include<GL\glut.h>
#include<time.h>
#include<cstdlib>
#include<math.h>
#define P 3.1415926
struct dian
{
	double x, y;

};
struct Angle
{
	double Cos, Sin;
};
struct jihe
{
	struct dian jianji[14], hongzha[14];
	int numberj, numberh;
};
double distance(struct dian p1, struct dian p2)
{
	double dis;
	dis = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
	return dis;
}
struct dian minlater(struct dian p, int angle, int speed)
{
	double x, y;
	struct dian a;
	x = speed*cos(angle*P/180);
	y = speed*sin(angle*P/180);
	a.x = p.x + x;
	a.y = p.y - y;
	return a;
}
struct dian minlater(struct dian p, struct Angle ang, int speed)
{
	double x, y;
	struct dian a;
	x = speed*ang.Cos;
	y = speed*ang.Sin;
	a.x = p.x + x;
	a.y = p.y - y;
	return a;
}
struct Angle doublevertex(struct dian x1, struct dian x2)
{
	double cos, sin;
	double dis;
	struct Angle a;
	dis = distance(x1, x2);
	cos = fabs(x1.x - x2.x) / dis;
	sin = fabs(x1.y - x2.y) / dis;
	a.Cos = cos;
	a.Sin = sin;
	return a;
}
struct jihe moni(void)
{
	int angle, i;
	struct Angle a;
	struct dian j1, j2, h1, h2;
	struct jihe j;
	j1.x = 0; j1.y = 50;
	h1.x = 80; h1.y = 0;
	j.numberh = 0;
	j.numberj = 0;
	j.jianji[j.numberj++] = j1;
	j.hongzha[j.numberh++] = h1;

	for (i = 0; i < 12; i++)
	{
		if (distance(j1, h1) < 10)
		{
			break;
		}
		angle = rand() % 91;
		a = doublevertex(j1, h1);
		j2 = minlater(j1, a, 25);
		h2 = minlater(h1, angle, 15);
		
		j.jianji[j.numberj++] = j2;
		
		j.hongzha[j.numberh++] = h2;
		j1 = j2;
		h1 = h2;
	}
	return j;
}
int main()
{
	int i;
	struct jihe j;
	srand((unsigned int)time(0));
	j=moni();
	for(i=0;i<j.numberj;i++)
	{
		printf("%.2lf  %.2lf\n",j.jianji[i].x,j.jianji[i].y);
	}
	for(i=0;i<j.numberh;i++)
	{
		printf("%.2lf  %.2lf\n",j.hongzha[i].x,j.hongzha[i].y);
	}
	printf("%d\n",j.numberh);
	return 0;
}