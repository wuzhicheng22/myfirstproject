#include <iostream>
using namespace std;
class Employee
{
public:
	Employee(const char Snumber[] = "\0", const char Sname[] = "\0", double bSalary = 2000)
	{
		strcpy_s(number, Snumber);
		strcpy_s(name, Sname);
		basicSalary = bSalary;
	}
	void input()
	{
		cout << "编号："; cin >> number;
		cout << "姓名："; cin >> name;
	}
	void print()
	{
		cout << "员工 ：" << name << "\t\t编号：" << number << "\t\t本月工资：" << basicSalary << endl;
	}
protected:
	char number[5];
	char name[10];
	double basicSalary;
};
class Salesman : public Employee
{
public:
	Salesman(int sal = 0)
	{
		sales = sal;
	}
	void input()
	{
		Employee::input();
		cout << "本月个人销售额：";
		cin >> sales;
	}
	void pay()
	{
		salary = basicSalary + sales * commrate;
	}
	void print()
	{
		pay();
		cout << "销售员 ：" << name << "\t\t编号：" << number << "\t\t本月工资：" << salary << endl;
	}
protected:
	static double commrate;
	int sales;
	double salary;
};
double Salesman::commrate = 0.005;
class Salesmanager : public Salesman
{
public:
	Salesmanager(double jSalary = 3000)
	{
		jobSalary = jSalary;
	}
	void input()
	{
		Employee::input();
		cout << "本月部门销售额：";
		cin >> sales;
	}
	void pay()
	{
		salary = jobSalary + sales * commrate;
	}
	void print()
	{
		pay();
		cout << "销售经理 ：" << name << "\t\t编号：" << number << "\t\t本月工资：" << salary << endl;
	}
private:
	double jobSalary;
};
int main()
{
	cout << "基本员工\n";
	Employee emp1;
	emp1.input();
	emp1.print();
	cout << "销售员\n";
	Salesman emp2;
	emp2.input();
	emp2.print();
	cout << "销售经理\n";
	Salesmanager emp3;
	emp3.input();
	emp3.print();
}