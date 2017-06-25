#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::string;
using std::endl;
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
class SortArray:virtual public MyArray
{
public:
	void Sort();
	SortArray(int leng):MyArray(leng)
	{
		cout<<"sortArray以创建\n";
	}
	virtual~SortArray();
};
class ReArray:virtual public MyArray
{
public:
	void reverse();
	ReArray(int leng);
	virtual ~ReArray();
};
class AverArray:virtual public MyArray
{
public:
	double aver();
	AverArray(int leng);
	virtual ~AverArray();
};
class NewArray:public SortArray,public ReArray,public AverArray
{
	NewArray(int leng);
	virtual ~NewArray();
};
NewArray::NewArray(int leng):MyArray(leng),SortArray(leng),ReArray(leng),AverArray(leng)
{
	cout <<"NewArray以创建\n";
}
NewArray::~NewArray()
{
	cout <<"NewArray已撤销\n";
}

double AverArray::aver()
{
	int i;
	double sum=0;
	for(i=0;i<length;i++)
	{
		sum+=alist[i];
	}
	return sum/(double)length;
}
AverArray::AverArray(int leng):MyArray(leng)
{
	cout <<"AverArray以创建\n";
}
AverArray::~AverArray()
{
	cout <<"AverArray已撤销\n";
}

void ReArray::reverse()
{
	int i,swap,j;
	for(i=0,j=length;i<length/2;i++,j--)
	{
		swap=alist[i];
		alist[i]=alist[j];
		alist[j]=swap;
	}
}
ReArray::ReArray(int leng):MyArray(leng)
{
	cout <<"reArray以创建\n";
}
ReArray::~ReArray()
{
	cout <<"reArray已撤销\n";
}


SortArray::~SortArray()
{
	cout <<"SortArray已撤销\n";
}
void SortArray::Sort()
{
	int i,j,swap;
	for(i=0;i<length;i++)
	{
		swap=alist[i];
		for(j=i-1;j>=0&&swap<alist[j];j--)
			alist[j+1]=alist[j];
		alist[j+1]=swap;
	}
	
}
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
	cout <<"MyArray类对象已创建."<<endl;
}
MyArray::~MyArray()
{
	delete[] alist;
	cout <<"MyArray类对象已撤销."<<endl;
}
void MyArray::Display(string str)
{
	int i;
	int *p=alist;
	cout <<str<<length<<"个整数:";
	for(i=0;i<length;i++,p++)
		cout <<*p<<"";
	cout <<endl;
}
void MyArray::Input()
{
	cout <<"请从键盘输入"<<length<<"个整数:";
	int i;
	int *p=alist;
	for(i=0;i<length;i++,p++)
		cin>>*p;
}
int main()
{
	MyArray a(5);
	a.Input();
	a.Display("显示已输入的");
	return 0;
}