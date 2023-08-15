
/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#ifndef SDDS_TOURNAMENT_H
#define SDDS_TOURNAMENT_H
#include "Soccer.h" 
#include <ostream>
namespace sdds {
	class Tournament {
		char* m_name;
		int m_num;
		SoccerTeam* m_soccer = nullptr;
	public:
		Tournament();
		Tournament(const char* name, int noOfteam, const SoccerTeam* soccer);
		~Tournament();
		void setTournament(const char* name, int noOfteam, const SoccerTeam* soccer);
		void setEmpty();
		bool isEmpty() const;
		Tournament& match(const SoccerTeam* ls);
		std::ostream& display() const;
	};

}

#endif 