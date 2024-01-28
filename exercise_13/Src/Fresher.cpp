#include "../include/Fresher.h"
#include <iostream>

Fresher::Fresher() {}

Fresher::Fresher(std::string id, std::string fullName, std::chrono::system_clock::time_point birthday,
        std::string phone, std::string email, const std::vector<Certificate>& certificates,
        std::chrono::system_clock::time_point graduationDate,
        std::string graduationRank, std::string universityName)
    : Employee(id, fullName, birthday, phone, email, certificates, 1),
      graduationDate(graduationDate), graduationRank(graduationRank), universityName(universityName) {}

void Fresher::showInformation() const {
    Employee::showInformation();
    std::cout << "Graduation Date: " << std::chrono::system_clock::to_time_t(graduationDate) << "\n";
    std::cout << "Graduation Rank: " << graduationRank << "\n";
    std::cout << "University Name: " << universityName << "\n";
}