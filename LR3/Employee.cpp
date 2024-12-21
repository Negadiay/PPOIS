#include "Employee.h"

Employee::Employee(int employeeId, const std::string& name, const std::string& position)
    : employeeId(employeeId), name(name), position(position) {}

int Employee::getEmployeeId() const {
    return employeeId;
}

const std::string& Employee::getName() const {
    return name;
}

const std::string& Employee::getPosition() const {
    return position;
}
