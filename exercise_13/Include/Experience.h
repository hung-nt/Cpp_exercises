#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include "Employee.h"

class Experience : public Employee {
private:
    int yearOfExperience;
    std::string proSkill;

public:
    Experience();
    Experience(std::string id, std::string fullName, std::string birthday,
               std::string phone, std::string email, const std::vector<Certificate>& certificates,
               int yearOfExperience, std::string proSkill);

    void showInformation() const override;
};

#endif // EXPERIENCE_H
