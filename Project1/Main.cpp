#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<fstream>
#include<map>
#include<sstream>
#include"classes.h"


using namespace std;


int main()
{
	cout << "  Choose from list : \n \n    1.Login as Employee.\n    2.Login as Administrator.\n    3.Login as Student.\n    4.Exite\n\n\n";
	int n;
	while (1)
	{
		cout << "Enter The number : ";
		cin >> n;
		if (n == 1)
		{
			Employee e;
			if (!e.login()) {
				cout << "Invalid Username Or Password!\n";
				continue;
			}
			else
			{
				cout << "Select an operation : \n   1.Record Data\n   2.View Attendace\n   3.View limited student\n";
				int s;
				cout << "Please Enter the number of your selection : ";
				cin >> s;
				if (s != 1 && s != 2 && s!=3)
				{
					cout << "Invalid input!\n";
					continue;
				}
				else 
				 e.select(s);
			}

		}
		else if (n == 2)
		{
			Admin admin;
			if (!admin.Adminlogin())
			{
				cout << "Invalid Username OR Password ! \n";
				continue;
			}
			else
			{
				cout << "Select an operation : \n   1.Add new Employee\n   2.Delete An Employee\n";
				int s;
				cout << "Please Enter the number of your selection : ";
				cin >> s;
				if (s == 1)
					admin.AddEmop();
				else if (s == 2)
					admin.deleteEmp();
				else
				{
					cout << "Invalid Input !\n";
					continue;
				}
			}
		}
		else if (n == 3)
		{
			student_ st;
			if (!st.login())
			{
				cout << "Invalid Username or password\n";
				continue;
			}
			else
			{
				cout << "valid Id" << endl;
				cout << "your report:" << endl;
				st.view_attendance();
			}
		}





		else
			break;
	}
	
	system("pause");
	return 0;
}