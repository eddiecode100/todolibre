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
       
        ~Item: default;
           
        // main functions

        bool create(std::string&);

        constexpr int generateID();

        void clear() const;


        // getters

        void getID() const;

        void getDesc() const;

        void getStatus() const;

        // setters

        void setDesc(std::string&);
        
        std::string setStatus();        
};
