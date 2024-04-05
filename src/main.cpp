#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Employee {
    /* 
    People seem to be very split as to whether or not
    getters and setters should be used to access and
    modify attriubutes or if they should be public.
    
    I chose the latter to reduce bloat, but in a
    professional environment I would go for the 
    former option to prevent these values from 
    being changed erroneously elsewhere in the program.
    */

    public:
        std::string username;
        std::string password; // In a secure program, this would be hashed.
        std::string role;

        Employee(std::string user, 
                 std::string pass, 
                 std::string job) {
                    username = user;
                    password = pass;
                    role = job;
        }
};

// Prompt the user with dialogue and put their answer in a buffer string.
void prompt(std::string dialogue, std::string *buffer) {
    while (std::cout << dialogue && !std::getline(std::cin, *buffer)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        std::cout << "Please enter a valid input." << std::endl;
    }
}

// Create a new Employee object based on user input.
void add_user(std::vector<Employee>& employees) {
    std::string username;
    std::string password;
    std::string role;

    prompt("USERNAME: ", &username);
    prompt("PASSWORD: ", &password);
    prompt("    ROLE: ", &role);

    // Username and role are converted to uppercase for future comparisons.
    std::transform(username.begin(), username.end(), 
        username.begin(), ::toupper);
    std::transform(role.begin(), role.end(), 
        role.begin(), ::toupper);

    if (!username.length() || 
        !password.length() || 
            !role.length()) {
            std::cout << "User creation failed due to one or more inputs ";
            std::cout << "being 0 characters in length." << std::endl;

            return;
    }

    employees.push_back(Employee(username, password, role));

    std::cout << "User " << username;
    std::cout << " with role " << role << " has been created.";
    std::cout << std::endl;
}

// View username and role of Employee object from vector list.
void view_user(std::vector<Employee>& employees, std::string username) {
    if (!username.length()) {
        std::cout << "You must input a username to search for." << std::endl;

        return;
    }

    /* Convert username to uppercase so that we can search the 
       vector without worrying about case-sensitivity. */
    std::transform(username.begin(), username.end(), 
        username.begin(), ::toupper);

    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].username == username) {
            Employee user = employees[i];

            std::cout << "User " << user.username;
            std::cout << " has role " << user.role << ".";
            std::cout << std::endl;

            return;
        }
    }
    
    std::cout << "User not found." << std::endl;
}

// Display all Employee object usernames from vector list.
void show_users(std::vector<Employee>& employees) {
    std::cout << "Users: ";

    for (int i = 0; i < employees.size() - 1; i++) {
        Employee user = employees[i];

        std::cout << user.username << ", ";
    }

    // Last employee shown outside the for loop to avoid an extra comma.
    if (employees.size() > 0) { 
        std::cout << employees[employees.size() - 1].username << ".";
    }
    
    std::cout << std::endl;
} 

// Delete Emplyoee object from vector list based off username.
void delete_user(std::vector<Employee>& employees, std::string username) {
    if (!username.length()) {
        std::cout << "You must input a username to search for." << std::endl;

        return;
    }

    /* Convert username to uppercase so that we can search the 
       vector without worrying about case-sensitivity. */
    std::transform(username.begin(), username.end(), 
        username.begin(), ::toupper);

    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].username == username) {
            employees.erase(employees.begin() + i);

            std::cout << "User " << username << " has been deleted.";
            std::cout << std::endl;

            return;
        }
    }
    
    std::cout << "User not found." << std::endl;
}

// Modify username and role of Employee Object based on user input.
void modify_user(std::vector<Employee>& employees, std::string username) {
    if (!username.length()) {
        std::cout << "You must input a username to search for." << std::endl;

        return;
    }

    /* Convert username to uppercase so that we can search the 
       vector without worrying about case-sensitivity. */
    std::transform(username.begin(), username.end(), 
        username.begin(), ::toupper);

    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].username == username) {
            /* Directly writing to employees[i] instead of variable
               user here so that our changes are not lost. */
            prompt("NEW USERNAME: ", &employees[i].username);
            prompt("NEW ROLE:     ", &employees[i].role);

            std::cout << "User " << employees[i].username;
            std::cout << " has role " << employees[i].role << ".";
            std::cout << std::endl;

            return;
        }
    }
    
    std::cout << "User not found." << std::endl;
}

int main(void) {
    // Create a list of all employee accounts, including a default account.
    std::vector<Employee> employees = {};
    employees.push_back(Employee("ADMIN", "ADMIN", "HUMAN RESOURCES"));

    // Implement login and menu here.

    return 0;
}