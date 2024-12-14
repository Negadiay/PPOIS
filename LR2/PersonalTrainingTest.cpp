#include <gtest/gtest.h>
#include "pch.h"
#include "../ppois22/PersonalTraining.h"
#include "../ppois22/PersonalTraining.cpp"
#include "../ppois22/Member.h"
#include "../ppois22/Coach.h"

// ������������ ���������� ������������ ����������
TEST(PersonalTrainingTest, ScheduleTrainingTest) {
    Member client("Alice", 30);
    Coach coach("Bob", "Fitness", 5);
    PersonalTraining pt(&client, &coach, "2024-12-12 10:00");
    testing::internal::CaptureStdout();
    pt.scheduleTraining();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������������ ���������� ��������� ��: 2024-12-12 10:00"), std::string::npos);
}

// ������������ �������� ������������ ����������
TEST(PersonalTrainingTest, RescheduleTrainingTest) {
    Member client("Bob", 25);
    Coach coach("Alice", "Yoga", 10);
    PersonalTraining pt(&client, &coach, "2024-12-13 15:00");
    pt.rescheduleTraining("2024-12-14 16:00");
    EXPECT_EQ(pt.getDateTime(), "2024-12-14 16:00");
}

// ������������ ����������� ���������� � ������������ ����������
TEST(PersonalTrainingTest, ShowInfoTest) {
    Member client("Charlie", 35);
    Coach coach("David", "Crossfit", 8);
    PersonalTraining pt(&client, &coach, "2024-12-15 08:00");
    testing::internal::CaptureStdout();
    pt.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������: Charlie, ������: David, ���� � ����� ����������: 2024-12-15 08:00"), std::string::npos);
}