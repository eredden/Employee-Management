cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(main VERSION 1.0)

add_executable(main 
    src/main.cpp
    src/employee.cpp
    src/client.cpp
    src/parse.cpp
)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)