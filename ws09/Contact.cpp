/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#include <iostream>
#include "Contact.h"
using namespace std;

namespace sdds {
	Contact::Contact() : Person() {}
	Contact::Contact(const Contact& copyFrom) : Person(copyFrom)
	{


		strCpy(m_province, copyFrom.m_province);
		


		strCpy(m_postalCode, copyFrom.m_postalCode);



		if (copyFrom)
		{
			delAlloCopy(m_address, copyFrom.m_address);

			delAlloCopy(m_city, copyFrom.m_city);
		}
	}




	Contact& Contact::operator=(const Contact& rightOperand)
	{

		if (this != &rightOperand)
		
		{
		
			if (rightOperand)
			
			{
			
				Person::operator=(rightOperand);
				delAlloCopy(m_address, rightOperand.m_address);
				delAlloCopy(m_city, rightOperand.m_city);
				strCpy(m_province, rightOperand.m_province);
				strCpy(m_postalCode, rightOperand.m_postalCode);
			}
		}

		return *this;

	}


	Contact::~Contact()

	{

		~*this;
	}


	std::istream& Contact::read(std::istream& istr)
	{
		~*this;
		Person::read(istr);
		m_address = dynRead(istr, ',');

		m_city = dynRead(istr, ',');
		istr.getline(m_province, 3, ',');
		istr.getline(m_postalCode, 7, '\n');

		if (istr.fail())
		{
			~*this;
		}
		return istr;
	}

	std::ostream& Contact::write(std::ostream& ostr) const
	{
		
		Person::write(ostr);


		if (*this)
		
		{
		
			ostr << endl << m_address << endl;

			ostr << m_city << " " << m_province << endl;

			for (int i = 0; i < strLen(m_postalCode); i++)
			{
				if (i == 3)
				{
					ostr << " " << m_postalCode[i];
				}
				else
				{
					ostr << m_postalCode[i];
				}
			}
			
			ostr << endl;
		
		}
		return ostr;
	}

	Contact::operator bool() const
	
	{
	
		return m_address && m_address[0] && m_city && m_city[0];
	
	}

	void Contact::operator~()
	{
		Person::operator~();

		delete[] m_address;

		delete[] m_city;

		m_address = m_city = nullptr;
	}

	std::istream& operator>>(std::istream& istr, Contact& rightOperand)
	{

		return rightOperand.read(istr);

	}

	std::ostream& operator<<(std::ostream& ostr, const Contact& rightOperand)
	{
	
		return rightOperand.write(ostr);
	
	}
}