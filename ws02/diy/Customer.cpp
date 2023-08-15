/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


/*student name - akash yadav
student id - 172566218
email- ayadav35@myseneca.ca
date- 30/jan/2023
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"

namespace sdds {
    
    int count = 0;
    // complete
    //this function is putting the values
    void EmptyRecord(Customers &customer) {
        for (int i = 0; i < 21; i++) {//doing the string null
             customer.user_name[i] = '\0';
        }
         customer.likes_count = 0;
         customer.replies_count = 0;
         customer.retweets_count = 0;
         customer.share_videos = '\0';
    }
    //this function is putting the values
    void EmptyRecord(CustomersRecord& customer) {
         customer.ptr_rec = nullptr;
         customer.noOfRecords = 0;
    }
    //taking the user input
    bool read(Customers& rec) {
        bool validate = false;
            cout << " Enter User name: ";
            read(rec.user_name, 21);
            if(rec.user_name[0] == '\0') {
                validate = false;
                             
            }
            else {
                cout << " Enter likes_count: ";
                cin >> rec.likes_count;
                cout << " Enter retweets_count: ";
                cin >> rec.retweets_count;
                cout << " Enter replies_count: ";
                cin >> rec.replies_count;
                cout << " Enter share videos (y/n): ";
                cin >> rec.share_videos;

                validate = true;
                
                
            }
            return validate;
        }
       
    
    
    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }
    //this is putting the data into the dynamic memory
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec) {

        Customers* temp_record = new Customers[t_rec.noOfRecords + 1];

        int j = 0;
        for (j = 0; j < t_rec.noOfRecords; j++) {
            temp_record[j] = t_rec.ptr_rec[j];
        }
        temp_record[t_rec.noOfRecords] = c_rec;


        delete[] t_rec.ptr_rec;

        t_rec.noOfRecords++;
        t_rec.ptr_rec = temp_record;
    }
       
  
    void display(const Customers& c_rec) {
        
        cout << c_rec.user_name << ", " << c_rec.likes_count << ", " << c_rec.retweets_count << ", "<<c_rec.replies_count << ", " << c_rec.share_videos << "\n";
        cout << endl;
    }
    void display(const CustomersRecord& t_rec) {
        for (int i = 0; i < t_rec.noOfRecords; i++) {
            cout << i+1 << ". ";
            display(t_rec.ptr_rec[i]);
          
        }
    }



   

    
    // complete
   

  }

