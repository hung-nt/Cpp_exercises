#include "../include/HRManagementSystem.h"
#include "../include/Experience.h"
#include "../include/Intern.h"
#include "../include/Fresher.h"

int main() {
    HRManagementSystem hrSystem;

    Employee* expEmployee = new Experience("001", "John Doe", std::chrono::system_clock::now(),
                                           "123456789", "john.doe@example.com", {}, 5, "Programming");
    hrSystem.addEmployee(expEmployee);

    Employee* internEmployee = new Intern("002", "Jane Smith", std::chrono::system_clock::now(),
                                          "987654321", "jane.smith@example.com", {}, "Computer Science", 3, "University XYZ");
    hrSystem.addEmployee(internEmployee);

    Employee* fresherEmployee = new Fresher("003", "Mike Johnson", std::chrono::system_clock::now(),
                                            "555555555", "mike.johnson@example.com", {}, std::chrono::system_clock::now(), "Excellent", "University ABC");
    hrSystem.addEmployee(fresherEmployee);

    hrSystem.displayAllEmployees();

    hrSystem.editEmployee("001");

    hrSystem.removeEmployee("002");

    hrSystem.displayAllEmployees();

    return 0;
}
