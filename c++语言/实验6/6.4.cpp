#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double x,a;
	while(1)
	{
		cout <<"������һ����:";
		cin >>x;
		try
		{
			if(x<0)
				throw x;
			cout <<x<<" ��ƽ����Ϊ��"<<sqrt(x)<<endl;
		}
		catch(double)
		{ 
			cout <<x<<" �Ǹ�����������ƽ����\n";
			exit(0);	
		}
	}
	
	return 0;
}