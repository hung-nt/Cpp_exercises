#include <iostream>
#include "../Include/HRManagementSystem.h"
#include "../include/Experience.h"
#include "../include/Intern.h"
#include "../include/Fresher.h"
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        switch (choice)
        {
        case 1:
        {
            // Add Employee
            string id, fullName, birthdayStr, phone, email;
            int employeeType;

            // Get user input for employee details
            cout << "Enter Employee ID: ";
            getline(cin, id);

            cout << "Enter Full Name: ";
            getline(cin, fullName);

            cout << "Enter Birthday (YYYY-MM-DD): ";
            getline(cin, birthdayStr);

            cout << "Enter Phone: ";
            getline(cin, phone);

            cout << "Enter Email: ";
            getline(cin, email);

            // Get user input for employee type
            cout << "Enter Employee Type (0: Experience, 1: Fresher, 2: Intern): ";
            cin >> employeeType;

            // Validate employee type input
            while (employeeType < 0 || employeeType > 2)
            {
                cout << "Invalid employee type. Please enter again (0, 1, 2): ";
                cin >> employeeType;
            }

            // Create an employee based on the employee type
            if (employeeType == 0)
            {
                // Experience Employee
                int yearOfExperience;
                string proSkill;

                cout << "Enter Years of Experience: ";
                cin >> yearOfExperience;

                cin.ignore(); // Clear newline character from buffer

                cout << "Enter Professional Skill: ";
                getline(cin, proSkill);

                // Create an Experience object
                Employee *expEmployee = new Experience(id, fullName, birthdayStr, phone, email, {}, yearOfExperience, proSkill);

                // Add the created employee to the HR system
                hrSystem.addEmployee(expEmployee);
            }
            else if (employeeType == 1)
            {
                // Fresher Employee
                string graduationDateStr, graduationRank, universityName;

                cout << "Enter Graduation Date (YYYY-MM-DD): ";
                getline(cin, graduationDateStr);

                cout << "Enter Graduation Rank: ";
                getline(cin, graduationRank);

                cout << "Enter University Name: ";
                getline(cin, universityName);

                // Create a Fresher object
                Employee *fresherEmployee = new Fresher(id, fullName, birthdayStr, phone, email, {}, graduationDateStr, graduationRank, universityName);

                // Add the created employee to the HR system
                hrSystem.addEmployee(fresherEmployee);
            }
            else if (employeeType == 2)
            {
                // Intern Employee
                string major, universityName;
                int semester;

                cout << "Enter Major: ";
                getline(cin, major);

                cout << "Enter Semester: ";
                cin >> semester;

                cin.ignore(); // Clear newline character from buffer

                cout << "Enter University Name: ";
                getline(cin, universityName);

                // Create an Intern object
                Employee *internEmployee = new Intern(id, fullName, birthdayStr, phone, email, {}, major, semester, universityName);

                // Add the created employee to the HR system
                hrSystem.addEmployee(internEmployee);
            }

            cout << "Employee added successfully.\n";
            break;
        }
        case 2:
        {
            // Edit Employee
            string id;
            cout << "Enter Employee ID to edit: ";
            getline(cin, id);
            hrSystem.editEmployee(id);
            break;
        }
        case 3:
        {
            // Remove Employee
            string id;
            cout << "Enter Employee ID to remove: ";
            getline(cin, id);

            // Search for the employee in the HR system
            auto it = find_if(hrSystem.getEmployees().begin(), hrSystem.getEmployees().end(), [id](const Employee *emp)
                              { return emp->getId() == id; });

            if (it != hrSystem.getEmployees().end())
            {
                // Display existing employee information before removal
                (*it)->showInformation();

                // Confirm with the user before removing the employee
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
            // Display All Employees
            hrSystem.displayAllEmployees();
            break;
        case 5:
            // Display All Interns
            hrSystem.displayAllInterns();
            break;
        case 6:
            // Display All Experiences
            hrSystem.displayAllExperiences();
            break;
        case 7:
            // Display All Freshers
            hrSystem.displayAllFreshers();
            break;
        case 8:
            // Exit the program
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 8);

    return 0;
}
