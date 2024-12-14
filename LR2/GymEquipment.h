#pragma once
#include <string>
#include <iostream>

class GymEquipment {
private:
    std::string name;    
    std::string type;    
    bool isWorking;      

public:
    GymEquipment(const std::string& name, const std::string& type);
    void checkCondition(); 
    void repair();         
    void showInfo() const; 
    bool getIsWorking() const;
};