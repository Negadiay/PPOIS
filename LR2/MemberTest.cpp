#include <gtest/gtest.h>
#include "pch.h"
#include "../ppois22/Member.h"
#include "../ppois22/Membership.h"

TEST(MemberTest, RegisterInClubTest) {
    Membership m("Gold", 100.0, 30);
    Member member("Alice", 25);
    member.registerInClub(&m);
    EXPECT_TRUE(member.getMembership() != nullptr);
}

TEST(MemberTest, CancelMembershipTest) {
    Membership m("Silver", 50.0, 30);
    Member member("Bob", 30);
    member.registerInClub(&m);
    member.cancelMembership();
    EXPECT_TRUE(member.getMembership() == nullptr);
}

// Run all the tests for Member
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}