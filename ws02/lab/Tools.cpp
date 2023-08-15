/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


/*student name - akash yadav
student id - 172566218
email- ayadav35@myseneca.ca
date- 26/jan/2023
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include <cstdio>
#include "Tools.h"
#include "Package.h"

FILE* fp;

namespace sdds {
    int openFile_r(const char filename[]) { // Fully provided
        fp = fopen(filename_r, "r");
        return fp != NULL;
    }
    int noOfTraces() {  // Fully provided
        int noOfTraces = 0;
        char ch;
        while (fscanf(fp, "%c", &ch) == 1) {
            noOfTraces += (ch == '\n');
        }
        rewind(fp);
        return noOfTraces;
    }


    // To Do: read functions (4 overloaded read functions)



    int read(char package_name[]) {
        return fscanf(fp, "%60[^\n]\n", package_name) == 1;
       
    }

    int read(int &value){
        return fscanf(fp, "%d,", &value)==1;
    }

    int read(double &timeinhours) {
        return fscanf(fp,"%lf,",&timeinhours)==1;
    }

    int read(char &dayofweek) {
        return fscanf(fp, "%[^ \t\n\r\v\f,]%*c", &dayofweek) == 1;
    }

    void closefile() { // Fully provided
        if (fp) fclose(fp);
    }
    
    void strCpy(char* str1, const char* str2) { // Fully provided 
        while (*str2) {
            *str1++ = *str2++;
        }
        *str1 = 0;
    }
    int strLen(const char* str) {  // Fully provided
        int i = -1;
        while (str[++i]);
        return i;
    }
}