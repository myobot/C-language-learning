#include<iostream>
#include<string>
using namespace std;
class Time
{
public:
	Time(int h=0,int m=0,int s=0);
	Time(Time&);
	Time operator +(Time&);
	void disptime();
	int gethours()
	{
		return hours;
	}
	int getminutes()
	{
		return minutes;
	}
	int getseconds()
	{	return seconds;}
private:
	int hours;
	int minutes;
	int seconds;
};
Time::Time(int h,int m,int s):hours(h),minutes(m),seconds(s)
{
	while(h<0)
	{
		cout<<"Сʱ����Ϊ����������������\n";
		cin>>hours;
		
	}
	while(m<0||m>59)
	{
		cout<<"������������0~59֮��,����������\n";
		cin>>minutes;
		
	}
	while(s<0||s>59)
	{
		cout<<"����������0~59֮�⣬����������\n";
		cin>>seconds;
		
	}
}
Time::Time(Time & t)
{
	hours=t.gethours();
	minutes=t.getminutes();
	seconds=t.getseconds();
}
Time Time::operator +(Time& right)
{
	int s,m,h,p;
	s=seconds+right.getseconds();
	p=s/60;
	s=s%60;
	m=minutes+right.getminutes()+p;
	p=m/60;
	m=m%60;
	h=hours+right.gethours()+p;

	return Time(h,m,s);
}
void Time::disptime()
{
	cout<<"��ǰʱ��Ϊ:\n";
	cout<<hours<<" Сʱ"<<minutes<<" ����"<<seconds<<" ��"<<endl;
}
int main()
{
	Time t1(2,23,44),t2(3,32,41),t3,t4(4,23,55);
	t1.disptime();
	t2.disptime();
	t4.disptime();
	t3=t1+t2+t4;
	t3.disptime();
	return 0;
}
