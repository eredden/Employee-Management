// employee.cpp

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include "../include/main.h"

// View username and role of Employee object from vector list.
void view_user(std::vector<Employee>& employees) {
    std::string username;
    prompt("Username: ", username);

    if (!username.length()) {
        std::cout << "You must input a username to search for." << std::endl;

        return;
    }

    /* Convert username to uppercase so that we can search the 
       vector without worrying about case-sensitivity. */
    username = upper(username);

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

    // Last employee processed outside the for loop to avoid an extra comma.
    if (employees.size() > 0) { 
        std::cout << employees[employees.size() - 1].username << ".";
    }
    
    std::cout << std::endl;
} 

// Create a new Employee object based on user input.
void add_user(std::vector<Employee>& employees) {
    std::string username;
    std::string password;
    std::string role;

    prompt("USERNAME: ", username);
    prompt("PASSWORD: ", password);
    prompt("    ROLE: ", role);

    // Username and role are converted to uppercase for future comparisons.
    username = upper(username);
    role     = upper(role);

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

// Modify username and role of Employee object based on user input.
void modify_user(std::vector<Employee>& employees) {
    std::string username;
    prompt("Username: ", username);

    if (!username.length()) {
        std::cout << "You must input a username to search for." << std::endl;

        return;
    }

    /* Convert username to uppercase so that we can search the 
       vector without worrying about case-sensitivity. */
    username = upper(username);

    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].username == username) {
            std::string new_username;
            std::string new_role;

            prompt("NEW USERNAME: ", new_username);
            prompt("NEW ROLE:     ", new_role);

            /* Directly writing to employees[i] instead of a
               variable here so that our changes are not lost. */
            employees[i].username = upper(new_username);
            employees[i].role     = upper(new_role);

            std::cout << "User " << employees[i].username;
            std::cout << " has role " << employees[i].role << ".";
            std::cout << std::endl;

            return;
        }
    }
    
    std::cout << "User not found." << std::endl;
}

// Delete Employee object from vector list based off username.
void delete_user(std::vector<Employee>& employees) {
    std::string username;
    prompt("Username: ", username);

    if (!username.length()) {
        std::cout << "You must input a username to search for." << std::endl;

        return;
    }

    /* Convert username to uppercase so that we can search the 
       vector without worrying about case-sensitivity. */
    username = upper(username);

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