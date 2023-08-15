/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-: 

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Store.h"
#include<cstring>
#include"Toys.h"
#include<iomanip>
using namespace std;
namespace  sdds {
	
	void Store::setStore(const char* sName, int no) {
		
		if (strlen(sName) > 0 && strlen(sName) <= MAX_SNAME && no > 0 && no <= MAX_NUM_TOYS)
		{
			strcpy(m_sName, sName);
			m_noOfToys = no;
			m_addToys = 0;
		}
		else
			setEmpty();
	}
	void Store::setToys(const char* tname, int sku, double price, int age) {
		if (m_addToys < m_noOfToys) {
			m_toy[m_addToys].addToys(tname, sku, price, age);
			m_addToys++;
		}
	}
	void Store::find(int sku) {
		for (int i = 0; i < m_addToys; i++)
		{
			if (m_toy[i].getsku() == sku)
			{
				m_toy[i].isSale(true);
				m_toy[i].calSale();
			}
		}
	}
	void Store::setEmpty() {
		m_sName[0] = '\0';
		m_noOfToys = 0;
		m_addToys = 0;
	}
	
	void Store::display()const {

		if (strlen(m_sName) > 0 && m_noOfToys > 0) {

			cout.width(60);

			cout.fill('*');

			cout << "*" << endl;

			cout << m_sName << endl;




			cout.width(60);

			cout.fill('*');

			cout << "*" << endl;

			cout << "list of the toys" << endl;




			cout.width(30);

			cout.fill(' ');

			cout << "SKU";




			cout.width(10);

			cout.fill(' ');

			cout << "Age";




			cout.width(11);

			cout.fill(' ');

			cout << "Price";




			cout.width(10);

			cout.fill(' ');

			cout << "Sale" << endl;




			for (int i = 0; i < m_noOfToys; i++) {

				cout << "Toy[" << i + 1 << "] :";

				m_toy[i].display();

				cout << endl;

			}

		}

		else

			cout << "Invalid Store" << endl;

	}




}