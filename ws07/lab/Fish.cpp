/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#include <iostream>
#include "Fish.h"


namespace sdds {
	Fish::Fish(const char* name, int age) :Pet(name, age, COST_CREATE_FISH) {

	}

	void Fish::feed() {
		Pet::feed();
		if (Fish::isAlive()) {
			addCharge(COST_FEED_FISH);
		}
	}

	void Fish::reSpawn() {
		Pet::reSpawn();
		addCharge(COST_RESPAWN_FISH);
	}

	Fish& Fish::operator++(int num) {
		if (Fish::isAlive()) {
			double healthDelta = 0.0;
			healthDelta += 0.20 * (getFeeds() - 1);
			applyHealthDelta(healthDelta);
			Pet::operator++(num);
		}	
		return *this;
	}

	Fish& Fish::operator=(const Fish& other) {
		if (this != &other) {
			Pet::operator=(other);
			addCharge(COST_CREATE_FISH * 2);
		
	
		}
		return *this;
	}

	ostream& operator<<(ostream& os,Fish& fish) {
		os << "** Generic Fish **\n";
		fish.outputData(os);
		return os;
	}
}