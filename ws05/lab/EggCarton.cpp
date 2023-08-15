/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "EggCarton.h"
#include <iomanip>

using namespace std;

namespace sdds
{

    EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize)
    {
        if (size % 6 == 0 && (noOfEggs >= 0 && noOfEggs <= size) && (size >= 0 && size <= 36))
        {
            this->size = size;
            this->noOfEggs = noOfEggs;
            this->jumboSize = jumboSize;
        }
        else
        {
            this->setBroken();
        }
    }

    void EggCarton::setBroken()
    {

        this->size = -1;
        this->noOfEggs = -1;
    }

    ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr) const
    {
        int cartonWidth = size == 6 ? 3 : 6;
        for (int i = 0; i < size; i++)
        {
            ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
            ((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
        }
        return ostr;
    }
    ostream& EggCarton::display(ostream& ostr) const
    {
        if (this->operator bool())
        {
            displayCarton(size, noOfEggs, jumboSize, ostr);
        }
        else
        {
            ostr << "Broken Egg Carton!" << endl;
        }
        return ostr;
    }

    istream& EggCarton::read(istream& istr)
    {
        char jumbo_char;
        istr >> jumbo_char;
        jumboSize = (jumbo_char == 'j');


        istr.ignore();

        istr >> size;
        istr.ignore(); 
        istr >> noOfEggs;
        if (size % 6 == 0 && (noOfEggs >= 0 && noOfEggs <= size) && (size >= 0 && size <= 36))
        {
            this->size = size;
            this->noOfEggs = noOfEggs;
            this->jumboSize = jumboSize;
        }
        else
        {
            this->setBroken();
        }
        return istr;
    }

    EggCarton::operator bool() const
    {
        if (this->size > 0)
            return true;
        return false;
    }
    EggCarton::operator int() const
    {
        if (operator bool())
            return this->noOfEggs;
        return -1;
    }

    EggCarton::operator double() const
    {
        if (operator bool())
        {
            if (this->jumboSize)
            {
                return (double)(this->noOfEggs * JumboEggWieght) / 1000;
            }
            else
            {
                return (double)(this->noOfEggs * RegularEggWieght) / 1000;
            }
        }
        return -1.0;
    }

    EggCarton& EggCarton::operator--()
    {
        if (operator bool())
        {
            if (this->noOfEggs > 0)
            {
                noOfEggs -= 1;
            }
        }
        return *this;
    }

    EggCarton& EggCarton::operator++()
    {
        if (operator bool())
        {
            if (this->noOfEggs > 0)
            {
                noOfEggs += 1;
                if (noOfEggs > size)
                {
                    this->setBroken();
                }
            }
        }
        return *this;
    }

    EggCarton EggCarton::operator++(int)
    {
        EggCarton temp = *this;
        ++* this;
        return temp;
    }

    EggCarton EggCarton::operator--(int)
    {
        EggCarton temp = *this;
        --* this;
        return temp;
    }
    EggCarton& EggCarton::operator=(int value)
    {
        this->noOfEggs = value;
        if (this->noOfEggs > this->size)
        {
            this->setBroken();
        }
        return *this;
    }

    EggCarton& EggCarton::operator+=(int value)
    {
        if (operator bool())
        {
            this->noOfEggs = this->noOfEggs + value;
            if (this->noOfEggs > size)
                this->setBroken();
        }
        return *this;
    }

    EggCarton& EggCarton::operator+=(EggCarton& right)
    {
        if (operator bool())
        {
            int emptyspace = this->size - this->noOfEggs;
            if (emptyspace > 0)
            {
                if (right.noOfEggs <= emptyspace)
                {
                    this->noOfEggs = this->noOfEggs + right.noOfEggs;
                    right.noOfEggs = 0;
                }
                else
                {
                    this->noOfEggs = this->noOfEggs + emptyspace;
                    right.noOfEggs = right.noOfEggs - emptyspace;
                }
            }
        }
        return *this;
    }

    bool EggCarton::operator==(const EggCarton& right) const
    {
        double diffweight = this->operator double() - right.operator double();
        if (diffweight < 0.001 && diffweight > -0.001)
        {
            return true;
        }
        return false;
    }

    int operator+(int left, const EggCarton& right)
    {
        if (right.operator bool())
        {
            return right.operator int() + left;
        }
        return left;
    }
    ostream& operator<<(ostream& ostr, const EggCarton& right)
    {
        right.display(ostr);
        return ostr;
    }
    istream& operator>>(istream& istr, EggCarton& right)
    {
        right.read(istr);
        return istr;
    }
};

