#include "../Include/HRManagementSystem.h"
#include <iostream>
#include <vector>
using namespace std;

HRManagementSystem::~HRManagementSystem()
{
    for (auto employee : employees)
    {
        delete employee;
    }
}

void HRManagementSystem::addEmployee(Employee *employee)
{
    employees.push_back(employee);
    std::cout << "Employee added successfully.\n";
}

void HRManagementSystem::editEmployee(const std::string &id)
{
    auto it = std::find_if(employees.begin(), employees.end(), [id](const Employee *emp)
                           { return emp->getId() == id; });

    if (it != employees.end())
    {
        int choice;

        do
        {
            std::cout << "\nEdit Employee Information:\n";
            std::cout << "1. Edit Full Name\n";
            std::cout << "2. Edit Birthday\n";
            std::cout << "3. Edit Phone\n";
            std::cout << "4. Edit Email\n";
            std::cout << "5. Return to Main Menu\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

            switch (choice)
            {
            case 1:
            {
                // Edit Full Name
                std::string newName;
                std::cout << "Enter new Full Name: ";
                std::getline(std::cin, newName);
                (*it)->setFullName(newName);
                break;
            }
            case 2:
            {
                // Edit Birthday
                std::string newBirthday;
                std::cout << "Enter new Birthday (YYYY-MM-DD): ";
                std::getline(std::cin, newBirthday);
                (*it)->setBirthday(newBirthday);
                break;
            }
            case 3:
            {
                // Edit Phone
                std::string newPhone;
                std::cout << "Enter new Phone: ";
                std::getline(std::cin, newPhone);
                (*it)->setPhone(newPhone);
                break;
            }
            case 4:
            {
                // Edit Email
                std::string newEmail;
                std::cout << "Enter new Email: ";
                std::getline(std::cin, newEmail);
                (*it)->setEmail(newEmail);
                break;
            }
            case 5:
                // Return to Main Menu
                std::cout << "Returning to Main Menu.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
            }

        } while (choice != 5);

        std::cout << "Employee information updated successfully.\n";
    }
    else
    {
        std::cout << "Employee with ID " << id << " not found.\n";
    }
}


void HRManagementSystem::removeEmployee(const std::string &id)
{
    auto it = std::remove_if(employees.begin(), employees.end(), [id](const Employee *emp)
                             { return emp->getId() == id; });

    if (it != employees.end())
    {
        delete *it;
        employees.erase(it, employees.end());
        std::cout << "Employee with ID " << id << " removed successfully.\n";
    }
    else
    {
        std::cout << "Employee with ID " << id << " not found.\n";
    }
}

void HRManagementSystem::displayAllEmployees() const
{
    for (const auto &employee : employees)
    {
        employee->showInformation();
        std::cout << "---------------------\n";
    }
}

void HRManagementSystem::displayAllInterns() const
{
    for (const auto &employee : employees)
    {
        if (employee->getEmployeeType() == 2)
        {
            employee->showInformation();
            std::cout << "---------------------\n";
        }
    }
}

void HRManagementSystem::displayAllExperiences() const
{
    for (const auto &employee : employees)
    {
        if (employee->getEmployeeType() == 0)
        {
            employee->showInformation();
            std::cout << "---------------------\n";
        }
    }
}

void HRManagementSystem::displayAllFreshers() const
{
    for (const auto &employee : employees)
    {
        if (employee->getEmployeeType() == 1)
        {
            employee->showInformation();
            std::cout << "---------------------\n";
        }
    }
}

const std::vector<Employee*>& HRManagementSystem::getEmployees() const {
    return employees;
}