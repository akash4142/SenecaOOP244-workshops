/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-: 

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#define _CRT_SECURE_NO_WARNINGS

#include "NameTag.h"
#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;
namespace sdds {
	NameTag::NameTag()
	{
		name = nullptr;
		extension = 0;
		isvalid = false;
	}

	NameTag::NameTag(const char* rec_name)
	{
		if (rec_name != nullptr && strlen(rec_name) > 0) {
			char* tmp = new char[strlen(rec_name) + 1];
			strcpy(tmp, rec_name);
			name = tmp;
			isvalid = true;
		}
		else {
			name = nullptr;
			isvalid = false;
		}
		extension = 0;
	}

	NameTag::NameTag(const char* rec_name, int tag)
	{
		if (rec_name != nullptr && strlen(rec_name) > 0) {
			char* tmp = new char[strlen(rec_name) + 1];
			strcpy(tmp, rec_name);
			name = tmp;
			isvalid = true;
		}
		else {
			name = nullptr;
			isvalid = false;
		}
		if (tag < 10000 || tag>99999)
		{
			extension = 0;
			isvalid = false;
		}
		else
			extension = tag;
	}

	NameTag::~NameTag()
	{
		delete[] name;
	}

	void NameTag::print()
	{
		if (!isvalid) {
			cout << "EMPTY NAMETAG!\n";
			return;
		}
		if (strlen(name) < 20) {
			cout.width(20);
			cout.setf(ios::left);
			cout << "+----------------------+";
			cout << "\n|                      |";
			char tmp[21];
			if (strlen(name) >= 20) {
				strncpy(tmp, name, 20);
				tmp[20] = '\0';
			}
			else {
				strcpy(tmp, name);
			}

			cout << "\n| " <<setw(20) << tmp << " |";
			cout << "\n|                      |";
			if (extension != 0)
			  cout << "\n| " << "Extension: " << setw(9) << extension;
			else
				cout << "\n| " << setw(20) << "Extension: N/A";
			cout << std::setw(0) << " |";
			cout << "\n|                      |";
			cout << "\n+----------------------+\n";
		}
		else {
			cout.width(40);
			cout.setf(ios::left);
			cout << "+------------------------------------------+";
			cout << "\n|                                          |";
			char tmp[41];
			if (std::strlen(name) >= 40) {
				strncpy(tmp, name, 40);
				tmp[40] = '\0';
			}
			else {
				strcpy(tmp, name);
			}

			cout << "\n| " << setw(40) << tmp << " |";
			cout << "\n|                                          |";
			if (extension != 0)
				cout << "\n| " << "Extension: " << setw(29) << extension;
			else
				cout << "\n| " << setw(40) << "Extension: N/A";
			cout << setw(0) << " |";
		    cout << "\n|                                          |";
			cout << "\n+------------------------------------------+\n";
		}
	}

	NameTag& sdds::NameTag::read()
	{
		cout << "Please enter the name: ";
		char tmp[1024];
		cin.getline(tmp, 1024, '\n');

		if (name != nullptr) {
			delete[] name;
		}
		name = new char[strlen(tmp) + 1];
		strcpy(name, tmp);

		cout << "Would you like to enter an extension? (Y)es/(N)o: ";
	x:
		cin.getline(tmp, 1024, '\n');
		if (strcmp(tmp, "Y") == 0 || strcmp(tmp, "y") == 0)
		{
			cout << "Please enter a 5 digit phone extension: ";
		y:
			cin.getline(tmp, 1024, '\n');

			extension = atoi(tmp);
			if (extension == 0)
			{
				cout << "Bad integer value, try again: ";
				goto y;
			}
			if (extension < 10000 || extension>99999) {
				cout << "Invalid value [10000<=value<=99999]: ";
				goto y;
			}
			isvalid = true;
		}
		else if (strcmp(tmp, "N") == 0 || strcmp(tmp, "n") == 0)
		{
			extension = 0;
			isvalid = true;
			return *this;
		}
		else {
			cout << "Only (Y) or (N) are acceptable, try agin: ";
			goto x;
		}

		return *this;
	}
}