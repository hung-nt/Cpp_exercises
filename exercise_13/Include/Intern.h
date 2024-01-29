#ifndef INTERN_H
#define INTERN_H

#include "Employee.h"

class Intern : public Employee {
private:
    std::string major;
    int semester;
    std::string universityName;

public:
    Intern();
    Intern(std::string id, std::string fullName, std::string birthday,
           std::string phone, std::string email, const std::vector<Certificate>& certificates,
           std::string major, int semester, std::string universityName);

    void showInformation() const override;
};

#endif // INTERN_H
