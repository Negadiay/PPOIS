#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois22/Competition.h"
#include "../ppois22/Competition.cpp"
#include "../ppois22/Member.h"
#include "../ppois22/Member.cpp"


// Тестирование регистрации участника на соревнование
TEST(CompetitionTest, RegisterParticipantTest) {
    Competition competition("Marathon", "2024-12-15", 1000.0);
    Member member("Alice", 20);
    testing::internal::CaptureStdout();
    competition.registerParticipant(&member);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Член клуба зарегистрирован на соревнование: Marathon"), std::string::npos);
}

// Тестирование публикации результатов соревнования
TEST(CompetitionTest, PublishResultsTest) {
    Competition competition("Swimming Competition", "2024-12-20", 1500.0);
    testing::internal::CaptureStdout();
    competition.publishResults();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Результаты соревнования \"Swimming Competition\" опубликованы."), std::string::npos);
}

// Тестирование отмены соревнования
TEST(CompetitionTest, CancelCompetitionTest) {
    Competition competition("Chess Tournament", "2024-12-10", 800.0);
    testing::internal::CaptureStdout();
    competition.cancelCompetition();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Соревнование \"Chess Tournament\" отменено."), std::string::npos);
}

// Тестирование отображения информации о соревновании
TEST(CompetitionTest, ShowInfoTest) {
    Competition competition("Running Race", "2024-12-25", 1200.0);
    testing::internal::CaptureStdout();
    competition.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Соревнование: Running Race, Дата: 2024-12-25, Призовой фонд: 1200"), std::string::npos);
}
