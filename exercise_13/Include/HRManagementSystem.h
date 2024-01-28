#ifndef HRMANAGEMENTSYSTEM_H
#define HRMANAGEMENTSYSTEM_H

#include <vector>
#include <algorithm>
#include "Employee.h"

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
};

#endif // HRMANAGEMENTSYSTEM_H
