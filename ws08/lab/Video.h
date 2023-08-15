/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/


#ifndef SDDS_VIDEO_H
#define SDDS_VIDEO_H
#include<iostream>
#include"Media.h"

using namespace std;
namespace sdds
{
	class Video : public Media
	{
		int m_length;
	protected:

		int get()const;

	public:

		Video();
		Video(int length);

		virtual ostream& play(ostream&)const = 0;
		void load(istream& istr);

		Video(const Video& obj) = delete;
		Video& operator=(const Video& obj) = delete;
	};
}
#endif