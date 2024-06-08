cmake_minimum_required(VERSION 3.28)

project(todolibre VERSION 0.2.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

cmake_policy(SET CMP0072 NEW)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(todolibre
    src/main.cpp
    src/item_class.cpp
)
