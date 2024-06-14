#include "item_class.h"
#include <iostream>
#include <string>
#include <list>
#include <random>
#include <ctime>
#include <cstdlib>
#include <set>

// ANSI escape codes for colors
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";

std::set<int> Item::ids; // initialize static set for unique id storage

int main() {

    srand(time(NULL)); // set entropy using system time 
    bool running = true;

    // initialize list and iterator for list
    std::list<Item> TodoList;
    std::list<Item>::iterator it;
    TodoList.clear();

    // create list objects
    Item test;
    test.create("first todo");
    TodoList.push_back(test); // push test object to list

    // main program loop
    while (running) {

        system("clear");

        std::string program_name = "TodoLibre - v0.2.0";
        std::cout << GREEN << program_name << RESET << '\n' << '\n';

        for (it = TodoList.begin(); it != TodoList.end(); it++) {
            std::cout << it->getID() << 
            " // " << it->getDesc() << 
            " // " << it->Status() <<
            '\n';   
        }

        if (TodoList.empty()) { std::cout << RED << "enter your first todo!" << RESET << '\n' << '\n'; }

        std::cout << '\n';
        std::cout << RED << "[a]dd a new todo" << '\n';
        std::cout << "[c]omplete a todo" << '\n';
        std::cout << "[r]emove a todo" << '\n';
        std::cout << "[n]ew message in a todo" << '\n';
        std::cout << "[q]uit the program" << RESET << '\n';

        std::cout << '\n' << "enter your choice: ";

        char input;
        std::cin >> input;

        switch (input) {
            case 'a': {
                break;
            }
            case 'c': {
                std::cout << "Enter ID to mark completed or unmark: ";

                int input_id;

                std::cin >> input_id;

                for (it = TodoList.begin(); it != TodoList.end(); ++it) {
                    if (input_id == it->getID()) {
                        it->setCompleted(!it->isCompleted());
                    }
                }
                break;
            }
            case 'r': {
                std::cout << "Enter the ID of the Todo to remove: ";

                int input_id;

                std::cin >> input_id;

                for (it = TodoList.begin(); it != TodoList.end(); ++it) {
                    if (input_id == it->getID()) {
                        it = TodoList.erase(it);
                    } else {
                        ++it;
                    }
                }

                break;
            }
            case 'n': {
                break;
            }
            case 'q': {
                running = false;
                std::cout << '\n' << "have a good day!" << '\n' << '\n';
                break;
            }
            default: {
                std::cout << "Invalid choice. Try again.\n";
                std::cout << "Press Enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;
            }
        }
    }
    return 0;
}
