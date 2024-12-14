#pragma once
#include <string>
#include <iostream>

class Coach {
private:
    std::string name;      
    std::string specialization;  
    int experience;        

public:
    Coach(const std::string& name, const std::string& specialization, int experience);
    void conductTraining();  
    void developPlan();      
    void evaluateProgress(); 
    void showInfo() const;   
    std::string getName();
    std::string getSpecialization();
    int getExperience();
};

