#include <gtest/gtest.h>
#include "pch.h"
#include "../ppois22/Administrator.h"
#include "../ppois22/Administrator.cpp"
#include "../ppois22/Member.h"
#include "../ppois22/Coach.h"


// ����� ��� processClientRequest
TEST(AdministratorTests, ProcessClientRequestOutput) {
    // ����������� ����� ������
    testing::internal::CaptureStdout();

    Administrator admin("John Doe", "9:00 - 17:00");
    admin.processClientRequest();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "��������� ������� �������.\n");
}

// ����� ��� assignTrainerToSession
TEST(AdministratorTests, AssignTrainerToSessionOutput) {
    // ����������� ����� ������
    testing::internal::CaptureStdout();

    Administrator admin("����� �����", "9:00 - 17:00");
    admin.assignTrainerToSession();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "���������� ������� �� ����������.\n");
}

// ����� ��� showInfo
TEST(AdministratorTests, ShowInfoOutput) {
    // ����������� ����� ������
    testing::internal::CaptureStdout();

    Administrator admin("����� �����", "9:00 - 17:00");
    admin.showInfo();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "�������������: ����� �����, ������ ������: 9:00 - 17:00\n");
}
