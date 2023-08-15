/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


/*student name - akash yadav
student id - 172566218
email- ayadav35@myseneca.ca
date- 22/jan/2023
*/
#define _CRT_SECURE_NO_WARNINGS
#include "UI.h"
#include<cstring>
#define MAX_CHAR 100
namespace sdds
{
    void sort(GPA* recs, int length) {

        double swap_gpa = 0;
        int swap_stno = 0;
        char swap_name[MAX_CHAR];
        for (int counter = 0; counter < length - 1; counter++)
        {
            for (int counter1 = 0; counter1 < length - counter - 1; counter1++)
            {
                if (recs[counter1].stno > recs[counter1 + 1].stno)
                {
                    swap_gpa = recs[counter1].gpa;
                    recs[counter1].gpa = recs[counter1 + 1].gpa;
                    recs[counter1 + 1].gpa = swap_gpa;

                    swap_stno = recs[counter1].stno;
                    recs[counter1].stno = recs[counter1 + 1].stno;
                    recs[counter1 + 1].stno = swap_stno;

                    strcpy(swap_name, recs[counter1].name);
                    strcpy(recs[counter1].name, recs[counter1 + 1].name);
                    strcpy(recs[counter1 + 1].name, swap_name);

                }
            }
        }


    }

}