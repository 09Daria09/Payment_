#include<iostream>
using namespace std;
class Payment
{
private:
	char* name;//
	char* surname;//�������
	char* patronymic;//�������
	double salary;//�����
	int yearOfEmployment;//��� ����������� �� ������
	double allowancePercentage;//������� �������� 
	int incomeTax = 13;//���������� �����
	int numWorkedDay;//���������� ������������ ���� � ������
	int numWorkingDay;//���������� ������� ���� � ������
	double withholding;// ���������� �����
	int exper;
	double wages;
	double allsum;
	static const int precent;

public:
	Payment();
	Payment(char* n, char* s, char* p, int sal, int year, double all, int numWed, int numWing);
	void Input();
	void Print();
	Payment(const Payment& person);
	int �xperience();
	int AccruedAmount();
	int RetainedAmount();
	int Incometax();
	//////////////////////////
	char* Getname()const;
	void Setname();
	char* Getsurname()const;
	void Setsurname();
	char* Getpatronym()const;
	void Setpatronym();
	int Getsalary()const;
	void Setsalary();
	int Getyear()const;
	void Setyear();
	double Getall()const;
	void Setall();
	int GetnumWed()const;
	void SetnumWed();
	int GetnumWing()const;
	void SetnumWing();
	//////////////////////////
	~Payment();
};
Payment::Payment()
{
	name = nullptr;
	surname = nullptr;
	patronymic = nullptr;
	salary = 0;//�����
	yearOfEmployment = 0;//��� ����������� �� ������
	allowancePercentage = 0;//������� �������� 
	incomeTax = 13;//���������� �����
	numWorkedDay = 0;//���������� ������������ ���� � ������
	numWorkingDay = 0;//���������� ������� ���� � ������
	withholding = 0;
	exper = 0;
	allsum = 0;
	wages = 0;
}
Payment::Payment(char* n, char* s, char* p, int sal, int year, double all, int numWed, int numWing)
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
	surname = new char[strlen(s) + 1];
	strcpy_s(surname, strlen(s) + 1, s);
	patronymic = new char[strlen(p) + 1];
	strcpy_s(patronymic, strlen(p) + 1, p);
	salary = sal;
	yearOfEmployment = year;
	allowancePercentage = all;
	numWorkedDay = numWed;
	numWorkingDay = numWing;
	withholding = 0;
	exper = 0;
	allsum = 0;
	wages = 0;
}
Payment::Payment(const Payment& person) 
{
	name = new char[strlen(person.name) + 1];
	strcpy_s(name, strlen(person.name) + 1, person.name);
	surname = new char[strlen(person.surname) + 1];
	strcpy_s(surname, strlen(person.surname) + 1, person.surname);
	patronymic = new char[strlen(person.patronymic) + 1];
	strcpy_s(patronymic, strlen(person.patronymic) + 1, person.patronymic);
	salary = person.salary;
	yearOfEmployment = person.yearOfEmployment;
	allowancePercentage = person.allowancePercentage;
	numWorkedDay = person.numWorkingDay;
	numWorkingDay = person.numWorkingDay;
	withholding = person.withholding;
	exper = person.exper;
	wages = person.wages;
	allsum = person.allsum;
}
void Payment::Input()
{
	Setname();
	Setsurname();
	Setpatronym();
	Setsalary();
	Setyear();
	Setall();
	SetnumWed();
	SetnumWing();
}
void Payment::Print()
{
	cout << "���: " << name << endl;
	cout << "�������: " << surname << endl;
	cout << "��������: " << patronymic << endl;
	cout << "����������� �����: " <<wages<< endl;
	cout << "���������� �����: "<< withholding << endl;
	cout << "�����, ���������� �� ����: "<<allsum << endl;
	cout << "����: "<<exper << endl;
}
char* Payment::Getname() const
{
	return name;
}
void Payment::Setname()
{
	char def_name[25];
	cout << "������� ���: ";
	cin >> def_name;
	if (name != nullptr)
	{
		delete[]name;
	}
	name = new char[strlen(def_name) + 1];
	strcpy_s(name, strlen(def_name) + 1, def_name);
}
char* Payment::Getsurname()const
{
	return surname;
}
void Payment::Setsurname()
{
	char def_surn[25];
	cout << "������� �������: ";
	cin >> def_surn;
	if (surname != nullptr)
	{
		delete[]surname;
	}
	surname = new char[strlen(def_surn) + 1];
	strcpy_s(surname, strlen(def_surn) + 1, def_surn);
}
char* Payment::Getpatronym()const
{
	return patronymic;
}
void Payment::Setpatronym()
{
	char def_patron[25];
	cout << "������� ��������: ";
	cin >> def_patron;
	if (patronymic != nullptr)
	{
		delete[]patronymic;
	}
	patronymic = new char[strlen(def_patron) + 1];
	strcpy_s(patronymic, strlen(def_patron) + 1, def_patron);
}
int Payment::Getsalary()const
{
	return salary;
}
void Payment::Setsalary()
{
	cout << "������� ����� ����������: ";
	cin >> salary;
}
int Payment::Getyear()const
{
	return yearOfEmployment;
}
void Payment::Setyear()
{
	cout << "������� ��� ������ �� ������: ";
	cin >> yearOfEmployment;
}
double Payment::Getall()const
{
	return allowancePercentage;
}
void Payment::Setall()
{
	cout << "������� ������� ��������: ";
	cin >> allowancePercentage;
}
int Payment::GetnumWed()const
{
	return numWorkedDay;
}
void Payment::SetnumWed()
{
	cout << "������� ���������� ����������� ���� � ������: ";
	cin >> numWorkedDay;
	if (numWorkedDay > 24)
	{
		cout << "��� ��������� ������� ����� ��������!!!" << endl;
	}
	if (numWorkedDay > 31)
	{
		cout << "�������� ��������� �����, ��������� ���� " << endl;
		SetnumWed();
	}
}
int Payment::GetnumWing()const
{
	return numWorkingDay;
}
void Payment::SetnumWing()
{
	cout << "������� ���������� ������� ���� � ������: ";
	cin >> numWorkingDay;
	if (numWorkingDay > 31)
	{
		cout << "�������� ��������� �����, ��������� ���� " << endl;
		SetnumWing();
	}
}
int Payment::�xperience()
{
	int This_year = 2022;
	exper = This_year - yearOfEmployment;
	return exper;
}
int Payment::AccruedAmount()
{
	double all=0;
	wages = (salary / numWorkingDay)*numWorkedDay;//�������� ��� ��������
	all = (wages * allowancePercentage) / precent;//��������
	wages += all;
	return wages;
}
int Payment::RetainedAmount()
{
	double all=0, al=0;
	all = (wages * incomeTax) / precent;
	al = wages / precent;
	withholding = (al + all);
	return withholding;
}
int Payment::Incometax()
{
	return  allsum = wages - withholding;
}
Payment::~Payment()
{
	delete[]name;
	delete[]surname;
	delete[]patronymic;
}
const int Payment::precent = 100;
int main()
{
	setlocale(LC_ALL, "ru");
	Payment person1;
	person1.Input();
	cout << endl;
	person1.�xperience();
	person1.AccruedAmount();
	person1.RetainedAmount();
	person1.Incometax();
	person1.Print();
	Payment per(person1);
	per.Print();
}