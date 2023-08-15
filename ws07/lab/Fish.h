/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef SDDS_FISH_H
#define SDDS_FISH_H
#include "Pet.h"

using namespace std;
namespace sdds {
	class Fish :public Pet {
		const double COST_CREATE_FISH = 2.0;
		const double COST_RESPAWN_FISH = 0.50;
		const double COST_FEED_FISH = 0.10;
	public:
		Fish(const char* name,int age=0);
		void feed();
		void reSpawn();
		Fish& operator++(int age);
		Fish& operator=(const Fish& other);
		
	};
	ostream& operator<<(ostream& os, Fish& Fish);


}

#endif