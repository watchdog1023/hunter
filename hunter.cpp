// The hunter application which can look for people
// v 0.0.2.0.1a

#include<iostream>

#include<string>

#include<fstream>
#include<cstdio>
#include<stdio.h>
#include<stdlib.h>  

using namespace std;

void hunt();
//void update();
void clean();
void quit();

int main()
{
	cout << " |||||	   ||||| " << endl;
	cout << " |   |	   |   | " << endl;
	cout << " |||||	   ||||| " << endl;
	cout << "       ||       " << endl;
	cout << " |	       | " << endl;
	cout << "  |	      | " << endl;
	cout << "   |||||||||| " << endl;
	cout << "Welcome to the hunter" << endl;
	cout << "Done by The Watch_dog" << endl;
    int choice;
    cout << "1.Start The Hunt" << endl;
	cout << "2.Clean" << endl;	
	cout << "3.Update" << endl;    
	cout << "4.Exit Program" << endl;
    cin >> choice;

	switch (choice)
	{
		case 1:
			hunt();
			break;
		case 2:
			clean();
			break;
//		case 3:
//			update();
//			break;
		case 4:
			quit();
			break;
       cin.get();
    }
}


void hunt()
	{
		//	The hunter looks for people
		cout << "Enter Criteria for hunt:" << endl;
		string mystr;
		cout << "Input Target name:";
		getline(cin, mystr);
		
		string mystr2;
		cout << "Enter age:";
		getline(cin, mystr2);

		string mystr3;
		cout << "Enter Gender:";
		getline(cin, mystr3);

		string mystr4;
		cout << "Enter race:";
		getline(cin, mystr4);

		string mystr5;
		cout << "Enter the hunting field:";
		getline(cin, mystr5);

		cout << "Check Criteria for hunt:" << endl;
		cout << "Name is:" << mystr << endl;
		cout << "Age is:" << mystr2 << endl;
		cout << "Gender is:" << mystr3 << endl;
		cout << "Race is:" << mystr4 << endl;
		cout << "Hunting Ground is:" << mystr5 << endl;

		string mystr6;
		cout << "Is This Correct? (y/n)";

		getline(cin, mystr6);

		if (mystr6 == "y")
		{
			cout << "Let The Hunt Begin!";
		}

		if (mystr6 == "n")
		{
		  loop:
			string mystr7;
			cout << "Input Target name:";
			getline(cin, mystr7);

			string mystr8;
			cout << "Enter age:";
			getline(cin, mystr8);


			string mystr9;
			cout << "Enter race:";
			getline(cin, mystr9);

			string mystr10;
			cout << "Enter the hunting field:";
			getline(cin, mystr10);

			cout << "Check Criteria for hunt:" << endl;

			cout << "Name is:" << mystr7 << endl;
			cout << "Age is:" << mystr8 << endl;
			cout << "Gender is:" << mystr3 << endl;
			cout << "Race is:" << mystr9 << endl;
			cout << "Hunting Ground is:" << mystr10 << endl;

			string mystr11;
			cout << "Is This Correct? (y/n)";
			getline(cin, mystr11);
			if (mystr11 != "y")
				{
					goto loop;
				}
			if (mystr11 == "y")
				{
					cout << "Let The Hunt Begin!" << endl;			
				}
			
		}
	}
	void clean()
	{
		ofstream myfile("killcode.bat");
		if (myfile.is_open())
		{
			myfile << "@echo off" << endl;
			myfile << "CMDKEY" << endl;
			myfile << "" << endl;
		}
	}
	void quit()
	{
	 cout << "Thank you for using the hunter program" << endl;
	 cin.get();
    }

//	return 0;
//}