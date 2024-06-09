#include "item_class.h"
#include <iostream>
#include <string>
#include <list>
#include <random>
#include <ctime>
#include <cstdlib>
#include <set>


std::set<int> Item::ids; // initialize static set for unique id storage

int main() {
    srand(time(NULL));


    std::string program_name = "TodoLibre - v0.2.0";
    
    // initialize list and iterator for list

    std::list<Item> TodoList;
    std::list<Item>::iterator it;
    TodoList.clear();

    // create list objects
    
    Item test;
    test.create("first todo");
    TodoList.push_back(test); // push test object to list
    



    while (1) {
        system("clear"); 
        std::cout << program_name << '\n' << '\n';
    
    
        for (it = TodoList.begin(); it != TodoList.end(); it++) {
            std::cout << it->getID() << " // " << it->getDesc() << " // " << it->Status() << '\n';    
        }
    }
    return 0;
}
