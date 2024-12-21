#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/Mortgage.h"
#include "../ppois33/Mortgage.cpp"
#include "../ppois33/Loan.h"

TEST(MortgageTest, ConstructorAndInitialization) {
    Mortgage mortgage(500000.0, 5.0, "2028-12-31", 600000.0, 100000.0);

    EXPECT_EQ(mortgage.getAmount(), 500000.0);
    EXPECT_EQ(mortgage.getInterestRate(), 5.0);
    EXPECT_EQ(mortgage.getDueDate(), "2028-12-31");
    EXPECT_EQ(mortgage.getPropertyValue(), 600000.0);
    EXPECT_EQ(mortgage.getDownPayment(), 100000.0);
}

TEST(MortgageTest, GetPropertyValue) {
    Mortgage mortgage(500000.0, 5.0, "2028-12-31", 600000.0, 100000.0);

    EXPECT_EQ(mortgage.getPropertyValue(), 600000.0);
}

TEST(MortgageTest, GetDownPayment) {
    Mortgage mortgage(500000.0, 5.0, "2028-12-31", 600000.0, 100000.0);

    EXPECT_EQ(mortgage.getDownPayment(), 100000.0);
}
