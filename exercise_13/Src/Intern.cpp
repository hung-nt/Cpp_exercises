#include "../include/Intern.h"
#include <iostream>

Intern::Intern() {}

Intern::Intern(std::string id, std::string fullName, std::string birthday,
       std::string phone, std::string email, const std::vector<Certificate>& certificates,
       std::string major, int semester, std::string universityName)
    : Employee(id, fullName, birthday, phone, email, certificates, 2),
      major(major), semester(semester), universityName(universityName) {}

void Intern::showInformation() const {
    Employee::showInformation();
    std::cout << "Major: " << major << "\n";
    std::cout << "Semester: " << semester << "\n";
    std::cout << "University Name: " << universityName << "\n";
}