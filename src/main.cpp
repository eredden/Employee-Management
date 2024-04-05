// main.cpp

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
#include <vector>
#include <string>

#include "../include/main.h"

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
