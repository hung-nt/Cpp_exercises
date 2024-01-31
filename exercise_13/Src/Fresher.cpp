#include "../Include/Fresher.h"
#include <iostream>

Fresher::Fresher() {}

Fresher::Fresher(std::string id, std::string fullName, std::string birthday,
        std::string phone, std::string email, const std::vector<Certificate>& certificates,
        std::string graduationDate,
        std::string graduationRank, std::string universityName)
    : Employee(id, fullName, birthday, phone, email, certificates, 1),
      graduationDate(graduationDate), graduationRank(graduationRank), universityName(universityName) {}

void Fresher::showInformation() const {
    Employee::showInformation();
    std::cout << "Graduation Date: " << graduationDate << "\n";
    std::cout << "Graduation Rank: " << graduationRank << "\n";
    std::cout << "University Name: " << universityName << "\n";
}