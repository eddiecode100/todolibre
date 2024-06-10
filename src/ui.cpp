#include "item_class.h"
#include <iostream>
#include <string>
#include <list>
#include <random>
#include <ctime>
#include <cstdlib>
#include <set>

void printUI() const {
    std::cout << program_name << '\n' << '\n';

    for (it = TodoList.begin(); it != TodoList.end(); it++) {
        std::cout << it->getID() << 
        " // " << it->getDesc() << 
        " // " << it->Status() <<
        '\n';    
    }
}

void clearUI() const { system("clear"); } 
}
