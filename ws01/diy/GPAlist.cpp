/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


/*student name - akash yadav
student id - 172566218
email- ayadav35@myseneca.ca
date- 22/jan/2023
*/

#include "GPAlist.h"
#include <cmath>
#include<stdlib.h>
#include <string>
#include<iomanip>
using namespace std;
namespace sdds
{

	GPA data[100];
	int length = 0;
	bool gpaQuery(const char* filename)
	{

		if (loadfile(filename, data, length))

		{
			cout << "Enter GPA query..." << endl;

			char selected[10]{ '\0' };
			while (selected[0] != '!')
			{
				cout << "? ";
				cin >> selected;
				if (!checkValid(selected[0]))
				{
					cout << "Syntax error: ? [Op][value]<ENTER>\nOp: [>,<,~,!]\nvalue: GPA value\n\n";
					fflush(stdin);
				}
				else
				{
					if (selected[0] == '!')
					{
						char a;
						cout << "Exit the program? (Y)es/(N)o: ";
						cin >> a;
						if (a == 'y' || a == 'Y')
						{
							break;

						}

					}
					string str = "";
					for (int i = 1; i < 9; i++)
					{
						str = str + selected[i];
					}
					double check = stof(str);
					check = round(check * 100) / 100;;
					display(selected[0], check);

				}
			}

			return true;
		}
		return false;
	}
	bool checkValid(char selected)
	{

		char valid[5] = { '>' ,'<','~','!' };

		for (int i = 0; i < 5; i++)
		{
			if (selected == valid[i])
			{
				return true;
			}
		}
		return false;
	}
	void display(const char selected, double check)
	{
		int count = 1;
		sort(data, length);

		switch (selected)
		{
		case '>':

			for (int i = 0; i < length; i++)
			{
				if (check < (data[i].gpa))
				{
					cout << "[" << count << "] " << data[i].stno << ": " << setprecision(1) << fixed << data[i].gpa << " " << "\(" << data[i].name << ")" << endl;
					count++;
				}

			}
			break;
		case '<':
			for (int i = 1; i < length; i++)
			{
				if (check > (data[i].gpa))
				{
					cout << "[" << count << "] " << data[i].stno << ": " << setprecision(1) << fixed << data[i].gpa << " " << "\(" << data[i].name << ")" << endl;
					count++;
				}

			}
			break;
		case '~':
			for (int i = 0; i < length; i++)
			{


				if ((data[i].gpa) == check)
				{
					cout << "[" << count << "] " << data[i].stno << ": " << setprecision(1) << fixed << data[i].gpa << " " << "\(" << data[i].name << ")" << endl;

					count++;
				}

			}
			break;
		default:
			break;
		}
	}

}