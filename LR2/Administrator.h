#pragma once
#include <string>
#include <iostream>
#include "Coach.h"
#include "Member.h"

class Administrator {
private:
    std::string name;        
    std::string workSchedule; 

public:
    Administrator(const std::string& name, const std::string& workSchedule);
    void processClientRequest();   
    void assignTrainerToSession(); 
    void showInfo() const;         
};

