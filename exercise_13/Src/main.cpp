#include <iostream>
#include "../Include/HRManagementSystem.h"
#include "../Include/Experience.h"
#include "../Include/Intern.h"
#include "../Include/Fresher.h"
using namespace std;

int main()
{
    HRManagementSystem hrSystem;
    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add Employee\n";
        cout << "2. Edit Employee\n";
        cout << "3. Remove Employee\n";
        cout << "4. Display All Employees\n";
        cout << "5. Display All Interns\n";
        cout << "6. Display All Experiences\n";
        cout << "7. Display All Freshers\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
        {
            string id, fullName, birthdayStr, phone, email;
            int employeeType;

            cout << "Enter Employee ID: ";
            getline(cin, id);

            cout << "Enter Full Name: ";
            getline(cin, fullName);
            try
            {
                hrSystem.validateFullName(fullName);
            }
            catch (const std::exception &ex)
            {
                cout << "Error: " << ex.what() << endl;
                continue;
            }
            

            cout << "Enter Birthday (YYYY-MM-DD): ";
            getline(cin, birthdayStr);
            try
            {
                hrSystem.validateBirthday(birthdayStr);
            }
            catch (const std::exception &ex)
            {
                cout << "Error: " << ex.what() << endl;
                continue;
            }

            cout << "Enter Phone: ";
            getline(cin, phone);
            try
            {
                hrSystem.validatePhone(phone);
            }
            catch (const std::exception &ex)
            {
                cout << "Error: " << ex.what() << endl;
                continue;
            }

            cout << "Enter Email: ";
            getline(cin, email);
            try
            {
                hrSystem.validateEmail(email);
            }
            catch (const std::exception &ex)
            {
                cout << "Error: " << ex.what() << endl;
                continue;
            }

            cout << "Enter Employee Type (0: Experience, 1: Fresher, 2: Intern): ";
            cin >> employeeType;
            while (employeeType < 0 || employeeType > 2)
            {
                cout << "Invalid employee type. Please enter again (0, 1, 2): ";
                cin >> employeeType;
            }
            if (employeeType == 0)
            {
                int yearOfExperience;
                string proSkill;

                cout << "Enter Years of Experience: ";
                cin >> yearOfExperience;

                cin.ignore();

                cout << "Enter Professional Skill: ";
                getline(cin, proSkill);

                Employee *expEmployee = new Experience(id, fullName, birthdayStr, phone, email, {}, yearOfExperience, proSkill);

                hrSystem.addEmployee(expEmployee);
            }
            else if (employeeType == 1)
            {
                string graduationDateStr, graduationRank, universityName;

                cout << "Enter Graduation Date (YYYY-MM-DD): ";
                getline(cin, graduationDateStr);
                cin.ignore();

                cout << "Enter Graduation Rank: ";
                getline(cin, graduationRank);
                cin.ignore();

                cout << "Enter University Name: ";
                getline(cin, universityName);

                Employee *fresherEmployee = new Fresher(id, fullName, birthdayStr, phone, email, {}, graduationDateStr, graduationRank, universityName);

                hrSystem.addEmployee(fresherEmployee);
            }
            else if (employeeType == 2)
            {
                string major, universityName;
                int semester;

                cout << "Enter Major: ";
                cin >> major;
                cin.ignore(); 

                cout << "Enter Semester: ";
                cin >> semester;

                cin.ignore(); 

                cout << "Enter University Name: ";
                getline(cin, universityName);

                Employee *internEmployee = new Intern(id, fullName, birthdayStr, phone, email, {}, major, semester, universityName);

                hrSystem.addEmployee(internEmployee);
            }

            cout << "Employee added successfully.\n";
            break;
        }
        case 2:
        {
            string id;
            cout << "Enter Employee ID to edit: ";
            getline(cin, id);
            hrSystem.editEmployee(id);
            break;
        }
        case 3:
        {
            string id;
            cout << "Enter Employee ID to remove: ";
            getline(cin, id);

            auto it = find_if(hrSystem.getEmployees().begin(), hrSystem.getEmployees().end(), [id](const Employee *emp)
                              { return emp->getId() == id; });

            if (it != hrSystem.getEmployees().end())
            {
                (*it)->showInformation();

                char confirmation;
                cout << "Are you sure you want to remove this employee? (Y/N): ";
                cin >> confirmation;

                if (confirmation == 'Y' || confirmation == 'y')
                {
                    // Remove the employee from the HR system
                    hrSystem.removeEmployee(id);
                    cout << "Employee with ID " << id << " removed successfully.\n"
                         << endl;
                }
                else
                {
                    cout << "Removal canceled.\n"
                         << endl;
                }
            }
            else
            {
                cout << "Employee with ID " << id << " not found.\n"
                     << endl;
            }

            break;
        }

        case 4:
            hrSystem.displayAllEmployees();
            break;
        case 5:
            hrSystem.displayAllInterns();
            break;
        case 6:
            hrSystem.displayAllExperiences();
            break;
        case 7:
            hrSystem.displayAllFreshers();
            break;
        case 8:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 8);

    return 0;
}
