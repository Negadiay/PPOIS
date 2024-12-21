#pragma once

#include <string>
#include <vector>
#include "Customer.h"
#include "Branch.h"

class Bank {
private:
    std::string name;
    std::string address;
    std::vector<Customer*> customers;
    std::vector<Branch*> branches;

public:
    Bank(const std::string& name, const std::string& address);
    void addCustomer(Customer* customer);
    void addBranch(Branch* branch);
    void transferFunds(int fromAccountId, int toAccountId, double amount);
    void printCustomers() const;
    void printBranches() const;
    const std::vector<Customer*>& getCustomers() const;
    const std::vector<Branch*>& getBranches() const;
    std::string getName();
    std::string getAddress();
};
