#include<iostream>
#include<string>
using namespace std;
class MyArray
{
public:
	MyArray(int leng);
	~MyArray();
	void Input();
	void Display(string);
protected:
	int *alist;
	int length;
};
MyArray::MyArray(int leng)
{
	if(leng<=0)
	{
		cout <<"error length";
		exit(1);
	}
	alist =new int(leng);
	length=leng;
	if (alist ==NULL)
	{
		cout <<"assign failure";
		exit(1);
	}
	cout <<"MyArray������Ѵ���."<<endl;
}
MyArray::~MyArray()
{
	delete[] alist;
	cout <<"MyArray������ѳ���."<<endl;
}
void MyArray::Display(string str)
{
	int i;
	int *p=alist;
	cout <<str<<length<<"������:";
	for(i=0;i<length;i++,p++)
		cout <<*p<<"";
	cout <<endl;
}
void MyArray::Input()
{
	cout <<"��Ӽ�������"<<length<<"������:";
	int i;
	int *p=alist;
	for(i=0;i<length;i++,p++)
		cin>>*p;
}
int main()
{
	MyArray a(5);
	a.Input();
	a.Display("��ʾ�������");
	return 0;
}