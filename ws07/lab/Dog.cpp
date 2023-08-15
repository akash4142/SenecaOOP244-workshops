/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#include <iostream>
#include "Dog.h"

using namespace std;
namespace sdds {
    
    Dog::Dog(const char* name, int initialAge  , int numWalks) : Pet(name, initialAge, COST_CREATE_DOG) {
        m_numWalks = numWalks;
    }

    void Dog::operator++(int num) {
        double healthDelta = 0;
        if (Dog::isAlive()) {
            
            healthDelta += 0.15 * (getHugs() - 1);
            healthDelta += 0.10 * (getFeeds() - 2);
            healthDelta += 0.10 * (getGrooms() - 1);
            healthDelta += 0.20 * (m_numWalks - 2);
            applyHealthDelta(healthDelta);
                   }
        m_numWalks = 0;

        Pet::operator++(num);
    }

    Dog& Dog::operator=(const Dog& other) {
        if (this != &other) {
            Pet::operator=(other);
            m_numWalks = other.m_numWalks;
            addCharge(COST_CREATE_DOG * 2);

        }
        return *this;
    }

    void Dog::feed() {
        Pet::feed();
        if (Dog::isAlive()) {
            addCharge(COST_FEED_DOG);
        }
    }

    void Dog::walk() {
        if (Dog::isAlive()) {
            m_numWalks++;
        }
    }

    void Dog::reSpawn() {
        Pet::reSpawn();
        m_numWalks = 0;
        addCharge(COST_RESPAWN_DOG);
    }

    int Dog::getnumwalk() {
        return m_numWalks;
    }


    std::ostream& operator<<(std::ostream& os, Dog& dog) {
        os << "** Generic Dog **\n";
        os << "   Walks: " << dog.getnumwalk() << "\n";
        dog.outputData(os);
 
        return os;
    }
}