/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#include "VRVideo.h"

using namespace std;
namespace sdds
{
	VRVideo::VRVideo() :Video()
	{
		m_equipment = nullptr;
	}

	VRVideo::VRVideo(int length, const char* name) :Video(length)
	{
		if (name != nullptr)
		{
			m_equipment = new char[strlen(name) + 1] {};
			strcpy(m_equipment, name);
		}
	}

	VRVideo::~VRVideo()
	{
		delete[] m_equipment;
		m_equipment = nullptr;
	}




	void VRVideo::load(istream& istr)
	{
		delete[] m_equipment;
		m_equipment = nullptr;
		char name[100];
		Video::load(istr);
		istr.get(name, 100);

		m_equipment = new char[strlen(name) + 1] {};
		strcpy(m_equipment, name);

	}



	ostream& VRVideo::play(ostream& ostr) const
	{
		int length = get();
		if (m_equipment != nullptr && length > -1)
		{
			ostr << "VRVideo requires ";
			ostr << m_equipment << endl;
			ostr << "Video Length = " << get();
		}
		return ostr;
	}




}
