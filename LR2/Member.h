#pragma once
#include <string>
#include <iostream>
#include "Membership.h"

class Member {
private:
    std::string name;       
    int age;                
    Membership* membership; 

public:
   
    Member(const std::string& name, int age);
    void registerInClub(Membership* m); 
    void cancelMembership();            
    void showInfo() const;              
    std::string getName() const;        
    Membership* getMembership() const;  // Получить членство члена клуба
};


