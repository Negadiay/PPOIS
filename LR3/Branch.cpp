#include "Branch.h"
#include "Account.h"

Branch::Branch(int id, const std::string& address) : id(id), address(address) {}

void Branch::addAccount(Account* account) {
    accounts.push_back(account);
}

const std::string& Branch::getAddress() const {
    return address;
}

const std::vector<Account*>& Branch::getAccounts() const {
    return accounts;
}

int Branch::getId() {
    return id;
}