#ifndef FRESHER_H
#define FRESHER_H

#include "Employee.h"

class Fresher : public Employee {
private:
    std::string graduationDate;
    std::string graduationRank;
    std::string universityName;

public:
    Fresher();
    Fresher(std::string id, std::string fullName, std::string birthday,
            std::string phone, std::string email, const std::vector<Certificate>& certificates,
            std::string graduationDate,
            std::string graduationRank, std::string universityName);

    void showInformation() const override;
};

#endif // FRESHER_H