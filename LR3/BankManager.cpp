#include "BankManager.h"
#include <iostream>

BankManager::BankManager(int employeeId, const std::string& name, double salary)
    : Employee(employeeId, name, "�������� �����"), salary(salary) {}

void BankManager::approveLoan() {
    std::cout << "������ ������� ���������� �����: " << getName() << std::endl;
}

double BankManager::getSalary() const {
    return salary;
}
