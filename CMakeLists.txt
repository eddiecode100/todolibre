cmake_minimum_required(VERSION 3.28)

project(todolibre VERSION 0.2.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

cmake_policy(SET CMP0072 NEW)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add options for cross-compiling
option(BUILD_FOR_WINDOWS "Build for Windows using mingw-w64" OFF)
option(BUILD_FOR_MACOS "Build for macOS using Clang" OFF)
option(BUILD_FOR_LINUX "Build for Linux" ON)  # Default to ON for Linux native build

if(BUILD_FOR_WINDOWS)
    # Set the cross-compilation toolchain for Windows
    set(CMAKE_SYSTEM_NAME Windows)
    set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
    set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
    set(CMAKE_RC_COMPILER x86_64-w64-mingw32-windres)
    set(CMAKE_FIND_ROOT_PATH /usr/local/opt/mingw-w64)
    set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
    set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
elseif(BUILD_FOR_MACOS)
    # Set the cross-compilation toolchain for macOS
    set(CMAKE_SYSTEM_NAME Darwin)
    set(CMAKE_OSX_ARCHITECTURES x86_64)
    set(CMAKE_C_COMPILER /usr/bin/clang)
    set(CMAKE_CXX_COMPILER /usr/bin/clang++)
    set(CMAKE_FIND_ROOT_PATH /usr/local/Cellar/osxcross/target/bin)
    set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
    set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
elseif(BUILD_FOR_LINUX)
    # No special settings needed for Linux as it's the native environment
    message(STATUS "Building for Linux")
else()
    message(FATAL_ERROR "You must specify one of BUILD_FOR_WINDOWS, BUILD_FOR_MACOS, or BUILD_FOR_LINUX")
endif()

add_executable(todolibre
    src/main.cpp
    src/item_class.cpp
)
