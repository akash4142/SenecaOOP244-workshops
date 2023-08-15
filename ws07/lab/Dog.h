/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef DOG_H
#define DOG_H
#include "Pet.h"

namespace sdds {
    class Dog : public Pet {
        const double COST_CREATE_DOG = 4.0;
        const double COST_RESPAWN_DOG = 1.00;
        const double COST_FEED_DOG = 0.25;
        int m_numWalks;
    public:
        int getnumwalk();
        Dog(const char* name, int initialAge = 0,int numWalks = 0);
        void operator++(int num);
        Dog& operator=(const Dog& other);
        void feed();
        void walk();
        void reSpawn();
    };
    std::ostream& operator<<(std::ostream& os,  Dog& dog);

}

#endif // DOG_H