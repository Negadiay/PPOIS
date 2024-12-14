#include <gtest/gtest.h>
#include "pch.h"
#include "../ppois22/Calendar.h"
#include "../ppois22/Calendar.cpp"

// Тест конструктора
TEST(CalendarTest, Constructor) {
    Calendar cal("2024-12-11");
    testing::internal::CaptureStdout(); // Перехват вывода в консоль
    cal.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("2024-12-11") != std::string::npos); // Проверяем, что дата выводится корректно
}

// Тест добавления события
TEST(CalendarTest, AddEvent) {
    Calendar cal("2024-12-11");
    cal.addEvent("Meeting at 10 AM");
    cal.addEvent("Lunch at 1 PM");

    testing::internal::CaptureStdout(); // Перехват вывода
    cal.showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Meeting at 10 AM") != std::string::npos); // Проверяем, что событие добавлено
    EXPECT_TRUE(output.find("Lunch at 1 PM") != std::string::npos);    // Проверяем, что второе событие добавлено
}

// Тест удаления события
TEST(CalendarTest, RemoveEvent) {
    Calendar cal("2024-12-11");
    cal.addEvent("Meeting at 10 AM");
    cal.addEvent("Lunch at 1 PM");
    cal.removeEvent("Meeting at 10 AM"); // Удаляем событие

    testing::internal::CaptureStdout();
    cal.showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Meeting at 10 AM") == std::string::npos); // Проверяем, что событие удалено
    EXPECT_TRUE(output.find("Lunch at 1 PM") != std::string::npos);    // Проверяем, что другое событие осталось
}

// Тест поиска события по дате
TEST(CalendarTest, FindEventByDate) {
    Calendar cal("2024-12-11");
    cal.addEvent("Meeting at 10 AM");
    cal.addEvent("Lunch at 1 PM");

    testing::internal::CaptureStdout();
    cal.findEventByDate("2024-12-11"); // Ищем события по дате
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Meeting at 10 AM") != std::string::npos); // Проверяем, что событие найдено
    EXPECT_TRUE(output.find("Lunch at 1 PM") != std::string::npos);    // Проверяем, что второе событие тоже найдено
}

// Тест на пустой календарь
TEST(CalendarTest, EmptyCalendar) {
    Calendar cal("2024-12-11");

    testing::internal::CaptureStdout();
    cal.showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("No events") != std::string::npos); // Проверяем, что для пустого календаря выводится соответствующее сообщение
}