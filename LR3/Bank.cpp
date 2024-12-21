#include "Bank.h"
#include "Customer.h"
#include "Branch.h"
#include <iostream>

Bank::Bank(const std::string& name, const std::string& address)
    : name(name), address(address) {}

void Bank::addCustomer(Customer* customer) {
    customers.push_back(customer);
}

void Bank::addBranch(Branch* branch) {
    branches.push_back(branch);
}

void Bank::transferFunds(int fromAccountId, int toAccountId, double amount) {
  
    std::cout << "���������� ������ " << amount << " �� ����� " << fromAccountId << " �� ���� " << toAccountId << std::endl;
}

void Bank::printCustomers() const {
    std::cout << "�������: " << std::endl;
    for (auto customer : customers) {
        std::cout << "������ ID: " << customer->getId() << ", ���: " << customer->getName() << std::endl;
    }
}

void Bank::printBranches() const {
    std::cout << "�������: " << std::endl;
    for (auto branch : branches) {
        std::cout << "������ ID: " << branch->getId() << ", �����: " << branch->getAddress() << std::endl;
    }
}

const std::vector<Customer*>& Bank::getCustomers() const {
    return customers;
}

const std::vector<Branch*>& Bank::getBranches() const {
    return branches;
}

std::string Bank::getName() {
    return name;
}

std::string Bank::getAddress() {
    return address;
}
