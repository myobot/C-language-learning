//13503327577  184023262
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a[5];
	int i;
	for(i=0;i<5;i++)
	{
		cin >>a[i];
	}
	for(i=4;i>=0;i--)
		cout <<a[i]<<" ";
	cout <<endl;
	return 0;
}
