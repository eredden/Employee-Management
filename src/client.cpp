// client.cpp

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include "../include/main.h"

// Client-side login prompt when entering the program.
int login(std::vector<Employee>& employees) {
    std::string username;
    std::string password;

    prompt("USERNAME: ", username);
    prompt("PASSWORD: ", password);

    if (!username.length() || !password.length()) {
        std::cout << "Username and password fields cannot be empty.";
        std::cout << std::endl << std::endl;

        return -1;
    }

    /* Convert username to uppercase so that we can search the 
       vector without worrying about case-sensitivity. */
    username = upper(username);

    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].username == username) {
            if (employees[i].password == password) {
                std::cout << "Welcome, " << employees[i].username << "!";
                std::cout << std::endl << std::endl;

                return i;
            } else {
                std::cout << "Invalid credentials.";
                std::cout << std::endl << std::endl;

                return -1;
            }
        }
    }

    std::cout << "Invalid credentials.";
    std::cout << std::endl << std::endl;

    return -1;
}

// Displays a menu of actions to the end-user and returns their choice.
void menu(std::vector<Employee>& employees, int index) {
    Employee user = employees[index];
    std::string option_str;
    int         option;

    std::cout << "Actions you may take:" << std::endl;
    std::cout << "1. EXIT the program."  << std::endl;
    std::cout << "2. VIEW yourself."     << std::endl;
    
    /* Role permissions are hard-coded in here and other spots as a quick 
       solution. This should be changed in the future to take a list instead. */
    if(user.role == "MANAGEMENT" || user.role == "HUMAN RESOURCES") {
        std::cout << "3. VIEW another employee." << std::endl;
        std::cout << "4. SHOW all employees."    << std::endl;
    }

    if (user.role == "HUMAN RESOURCES") {
        std::cout << "5. ADD a new user." << std::endl;
        std::cout << "6. MODIFY a user."  << std::endl;
        std::cout << "7. DELETE a user."  << std::endl;
    }

    prompt("Enter the number associated with the action you want to take: ",
        option_str);
    option = str_to_int(option_str);

    std::cout << std::endl;

    // Options available to all employees.
    if (option == 1) {
        std::cout << "Have a great day!" << std::endl;

        exit(EXIT_SUCCESS);
    }

    else if (option == 2) {
        std::cout << "User " << user.username;
        std::cout << " has role " << user.role << ".";
        std::cout << std::endl << std::endl; 
    }

    // Options exclusive to non-general employees.
    if (user.role == "MANAGEMENT" || user.role == "HUMAN RESOURCES") {
        if (option == 3) {
            view_user(employees);
            std::cout << std::endl;
        }

        else if (option == 4) {
            show_users(employees);
            std::cout << std::endl;
        }
    }

    // Options exclusive to HUMAN RESOURCES employees.
    if (user.role == "HUMAN RESOURCES") {
        if (option == 5) {
            add_user(employees);
            std::cout << std::endl;
        }

        else if (option == 6) {
            modify_user(employees);
            std::cout << std::endl;
        }

        else if (option == 7) {
            delete_user(employees);
            std::cout << std::endl;
        }
    }
}