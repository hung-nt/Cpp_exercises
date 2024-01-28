#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <vector>
#include <string>
#include "Certificate.h"

class Employee {
protected:
    std::string id;
    std::string fullName;
    std::chrono::system_clock::time_point birthday;
    std::string phone;
    std::string email;
    std::vector<Certificate> certificates;
    int employeeType; 
    static int employeeCount; 

public:
    Employee();
    Employee(std::string id, std::string fullName, std::chrono::system_clock::time_point birthday,
             std::string phone, std::string email, const std::vector<Certificate>& certificates, int employeeType);
    virtual void showInformation() const;

    std::string getId() const;
    std::chrono::system_clock::time_point getBirthday() const;
    std::string getPhone() const;
    std::string getEmail() const;
    std::string getFullName() const;
    int getEmployeeType() const;
    std::string getEmployeeTypeString() const;
    static int getEmployeeCount();
};

#endif // EMPLOYEE_H
