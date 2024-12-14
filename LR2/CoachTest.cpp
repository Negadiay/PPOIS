#include <gtest/gtest.h>
#include "pch.h"
#include "../ppois22/Coach.h"
#include "../ppois22/Coach.cpp"

// Тесты конструктора
TEST(CoachTest, ConstructorInitializesFields) {
    Coach coach("Иван Иванов", "Фитнес", 10);

    EXPECT_EQ(coach.getName(), "Иван Иванов");
    EXPECT_EQ(coach.getSpecialization(), "Фитнес");
    EXPECT_EQ(coach.getExperience(), 10);
}

// Тест метода conductTraining
TEST(CoachTest, ConductTrainingDoesNotCrash) {
    Coach coach("Иван Иванов", "Фитнес", 10);
    EXPECT_NO_THROW(coach.conductTraining());
}

// Тест метода developPlan
TEST(CoachTest, DevelopPlanDoesNotCrash) {
    Coach coach("Иван Иванов", "Фитнес", 10);
    EXPECT_NO_THROW(coach.developPlan());
}

// Тест метода evaluateProgress
TEST(CoachTest, EvaluateProgressDoesNotCrash) {
    Coach coach("Иван Иванов", "Фитнес", 10);
    EXPECT_NO_THROW(coach.evaluateProgress());
}

// Тест метода showInfo
TEST(CoachTest, ShowInfoOutputsInfo) {
    Coach coach("Иван Иванов", "Фитнес", 10);
    testing::internal::CaptureStdout();
    coach.showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_FALSE(output.empty());
    EXPECT_NE(output.find("Иван Иванов"), std::string::npos);
    EXPECT_NE(output.find("Фитнес"), std::string::npos);
    EXPECT_NE(output.find("10"), std::string::npos);
}

// Тест метода getName
TEST(CoachTest, GetNameReturnsCorrectName) {
    Coach coach("Иван Иванов", "Фитнес", 10);
    EXPECT_EQ(coach.getName(), "Иван Иванов");
}

// Тест метода getSpecialization
TEST(CoachTest, GetSpecializationReturnsCorrectSpecialization) {
    Coach coach("Иван Иванов", "Фитнес", 10);
    EXPECT_EQ(coach.getSpecialization(), "Фитнес");
}

// Тест метода getExperience
TEST(CoachTest, GetExperienceReturnsCorrectExperience) {
    Coach coach("Иван Иванов", "Фитнес", 10);
    EXPECT_EQ(coach.getExperience(), 10);
}
