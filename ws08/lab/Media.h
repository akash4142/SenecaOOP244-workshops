/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#ifndef SDDS_MEDIA_H
#define SDDS_MEDIA_H
#include<iostream>

using namespace std;
namespace sdds

{
	class Media {
	public:

		virtual ostream& play(ostream&)const = 0;

		virtual void load(istream& istr) = 0;

		virtual ~Media() = default;
	};

	ostream& operator <<(ostream& ostr, Media& right);
	istream& operator >>(istream& istr, Media& right);
}


#endif