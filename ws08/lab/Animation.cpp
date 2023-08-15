/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#include<iostream>
#include "Animation.h"

using namespace std;

namespace sdds
{
	Animation::Animation() :Video()
	{
		m_dimension = 0;
	}

	Animation::Animation(int length, int dimension) :Video(length)
	{

		if (dimension == 2 || dimension == 3)

		{

			m_dimension = dimension;

		}

	}

	void Animation::load(istream& istr)

	{

		int dimension;

		istr.ignore(1);

		Video::load(istr);

		istr >> dimension;

		istr.ignore(1000, '\n');

		if (dimension == 2 || dimension == 3)

		{

			m_dimension = dimension;

		}
	}

	ostream& Animation::play(ostream& ostr) const
	{
		int length = get();

		if (m_dimension != 0 && length > -1)
		{
			ostr << "Animation is in " << m_dimension << "-D" << endl;
			ostr << "Video Length = " << get();
		}
		return ostr;
	}

}