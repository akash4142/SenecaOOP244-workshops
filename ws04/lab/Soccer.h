
/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#ifndef SDDS_SOCCER_H
#define SDDS_SOCCER_H
#include <ostream>
#define MAX_FOUL 4
namespace sdds {
	struct SoccerTeam {
		SoccerTeam();
		SoccerTeam(const char* tname, double fines, int foul);
		char m_teamName[41];
		int m_noFouls;
		double m_fines;
		int m_goals;
		void setTeam(const SoccerTeam& team);
		void setName(const char* tname);
		void setFine(double fines, int foul);
		void setEmpty();
		bool isEmpty() const;
		void calFines();
		int fouls() const;
		std::ostream& display()const;
	};


}







#endif 