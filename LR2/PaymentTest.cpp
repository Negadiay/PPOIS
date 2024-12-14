#include <gtest/gtest.h>
#include "pch.h"
#include "../ppois22/Payment.h"
#include "../ppois22/Payment.cpp"

// Тестирование обработки платежа
TEST(PaymentTest, ProcessPaymentTest) {
    Payment p(50.0, "2024-12-12", "Credit Card");
    testing::internal::CaptureStdout();
    p.processPayment();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Платеж на сумму 50 проведен."), std::string::npos);
}

// Тестирование отмены платежа
TEST(PaymentTest, CancelPaymentTest) {
    Payment p(30.0, "2024-12-13", "PayPal");
    testing::internal::CaptureStdout();
    p.cancelPayment();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Платеж на сумму 30 отменен."), std::string::npos);
}

// Тестирование отображения информации о платеже
TEST(PaymentTest, ShowInfoTest) {
    Payment p(100.0, "2024-12-14", "Bank Transfer");
    testing::internal::CaptureStdout();
    p.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Платеж: Сумма - 100, Дата - 2024-12-14, Способ оплаты - Bank Transfer"), std::string::npos);
}