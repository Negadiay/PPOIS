#pragma once
#include <string>
#include <iostream>
#include "Coach.h"
#include "Member.h"

class PersonalTraining {
private:
    Member* client;          
    Coach* coach;        
    std::string dateTime;    

public:
    PersonalTraining(Member* client, Coach* trainer, const std::string& dateTime);
    void scheduleTraining(); 
    void rescheduleTraining(const std::string& newDateTime); 
    void showInfo() const;   
    std::string getDateTime() const;
};

