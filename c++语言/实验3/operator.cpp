#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
class money
{
public:
	money();
	money(int m);
	int getmoney() const;
	void input();
	void output() const;
	friend const money operator +(const money& amount1,const money& amount2);
	friend const money operator -(const money& amount1,const money& amount2);
	friend const money operator ==(const money& amount1,const money& amount2);
	friend const money operator -(const monet& amount1);
private:
	int rmb;
};

money::money()
{
	rmb=0;
}
money::money(int m)
	:rmb(m)
{}
int money::getmoney() const
{
	return rmb;
}
void money::input()
{
	cout <<"��������:";
	cin >>rmb;
}
void money::output() const
{
	cout <<"��ǰ���Ϊ:"<<rmb<<endl;
}
const money operator +(const money& amount1,const money& amount2)
{
	int finalrmb;
	finalrmb=amount1.rmb+amount2.rmb;
	return finalrmb;
}
const money operator -(const money& amount1,const money& amount2)
{
	int finalrmb;
	finalrmb=amount1.rmb-amount2.rmb;
	return finalrmb;
}
const money operator ==(const money& amount1,const money& amount2)
{
	return (amount1.rmb==amount2.rmb);
}
const money operator -(const money& amount1)
{
	return -amount.rmb;
}
int main()
{
	money amount1(1000),amount2,amount3,amount4;
	cout <<"�˻�1��";
	amount1.output();
	count <<"�˻�2��"<<amount2.getmoney()<<endl;
	amount2.input();
	cout <<"�����˻�2���Ϊ:"<<amount2.getmoney()<<endl;
	amount3=amount1+amount2;
	amount4=amount1-amount2;
	cout <<"�˻�3: "<<amount3.getmoney()<<endl;
	cout <<"�˻�4: "<<amount4.getmoney()<<endl;
	amount4=-amount4;
	cout <<"�˻�4: "<<amount4.getmoney()<<endl;
	if(amount4==amount3)
		cout <<"�˻�4�������˻�3\n";
	else
		cout <<"�˻�4�����˻�3\n";
	return 0;
}


