cmake_minimum_required(VERSION 3.28)

project(my_todo_list VERSION 0.2.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

cmake_policy(SET CMP0072 NEW)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(my_todo_list
    src/main.cpp
    src/todo_item_class.cpp
)
