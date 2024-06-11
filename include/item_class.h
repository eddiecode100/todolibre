#pragma once

#include <iostream>
#include <string>
#include <list>
#include <random>
#include <ctime>
#include <cstdlib>
#include <set>

class Item {
    private:
        int id_;
        std::string description_;
        bool completed_;
        static std::set<int> ids; // declare static set to store unique ids
    public:
        Item() : id_(0), description_(""), completed_(false) {}
       
        ~Item() = default;
           
        // main functions

        bool create(const std::string&);

        int generateID();

        std::string Status();        

        // getters

        int getID() const;

        std::string getDesc() const;
        
        void displayUI();
        
        bool isCompleted() const;
        // setters

        void setDesc(std::string&);

        bool setCompleted(bool);
};
