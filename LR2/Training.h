#pragma once
#include <string>
#include <iostream>

class Training {
private:
    std::string type;              
    int duration;                  
    int maxParticipants;           

public:
    Training(const std::string& type, int duration, int maxParticipants);
    void enrollMember();            
    void cancelTraining();          
    void showInfo() const;          
};


