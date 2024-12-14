#include <gtest/gtest.h>
#include "pch.h"
#include "../ppois22/Calendar.h"
#include "../ppois22/Calendar.cpp"

// ���� ������������
TEST(CalendarTest, Constructor) {
    Calendar cal("2024-12-11");
    testing::internal::CaptureStdout(); // �������� ������ � �������
    cal.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("2024-12-11") != std::string::npos); // ���������, ��� ���� ��������� ���������
}

// ���� ���������� �������
TEST(CalendarTest, AddEvent) {
    Calendar cal("2024-12-11");
    cal.addEvent("Meeting at 10 AM");
    cal.addEvent("Lunch at 1 PM");

    testing::internal::CaptureStdout(); // �������� ������
    cal.showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Meeting at 10 AM") != std::string::npos); // ���������, ��� ������� ���������
    EXPECT_TRUE(output.find("Lunch at 1 PM") != std::string::npos);    // ���������, ��� ������ ������� ���������
}

// ���� �������� �������
TEST(CalendarTest, RemoveEvent) {
    Calendar cal("2024-12-11");
    cal.addEvent("Meeting at 10 AM");
    cal.addEvent("Lunch at 1 PM");
    cal.removeEvent("Meeting at 10 AM"); // ������� �������

    testing::internal::CaptureStdout();
    cal.showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Meeting at 10 AM") == std::string::npos); // ���������, ��� ������� �������
    EXPECT_TRUE(output.find("Lunch at 1 PM") != std::string::npos);    // ���������, ��� ������ ������� ��������
}

// ���� ������ ������� �� ����
TEST(CalendarTest, FindEventByDate) {
    Calendar cal("2024-12-11");
    cal.addEvent("Meeting at 10 AM");
    cal.addEvent("Lunch at 1 PM");

    testing::internal::CaptureStdout();
    cal.findEventByDate("2024-12-11"); // ���� ������� �� ����
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Meeting at 10 AM") != std::string::npos); // ���������, ��� ������� �������
    EXPECT_TRUE(output.find("Lunch at 1 PM") != std::string::npos);    // ���������, ��� ������ ������� ���� �������
}

// ���� �� ������ ���������
TEST(CalendarTest, EmptyCalendar) {
    Calendar cal("2024-12-11");

    testing::internal::CaptureStdout();
    cal.showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("No events") != std::string::npos); // ���������, ��� ��� ������� ��������� ��������� ��������������� ���������
}