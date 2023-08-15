/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-: 

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#define CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<iomanip>
#include"Toys.h"
using namespace std;
namespace  sdds {
    void Toys::setsku(int sku) {
        m_sku = sku;
    }
    int Toys::getsku() {
        return m_sku;
    }
	void Toys::addToys(const char* tname, int sku, double price, int age) {
        if (tname != nullptr && tname[0] != '\0' && strlen(tname) <= MAX_TNAME && sku >= 0) {
            strcpy(m_tname, tname);
            m_sku = sku;
            m_price = price;
            m_age = age;
        }
        else {
            m_tname[0] = '\0';
            m_sku = 0;
            m_price = 0.0;
            m_age = 0;
        }
		
	}
	void Toys::isSale(bool sale) {
		m_onSale = sale;
	}
	void Toys::calSale() {
        if (m_onSale){
		m_price *= 0.8;
        }
	}
	
    void Toys::display() const

    {

        if ((m_tname[0] != '\0') && (m_sku > 10000000)) {



            cout.width(15);

            cout.fill(' ');

            cout.setf(ios::left);

            cout << m_tname;




            cout.unsetf(ios::left);

            cout.width(10);

            cout << m_sku;




            cout.width(6);

            cout << m_age;




            cout.width(12);

            cout.setf(ios::fixed);

            cout.precision(2);

            cout << m_price;




            if (m_onSale) {

                cout.width(10);

                cout << "On Sale";

            }

            else

                cout.width(8);

            cout << " ";

        }




        else

            cout << "Invalid Toy";




    }



}