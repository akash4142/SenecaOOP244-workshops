/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


/*student name - akash yadav
student id - 172566218
email- ayadav35@myseneca.ca
date- 1/feb/2023
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {


    //fully provided for students to display details of a project
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //fully provided for students to display details of a department
    void display(const Department& department) {
            Project* temp = department.fetchProjects();
            int projects = department.fetchNumProjects();
            cout << "Department " << department.fetchName() << " details:" << endl;
            cout << "Budget: " << department.fetchBudget()
                << " and the number of projects in progress is: " << projects << endl;
            cout << "Below are the details of the projects we are currently working on: " << endl;
            for (int i = 0; i < projects; i++) {
                display(temp[i]);
            }
    }

    void Department::updateName(const char* newname) {
        
        if (newname != nullptr && strlen(newname) > 0) {
            if (Department_name != nullptr) {
                delete[] Department_name;
            }
            int length = strlen(newname);
            Department_name = new char[length + 1];
            strcpy(Department_name, newname);
        }
    }

    void Department::updateBudget(double change) {
        budget += change;
    }

    bool Department::addProject(Project& newproject) {
        double totalCost = totalexpenses() + newproject.m_cost;
        if (totalCost > budget) {
            return false;
        }
        else {
            Project* temp = nullptr;
            if (num_of_current_projects == 0) {
                projects = new Project[1];
                projects[0] = newproject;
            }
            else {
                temp = new Project[num_of_current_projects + 1];
                for (int i = 0; i < num_of_current_projects; i++) {
                    temp[i] = projects[i];
                }
                temp[num_of_current_projects] = newproject;
                delete[] projects;
                projects = new Project[num_of_current_projects + 1];
                for (int i = 0; i <= num_of_current_projects; i++) {
                    projects[i] = temp[i];
                }
                delete[] temp;
            }
            num_of_current_projects++;
            return true;
        }
    }

    void Department::createDepartment(const char* newname,
        Project& newproject,
        double change) {
        updateName(newname);
        addProject(newproject);
        updateBudget(change);
    }

    Project* Department::fetchProjects() const {
        return projects;

    }

    int Department::fetchNumProjects() const {
        return num_of_current_projects;
    }

    double Department::fetchBudget() const {
        return budget;
    }

    char* Department::fetchName() const {
        return Department_name;
    }
    double Department::totalexpenses() {
        double total = 0;
        for (int i = 0; i < num_of_current_projects; i++) {
            total += projects[i].m_cost;
        }
        return total;
    }
    double Department::remainingBudget() {
        return (budget - totalexpenses());
    }
    void Department::clearDepartment() {
        delete[] Department_name;
        delete[] projects;
    }

}