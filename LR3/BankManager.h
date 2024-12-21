#pragma once

#include <string>
#include "Employee.h"

class BankManager : public Employee {
private:
    double salary;

public:
    BankManager(int employeeId, const std::string& name, double salary);
    void approveLoan();
    double getSalary() const;
};
