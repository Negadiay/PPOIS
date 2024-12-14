#pragma once
#include <string>
#include <iostream>

class Payment {
private:
    double amount;         
    std::string date;      
    std::string paymentMethod; 

public:
    Payment(double amount, const std::string& date, const std::string& paymentMethod);
    void processPayment();   
    void cancelPayment();    
    void showInfo() const;   
};

