#include "item_class.h"
#include <iostream>
#include <string>
#include <list>
#include <random>
#include <ctime>
#include <cstdlib>
#include <set>
#include <thread>
#include <chrono> 

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




    /* create list objects
    Item test;
    test.create("first todo");
    TodoList.push_back(test); // push test object to list
    */

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
                std::cout << "enter your new todo message: ";

                // clear newline character left in the input buffer
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::string msg;
                std::getline(std::cin, msg);

                Item newItem;
                newItem.create(msg);
                TodoList.push_back(newItem); 
                break;
            }
            case 'c': {
                std::cout << "enter ID to mark completed or unmark: ";
                int input_id;
                std::cin >> input_id;

                if (std::cin.fail()) {

                    std::cout << YELLOW << "please enter a valid ID: " << '\n' << RESET;
                    
                    std::cin.clear();

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    std::this_thread::sleep_for(std::chrono::seconds(2)); 
                } else {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    for (it = TodoList.begin(); it != TodoList.end(); ++it) {
                        if (input_id == it->getID()) {
                            it->setCompleted(!it->isCompleted());
                        }
                    }
                }
                break;
            }
            case 'r': {
                int input_id;
                
                std::cout << "enter ID of the Todo to remove: ";
                std::cin >> input_id;

                if (std::cin.fail()) {

                    std::cout << YELLOW << "please enter a valid ID: " << '\n' << RESET;
                    
                    std::cin.clear();

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    std::this_thread::sleep_for(std::chrono::seconds(2)); 
                } else {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    bool found = false;    
                for (it = TodoList.begin(); it != TodoList.end(); ++it) {
                    if (input_id == it->getID()) {
                        found = true;
                        it = TodoList.erase(it);
                    } else {
                        ++it;
                    }

                    if (!found) { // If no matching ID was found
                        std::cout << YELLOW << "please enter a valid ID: " << '\n' << RESET;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        break;
                         }
                }
                }
                break;
            }
            case 'n': {
                std::cout << "enter ID of the todo you would like to edit: ";
                int input_id;
                std::cin >> input_id;

                if (std::cin.fail()) {
                    std::cout << YELLOW << "please enter a valid ID: " << '\n' << RESET;

                    std::cin.clear();

                
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                
                    std::this_thread::sleep_for(std::chrono::seconds(2)); 
                } else {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    bool found = false;

                    std::cout << "enter the new message you would like: ";
                    std::string new_msg;
                    std::getline(std::cin, new_msg);

                    for (it = TodoList.begin(); it != TodoList.end(); ++it) {
                        if (input_id == it->getID()) {
                            it->setDesc(new_msg);
                            found = true;
                        } else {
                            ++it;
                        }
                         if (!found) { // If no matching ID was found
                            std::cout << YELLOW << "please enter a valid ID: " << '\n' << RESET;
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                            break;
                         }

                    }
                }
                break;
            }
            case 'q': {
                running = false;
                std::cout << '\n' << "have a good day!" << '\n' << '\n';
                break;
            }
            default: {
                std::cout << "invalid choice. try again.\n";
                std::cout << "press enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;
            }
        }
    }
    return 0;
}
