/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


/*student name - akash yadav
student id - 172566218
email- ayadav35@myseneca.ca
date- 30/jan/2023
*/
#ifndef SDDS_CUSTOMER_H_
#define SDDS_CUSTOMER_H_

namespace sdds {

    struct Customers {
        char user_name[21];
        int retweets_count;;
        int likes_count;
        int replies_count;
        char share_videos;
    };

    struct CustomersRecord {
        Customers* ptr_rec;  // Dynamically holds the customers' tweets' report.
        int noOfRecords;
    };
    void EmptyRecord(Customers &customer);
    void EmptyRecord(CustomersRecord &customer);
       
    void read(char* str, int len);
   
    // to be completed
    bool read(Customers& rec);
    void read(char* str, int len);
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec);
    void display(const Customers& c_rec);
    void display(const CustomersRecord& t_rec);
}
#endif 
