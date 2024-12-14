#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois22/Competition.h"
#include "../ppois22/Competition.cpp"
#include "../ppois22/Member.h"
#include "../ppois22/Member.cpp"


// ������������ ����������� ��������� �� ������������
TEST(CompetitionTest, RegisterParticipantTest) {
    Competition competition("Marathon", "2024-12-15", 1000.0);
    Member member("Alice", 20);
    testing::internal::CaptureStdout();
    competition.registerParticipant(&member);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("���� ����� ��������������� �� ������������: Marathon"), std::string::npos);
}

// ������������ ���������� ����������� ������������
TEST(CompetitionTest, PublishResultsTest) {
    Competition competition("Swimming Competition", "2024-12-20", 1500.0);
    testing::internal::CaptureStdout();
    competition.publishResults();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("���������� ������������ \"Swimming Competition\" ������������."), std::string::npos);
}

// ������������ ������ ������������
TEST(CompetitionTest, CancelCompetitionTest) {
    Competition competition("Chess Tournament", "2024-12-10", 800.0);
    testing::internal::CaptureStdout();
    competition.cancelCompetition();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������������ \"Chess Tournament\" ��������."), std::string::npos);
}

// ������������ ����������� ���������� � ������������
TEST(CompetitionTest, ShowInfoTest) {
    Competition competition("Running Race", "2024-12-25", 1200.0);
    testing::internal::CaptureStdout();
    competition.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������������: Running Race, ����: 2024-12-25, �������� ����: 1200"), std::string::npos);
}
