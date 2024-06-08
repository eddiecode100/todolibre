#pragma once

#include <iostream>
#include <string>
#include <list>
#include <random>

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

        int generateID();

        void clear() const;


        // getters

        void getID() const;

        void getDesc() const;

        void getStatus() const;

        // setters

        std::string setDesc(std::string&);
        
        bool setStatus(const bool&);
};
