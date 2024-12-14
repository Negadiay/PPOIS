#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois22/GymEquipment.h"



// ������������ �������� ��������� ���������
TEST(GymEquipmentTest, CheckConditionTest) {
    GymEquipment equipment("Treadmill", "Cardio");
    testing::internal::CaptureStdout();
    equipment.checkCondition();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("�������� Treadmill � ������� ���������"), std::string::npos);
}

// ������������ ������� ���������
TEST(GymEquipmentTest, RepairTest) {
    GymEquipment equipment("Treadmill", "Cardio");
    equipment.repair();
    EXPECT_TRUE(equipment.getIsWorking());
}

// ������������ ����������� ���������� � ���������
TEST(GymEquipmentTest, ShowInfoTest) {
    GymEquipment equipment("Bench Press", "Strength");
    testing::internal::CaptureStdout();
    equipment.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("��������: Bench Press, ���: Strength, ���������: ��������"), std::string::npos);
}