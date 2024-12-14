#include <gtest/gtest.h>
#include "pch.h"
#include "../ppois22/TrainingGroup.h"
#include "../ppois22/TrainingGroup.cpp"
#include "../ppois22/Member.h"
#include "../ppois22/Membership.h"

TEST(TrainingGroupTest, AddMemberTest) {
    Membership membership("Premium", 50.0, 12);  // ������� ��������
    Member member("Alice", 20);
    member.registerInClub(&membership);  // ������������ ����� � �����
    TrainingGroup group("Yoga Class", &member);  // ������� ������ � ����������
    testing::internal::CaptureStdout();
    group.addMember(&member);  // ��������� ��������� � ������ (���� �� ��� �������� � ������������)
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("�������� �������� � ������: Yoga Class"), std::string::npos);
}

// ������������ �������� ��������� �� ������
TEST(TrainingGroupTest, RemoveMemberTest) {
    Membership membership("Standard", 30.0, 6);  // ������� ��������
    Member member("Bob", 35);
    member.registerInClub(&membership);  // ������������ ����� � �����
    TrainingGroup group("Pilates Class", &member);  // ������� ������ � ����������
    testing::internal::CaptureStdout();
    group.removeMember(&member);  // ������� ��������� �� ������
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("�������� ������ �� ������: Pilates Class"), std::string::npos);
}

// ������������ ����������� ���������� � ������
TEST(TrainingGroupTest, ShowInfoTest) {
    Membership membership1("Premium", 50.0, 12);  // ������� �������� ��� ������� ���������
    Membership membership2("Standard", 30.0, 6);  // ������� �������� ��� ������� ���������
    Member member1("Charlie", 18);
    Member member2("David", 20);
    member1.registerInClub(&membership1);  // ������������ ������� �����
    member2.registerInClub(&membership2);  // ������������ ������� �����
    TrainingGroup group("Crossfit Class", &member1);  // ������� ������ � ������ ����������
    group.addMember(&member2);  // ��������� ������� ��������� � ������
    testing::internal::CaptureStdout();
    group.showInfo();  // ���������� ���������� � ������
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������: Crossfit Class, ����������: 2"), std::string::npos);
}