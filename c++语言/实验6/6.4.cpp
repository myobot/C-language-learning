#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double x,a;
	while(1)
	{
		cout <<"请输入一个数:";
		cin >>x;
		try
		{
			if(x<0)
				throw x;
			cout <<x<<" 的平方根为："<<sqrt(x)<<endl;
		}
		catch(double)
		{ 
			cout <<x<<" 是负数，不能求平方根\n";
			exit(0);	
		}
	}
	
	return 0;
}