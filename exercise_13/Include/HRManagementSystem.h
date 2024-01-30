#ifndef HRMANAGEMENTSYSTEM_H
#define HRMANAGEMENTSYSTEM_H

#include <vector>
#include <algorithm>
#include "Employee.h"
using namespace std;

class HRManagementSystem {
private:
    std::vector<Employee*> employees;

public:
    ~HRManagementSystem();

    void addEmployee(Employee* employee);
    void editEmployee(const std::string& id);
    void removeEmployee(const std::string& id);
    void displayAllEmployees() const;
    void displayAllInterns() const;
    void displayAllExperiences() const;
    void displayAllFreshers() const;
    const vector<Employee*>& getEmployees() const;
    void validateEmployeeData (const Employee *employee) const;
    void validateFullName(const string &fullName) const;
    void validateBirthday(const string &birthday) const;
    void validatePhone(const string &phone) const;
    void validateEmail(const string &email)const;
    static bool is_valid_number(const string& number);
    static bool is_valid_email(const string& email);
    static bool is_valid_birthday(const string& birthday);
};

#endif // HRMANAGEMENTSYSTEM_H
