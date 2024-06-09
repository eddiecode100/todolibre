#include "item_class.h"
#include <iostream>
#include <string>
#include <list>
#include <random>
#include <ctime>
#include <cstdlib>
#include <set>

// main functions

int Item::generateID() {
        int newID;
        do {
            newID = rand() % 100 + 1;
        } while (ids.find(newID) != ids.end());
        ids.insert(newID);
        return newID;
    }

bool Item::create(const std::string& new_msg) {
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

// getters 

int Item::getID() { return id_; }

std::string Item::getDesc() { return description_; }

// setters

void Item::setDesc(std::string& new_msg) { description_ = new_msg; }
