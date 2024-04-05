/*
EMPLOYEE MANAGEMENT SYSTEM by Evan Redden.

This program is used to manage employees and meets the standard
criteria set out by the creators of the Computer Science 112 course.

In the creation of this program, I made several trade-offs:
1. Iteratively searching a vector for users rather than using a hashmap.
    - This increases time complexity from O(1) to O(N) time.
    - However, hashmaps were not taught in the course.
2. Not hashing passwords or implementing any sort of password security.
    - This was also not covered in the course.
3. Opting for using public attributes rather than getters/setters.
    - Purposeful decision to reduce bloat.
    - While this makes sense for larger programs, it is not necessary here.
4. Not persistently storing account information once the program closes.

With all the above in mind, the remainder of my code should be pretty alright.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Employee {
    public:
        std::string username;
        std::string password;
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
void prompt(std::string dialogue, std::string& buffer) {
    while (std::cout << dialogue && !std::getline(std::cin, buffer)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        std::cout << "Please enter a valid input." << std::endl;
    }
}

// Reusing this from a previous C language project of mine.
int str_to_int(std::string str) {

    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str.at(i)) == 0) {
            std::cout << "Input must be an integer number." << std::endl;
            return 0;
        }
    }

    return std::stoi(str);
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
void view_user(std::vector<Employee>& employees) {
    std::string username;
    prompt("Username: ", username);

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

    // Last employee processed outside the for loop to avoid an extra comma.
    if (employees.size() > 0) { 
        std::cout << employees[employees.size() - 1].username << ".";
    }
    
    std::cout << std::endl;
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
    std::transform(username.begin(), username.end(), 
        username.begin(), ::toupper);

    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].username == username) {
            /* Directly writing to employees[i] instead of variable
               user here so that our changes are not lost. */
            prompt("NEW USERNAME: ", employees[i].username);
            prompt("NEW ROLE:     ", employees[i].role);

            std::cout << "User " << employees[i].username;
            std::cout << " has role " << employees[i].role << ".";
            std::cout << std::endl;

            return;
        }
    }
    
    std::cout << "User not found." << std::endl;
}

// Client-side login prompt when entering the program.
Employee* login(std::vector<Employee>& employees) {
    std::string username;
    std::string password;

    prompt("USERNAME: ", username);
    prompt("PASSWORD: ", password);

    if (!username.length() || !password.length()) {
        std::cout << "Username and password fields cannot be empty.";
        std::cout << std::endl << std::endl;

        return nullptr;
    }

    /* Convert username to uppercase so that we can search the 
       vector without worrying about case-sensitivity. */
    std::transform(username.begin(), username.end(), 
        username.begin(), ::toupper);

    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].username == username) {
            if (employees[i].password == password) {
                std::cout << "Welcome, " << employees[i].username << "!";
                std::cout << std::endl << std::endl;

                return &employees[i];
            } else {
                std::cout << "Invalid credentials.";
                std::cout << std::endl << std::endl;

                return nullptr;
            }
        }
    }

    std::cout << "Invalid credentials.";
    std::cout << std::endl << std::endl;

    return nullptr;
}

// Displays a menu of actions to the end-user and returns their choice.
void menu(std::vector<Employee>& employees, Employee& user) {
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

int main(void) {
    // Create a list of all employee accounts, including a default account.
    std::vector<Employee> employees = {};
    employees.push_back(Employee("ADMIN", "ADMIN", "HUMAN RESOURCES"));

    Employee* user_ptr = nullptr; // Pointer to employee you are logged in as.

    std::cout << "EMPLOYEE MANAGEMENT PORTAL" << std::endl;

    while (!user_ptr) {
        user_ptr = login(employees);
    }

    // Repeatedly go through the menu and process the desired actions.
    for (;;) {
        menu(employees, *user_ptr);
    }

    return 0;
}
