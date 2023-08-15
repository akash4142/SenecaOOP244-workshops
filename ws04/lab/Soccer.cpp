/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ostream>
#include <cstring>
#include <iomanip>
#include "Soccer.h"
#include "Tournament.h"
using namespace std;
namespace sdds {
	SoccerTeam::SoccerTeam() {
		setEmpty();
	}
	SoccerTeam::SoccerTeam(const char* tname, double fines, int foul) {
		setName(tname);
		setFine(fines, foul);
		m_goals = 0;
	}

	void SoccerTeam::setTeam(const SoccerTeam& team) {
		setName(team.m_teamName);
		setFine(team.m_fines, team.m_noFouls);

	}
	void SoccerTeam::setName(const char* tname) {
		if (tname != nullptr && tname[0] != '\0') {
			strcpy(m_teamName, tname);
		}
		else {
			setEmpty();
		}
	}
	void SoccerTeam::setFine(double fines, int foul) {
		if (fines >= 0 && foul >= 0) {
			m_fines = fines;
			m_noFouls = foul;

		}
		else {
			setEmpty();
		}
	}
	void SoccerTeam::setEmpty() {
		m_teamName[0] = '\0';
		m_noFouls = -1;
		m_fines = -1;
		m_goals = 0;
	}
	bool SoccerTeam::isEmpty() const {
		return (m_teamName[0] == '\0' || m_fines < 0 || m_noFouls < 0);
	}
	void SoccerTeam::calFines() {
		m_fines *= 1.2;
	}
	int SoccerTeam::fouls() const {
		return m_noFouls;
	}
	ostream& SoccerTeam::display()const {
		if (!isEmpty()) {
			cout << left << setw(30) << m_teamName << "" << right << fixed << setprecision(2) << setw(6) << m_fines << "" << right << setw(6) << m_noFouls << "" << right << setw(10) << m_goals << (m_goals > 0 ? "w" : " ") << endl;
			return cout;
		}
		else {
			cout << "Invalid Team";
			return cout;
		}
	}


}