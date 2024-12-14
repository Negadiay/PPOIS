#include <gtest/gtest.h>
#include "pch.h"
#include "../ppois22/Administrator.h"
#include "../ppois22/Administrator.cpp"
#include "../ppois22/Member.h"
#include "../ppois22/Coach.h"


// Тесты для processClientRequest
TEST(AdministratorTests, ProcessClientRequestOutput) {
    // Захватываем поток вывода
    testing::internal::CaptureStdout();

    Administrator admin("John Doe", "9:00 - 17:00");
    admin.processClientRequest();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Обработка запроса клиента.\n");
}

// Тесты для assignTrainerToSession
TEST(AdministratorTests, AssignTrainerToSessionOutput) {
    // Захватываем поток вывода
    testing::internal::CaptureStdout();

    Administrator admin("Павел Котко", "9:00 - 17:00");
    admin.assignTrainerToSession();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Назначение тренера на тренировку.\n");
}

// Тесты для showInfo
TEST(AdministratorTests, ShowInfoOutput) {
    // Захватываем поток вывода
    testing::internal::CaptureStdout();

    Administrator admin("Павел Котко", "9:00 - 17:00");
    admin.showInfo();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Администратор: Павел Котко, График работы: 9:00 - 17:00\n");
}
