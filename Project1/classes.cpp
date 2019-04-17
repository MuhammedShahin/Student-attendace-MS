#include "classes.h"
#include<string>
#include<unordered_map>
#include<iostream>
#include<fstream>
using namespace std;
unordered_map<string, string> getEmp()
{
	unordered_map <string, string> EmpData;
	ifstream EmpFile;
	EmpFile.open("Emp.txt");
	string EmpName, empID;
	while (EmpFile >> EmpName >> empID)
	{
		EmpData[empID] = EmpName;
	}
	EmpFile.close();
	return EmpData;
}

unordered_map<string, string> getAdmin()
{
	unordered_map <string, string> AdminData;
	ifstream Admins;
	Admins.open("Admins.txt");
	string AdminName, AdminID;
	while (Admins >> AdminName >> AdminID)
	{
		AdminData[AdminID] = AdminName;
	}
	Admins.close();
	return AdminData;
}
unordered_map<string, pair<string, string>> getCourse()
{
	unordered_map<string, pair<string, string>> CourseData;
	ifstream Courses;
	Courses.open("course.txt");
	string name, id, Acyear;
	while (Courses >> id >> name >> Acyear)
	{
		pair<string, string>Data;
		Data.first = name;
		Data.second = Acyear;
		CourseData[id] = Data;
	}
	Courses.close();
	return CourseData;
}

unordered_map<string, pair<string, string>> getStudent()
{
	unordered_map<string, pair<string, string>> StudentData;
	ifstream students;
	students.open("student.txt");
	string name, id, Acyear;
	while (students >> id >> name >> Acyear)
	{
		pair<string, string>Data;
		Data.first = name;
		Data.second = Acyear;
		StudentData[id] = Data;
	}
	students.close();
	return StudentData;
}



Admin::Admin()
{
	ID = "";
	name = "";
}

Admin Admin::Admininput()
{
	Admin A;
	//get the username and the password from user.
	cout << "Enter the username as(Administrator) : ";
	cin >> A.name;
	cout << "Enter the password : ";
	cin >> A.ID;
	return A;
}

bool Admin::Admincheck(Admin A, unordered_map<string, string> AdminData)
{
	unordered_map<string, string>::iterator it;
	it = AdminData.find(A.ID);
	if (it != AdminData.end() && it->first == A.ID&&it->second == A.name)
		return 1;
	return 0;
}

bool Admin::Adminlogin()
{
	unordered_map<string, string> AdminData;
	AdminData = getAdmin();
	return Admincheck(Admininput(), AdminData);
}

void Admin::AddEmop()
{
	unordered_map<string, string> emp = getEmp();
	cout << "Please Enter The Data for the New Employee. \n";
	string name, pass;
	cout << "Enter the name : ";
	cin >> name;
	cout << "Enter the password : ";
	cin >> pass;
	unordered_map<string, string>::iterator it3;
	it3 = emp.find(pass);
	while (true)
	{
		if (it3 != emp.end())
		{
			cout << "recorded pass !!" << " please enter new password : ";
			cin >> pass;
			it3 = emp.find(pass);
		}
		else break;
	}
	emp[pass] = name;
	unordered_map<string, string>::iterator it;
	ofstream empfile;
	empfile.open("Emp.txt");
	for (it = emp.begin(); it != emp.end(); it++)
	{
		empfile << it->second << " " << it->first << "\n";
	}
	empfile.close();
	cout << "Done !!\n";
}

void Admin::deleteEmp()
{
	unordered_map<string, string> emp = getEmp();
	cout << "Please Enter The Data for deleting  Employee. \n";
	string name, pass;
	cout << "Enter the name : ";
	cin >> name;
	cout << "Enter the password : ";
	cin >> pass;
	emp.erase(pass);
	unordered_map<string, string>::iterator it;
	ofstream empfile;
	empfile.open("Emp.txt");
	for (it = emp.begin(); it != emp.end(); it++)
	{
		empfile << it->second << " " << it->first << "\n";
	}
	empfile.close();
	cout << "Done !!\n";
}



Employee::Employee()
{
	ID = "";
	name = "";
}

Employee Employee::input()
{
	Employee Emp;
	//get the username and the password from user.
	cout << "Enter The username : ";
	cin >> Emp.name;
	cout << "Enter The password : ";
	cin >> Emp.ID;
	return Emp;
}
bool Employee::check(Employee E,unordered_map<string,string> Empdata)
{
	unordered_map<string, string>::iterator it;
	it = Empdata.find(E.ID);
	if (it != Empdata.end() && it->first == E.ID&&it->second == E.name)
		return 1;
	return 0;
}


bool Employee::cheak_ID_student(int id)
{
	ifstream read;
	read.open("student.txt");
	while (read.good())
	{
		string line;
		getline(read, line);
		int count1 = 0;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == ' ')
				break;
			count1++;
		}
		line.erase(line.begin() + count1, line.end());
		//cout << line << endl;
		int line_con = atoi(line.c_str());
		//cout << line_con << endl;
		if (id == line_con)
		{
			cout << "cheaked!!" << endl;
			read.close();
			return true;
		}
	}
	read.close();
	return false;
}


bool Employee::login()
{
	unordered_map<string, string> Empdata;
	Empdata = getEmp();
	return check(input(), Empdata);
}

void Employee::select(int val)
{
	if (val == 1)
		record();
	else if (val == 2)
		view_report();
	else if (val == 3)
		view_report_of_limited();

}

void Employee::record()
{
	vector<string> data;
	ifstream read;
	read.open("data.txt");
	while (read.good())
	{
		string line;
		getline(read, line);
		data.push_back(line);
	//	cout << line << endl;
	}
	read.close();
	cout << "Now we will Record the data for the student" << endl;
	cout << "Enter the id of the student you want to recored his appsens : ";
	int ID;
	cin >> ID;
	bool cheak7=cheak_ID_student(ID);
	/*if (cheak7 == false)
	{
		cout << "invaled id !!" << endl;
		return;
	}*/
	cout << "Enter the name of the subject you want to record : ";
	string subject_name;
	cin >> subject_name;
	cout << "if you want to recored press 'y' to continue or 'n' to undo : ";
	char conf;
	cin >> conf;
	int count1 = 0;
	char want[100];
	bool cheak2 = true;
	if (conf == 'y')
	{
		for (int i = 0; i < data.size(); i++)
		{
			string compar = data[i];
			string line1 = data[i];
			int count2 = 0;
			for (int i = 0; i < line1.size(); i++)
			{
				if (line1[i] == ' ')
					break;
				count2++;
			}
			line1.erase(line1.begin() +count2, line1.end());
			//int id_size = line1.size();
			int line_con = atoi(line1.c_str());
			if (ID == line_con)
			{
				cout << "cheaked!!" << endl;
				for (int j = count2+1; j < compar.size(); j++)
				{
					if (compar[j] == ' ')
					{
						for (int k = 0; k < subject_name.size(); k++)
						{
							if (want[k] != subject_name[k]) {
								cheak2 = false;
								//cout << want[k] << " " << subject_name[k] << endl;
								break;
							}
						}
						if (cheak2 == true)
						{
							//int
							string car = "";
							car += compar[j + 1];
							car += compar[j + 2];
							int rec = atoi(car.c_str());
							rec += 1;
							string na = to_string(rec);
							char n = na[0];
							char s = na[1];
							if (rec >= 10) {
								compar[j + 1] = n;
								compar[j + 2] = s;
							}
							else
							{
								char zero = '0';
								compar[j + 1] = zero;
								compar[j + 2] = n;
							}
							data[i] = compar;
							cout << "Success!!" << endl;
							ofstream in;
							in.open("data.txt");
							for (int i = 0; i<data.size(); i++)
							{
								in << data[i] << endl;
							}
							in.close();
							return;
						}
						else
						{
							count1 = 0;
							j += 4;
							cheak2 = true;
						}
					}
					want[count1] = compar[j];
					//cout << compar[j] << " " << want[count1] << endl;
					count1++;
				}
			}
		}
	}
	else
	{
		return;
	}
}

//...........................................................................................................
unordered_map<string, vector<pair<string, string>>> getData()
{
	ifstream Data;
	Data.open("data.txt");
	string line;
	vector<string> data;
	while (getline(Data, line))
	{
		data.push_back(line);
	}
	Data.close();
	string tmp = "", id, sub_name, Atten;
	unordered_map<string, vector<pair<string, string>>> d;
	for (int i = 0; i < data.size(); i++)
	{
		int counter = 0;
		for (int j = 0; j < data[i].size(); j++)
		{
			if (data[i][j] == ' ')
			{
				if (counter == 0)
				{
					counter++;
					id = tmp;
					tmp = "";

				}
				else if (counter == 1)
				{
					Atten = tmp;
					counter++;
					tmp = "";
				}
				else if (counter == 2)
				{
					sub_name = tmp;
					counter = 1;
					string id_s = "";
					for (int i = 0; i < id.size(); i++)
					{
						if (id[i] != ' ')
						{
							id_s += id[i];
						}
					}
					d[id_s].push_back(make_pair(sub_name, Atten));
					tmp = "";
				}
			}
			tmp += data[i][j];
		}
	}
	return d;
}


void Employee::view_report()
{
	
	unordered_map<string, vector<pair<string, string>>> d=getData();
	unordered_map<string, pair<string, string>> students=getStudent();
	unordered_map<string, pair<string, string>>::iterator it1;
	unordered_map<string, vector<pair<string, string>>>::iterator it;
	for (it = d.begin(); it != d.end(); it++)
	{
		
		it1 = students.find(it->first);
		cout << "Student name : " << it1->second.first << " The Academic_year is : " << it1->second.second<<endl;
		cout << endl;
		for (int i = 0; i < it->second.size(); i++)
		{
			cout <<"sub_name : " << it->second[i].second << "    "<<" days of absence : " << it->second[i].first << endl;
		}
		cout << endl;
	}
}



Employee::~Employee()
{
}

student_::student_()
{
	name = "NULL";
	ID = "NULL";
	Academic_year = "NULL";
}
string studentID;
student_ student_::input()
{
	student_ s;
	cout << "Enter your Name : ";
	cin >> s.name;
	cout << "Enter your ID : ";
	cin >> s.ID;
	studentID = s.ID;
	return s;
}

bool student_::studentCheck(student_ s, unordered_map<string, pair<string, string>> s_data)
{
	unordered_map<string, pair<string, string>>::iterator it;
	it = s_data.find(s.ID);
	if (it != s_data.end() && it->first == s.ID&&it->second.first == s.name)
	{
		return 1;
	}
	return false;
}

bool student_::login()
{
	unordered_map<string, pair<string, string>> s_data = getStudent();
	return studentCheck(input(), s_data);
}
//student view 
void student_::view_attendance()
{	
	unordered_map<string, pair<string, string>> su = getStudent();
	unordered_map<string, pair<string, string>>::iterator t;
	unordered_map<string, vector<pair<string, string>>> Data=getData();
	unordered_map<string, vector<pair<string, string>>>::iterator it;
	t = su.find(studentID);//get student name and Ac_year.
	it = Data.find(studentID);//get student subjects .
	cout << "Student name : " << t->second.first << " The Academic_year is : " << t->second.second << endl;
	cout << endl; 
	for (int i = 0; i < it->second.size(); i++)
	{
		cout << "sub_name : " << it->second[i].second << "    " << " days of absence : " << it->second[i].first << endl;
	}
	cout << endl;
}


void Employee::view_report_of_limited()
{
	unordered_map<string, vector<pair<string, string>>> d = getData();
	unordered_map<string, pair<string, string>> students = getStudent();
	unordered_map<string, pair<string, string>>::iterator it1;
	unordered_map<string, vector<pair<string, string>>>::iterator it;
	for (it = d.begin(); it != d.end(); it++)
	{
	
		it1 = students.find(it->first);
		int counter = 0;
		for (int i = 0; i < it->second.size(); i++)
		{
			int num= atoi(it->second[i].first.c_str());
			if (num >= 21)
			{
				if (counter == 0)
				{
					cout << "Student name : " << it1->second.first << " The Academic_year is : " << it1->second.second << endl;
					cout << endl;
					counter++;
				}
				cout << "sub_name : " << it->second[i].second << "    " << " days of absence : " << it->second[i].first << endl;

			}
		}
	}
	cout << endl;
}