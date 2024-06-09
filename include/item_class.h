#pragma once

#include <iostream>
#include <string>
#include <list>
#include <random>
#include <ctime>
#include <cstdlib>

class Item {
    private:
        int id_;
        std::string description_;
        bool completed_;
    
    public:
        Item() : id_(0), description_(""), completed_(false) {}
       
        ~Item();
           
        // main functions

        bool create(std::string&);

        int generateID();

        std::string Status();        

        void clear() const;


        // getters

        void getID();

        void getDesc();
        
        void displayUI();

        // setters

        void setDesc(std::string&);
};
