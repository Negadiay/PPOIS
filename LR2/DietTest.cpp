#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois22/Diet.h"
#include "../ppois22/Diet.cpp"

// ������������ �������� �����
TEST(DietTest, CreateDiet) {
    Diet diet("Healthy Diet", { "Fruits", "Vegetables", "Whole grains" }, "Balanced nutrition");
    testing::internal::CaptureStdout();
    diet.createDiet();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Healthy Diet"), std::string::npos);
}

// ������������ ��������� ������������
TEST(DietTest, ModifyRecommendations) {
    Diet diet("Weight Loss Diet", { "Lean protein", "Leafy greens", "Nuts" }, "Low calorie intake");
    testing::internal::CaptureStdout();
    diet.modifyRecommendations();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Weight Loss Diet"), std::string::npos);
}

// ������������ ����������� ���������� � �����
TEST(DietTest, ShowInfo) {
    Diet diet("Balanced Diet", { "Proteins", "Carbohydrates", "Fats" }, "Healthy choices");
    testing::internal::CaptureStdout();
    diet.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Balanced Diet"), std::string::npos);
}