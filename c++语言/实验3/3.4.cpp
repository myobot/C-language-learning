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

//��ʼ����̬��Ա������must!
int Student::total_score=0;
int Student::count=0;

void Student::account()
{
	cout <<"������ѧ���ɼ�:";
	cin >>score;
	total_score+=score;
	count++;
}
//��̬��Ա����ֻ�ܵ��þ�̬����
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
		cout <<"��������?1)����0)����\n";
		cin >>j;
		if(j==0)
			break;
	}
	cout <<"�ܷ�Ϊ:"<<Student::sum()<<endl;		//���þ�̬��Ա������Ҫʹ�ã������������::
	cout <<"ƽ����Ϊ:"<<Student::average()<<endl;
	return 0;
}
	

		
