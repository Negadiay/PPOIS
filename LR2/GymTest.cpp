#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois22/Gym.h"
#include "../ppois22/Gym.cpp"
#include "../ppois22/GymEquipment.h"
#include "../ppois22/GymEquipment.cpp"

// Тестирование добавления тренажера в зал
TEST(GymTest, AddEquipmentTest) {
    Gym gym("Fitness Center", 10);
    GymEquipment equipment1("Treadmill", "Cardio");
    GymEquipment equipment2("Barbell", "Strength");

    testing::internal::CaptureStdout();
    gym.addEquipment(equipment1);
    std::string output1 = testing::internal::GetCapturedStdout();
    EXPECT_NE(output1.find("Тренажер добавлен в зал."), std::string::npos);

    testing::internal::CaptureStdout();
    gym.addEquipment(equipment2);
    std::string output2 = testing::internal::GetCapturedStdout();
    EXPECT_NE(output2.find("Тренажер добавлен в зал."), std::string::npos);
}

// Тестирование списка тренажеров в зале
TEST(GymTest, ListEquipmentsTest) {
    Gym gym("Fitness Center", 10);
    GymEquipment equipment1("Treadmill", "Cardio");
    gym.addEquipment(equipment1);

    testing::internal::CaptureStdout();
    gym.listEquipments();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Тренажеры в зале Fitness Center:"), std::string::npos);
    EXPECT_NE(output.find("Тренажер: Treadmill, Тип: Cardio"), std::string::npos);
}

// Тестирование проверки доступности тренажеров
TEST(GymTest, IsAvailableTest) {
    Gym gym("Fitness Center", 10);
    EXPECT_FALSE(gym.isAvailable()); // Проверка наличия тренажеров в начале

    GymEquipment equipment1("Treadmill", "Cardio");
    gym.addEquipment(equipment1);

    EXPECT_TRUE(gym.isAvailable()); // Проверка наличия тренажеров после добавления
}

// Тестирование отображения информации о зале
TEST(GymTest, ShowInfoTest) {
    Gym gym("Fitness Center", 10);
    GymEquipment equipment1("Treadmill", "Cardio");
    gym.addEquipment(equipment1);

    testing::internal::CaptureStdout();
    gym.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Название зала: Fitness Center"), std::string::npos);
    EXPECT_NE(output.find("Вместимость: 10"), std::string::npos);
    EXPECT_NE(output.find("Число тренажеров: 1"), std::string::npos);
}