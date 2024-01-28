#include "../include/Experience.h"
#include <iostream>

Experience::Experience() {}

Experience::Experience(std::string id, std::string fullName, std::chrono::system_clock::time_point birthday,
           std::string phone, std::string email, const std::vector<Certificate>& certificates,
           int yearOfExperience, std::string proSkill)
    : Employee(id, fullName, birthday, phone, email, certificates, 0),
      yearOfExperience(yearOfExperience), proSkill(proSkill) {}

void Experience::showInformation() const {
    Employee::showInformation();
    std::cout << "Years of Experience: " << yearOfExperience << "\n";
    std::cout << "Professional Skill: " << proSkill << "\n";
}
