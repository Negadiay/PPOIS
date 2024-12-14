#include <gtest/gtest.h>
#include "pch.h"
#include "../ppois22/Training.h"
#include "../ppois22/Training.cpp"

// Тестирование записи члена клуба на тренировку
TEST(TrainingTest, EnrollMemberTest) {
    Training training("Yoga", 60, 15);
    testing::internal::CaptureStdout();
    training.enrollMember();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Член клуба записан на тренировку: Yoga"), std::string::npos);
}

// Тестирование отмены тренировки
TEST(TrainingTest, CancelTrainingTest) {
    Training training("Pilates", 45, 10);
    testing::internal::CaptureStdout();
    training.cancelTraining();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Тренировка Pilates отменена."), std::string::npos);
}

// Тестирование отображения информации о тренировке
TEST(TrainingTest, ShowInfoTest) {
    Training training("Crossfit", 75, 20);
    testing::internal::CaptureStdout();
    training.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Тип тренировки: Crossfit, Продолжительность: 75 минут, Максимум участников: 20"), std::string::npos);
}