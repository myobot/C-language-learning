#include<iostream>
using namespace std;
class magic
{
	public:
		void getdata();
		void setfirstmagic();
		void generatemagic();
		void printmagic();
	private:
		int m[4][4];
		int step;
		int first;
		int sum;
};

void magic::getdata()
{
	cout <<"请输入第一个值:";
	cin >>first;
	cout <<"\n请输入相邻元素差值:";
	cin >>step;
}

void magic::setfirstmagic()
{
	int i,j,p=first;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			m[i][j]=p;
			p+=step;
		}
	}
}

void magic::generatemagic()
{
	int i,j,k;
	sum=m[0][0]+m[3][3];
	for(i=0;i<4;i++)
	{
		k=m[i][i];
		m[i][i]=sum-k;
	}
	for(i=0,j=3;i<4;i++,j--)
	{
		
		k=m[i][j];
		m[i][j]=sum-k;
		
	}
}

void magic::printmagic()
{
	int i,j;
	cout <<endl;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%3d",m[i][j]);
		}
		cout <<endl;
	}
}



int main()
{	
	magic one;
	one.getdata();
	one.setfirstmagic();
	one.printmagic();
	one.generatemagic();
	one.printmagic();
	return 0;
}
	