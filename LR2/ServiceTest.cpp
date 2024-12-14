#include <gtest/gtest.h>
#include "pch.h"
#include "../ppois22/Service.h"
#include "../ppois22/Service.cpp"

// ������������ ���������� ������
TEST(ServiceTest, AddServiceTest) {
    Service service("Haircut", 25.0);
    testing::internal::CaptureStdout();
    service.addService();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������ \"Haircut\" ���������."), std::string::npos);
}

// ������������ �������� ������
TEST(ServiceTest, RemoveServiceTest) {
    Service service("Massage", 50.0);
    testing::internal::CaptureStdout();
    service.removeService();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������ \"Massage\" �������."), std::string::npos);
}

// ������������ ����������� ���������� �� ������
TEST(ServiceTest, ShowInfoTest) {
    Service service("Facial", 35.0);
    testing::internal::CaptureStdout();
    service.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������: Facial, ���������: 35"), std::string::npos);
}