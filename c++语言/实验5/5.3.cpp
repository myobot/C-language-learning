#include<iostream>
using namespace std;
class container
{
protected:
	double radius;
	double tiji;
	double biaomianji;
public:
	container(double radiusl);
	virtual void surface_area()=0;
	virtual void volume()=0;
	void printtiji();
	void printbiaomianji();
};
class cube:public container
{
public:
	cube(double radiusl):container(radiusl)
	{}
	void surface_area();
	void volume();
};
class sphere:public container
{
public:
	sphere(double radiusl):container(radiusl)
	{}
	void surface_area();
	void volume();
};
class cylinder:public container
{
public:
	cylinder(double radiusl,double length):container(radiusl),L(length)
	{
		while(length<0)
		{
			cout <<"长度不能为负,请重新输入\n";
			cin >>L;
		}
	}
	void surface_area();
	void volume();
private:
	double L;
};
container::container(double radiusl):radius(radiusl),tiji(0),biaomianji(0)
{}
void container::printtiji()
{
	cout<<"体积为:  "<<tiji<<" 立方米"<<endl;
}
void container::printbiaomianji()
{
	cout <<"表面积为:  "<<biaomianji<<" 平方米"<<endl;
}
void cube::surface_area()
{
	double s;
	s=radius*radius*6;
	biaomianji=s;
}
void cube::volume()
{
	tiji=radius*radius*radius;
}
void sphere::surface_area()
{
	biaomianji=radius*radius*3.1415*4;
}
void sphere::volume()
{
	tiji=4.0/3*radius*radius*radius*3.1415;
}
void cylinder::surface_area()
{
	double s1,s2,c;
	c=radius*2*3.1415;
	s1=radius*radius*3.1415*2;
	s2=c*L;
	biaomianji=s1+s2;
}
void cylinder::volume()
{
	tiji=radius*radius*3.1415*L;
}
int main()
{
	cube c(4.2);
	sphere s(5.6);
	cylinder cy(3.3,6);
	c.surface_area();
	c.volume();
	s.surface_area();
	s.volume();
	cy.surface_area();
	cy.volume();
	c.printtiji();
	c.printbiaomianji();
	s.printtiji();
	s.printbiaomianji();

	cy.printtiji();
	cy.printbiaomianji();
	return 0;
}
