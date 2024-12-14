#include <gtest/gtest.h>
#include "pch.h"
#include "../ppois22/Training.h"
#include "../ppois22/Training.cpp"

// ������������ ������ ����� ����� �� ����������
TEST(TrainingTest, EnrollMemberTest) {
    Training training("Yoga", 60, 15);
    testing::internal::CaptureStdout();
    training.enrollMember();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("���� ����� ������� �� ����������: Yoga"), std::string::npos);
}

// ������������ ������ ����������
TEST(TrainingTest, CancelTrainingTest) {
    Training training("Pilates", 45, 10);
    testing::internal::CaptureStdout();
    training.cancelTraining();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("���������� Pilates ��������."), std::string::npos);
}

// ������������ ����������� ���������� � ����������
TEST(TrainingTest, ShowInfoTest) {
    Training training("Crossfit", 75, 20);
    testing::internal::CaptureStdout();
    training.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("��� ����������: Crossfit, �����������������: 75 �����, �������� ����������: 20"), std::string::npos);
}