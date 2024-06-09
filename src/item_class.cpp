#include "item_class.h"
#include <iostream>
#include <string>
#include <list>
#include <random>
#include <ctime>
#include <cstdlib>


// main functions

constexpr int Item::generateID() { return rand() % 100 + 1; }

bool Item::create(std::string& new_msg) {
    id_ = generateID;
    description_ = new_msg;
    return true;
}

void Item::clear() const {
    system("clear");
}

// getters 

void Item::getID() const { return id_; }

void Item::getDesc() const { return description_; }

std::string Item::getStatus() const { return completed_; } 

// setters

void Item::setDesc(std::string& new_msg) { description_ = new_msg; }

void Item::setStatus() {
    if (completed_) {
        return "done";
} else { 
    return "not done"; }
}


