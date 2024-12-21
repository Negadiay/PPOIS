#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/Employee.h"
#include "../ppois33/Employee.cpp"


TEST(EmployeeTest, ConstructorAndInitialization) {
    Employee employee(1, "Alice", "Manager");

    EXPECT_EQ(employee.getEmployeeId(), 1);
    EXPECT_EQ(employee.getName(), "Alice");
    EXPECT_EQ(employee.getPosition(), "Manager");
}

TEST(EmployeeTest, GetEmployeeId) {
    Employee employee(2, "Bob", "Developer");

    EXPECT_EQ(employee.getEmployeeId(), 2);
}

TEST(EmployeeTest, GetName) {
    Employee employee(3, "Charlie", "Tester");

    EXPECT_EQ(employee.getName(), "Charlie");
}

TEST(EmployeeTest, GetPosition) {
    Employee employee(4, "David", "HR");

    EXPECT_EQ(employee.getPosition(), "HR");
}
