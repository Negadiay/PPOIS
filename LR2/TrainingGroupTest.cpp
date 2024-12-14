#include <gtest/gtest.h>
#include "pch.h"
#include "../ppois22/TrainingGroup.h"
#include "../ppois22/TrainingGroup.cpp"
#include "../ppois22/Member.h"
#include "../ppois22/Membership.h"

TEST(TrainingGroupTest, AddMemberTest) {
    Membership membership("Premium", 50.0, 12);  // Создаем членство
    Member member("Alice", 20);
    member.registerInClub(&membership);  // Регистрируем члена в клубе
    TrainingGroup group("Yoga Class", &member);  // Создаем группу с участником
    testing::internal::CaptureStdout();
    group.addMember(&member);  // Добавляем участника в группу (хотя он уже добавлен в конструкторе)
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Участник добавлен в группу: Yoga Class"), std::string::npos);
}

// Тестирование удаления участника из группы
TEST(TrainingGroupTest, RemoveMemberTest) {
    Membership membership("Standard", 30.0, 6);  // Создаем членство
    Member member("Bob", 35);
    member.registerInClub(&membership);  // Регистрируем члена в клубе
    TrainingGroup group("Pilates Class", &member);  // Создаем группу с участником
    testing::internal::CaptureStdout();
    group.removeMember(&member);  // Удаляем участника из группы
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Участник удален из группы: Pilates Class"), std::string::npos);
}

// Тестирование отображения информации о группе
TEST(TrainingGroupTest, ShowInfoTest) {
    Membership membership1("Premium", 50.0, 12);  // Создаем членство для первого участника
    Membership membership2("Standard", 30.0, 6);  // Создаем членство для второго участника
    Member member1("Charlie", 18);
    Member member2("David", 20);
    member1.registerInClub(&membership1);  // Регистрируем первого члена
    member2.registerInClub(&membership2);  // Регистрируем второго члена
    TrainingGroup group("Crossfit Class", &member1);  // Создаем группу с первым участником
    group.addMember(&member2);  // Добавляем второго участника в группу
    testing::internal::CaptureStdout();
    group.showInfo();  // Отображаем информацию о группе
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Группа: Crossfit Class, Участников: 2"), std::string::npos);
}