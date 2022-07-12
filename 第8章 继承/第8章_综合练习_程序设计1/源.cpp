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
		cout << "��ţ�"; cin >> number;
		cout << "������"; cin >> name;
	}
	void print()
	{
		cout << "Ա�� ��" << name << "\t\t��ţ�" << number << "\t\t���¹��ʣ�" << basicSalary << endl;
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
		cout << "���¸������۶";
		cin >> sales;
	}
	void pay()
	{
		salary = basicSalary + sales * commrate;
	}
	void print()
	{
		pay();
		cout << "����Ա ��" << name << "\t\t��ţ�" << number << "\t\t���¹��ʣ�" << salary << endl;
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
		cout << "���²������۶";
		cin >> sales;
	}
	void pay()
	{
		salary = jobSalary + sales * commrate;
	}
	void print()
	{
		pay();
		cout << "���۾��� ��" << name << "\t\t��ţ�" << number << "\t\t���¹��ʣ�" << salary << endl;
	}
private:
	double jobSalary;
};
int main()
{
	cout << "����Ա��\n";
	Employee emp1;
	emp1.input();
	emp1.print();
	cout << "����Ա\n";
	Salesman emp2;
	emp2.input();
	emp2.print();
	cout << "���۾���\n";
	Salesmanager emp3;
	emp3.input();
	emp3.print();
}