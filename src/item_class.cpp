#include "item_class.h"
#include <iostream>
#include <string>
#include <list>
#include <random>
#include <ctime>
#include <cstdlib>

// main functions

int Item::generateID() { return rand() % 100 + 1; }

bool Item::create(std::string& new_msg) {
    id_ = generateID();
    description_ = new_msg;
    return true;
}

std::string Item::Status() {
    if (completed_) {
        return "done";
} else { 
    return "not done"; }
}

void Item::clear() const {
    system("clear");
}

// getters 

void Item::getID() { std::cout << id_; }

void Item::getDesc() { std::cout << description_; }

// setters

void Item::setDesc(std::string& new_msg) { description_ = new_msg; }
