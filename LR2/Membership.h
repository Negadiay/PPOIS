#pragma once
#include <string>
#include <iostream>

class Member;

class Membership {
private:
    std::string type;    
    double price;        
    int duration;        

public:
    Membership(const std::string& type, double price, int duration);
    void renew();                
    void freeze();               
    void showInfo() const;       
    int getDuration() const;
};
