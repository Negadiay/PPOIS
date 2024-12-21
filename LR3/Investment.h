#pragma once

#include <string>
#include "Customer.h"

class Investment {
private:
    double amount;
    std::string investmentType;
    Customer* investor;

public:
    Investment(double amount, const std::string& investmentType, Customer* investor);
    void invest();
    void withdraw();
    double getAmount() const;
    const std::string& getInvestmentType() const;
};
