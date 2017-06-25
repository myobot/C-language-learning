#include<iostream>
#define MAX 20
using namespace std;

class set
{
private:
	int len;
	int s[MAX];
public:
	set();
	set(int length);
	void input();
	void input(int x);
	int getset(int i);
	void dispset();
	void setlen(int l)
	{
		len=l;
	}
	int getlen()
	{
		return len;
	}
	set operator +(set &);
	set operator -(set&);
	set operator *(set&);
	set &operator =(set&);
};
set::set():len(0)
{}
set::set(int length):len(length)
{
	while(length<0)
	{
		cout <<"长度不能为负,请重新输入\n";
		cin>>len;
	}
	int i;
	cout <<"请输入"<<len<<"个数字\n";
	for(i=0;i<len;i++)
		cin>>s[i];
}
void set::input()
{
	cout <<"请输入一个数\n";
	cin>>s[len++];
}
void set::input(int x)
{
	s[len++]=x;
}
int set::getset(int i)
{
	if(i<0)
	{
		cout <<"位置有误!\n";
		exit(1);
	}
	else
		return s[i];
}
void set::dispset()
{
	int i;
	cout <<"目前集合中有:\n";
	for(i=0;i<len;i++)
		cout <<s[i]<<"\t";
}
set set::operator +(set & right)
{
	set a;
	int i,l=0,rlen,s1[MAX],j,i1,mark;
	rlen=right.getlen();
	for(i=0;i<len;i++,l++)
	{
		s1[i]=s[i];
	}
	for(i=0;i<rlen;i++)
	{	
		mark=0;
		j=right.getset(i);
		for(i1=0;i1<l;i1++)
		{
			if(j==s1[i1])
			{
				mark=1;
				break;
			}
		}
		if(mark==0)
		{
			s1[l++]=j;
		}
	}
	for(i=0;i<l;i++)
		a.input(s1[i]);
	a.setlen(l);
	return a;
}
set set::operator -(set & right)
{
	set a;
	int i,l=0,rlen,s1[MAX],j,mark;
	rlen=right.getlen();
	for(i=0;i<len;i++)
	{
		mark=0;
		for(j=0;j<rlen;j++)
		{
			if(s[i]==right.getset(j))
			{
				mark=1;
				break;
			}
		}
		if(mark==0)
		{
			s1[l++]=s[i];
		}
	}
	for(i=0;i<l;i++)
		a.input(s1[i]);
	a.setlen(l);
	return a;
}
set set::operator *(set & right)
{
	set a;
	int i,l=0,rlen,s1[MAX],j,mark;
	rlen=right.getlen();
	for(i=0;i<len;i++)
	{
		mark=0;
		for(j=0;j<rlen;j++)
		{
			if(s[i]==right.getset(j))
			{
				mark=1;
				break;
			}
		}
		if(mark==1)
		{
			s1[l++]=s[i];
		}
	}
	for(i=0;i<l;i++)
		a.input(s1[i]);
	a.setlen(l);
	return a;
}
set &set::operator =(set & right)
{

	int i,rlen;
	rlen=right.getlen();
	for(i=0;i<rlen;i++)
	{
		s[i]=right.getset(i);
	}
	len=rlen;
	return *this;

}
int main()
{
	set a,b,c,d,e;
	a.input(9),a.input(5),a.input(4),a.input(3),a.input(6),a.input(7);
	b.input(2),b.input(4),b.input(6),b.input(9);
	c=a+b;
	d=a-b;
	e=a*b;
	cout <<"并运算后:\n";
	c.dispset();
	cout <<"\n差运算后:"<<endl;
	d.dispset();
	cout <<"\n交运算后:"<<endl;
	e.dispset();
	cout <<endl;
	return 0;
}



