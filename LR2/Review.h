#pragma once
#include <string>
#include <iostream>
#include "Member.h"
#include "Membership.h"


class Review {
private:
    Member* member;
    std::string clientName;   
    std::string text;         

public:
    Review(const std::string& clientName, const std::string& text,Member*member); 
    Review(const std::string& clientName, const std::string& text);
    void leaveReview();  
    void deleteReview(); 
    void showInfo() const; 
};

