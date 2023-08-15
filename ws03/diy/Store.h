/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-: 

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef SDDS_STORE_H
#define SDDS_STORE_H
#include "Toys.h"
#define MAX_NUM_TOYS 10
#define MAX_SNAME 31

namespace sdds {
	class Store {
		char m_sName[MAX_SNAME];
		int m_noOfToys;
		int m_addToys;
		Toys m_toy[MAX_NUM_TOYS];
	public:
		void setStore(const char* sName, int no);
		void setToys(const char* tname, int sku, double price, int age);
		void find(int sku);
		void setEmpty();
		void display()const;
	};
}

#endif // !SDDS_STORE_H

