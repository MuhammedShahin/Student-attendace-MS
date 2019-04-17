#pragma once
#include<string>
#include<unordered_map>
using namespace std;

class Admin
{
	string name;
	string ID;
public:
	Admin();
	Admin Admininput();
	bool Admincheck(Admin, unordered_map<string, string>);
	bool Adminlogin();
	void AddEmop();
	void deleteEmp();
};

class Employee
{
	string name;
	string ID;
public:
	Employee();
	Employee input();
	bool login();
	bool check(Employee , unordered_map<string, string> );
	bool cheak_ID_student(int id);
	void select(int);
	void record();
	void view_report();
	void view_report_of_limited();
	~Employee();
};

class student_
{
	string name;
	string ID;
	string Academic_year;
public:
	student_();
	student_ input();
	bool studentCheck(student_, unordered_map<string, pair <string, string>>);
	bool login();
	void view_attendance();
};

class course
{
	string code;
	string name;
	int Academic_year;
public:
	course();
};

