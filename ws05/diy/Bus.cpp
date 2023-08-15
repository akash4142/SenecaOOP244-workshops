/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#include <iomanip>
#include "Bus.h"

using namespace std;

namespace sdds {
	Bus::Bus() {
		num_of_seats = 20;
		num_of_passengers = 0;
		not_service = false;
	}

	Bus::Bus(int num) {
		num_of_passengers = -1;
		num_of_seats = -1;
		not_service = true;
	}

	Bus::Bus(int seats, int passengers) {
		if (!validate(seats, passengers)) {
			num_of_passengers = -1;
			num_of_seats = -1;
			not_service = true;
			return;
		}

		num_of_seats = seats;
		num_of_passengers = passengers;
		not_service = false;
	}

	bool Bus::validate(int seats, int passengers) {
		if (seats % 2 != 0) {
			return false;
		}
		if (seats > 40 || seats < 10) {
			return false;
		}

		if (passengers > seats || passengers < 0) {
			return false;
		}
		return true;
	}


	Bus::operator bool () const {
		return !not_service;
	}
	Bus::operator int() const {
		return num_of_passengers;
	}

	Bus::operator double() const {
		return not_service ? -1.0 : num_of_passengers * bus_ticket;
	}

	bool Bus::operator--() {
		if (not_service || num_of_passengers == 0) {
			return false;
		}
		num_of_passengers--;
		return true;
	}

	bool Bus::operator--(int) {
		return -- * this;
	}

	bool Bus::operator++() {
		if (not_service || num_of_passengers == num_of_seats) {
			return false;
		}
		num_of_passengers++;
		return true;
	}

	bool Bus::operator++(int) {
		return ++ * this;
	}

	Bus& Bus::operator=(int value) {
		if (!validate(num_of_seats, value)) {
			num_of_seats = -1;
			num_of_passengers = -1;
			not_service = true;
			return *this;
		}
		num_of_passengers = value;
		return *this;
	}

	Bus& Bus::operator+=(int value) {
		if (!validate(num_of_seats, num_of_passengers + value)) {
			num_of_seats = -1;
			num_of_passengers = -1;
			not_service = true;
			return *this;
		}
		num_of_passengers += value;
		return *this;
	}

	Bus& Bus::operator+=(Bus& right) {
		if (not_service || right.not_service) {
			return *this;
		}
		if (num_of_passengers + right.num_of_passengers > num_of_seats) {
			right.num_of_passengers = num_of_passengers + right.num_of_passengers - num_of_seats;
			num_of_passengers = num_of_seats;
		}
		else {  
			num_of_passengers = num_of_passengers + right.num_of_passengers;
			right.num_of_passengers = 0;
		}
		return *this;
	}

	bool Bus::operator==(const Bus& right) {
		if (not_service || right.not_service) {
			return false;
		}
		return num_of_passengers == right.num_of_passengers;
	}

	int operator+(int number, const Bus& right) {
		return right.not_service ? number : right.num_of_passengers + number;
	}

	ostream& operator<<(ostream& ostr, const Bus& right) {
		if (right.not_service) {
			ostr << "Out of service!" << endl;
			return ostr;
		}

	int i, p;
		ostr.fill('_');
		ostr.width((right.num_of_seats / 2) * 3 + 4);
		ostr << "_";
		ostr << endl << "| ";
		for (i = 0, p = -1; i < (right.num_of_seats / 2); i++, ostr << "[" << ((p += 2) < right.num_of_passengers ? '2' : ((p == right.num_of_passengers) ? '1' : ' ')) << "]");
		ostr << "|_\\_" << endl;
		ostr << "| ";
		ostr.fill(' ');
		ostr.width(((right.num_of_seats / 2) * 3 - 14) / 2);
		ostr << " " << "Seneca College";
		ostr.width(((right.num_of_seats / 2) * 3 - 14) / 2 + (right.num_of_seats % 4 != 0));
		ostr << " " << "    )" << endl;
		ostr << "`---OO";
		ostr.fill('-');
		ostr.width((right.num_of_seats / 2) * 3 - 5);
		ostr << "-" << "O---'" << endl;

		ostr << "Total Fare Price: " << fixed << setprecision(2) << right.num_of_passengers * bus_ticket << endl;

		return ostr;
	}

	istream& operator>>(istream& in, Bus& right) {
		int seats, passengers;
		in >> seats;
		in.ignore(1);
		in >> passengers;

		if (!right.validate(seats, passengers)) {
			right.num_of_seats = -1;
			right.num_of_passengers = -1;
			right.not_service = true;
			return in;
		}

		right.num_of_seats = seats;
		right.num_of_passengers = passengers;
		right.not_service = false;
		return in;
	}

}
	
