#include <iostream>
#include <vector>
#include "../Include/HRManagementSystem.h"
#include "../Include/Exception.h"
using namespace std;

HRManagementSystem::~HRManagementSystem()
{
    for (auto employee : employees)
    {
        delete employee;
    }
}

bool HRManagementSystem::is_valid_number(const string &number)
{
    static const std::string AllowedChars = "0123456789";
    for (char numberChar : number)
    {
        bool isDigit = false;
        for (char allowedChar : AllowedChars)
        {
            if (numberChar == allowedChar)
            {
                isDigit = true;
                break;
            }
        }
        if (!isDigit)
        {
            return false;
        }
    }
    return true;
}
bool HRManagementSystem::is_valid_email(const std::string &email)
{
    if (!((email[0] >= 'a' && email[0] <= 'z') || (email[0] >= 'A' && email[0] <= 'Z')))
    {
        return false;
    }

    int atCount = 0;
    int dotCount = 0;
    for (char ch : email)
    {
        if (ch == '@')
        {
            atCount++;
        }
        else if (ch == '.')
        {
            dotCount++;
        }
    }

    if (atCount != 1 || dotCount != 1 || email.find('@') > email.find('.'))
    {
        return false;
    }

    return true;
}

bool HRManagementSystem::is_valid_birthday(const std::string &birthday)
{
    return (birthday.length() == 10);
}
void HRManagementSystem::validateEmployeeData(const Employee *employee) const
{
    validateFullName(employee->getFullName());
    validateBirthday(employee->getBirthday());
    validatePhone(employee->getPhone());
    validateEmail(employee->getEmail());
}

void HRManagementSystem::validateFullName(const std::string &fullName) const
{
    if (fullName.empty())
    {
        throw NameException();
    }
}

void HRManagementSystem::validateBirthday(const std::string &birthday) const
{

    if (!is_valid_birthday(birthday))
    {
        throw BirthdayException("Invalid birthday format or range.");
    }
}

void HRManagementSystem::validatePhone(const std::string &phone) const
{

    if (!is_valid_number(phone))
    {
        throw PhoneException("Invalid phone number format.");
    }
}

void HRManagementSystem::validateEmail(const std::string &email) const
{

    if (!is_valid_email(email))
    {
        throw EmailException("Invalid email format or domain.");
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

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (choice)
            {
            case 1:
            {
                std::string newName;
                std::cout << "Enter new Full Name: ";
                std::getline(std::cin, newName);
                validateFullName(newName);
                (*it)->setFullName(newName);
                break;
            }
            case 2:
            {
                std::string newBirthday;
                std::cout << "Enter new Birthday (YYYY-MM-DD): ";
                std::getline(std::cin, newBirthday);
                validateBirthday(newBirthday);
                (*it)->setBirthday(newBirthday);
                break;
            }
            case 3:
            {
                std::string newPhone;
                std::cout << "Enter new Phone: ";
                std::getline(std::cin, newPhone);
                validatePhone(newPhone);
                (*it)->setPhone(newPhone);
                break;
            }
            case 4:
            {
                std::string newEmail;
                std::cout << "Enter new Email: ";
                std::getline(std::cin, newEmail);
                validateEmail(newEmail);
                (*it)->setEmail(newEmail);
                break;
            }
            case 5:
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

const std::vector<Employee *> &HRManagementSystem::getEmployees() const
{
    return employees;
}