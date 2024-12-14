#include <gtest/gtest.h>
#include "pch.h"
#include "../ppois22/Membership.h"
#include "../ppois22/Membership.cpp"
#include "../ppois22/Member.h"


TEST(MembershipTest, RenewTest) {
    Membership m("Gold", 100.0, 30);
    m.renew();
    EXPECT_EQ(m.getDuration(), 60);
}

TEST(MembershipTest, FreezeTest) {
    Membership m("Silver", 50.0, 30);
    m.freeze();
    // Add suitable expectations for freeze functionality
}

// Run all the tests for Membership
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}