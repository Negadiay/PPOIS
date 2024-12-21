#include "BankManager.h"
#include <iostream>

BankManager::BankManager(int employeeId, const std::string& name, double salary)
    : Employee(employeeId, name, "Менеджер банка"), salary(salary) {}

void BankManager::approveLoan() {
    std::cout << "Кредит одобрен менеджером банка: " << getName() << std::endl;
}

double BankManager::getSalary() const {
    return salary;
}
