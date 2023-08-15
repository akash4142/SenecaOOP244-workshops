/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


/*student name - akash yadav
student id - 172566218
email- ayadav35@myseneca.ca
date- 26/jan/2023
*/
#ifndef SDDS_TOOLS_H_
#define SDDS_TOOLS_H_

namespace sdds {
	int openFile_r(const char filename[]); // Provided
	void closefile(); // Provided
	int noOfTraces(); // Provided

	// ADD: Declare read prototypes (4 prototypes)

	
	int read(char package_name[]);
	int read(int &value);
	int read(double &timeinhours);
	int read(char &dayofweek);




	void strCpy(char* des, const char* src); // Provided
	int strLen(const char* s); // Provided
}
#endif 
