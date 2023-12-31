/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#ifndef SDDS_CONTACT_H_
#define SDDS_CONTACT_H_

#include <iostream>
#include "Person.h"

#include "Tools.h"

namespace sdds {
	class Contact : public Person {


		char* m_address{};
		char* m_city{};
		char m_province[3]{};
		char m_postalCode[7]{};


	public:


		Contact();
		Contact(const Contact& copyFrom);
		Contact& operator=(const Contact& RightOperand);
		virtual ~Contact();
		
		virtual std::istream& read(std::istream& istr);
		virtual std::ostream& write(std::ostream& ostr)const;
		
		virtual operator bool()const;
		virtual void operator~();
	};
	
	std::istream& operator>>(std::istream& istr, Contact& rightOperand);
	std::ostream& operator<<(std::ostream& ostr, const Contact& rightOperand);

}

#endif