/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
#define MAX_FNAME_SIZE 255    //Macros

using namespace std;
namespace sdds {
	class Numbers {
		double* Collection = nullptr;
		char fileName[MAX_FNAME_SIZE + 1] = { '\0' };
		unsigned int total_collection = 0;
		bool flag = false;
		bool Flag2 = false;

		void sort(double* nums, unsigned int size);
		unsigned int countLines(const char* filename);
		void setEmpty();
		bool isEmpty() const;
		bool load();
		Numbers& save();
		double max() const;
		double min() const;
		double average() const;

	public:
		Numbers();   //default constructor
		Numbers(const char filename[]); //parameterised constructor
		Numbers(const Numbers& copy); //copy constructor
		Numbers& operator = (const Numbers& copy);//assignment operator
		operator bool() const;
		void sort();
		Numbers& operator+=(double value);
		ostream& display(ostream& ostr) const;
		~Numbers();
	};

	ostream& operator<<(ostream& ostr, const Numbers& right); //helper functions
	istream& operator>>(istream& istr, Numbers& right);


}
#endif // !SDDS_NUMBERS_H_