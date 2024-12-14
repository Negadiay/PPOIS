#include <gtest/gtest.h>
#include "pch.h"
#include "../ppois22/Payment.h"
#include "../ppois22/Payment.cpp"

// ������������ ��������� �������
TEST(PaymentTest, ProcessPaymentTest) {
    Payment p(50.0, "2024-12-12", "Credit Card");
    testing::internal::CaptureStdout();
    p.processPayment();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������ �� ����� 50 ��������."), std::string::npos);
}

// ������������ ������ �������
TEST(PaymentTest, CancelPaymentTest) {
    Payment p(30.0, "2024-12-13", "PayPal");
    testing::internal::CaptureStdout();
    p.cancelPayment();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������ �� ����� 30 �������."), std::string::npos);
}

// ������������ ����������� ���������� � �������
TEST(PaymentTest, ShowInfoTest) {
    Payment p(100.0, "2024-12-14", "Bank Transfer");
    testing::internal::CaptureStdout();
    p.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������: ����� - 100, ���� - 2024-12-14, ������ ������ - Bank Transfer"), std::string::npos);
}