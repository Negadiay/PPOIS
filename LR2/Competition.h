#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Member.h"


class Competition {
private:
    Member* member;
    std::string name;      
    std::string date;      
    double prizeFund;      
    std::vector<Member*> participants; 

public:
    Competition(const std::string& name, const std::string& date, double prizeFund);
    void registerParticipant(Member* member); 
    void publishResults();                     
    void cancelCompetition();                  
    void showInfo() const;  
    std::string getName() const;
    std::string getDate() const;
};


