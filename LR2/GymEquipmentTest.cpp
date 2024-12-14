#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois22/GymEquipment.h"



// Тестирование проверки состояния тренажера
TEST(GymEquipmentTest, CheckConditionTest) {
    GymEquipment equipment("Treadmill", "Cardio");
    testing::internal::CaptureStdout();
    equipment.checkCondition();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Тренажер Treadmill в хорошем состоянии"), std::string::npos);
}

// Тестирование ремонта тренажера
TEST(GymEquipmentTest, RepairTest) {
    GymEquipment equipment("Treadmill", "Cardio");
    equipment.repair();
    EXPECT_TRUE(equipment.getIsWorking());
}

// Тестирование отображения информации о тренажере
TEST(GymEquipmentTest, ShowInfoTest) {
    GymEquipment equipment("Bench Press", "Strength");
    testing::internal::CaptureStdout();
    equipment.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Тренажер: Bench Press, Тип: Strength, Состояние: Исправен"), std::string::npos);
}