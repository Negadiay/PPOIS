#pragma once
#include <string>
#include <iostream>

class Service {
private:
    std::string name;    
    double price;        

public:
    Service(const std::string& name, double price);
    void addService();    
    void removeService(); 
    void showInfo() const; 
};


