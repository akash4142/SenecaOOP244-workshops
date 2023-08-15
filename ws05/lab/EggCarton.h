/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef SDDS_EGGCARTON_H_
#define SDDS_EGGCARTON_H_
#include <iostream>
const int RegularEggWieght = 50;
const int JumboEggWieght = 75;
using namespace std;
namespace sdds {


    class EggCarton
    {
    private:
        int size;
        int noOfEggs;
        bool jumboSize;
        void setBroken();
        ostream& displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr)const;
    public:
        EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);

        ostream& display(ostream& ostr = cout) const;
        istream& read(istream& istr = cin);

        operator bool() const;
        operator int() const;
        operator double() const;
        EggCarton& operator --();
        EggCarton& operator ++();
        EggCarton operator --(int);
        EggCarton operator ++(int);
        EggCarton& operator=(int value);
        EggCarton& operator+=(int value);

        EggCarton& operator+=(EggCarton& right);

        bool operator==(const EggCarton& right) const;

        friend int operator+(int left, const EggCarton& right);
        friend ostream& operator<<(ostream& ostr, const EggCarton& right);
        friend istream& operator>>(istream& istr, EggCarton& right);
    };







};
#endif 

