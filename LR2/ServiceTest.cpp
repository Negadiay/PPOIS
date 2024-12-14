#include <gtest/gtest.h>
#include "pch.h"
#include "../ppois22/Service.h"
#include "../ppois22/Service.cpp"

// Тестирование добавления услуги
TEST(ServiceTest, AddServiceTest) {
    Service service("Haircut", 25.0);
    testing::internal::CaptureStdout();
    service.addService();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Услуга \"Haircut\" добавлена."), std::string::npos);
}

// Тестирование удаления услуги
TEST(ServiceTest, RemoveServiceTest) {
    Service service("Massage", 50.0);
    testing::internal::CaptureStdout();
    service.removeService();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Услуга \"Massage\" удалена."), std::string::npos);
}

// Тестирование отображения информации об услуге
TEST(ServiceTest, ShowInfoTest) {
    Service service("Facial", 35.0);
    testing::internal::CaptureStdout();
    service.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Услуга: Facial, Стоимость: 35"), std::string::npos);
}