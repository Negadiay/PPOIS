#pragma once
#include <string>
#include <vector>
#include <iostream>

class Calendar {
private:
    std::string date;                  
    std::vector<std::string> events;   

public:
    Calendar(const std::string& date);
    void addEvent(const std::string& event);       
    void removeEvent(const std::string& event);    
    void findEventByDate(const std::string& date); 
    void showInfo() const;                       
};