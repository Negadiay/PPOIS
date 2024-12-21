#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/Investment.h"
#include "../ppois33/Investment.cpp"
#include "../ppois33/Customer.h"

TEST(InvestmentTest, ConstructorAndInitialization) {
    Customer customer(1, "Иван Иванов");
    Investment investment(10000.0, "Акции", &customer);

    EXPECT_EQ(investment.getAmount(), 10000.0);
    EXPECT_EQ(investment.getInvestmentType(), "Акции");
}

TEST(InvestmentTest, Invest) {
    Customer customer(1, "Иван Иванов");
    Investment investment(10000.0, "Акции", &customer);

    testing::internal::CaptureStdout();
    investment.invest();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Инвестировано 10000 в Акции\n");
}

TEST(InvestmentTest, Withdraw) {
    Customer customer(1, "Иван Иванов");
    Investment investment(10000.0, "Акции", &customer);

    testing::internal::CaptureStdout();
    investment.withdraw();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Снято 10000 с Акции\n");
}

TEST(InvestmentTest, GetAmount) {
    Customer customer(1, "Иван Иванов");
    Investment investment(10000.0, "Облигации", &customer);

    EXPECT_EQ(investment.getAmount(), 10000.0);
}

TEST(InvestmentTest, GetInvestmentType) {
    Customer customer(1, "Иван Иванов");
    Investment investment(10000.0, "Облигации", &customer);

    EXPECT_EQ(investment.getInvestmentType(), "Облигации");
}
