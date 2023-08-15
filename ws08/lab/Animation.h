/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#ifndef SDDS_ANIMATION_H
#define SDDS_ANIMATION_H

#include<iostream>
#include"Video.h"

using namespace std;
namespace sdds
{
	class Animation : public Video
	{
		int m_dimension = 0;
	public:

		Animation();

		Animation(int length, int dimension);

		void load(istream& istr)override;

		ostream& play(ostream&)const override;
	};
}

#endif