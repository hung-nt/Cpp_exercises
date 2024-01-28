#include "../include/HRManagementSystem.h"
#include <iostream>

HRManagementSystem::~HRManagementSystem() {
    for (auto employee : employees) {
        delete employee;
    }
}

void HRManagementSystem::addEmployee(Employee* employee) {
    employees.push_back(employee);
    std::cout << "Employee added successfully.\n";
}

void HRManagementSystem::editEmployee(const std::string& id) {
    auto it = std::find_if(employees.begin(), employees.end(), [id](const Employee* emp) {
        return emp->getId() == id;
    });

    if (it != employees.end()) {
        (*it)->showInformation();
        std::cout << "Employee information updated successfully.\n";
    } else {
        std::cout << "Employee with ID " << id << " not found.\n";
    }
}

void HRManagementSystem::removeEmployee(const std::string& id) {
    auto it = std::remove_if(employees.begin(), employees.end(), [id](const Employee* emp) {
        return emp->getId() == id;
    });

    if (it != employees.end()) {
        delete *it;
        employees.erase(it, employees.end());
        std::cout << "Employee with ID " << id << " removed successfully.\n";
    } else {
        std::cout << "Employee with ID " << id << " not found.\n";
    }
}

void HRManagementSystem::displayAllEmployees() const {
    for (const auto& employee : employees) {
        employee->showInformation();
        std::cout << "---------------------\n";
    }
}

void HRManagementSystem::displayAllInterns() const {
    for (const auto& employee : employees) {
        if (employee->getEmployeeType() == 2) {
            employee->showInformation();
            std::cout << "---------------------\n";
        }
    }
}

void HRManagementSystem::displayAllExperiences() const {
    for (const auto& employee : employees) {
        if (employee->getEmployeeType() == 0) {
            employee->showInformation();
            std::cout << "---------------------\n";
        }
    }
}

void HRManagementSystem::displayAllFreshers() const {
    for (const auto& employee : employees) {
        if (employee->getEmployeeType() == 1) {
            employee->showInformation();
            std::cout << "---------------------\n";
        }
    }
}