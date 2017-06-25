#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
class Person
{
public:
	Person();
	Person(string number,string name,string sex,int age);
	Person(Person &object);
	string getnumber() const;
	string getname() const;
	string getsex() const;
	int getage() const;
	void setnumber(string );
	void setname(string );
	void setsex(string );
	void setage(int );
	void input();
	void output() const;

private:
	string sex,number,name;
	int age;
};


class Student:public Person
{
public:
	Student();
	Student(string Number,string Name,string Sex,int Age,string Department,int Score);
	string getdepartment() const;
	int getscore() const;
	void setdepartment(string Department);
	void setscore(int Score);
	void sinput();
	void soutput() const;
private:
	string department;
	int score;
};

class Teacher:public Person
{
public:
	Teacher();
	Teacher(string Number,string Name,string Sex,int Age,string Profession,string Major);
	string getprofession() const;
	string getmajor() const;
	void setprofession(string );
	void setmajor(string);
	void tinput();
	void toutput() const;
private:
	string profession,major;
};



Person::Person()
{
	number="";
	name="";
	sex="";
	age=0;
}
Person::Person(string Number,string Name,string Sex,int Age):number(Number),name(Name),sex(Sex),age(Age)
{
	if(age<0)
	{
		cout <<"���䲻��Ϊ����\n";
		exit(1);
	}
}
Person::Person(Person &object):number(object.number),name(object.name),sex(object.sex),age(object.age)
{
}
string Person::getnumber() const
{
	return number;
}
string Person::getname() const
{
	return name;
}
string Person::getsex() const
{
	return sex;
}
int Person::getage() const
{
	return age;
}
void Person::setnumber(string Number)
{
	number=Number;
}
void Person::setname(string Name)
{
	name=Name;
}
void Person::setsex(string Sex)
{
	sex=Sex;
}
void Person::setage(int Age)
{
	age=Age;
	
}
	
void Person::input()
{
	cout <<"��������:";
	cin >>number;
	fflush(stdin);
	cout <<"\n����������:";
	cin >>name;
	fflush(stdin);
	cout <<"\n�������Ա�:";
	cin >>sex;
	fflush(stdin);
	cout <<"\n����������:";
	cin >>age;
	fflush(stdin);
}
void Person::output() const
{
	cout <<"���:"<<getnumber()<<"\n����:"<<getname()<<"\n�Ա�:"<<getsex()<<"\n����:"<<getage()<<endl;
}


Student::Student():Person()
{
	department="";
	score=0;
}
Student::Student(string Number,string Name,string Sex,int Age,string Department,int Score):Person(Number,Name,Sex,Age),department(Department),score(Score)
{
	if(score<0)
	{
		cout <<"�ɼ�����Ϊ����\n";
		exit(1);
	}
}
string Student::getdepartment() const
{
	return department;
}
int Student::getscore() const
{
	return score;
}
void Student::setdepartment(string Department)
{
	department=Department;
}
void Student::setscore(int Score)
{
	score=Score;
}
void Student::sinput()
{
	string number,name,sex;
	int age;
	cout <<"��������:";
	cin >>number;
	setnumber(number);
	fflush(stdin);
	cout <<"\n����������:";
	cin >>name;
	setname(name);
	fflush(stdin);
	cout <<"\n�������Ա�:";
	cin >>sex;
	setsex(sex);
	fflush(stdin);
	cout <<"\n����������:";
	cin >>age;
	setage(age);
	fflush(stdin);
	cout <<"\n������ϵ��:";
	cin >>department;
	fflush(stdin);
	cout <<"\n������ɼ�:";
	cin >>score;
	fflush(stdin);
}
void Student::soutput() const
{
	output();
	cout <<"ϵ��:"<<department<<"\n�ɼ�:"<<score<<endl;
}




Teacher::Teacher():Person()
{
	profession="";
	major="";
}
Teacher::Teacher(string Number,string Name,string Sex,int Age,string Profession,string Major):Person(Number,Name,Sex,Age),profession(Profession),major(Major)
{
}
string Teacher::getprofession() const
{
	return profession;
}
string Teacher::getmajor() const
{
	return major;
}
void Teacher::setprofession(string Profession)
{
	profession=Profession;
}
void Teacher::setmajor(string Major)
{
	major=Major;
}
void Teacher::tinput()
{
	string number,name,sex;
	int age;
	cout <<"��������:";
	cin >>number;
	setnumber(number);
	fflush(stdin);
	cout <<"\n����������:";
	cin >>name;
	setname(name);
	fflush(stdin);
	cout <<"\n�������Ա�:";
	cin >>sex;
	setsex(sex);
	fflush(stdin);
	cout <<"\n����������:";
	cin >>age;
	setage(age);
	fflush(stdin);
	cout <<"\n������ְ��:";
	cin >>profession;
	fflush(stdin);
	cout <<"\n�����벿��:";
	cin >>major;
	fflush(stdin);
}
void Teacher::toutput() const
{
	output();
	cout <<"ְ��:"<<profession<<"\n����:"<<major<<endl;
}


int main()
{
	Person p;
	Student l("008321","����","��",19,"�������ѧ�뼼��",99);
	Teacher	c("007321","�����","Ů",32,"����","�����");
	p.input();
	p.output();
	cout <<endl;
	l.soutput();
	cout <<endl;
	c.toutput();
	l.setdepartment("��ѧ");
	l.soutput();
	return 0;
}