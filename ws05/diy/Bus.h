/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#include <iostream>
#include <ostream>

#ifndef SDDS_BUS_H
#define SDDS_BUS_H
using namespace std;
namespace sdds {
	const double bus_ticket = 125.34;

	class Bus {
		int num_of_seats;
		int num_of_passengers;
		bool not_service;
		bool validate(int seats, int noOfPassengers);
	public:
		Bus();
		Bus(int num);
		Bus(int seats, int passengers);


		operator bool() const;
		operator int() const;
		operator double() const;

		bool operator++ ();
		bool operator-- ();
		bool operator++ (int);
		bool operator-- (int);

		Bus& operator=(int value);
		Bus& operator+= (int value);
		Bus& operator+=(Bus& right);


		bool operator == (const Bus& right);

		friend int operator+(int left, const Bus& right);
		friend istream& operator>>(istream& in, Bus& right);
		friend ostream& operator<<(ostream& os, const Bus& right);
	};
};
#endif 