/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#include<iostream>
#include"Media.h"

using namespace std;

namespace sdds
{
	ostream& operator<<(ostream& ostr, Media& right)
	{
		right.play(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, Media& right)
	{
		right.load(istr);
		return istr;
	}

}
