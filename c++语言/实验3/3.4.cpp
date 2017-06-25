#include<iostream>
using namespace std;
class Student
{
	public:
		void account();
		static int sum();
		static double average();
	private:
		int score;
		static int total_score;
		static int count;
		
		
};

//初始化静态成员变量；must!
int Student::total_score=0;
int Student::count=0;

void Student::account()
{
	cout <<"请输入学生成绩:";
	cin >>score;
	total_score+=score;
	count++;
}
//静态成员函数只能调用静态变量
int Student::sum()
{
	return total_score;
}

double Student::average()
{
	double average;
	average=total_score/(count*1.0);
	return average;
}
int main()
{
	int i=0,j=1;
	Student student[100];
	while(1)
	{
		student[i].account();
		cout <<"继续输入?1)继续0)结束\n";
		cin >>j;
		if(j==0)
			break;
	}
	cout <<"总分为:"<<Student::sum()<<endl;		//调用静态成员函数需要使用，作用域运算符::
	cout <<"平均分为:"<<Student::average()<<endl;
	return 0;
}
	

		
