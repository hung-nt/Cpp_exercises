#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
using namespace std;

class Certificate {
private:
    string id;
    string name;
    string rank;
    chrono::system_clock::time_point date;

public:
    Certificate() {}

    Certificate(string id, string name, string rank, chrono::system_clock::time_point date)
        : id(id), name(name), rank(rank), date(date) {}

    string getId() const {
        return id;
    }

    void setId(const string& id) {
        this->id = id;
    }

    string getName() const {
        return name;
    }

    void setName(const string& name) {
        this->name = name;
    }

    string getRank() const {
        return rank;
    }

    void setRank(const string& rank) {
        this->rank = rank;
    }

    chrono::system_clock::time_point getDate() const {
        return date;
    }

    void setDate(const chrono::system_clock::time_point& date) {
        this->date = date;
    }
};

class Employee {
protected:
    string id;
    string fullName;
    chrono::system_clock::time_point birthday;
    string phone;
    string email;
    vector<Certificate> certificates;
    int employeeType; 
    static int employeeCount; 

public:
    Employee() {
        employeeCount++;
    }

    Employee(string id, string fullName, chrono::system_clock::time_point birthday,
             string phone, string email, const vector<Certificate>& certificates, int employeeType)
        : id(id), fullName(fullName), birthday(birthday), phone(phone), email(email),
          certificates(certificates), employeeType(employeeType) {
        employeeCount++;
    }

    virtual void showInformation() const {
        cout << "Employee Information:\n";
        cout << "ID: " << getId() << "\n";
        cout << "Name: " << getFullName() << "\n";
        cout << "Birthday: " << chrono::system_clock::to_time_t(getBirthday()) << "\n";
        cout << "Phone: " << getPhone() << "\n";
        cout << "Email: " << getEmail() << "\n";
        cout << "Employee Type: " << getEmployeeTypeString() << "\n";

        for (const auto& certificate : certificates) {
            cout << "Certificate ID: " << certificate.getId() << "\n";
            cout << "Certificate Name: " << certificate.getName() << "\n";
            cout << "Certificate Rank: " << certificate.getRank() << "\n";
            cout << "Certificate Date: " << chrono::system_clock::to_time_t(certificate.getDate()) << "\n";
        }
    }

    string getId() const {
        return id;
    }

    chrono::system_clock::time_point getBirthday() const {
        return birthday;
    }

    string getPhone() const {
        return phone;
    }

    string getEmail() const {
        return email;
    }

    string getFullName() const {
        return fullName;
    }

    int getEmployeeType() const {
        return employeeType;
    }

    string getEmployeeTypeString() const {
        switch (employeeType) {
            case 0:
                return "Experience";
            case 1:
                return "Fresher";
            case 2:
                return "Intern";
            default:
                return "Unknown";
        }
    }

    static int getEmployeeCount() {
        return employeeCount;
    }
};

int Employee::employeeCount = 0;

class Experience : public Employee {
private:
    int yearOfExperience;
    string proSkill;

public:
    Experience() {}

    Experience(string id, string fullName, chrono::system_clock::time_point birthday,
               string phone, string email, const vector<Certificate>& certificates,
               int yearOfExperience, string proSkill)
        : Employee(id, fullName, birthday, phone, email, certificates, 0),
          yearOfExperience(yearOfExperience), proSkill(proSkill) {}

    void showInformation() const override {
        Employee::showInformation();
        // Hiển thị thông tin riêng của Experience nếu cần
        cout << "Years of Experience: " << yearOfExperience << "\n";
        cout << "Professional Skill: " << proSkill << "\n";
    }
};

class Intern : public Employee {
private:
    string major;
    int semester;
    string universityName;

public:
    Intern() {}

    Intern(string id, string fullName, chrono::system_clock::time_point birthday,
           string phone, string email, const vector<Certificate>& certificates,
           string major, int semester, string universityName)
        : Employee(id, fullName, birthday, phone, email, certificates, 2),
          major(major), semester(semester), universityName(universityName) {}

    void showInformation() const override {
        Employee::showInformation();
        cout << "Major: " << major << "\n";
        cout << "Semester: " << semester << "\n";
        cout << "University Name: " << universityName << "\n";
    }
};

class Fresher : public Employee {
private:
    chrono::system_clock::time_point graduationDate;
    string graduationRank;
    string universityName;

public:
    Fresher() {}

    Fresher(string id, string fullName, chrono::system_clock::time_point birthday,
            string phone, string email, const vector<Certificate>& certificates,
            chrono::system_clock::time_point graduationDate,
            string graduationRank, string universityName)
        : Employee(id, fullName, birthday, phone, email, certificates, 1),
          graduationDate(graduationDate), graduationRank(graduationRank), universityName(universityName) {}

    void showInformation() const override {
        Employee::showInformation();
        cout << "Graduation Date: " << chrono::system_clock::to_time_t(graduationDate) << "\n";
        cout << "Graduation Rank: " << graduationRank << "\n";
        cout << "University Name: " << universityName << "\n";
    }
};


class HRManagementSystem {
private:
    vector<Employee*> employees;

public:
    ~HRManagementSystem() {
        for (auto employee : employees) {
            delete employee;
        }
    }

    // Function to add an employee
    void addEmployee(Employee* employee) {
        employees.push_back(employee);
        cout << "Employee added successfully.\n";
    }

    // Function to edit an employee
    void editEmployee(const string& id) {
        auto it = find_if(employees.begin(), employees.end(), [id](const Employee* emp) {
            return emp->getId() == id;
        });

        if (it != employees.end()) {
            (*it)->showInformation();

            // Allow user to edit employee information here
            cout << "Employee information updated successfully.\n";
        } else {
            cout << "Employee with ID " << id << " not found.\n";
        }
    }

    // Function to remove an employee
    void removeEmployee(const string& id) {
        auto it = remove_if(employees.begin(), employees.end(), [id](const Employee* emp) {
            return emp->getId() == id;
        });

        if (it != employees.end()) {
            delete *it;  // Free memory of the Employee object
            employees.erase(it, employees.end());
            cout << "Employee with ID " << id << " removed successfully.\n";
        } else {
            cout << "Employee with ID " << id << " not found.\n";
        }
    }

    // Function to display all employees
    void displayAllEmployees() const {
        for (const auto& employee : employees) {
            employee->showInformation();
            cout << "---------------------\n";
        }
    }

    // Function to find and display all Intern employees
    void displayAllInterns() const {
        for (const auto& employee : employees) {
            if (employee->getEmployeeType() == 2) {
                employee->showInformation();
                cout << "---------------------\n";
            }
        }
    }

    // Function to find and display all Experience employees
    void displayAllExperiences() const {
        for (const auto& employee : employees) {
            if (employee->getEmployeeType() == 0) {
                employee->showInformation();
                cout << "---------------------\n";
            }
        }
    }

    // Function to find and display all Fresher employees
    void displayAllFreshers() const {
        for (const auto& employee : employees) {
            if (employee->getEmployeeType() == 1) {
                employee->showInformation();
                cout << "---------------------\n";
            }
        }
    }
};


int main() {
    HRManagementSystem hrSystem;
    Employee* expEmployee = new Experience("001", "John Doe", chrono::system_clock::now(),
                                           "123456789", "john.doe@example.com", {}, 5, "Programming");
    hrSystem.addEmployee(expEmployee);

    Employee* internEmployee = new Intern("002", "Jane Smith", chrono::system_clock::now(),
                                          "987654321", "jane.smith@example.com", {}, "Computer Science", 3, "University XYZ");
    hrSystem.addEmployee(internEmployee);

    Employee* fresherEmployee = new Fresher("003", "Mike Johnson", chrono::system_clock::now(),
                                            "555555555", "mike.johnson@example.com", {}, chrono::system_clock::now(), "Excellent", "University ABC");
    hrSystem.addEmployee(fresherEmployee);

    hrSystem.displayAllEmployees();

    hrSystem.editEmployee("001");

    hrSystem.removeEmployee("002");

    hrSystem.displayAllEmployees();

    return 0;
}