// main.h

#include <vector>
#include <string>

#ifndef MANAGE
#define MANAGE

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

Employee* login(std::vector<Employee>& employees);
void menu(std::vector<Employee>& employees, Employee& user);

void view_user(std::vector<Employee>& employees);
void show_users(std::vector<Employee>& employees);
void add_user(std::vector<Employee>& employees);
void modify_user(std::vector<Employee>& employees);
void delete_user(std::vector<Employee>& employees);

void prompt(std::string dialogue, std::string& buffer);
int str_to_int(std::string str);

#endif // MANAGE