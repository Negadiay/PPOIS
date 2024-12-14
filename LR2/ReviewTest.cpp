#include <gtest/gtest.h>
#include "pch.h"
#include "../ppois22/Review.h"
#include "../ppois22/Review.cpp"

// Тестирование оставления отзыва
TEST(ReviewTest, LeaveReviewTest) {
    Review r("Alice", "Great service!");
    testing::internal::CaptureStdout();
    r.leaveReview();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Отзыв от Alice: Great service!"), std::string::npos);
}

// Тестирование удаления отзыва
TEST(ReviewTest, DeleteReviewTest) {
    Review r("Bob", "Not satisfied with the product.");
    testing::internal::CaptureStdout();
    r.deleteReview();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Отзыв удален."), std::string::npos);
}

// Тестирование отображения информации об отзыве
TEST(ReviewTest, ShowInfoTest) {
    Review r("Charlie", "Excellent experience!");
    testing::internal::CaptureStdout();
    r.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Отзыв от Charlie: Excellent experience!"), std::string::npos);
}