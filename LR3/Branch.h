#pragma once

#include <string>
#include <vector>
#include "Account.h"

class Branch {
private:
    int id;
    std::string address;
    std::vector<Account*> accounts;

public:
    Branch(int id, const std::string& address);
    void addAccount(Account* account);
    const std::string& getAddress() const;
    const std::vector<Account*>& getAccounts() const;
    int getId();
};
