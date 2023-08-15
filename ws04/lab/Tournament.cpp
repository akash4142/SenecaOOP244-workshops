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
#include <iomanip>
#include "Tournament.h"
#include <cstring>
using namespace std;
namespace sdds {
	Tournament::Tournament() {
		m_name = nullptr;
		m_num = 0;
	}

	Tournament::Tournament(const char* name, int noOfteam, const SoccerTeam* soccer) {
		setTournament(name, noOfteam, soccer);
	}

	Tournament::~Tournament() {
		delete[] m_name;
		delete[] m_soccer;


	}


	void Tournament::setTournament(const char* name, int noOfteam, const SoccerTeam* soccer) {
		if (name == nullptr || noOfteam <= 0 || soccer == nullptr)
		{
			setEmpty();
			return;
		}
		m_num = noOfteam;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
		m_soccer = new SoccerTeam[m_num];
		for (int i = 0; i < m_num; i++) {
			m_soccer[i] = soccer[i];

		}
	}
	void Tournament::setEmpty() {
		m_name = nullptr;
		m_num = 0;
		m_soccer = nullptr;

	}
	bool Tournament::isEmpty() const {
		return m_name == nullptr && m_soccer == nullptr && m_num == 0;
	}
	Tournament& Tournament::match(const SoccerTeam* ls) {
		for (int i = 0; i < 1; i++) {
			if (m_soccer[i].fouls() < m_soccer[i + 1].fouls()) {
				m_soccer[i + 1].m_noFouls *= 2;
				m_soccer[i + 1].calFines();
				m_soccer[i].m_goals++;
				if (m_soccer[i + 1].m_noFouls > MAX_FOUL) {
					m_soccer[i + 1].m_noFouls = -1;

				}
			}
		}
		return *this;
	}



	ostream& Tournament::display() const {
		if (isEmpty())
		{
			cout << "Invalid Tournament";
			return cout;
		}

		cout << "Tournament name: " << m_name << endl;
		cout << "list of the teams" << endl;
		cout << setw(45) << "Fines" << setw(10) << "Fouls" << setw(10) << "Goals" << endl;
		for (int i = 0; i < m_num; i++)
		{
			cout << "Team[" << i + 1 << "] :";
			m_soccer[i].display();
		}

		return std::cout;

	}


};
