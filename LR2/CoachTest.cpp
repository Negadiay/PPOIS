#include <gtest/gtest.h>
#include "pch.h"
#include "../ppois22/Coach.h"
#include "../ppois22/Coach.cpp"

// ����� ������������
TEST(CoachTest, ConstructorInitializesFields) {
    Coach coach("���� ������", "������", 10);

    EXPECT_EQ(coach.getName(), "���� ������");
    EXPECT_EQ(coach.getSpecialization(), "������");
    EXPECT_EQ(coach.getExperience(), 10);
}

// ���� ������ conductTraining
TEST(CoachTest, ConductTrainingDoesNotCrash) {
    Coach coach("���� ������", "������", 10);
    EXPECT_NO_THROW(coach.conductTraining());
}

// ���� ������ developPlan
TEST(CoachTest, DevelopPlanDoesNotCrash) {
    Coach coach("���� ������", "������", 10);
    EXPECT_NO_THROW(coach.developPlan());
}

// ���� ������ evaluateProgress
TEST(CoachTest, EvaluateProgressDoesNotCrash) {
    Coach coach("���� ������", "������", 10);
    EXPECT_NO_THROW(coach.evaluateProgress());
}

// ���� ������ showInfo
TEST(CoachTest, ShowInfoOutputsInfo) {
    Coach coach("���� ������", "������", 10);
    testing::internal::CaptureStdout();
    coach.showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_FALSE(output.empty());
    EXPECT_NE(output.find("���� ������"), std::string::npos);
    EXPECT_NE(output.find("������"), std::string::npos);
    EXPECT_NE(output.find("10"), std::string::npos);
}

// ���� ������ getName
TEST(CoachTest, GetNameReturnsCorrectName) {
    Coach coach("���� ������", "������", 10);
    EXPECT_EQ(coach.getName(), "���� ������");
}

// ���� ������ getSpecialization
TEST(CoachTest, GetSpecializationReturnsCorrectSpecialization) {
    Coach coach("���� ������", "������", 10);
    EXPECT_EQ(coach.getSpecialization(), "������");
}

// ���� ������ getExperience
TEST(CoachTest, GetExperienceReturnsCorrectExperience) {
    Coach coach("���� ������", "������", 10);
    EXPECT_EQ(coach.getExperience(), 10);
}
