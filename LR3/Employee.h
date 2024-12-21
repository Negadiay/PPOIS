#pragma once

#include <string>

class Employee {
private:
    int employeeId;
    std::string name;
    std::string position;

public:
    Employee(int employeeId, const std::string& name, const std::string& position);
    int getEmployeeId() const;
    const std::string& getName() const;
    const std::string& getPosition() const;
};
