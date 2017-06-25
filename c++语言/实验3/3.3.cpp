#include<iostream>
#include<cmath>
using namespace std;
class location
{	
	public:
		location(double x,double y);
		double getx();
		double gety();
		double Distance(location &);
		friend double Distance(location& x1,location& x2);
	private:
		double x,y;
};
location::location(double x1,double y1)
					:x(x1),y(y1)
{
}

double location::getx()
{
	return x;
}

double location::gety()
{
	return y;
}

double location::Distance(location& object1)
{
	double fang1,fang2;
	fang1=(x-object1.x)*(x-object1.x);
	fang2=(y-object1.y)*(y-object1.y);
	return sqrt(fang1+fang2);
}

double Distance(location & x1,location & x2)
{
	double fang1,fang2;
	fang1=(x1.x-x2.x)*(x1.x-x2.x);
	fang2=(x1.y-x2.y)*(x1.y-x2.y);
	return sqrt(fang1+fang2);
}
int main()
{
	location x1(-5.5,-6.2),x2(-2.8,4.4);
	cout <<"Distance1:"<<x1.Distance(x2)<<endl;
	cout <<"Distance2:"<<Distance(x1,x2)<<endl;
	return 0;
}