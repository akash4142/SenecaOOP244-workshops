/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef SDDS_VRVIDEO_H
#define SDDS_VRVIDEO_H
#include<iostream>
#include"Media.h"
#include"Video.h"

using namespace std;
namespace sdds
{
	class VRVideo : public Video
	{
		char* m_equipment = nullptr;
	public:
		VRVideo();
		VRVideo(int length, const char* name);
		~VRVideo();

		void load(istream& istr);
		ostream& play(ostream&)const override;
	};
}
#endif