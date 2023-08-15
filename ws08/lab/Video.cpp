/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#include<iostream>
#include"Media.h"
#include "Video.h"

using namespace std;

namespace sdds
{
	int Video::get() const
	{
		return m_length;
	}

	Video::Video()
	{
		m_length = 0;
	}

	Video::Video(int length)
	{
		if (length > -1)
		{
			m_length = length;
		}
		else
		{
			m_length = -1;
		}
	}

	void Video::load(istream& istr)
	{
		int length = 0;
		istr >> length;
		istr.ignore(1);		
		if (length > -1)
		{
			m_length = length;
		}
		else
		{
			m_length = -1;
		}
	}

}