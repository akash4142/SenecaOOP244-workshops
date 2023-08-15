/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-: 

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef SDDS_TOYS_H
#define SDDS_TOYS_H

namespace sdds {
#define MAX_TNAME 31


	class Toys {
	
		char m_tname[MAX_TNAME];
		int m_sku;
		double m_price;
		int m_age;
		bool m_onSale=false;
	public:
		void setsku(int sku);
		int getsku();
		void addToys(const char* tname, int sku, double price, int age);
		void isSale(bool sale);
		void calSale();
		void display()const;

	};
}
#endif // !SDDS_TOYS_H