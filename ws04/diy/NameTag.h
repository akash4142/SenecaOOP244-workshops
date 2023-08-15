/*name - akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
section - ncc

citation-: 

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef SDDS_NAMETAG_MODULE
#define SDDS_NAMETAG_MODULE



namespace sdds {
	const int MAX_NAME_LEN = 40;

	class NameTag {
		bool isvalid = false;
		char* name;
		int extension;
	public:
		NameTag();
		NameTag(const char* n);
		NameTag(const char* n, int tag);
		~NameTag();

		void print();
		NameTag& read();
	};
}

#endif // !SDDS_NAMETAG_MODULE
