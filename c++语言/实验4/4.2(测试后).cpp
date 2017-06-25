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
		cout <<"年龄不能为负！\n";
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
	cout <<"请输入编号:";
	cin >>number;
	fflush(stdin);
	cout <<"\n请输入名字:";
	cin >>name;
	fflush(stdin);
	cout <<"\n请输入性别:";
	cin >>sex;
	fflush(stdin);
	cout <<"\n请输入年龄:";
	cin >>age;
	fflush(stdin);
}
void Person::output() const
{
	cout <<"编号:"<<getnumber()<<"\n姓名:"<<getname()<<"\n性别:"<<getsex()<<"\n年龄:"<<getage()<<endl;
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
		cout <<"成绩不能为负！\n";
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
	cout <<"请输入编号:";
	cin >>number;
	setnumber(number);
	fflush(stdin);
	cout <<"\n请输入名字:";
	cin >>name;
	setname(name);
	fflush(stdin);
	cout <<"\n请输入性别:";
	cin >>sex;
	setsex(sex);
	fflush(stdin);
	cout <<"\n请输入年龄:";
	cin >>age;
	setage(age);
	fflush(stdin);
	cout <<"\n请输入系别:";
	cin >>department;
	fflush(stdin);
	cout <<"\n请输入成绩:";
	cin >>score;
	fflush(stdin);
}
void Student::soutput() const
{
	output();
	cout <<"系别:"<<department<<"\n成绩:"<<score<<endl;
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
	cout <<"请输入编号:";
	cin >>number;
	setnumber(number);
	fflush(stdin);
	cout <<"\n请输入名字:";
	cin >>name;
	setname(name);
	fflush(stdin);
	cout <<"\n请输入性别:";
	cin >>sex;
	setsex(sex);
	fflush(stdin);
	cout <<"\n请输入年龄:";
	cin >>age;
	setage(age);
	fflush(stdin);
	cout <<"\n请输入职称:";
	cin >>profession;
	fflush(stdin);
	cout <<"\n请输入部门:";
	cin >>major;
	fflush(stdin);
}
void Teacher::toutput() const
{
	output();
	cout <<"职称:"<<profession<<"\n部门:"<<major<<endl;
}


int main()
{
	Person p;
	Student l("008321","李宁","男",19,"计算机科学与技术",99);
	Teacher	c("007321","常淑慧","女",32,"教授","计算机");
	p.input();
	p.output();
	cout <<endl;
	l.soutput();
	cout <<endl;
	c.toutput();
	l.setdepartment("化学");
	l.soutput();
	return 0;
}