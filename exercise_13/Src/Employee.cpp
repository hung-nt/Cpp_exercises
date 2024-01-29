#include "../include/Employee.h"
#include <iostream>
#include <algorithm>

int Employee::employeeCount = 0;

Employee::Employee() {
    employeeCount++;
}

Employee::Employee(std::string id, std::string fullName, std::string birthday,
         std::string phone, std::string email, const std::vector<Certificate>& certificates, int employeeType)
    : id(id), fullName(fullName), birthday(birthday), phone(phone), email(email),
      certificates(certificates), employeeType(employeeType) {
    employeeCount++;
}

void Employee::showInformation() const {
    std::cout << "Employee Information:\n";
    std::cout << "ID: " << getId() << "\n";
    std::cout << "Name: " << getFullName() << "\n";
    std::cout << "Birthday: " << getBirthday() << "\n";
    std::cout << "Phone: " << getPhone() << "\n";
    std::cout << "Email: " << getEmail() << "\n";
    std::cout << "Employee Type: " << getEmployeeTypeString() << "\n";

    for (const auto& certificate : certificates) {
        std::cout << "Certificate ID: " << certificate.getId() << "\n";
        std::cout << "Certificate Name: " << certificate.getName() << "\n";
        std::cout << "Certificate Rank: " << certificate.getRank() << "\n";
        std::cout << "Certificate Date: " << std::chrono::system_clock::to_time_t(certificate.getDate()) << "\n";
    }
}

std::string Employee::getId() const {
    return id;
}

std::string Employee::getBirthday() const {
    return birthday;
}

std::string Employee::getPhone() const {
    return phone;
}

std::string Employee::getEmail() const {
    return email;
}

std::string Employee::getFullName() const {
    return fullName;
}

int Employee::getEmployeeType() const {
    return employeeType;
}

std::string Employee::getEmployeeTypeString() const {
    switch (employeeType) {
        case 0:
            return "Experience";
        case 1:
            return "Fresher";
        case 2:
            return "Intern";
        default:
            return "Unknown";
    }
}

int Employee::getEmployeeCount() {
    return employeeCount;
}