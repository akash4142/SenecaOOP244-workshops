/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>
#include "Numbers.h"

using namespace std;

namespace sdds {
	Numbers::Numbers() {
		this->setEmpty();
	}
	Numbers::Numbers(const char filename[]) {
		this->setEmpty();
		if (filename != nullptr && filename[0] != '\0' && strlen(filename) <= MAX_FNAME_SIZE) {
			strncpy(fileName, filename, strlen(filename));
			load();
		}
	}

	
	Numbers::Numbers(const Numbers& right) {
		if (right) {
			this->setEmpty();
			*this = right;
		}
	}

	void Numbers::setEmpty() {
		Collection = nullptr;
		fileName[0] = '\0';
		total_collection = 0;
		flag = false;
		Flag2 = false;
	}

	bool Numbers::isEmpty() const {
		return  total_collection == 0;
	}

	void Numbers::sort(double* num, unsigned int sz) {
		unsigned int i, a;
		double temp;
		for (i = sz - 1; sz && i > 0; i--) {
			for (a = 0; a < i; a++) {
				if (num[a] > num[a + 1]) {
					temp = num[a];
					num[a] = num[a + 1];
					num[a + 1] = temp;
				}
			}
		}
	}

	unsigned int Numbers::countLines(const char* filename) { 
		unsigned int lines = 0u;
		ifstream nums(filename);
		while (nums) {
			lines += (nums.get() == '\n');
		}
		return lines;
	}

	bool Numbers::load() {
		unsigned int size = countLines(fileName);
		unsigned int count = 0;
		if (size > 0) {
			delete[] Collection;
			Collection = new double[size];   //memory alloaction for the collection 
			ifstream fileStream(fileName);  //creating the file pointer
			if (fileStream.is_open()) {     
				string str;

				while (getline(fileStream, str)) {
					if (str != "") {
						Collection[count++] = stod(str);
					}
				}
				fileStream.close();
				if (size != count) {
					delete[] Collection;
					Collection = nullptr;
					count = 0;
				}
				else {
					flag = true;
					total_collection = size;
				}
			}
		}
		return count > 0;
	}

	Numbers& Numbers::save() {
		if (flag && Flag2) {
			ofstream outputStream(fileName);
			for (unsigned int i = 0; i < total_collection; i++) {
				outputStream << fixed << setprecision(2) << Collection[i] << endl;
			}
			outputStream.close();
		}
		return *this;
	}

	double Numbers::max() const {
		unsigned int i;
		double MAX_value = -99999;
		for (i = 0; i < total_collection; i++) {
			if (Collection[i] > MAX_value)
			{
				MAX_value = Collection[i];
			}
		}
		return MAX_value;
	}

	double Numbers::min() const {
		unsigned int i;
		double MIN_value = 99999;
		for (i = 0; i < total_collection; i++) {
			if (Collection[i] < MIN_value) {
				MIN_value = Collection[i];
			}
		}
		return MIN_value;
	}
	double Numbers::average() const {
		unsigned int i;
		double sum = 0;
		double average = 0;
		for (i = 0; i < total_collection; i++) {
			sum += Collection[i];
		}
		if (total_collection > 0) {
			average = sum / total_collection;
		}
		return average;
	}

	Numbers& Numbers::operator = (const Numbers& right) {
		if (this != &right) {
			save();
			if (Collection != nullptr) {
				delete[] Collection;
			}

			this->setEmpty();

			if (right.total_collection > 0) {
				total_collection = right.total_collection;
				flag = false;
				Collection = new double[right.total_collection];
				for (unsigned int i = 0; i < total_collection; i++) {
					Collection[i] = right.Collection[i];
				}
				strcpy(fileName, right.fileName);
			}
		}
		return *this;
	}
	Numbers::operator bool() const {
		if (this->total_collection > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void Numbers::sort() {
		sort(Collection, total_collection);
	}

	Numbers& Numbers::operator+=(double value) {
		if (total_collection > 0) {
			double* tempCollection;
			unsigned int i;
			tempCollection = new double[total_collection + 1];

			for (i = 0; i < total_collection; i++) {
				tempCollection[i] = Collection[i];
			}
			tempCollection[i] = value;
			total_collection++;
			Flag2 = true;

			delete[] Collection;
			Collection = tempCollection;
		}
		return *this;
	}

	ostream& Numbers::display(ostream& ostr = cout) const {
		if (this->isEmpty()) {
			ostr << "Empty list";
		}
		else {
			if (!flag) {
				ostr << "Copy of ";
			}
			ostr << fileName << endl;
			for (unsigned int i = 0; i < total_collection; i++) {
				ostr << fixed << setprecision(2) << Collection[i];
				if (i != total_collection - 1) {
					ostr << ", ";
				}
			}
			ostr << endl;
			ostr << setw(76) << setfill('-') << '-' << endl;
			ostr << "Total of " << total_collection << " number(s), Largest: " << this->max() << ", Smallest: " << this->min() << ", Average: " << this->average() << endl;
			ostr << setw(76) << setfill('=') << '=';
		}
		return ostr;
	}
	Numbers::~Numbers() {
		save();
		delete[] Collection;
	}

	ostream& operator<<(ostream& ostr, const Numbers& right) {
		right.display(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, Numbers& right) {
		string str;
		getline(istr, str);
		if (str != "") {
			right += stod(str);
		}
		return istr;
	}

}
