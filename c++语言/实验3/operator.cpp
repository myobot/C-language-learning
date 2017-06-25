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
	cout <<"请输入存款:";
	cin >>rmb;
}
void money::output() const
{
	cout <<"当前存款为:"<<rmb<<endl;
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
	cout <<"账户1：";
	amount1.output();
	count <<"账户2："<<amount2.getmoney()<<endl;
	amount2.input();
	cout <<"现在账户2存款为:"<<amount2.getmoney()<<endl;
	amount3=amount1+amount2;
	amount4=amount1-amount2;
	cout <<"账户3: "<<amount3.getmoney()<<endl;
	cout <<"账户4: "<<amount4.getmoney()<<endl;
	amount4=-amount4;
	cout <<"账户4: "<<amount4.getmoney()<<endl;
	if(amount4==amount3)
		cout <<"账户4不等于账户3\n";
	else
		cout <<"账户4等于账户3\n";
	return 0;
}


