## Employee Management Program

This project was created for the [Computer Science 112 course](https://study.com/academy/course/computer-science-112-programming-in-c.html) on [Study.com](https://study.com). I did this to expand my knowledge of the C++ programming language as well as to pursue a college degree from Western Governor's University. It allows for the addition, modification, and deletion of users using a command-line interface.

### Setup

You can execute `build.sh` in the root directory of this project to build an executable. This script should work in Bash and Powershell.

### Usage

Run the compiled executable that you made during the setup process and log in using default credentials `ADMIN` / `ADMIN`. Once you have logged in, you will be presented with a myriad of options to use for user management. Option 1 allows you to exit the program, Options 2-4 let you view employee information, and Options 5-7 allow you to modify the users.

```
EMPLOYEE MANAGEMENT PORTAL
USERNAME: ADMIN
PASSWORD: ADMIN
Welcome, ADMIN!

1. EXIT the program.
2. VIEW yourself.
3. VIEW another employee.
4. SHOW all employees.
5. ADD a new user.
6. MODIFY a user.
7. DELETE a user.
Enter the number associated with the action you want to take:
```

As an example, you can create a user by selecting Option 5 and entering the required information.

```
Enter the number associated with the action you want to take: 5

USERNAME: TEST
PASSWORD: TEST
    ROLE: TEST
User TEST with role TEST has been created.
```

You can then view the user by selecting Option 3 for viewing another employee.

```
Enter the number associated with the action you want to take: 3

Username: TEST
User TEST has role TEST.
```

User information is not persistently stored and disappears after the program is closed.