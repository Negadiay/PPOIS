#include "pch.h"
#include "../ppois11/Rectangle.h"
#include "../ppois11/Rectangle.cpp"

TEST(RectangleTest, DefaultConstructor) {
    Rectangle rect;
    EXPECT_EQ(rect.getBottomLeft().x, 0);
    EXPECT_EQ(rect.getBottomLeft().y, 0);
    EXPECT_EQ(rect.getTopRight().x, 1);
    EXPECT_EQ(rect.getTopRight().y, 1);
}

TEST(RectangleTest, ParameterizedConstructor) {
    Rectangle rect(1, 2, 3, 4);
    EXPECT_EQ(rect.getBottomLeft().x, 1);
    EXPECT_EQ(rect.getBottomLeft().y, 2);
    EXPECT_EQ(rect.getTopRight().x, 5);
    EXPECT_EQ(rect.getTopRight().y, 5);
}

TEST(RectangleTest, CopyConstructor) {
    Rectangle rect1(1, 2, 3, 4);
    Rectangle rect2(rect1);
    EXPECT_EQ(rect2.getBottomLeft().x, 1);
    EXPECT_EQ(rect2.getBottomLeft().y, 2);
    EXPECT_EQ(rect2.getTopRight().x, 5);
    EXPECT_EQ(rect2.getTopRight().y, 5);
}

TEST(RectangleTest, SetNewLocation) {
    Rectangle rect;
    rect.setNewLocation(5, 6);
    EXPECT_EQ(rect.getBottomLeft().x, 5);
    EXPECT_EQ(rect.getBottomLeft().y, 6);
}

TEST(RectangleTest, ChangeHeight) {
    Rectangle rect;
    rect.changeHeight(10);
    EXPECT_EQ(rect.getTopLeft().y, 10);
}

TEST(RectangleTest, ChangeLength) {
    Rectangle rect;
    rect.changeLength(15);
    EXPECT_EQ(rect.getBottomRight().x, 15);
}

TEST(RectangleTest, IncrementDecrementOperators) {
    Rectangle rect(0, 0, 3, 4);
    rect++;
    EXPECT_EQ(rect.getTopRight().x, 5);
    EXPECT_EQ(rect.getTopRight().y, 4);

    rect--;
    EXPECT_EQ(rect.getTopRight().x, 4);
    EXPECT_EQ(rect.getTopRight().y, 3);
}

TEST(RectangleTest, EqualityOperators) {
    Rectangle rect1(0, 0, 3, 4);
    Rectangle rect2(0, 0, 3, 4);
    Rectangle rect3(0, 0, 5, 6);

    EXPECT_TRUE(rect1 == rect2);
    EXPECT_FALSE(rect1 == rect3);
    EXPECT_TRUE(rect1 != rect3);
    EXPECT_FALSE(rect1 != rect2);
}

TEST(RectangleTests, AdditionOperator) {
    Rectangle r1(0, 0, 4, 5);
    Rectangle r2(0, 0, 3, 6);
    Rectangle result = r1 + r2;

    EXPECT_EQ(result.getBottomLeft().x, 0);
    EXPECT_EQ(result.getBottomLeft().y, 0);
    EXPECT_GE(result.getTopRight().x, r1.getTopRight().x);
    EXPECT_GE(result.getTopRight().y, r1.getTopRight().y);
}

TEST(RectangleTest, SubtractionOperators) {
    Rectangle rect1(0, 0, 5, 6);
    Rectangle rect2(0, 0, 3, 4);

    Rectangle rect3 = rect1 - rect2;
    EXPECT_EQ(rect3.getTopRight().x, 4);
    EXPECT_EQ(rect3.getTopRight().y, 3);

    rect1 -= rect2;
    EXPECT_EQ(rect1.getTopRight().x, 4);
    EXPECT_EQ(rect1.getTopRight().y, 3);
}

TEST(RectangleTest, IOOperators) {
    Rectangle rect;
    std::istringstream input("1 2 3 4");
    input >> rect;

    EXPECT_EQ(rect.getBottomLeft().x, 1);
    EXPECT_EQ(rect.getBottomLeft().y, 2);
    EXPECT_EQ(rect.getTopRight().x, 5);
    EXPECT_EQ(rect.getTopRight().y, 5);

    std::ostringstream output;
    output << rect;
    std::string expected = "Координата x: 1\nКоордината y: 2\nВысота: 3\nДлина: 4\n";
    EXPECT_EQ(output.str(), expected);
}

TEST(RectangleTests, PrefixIncrement) {
    Rectangle r(0, 0, 4, 5);
    ++r;
    EXPECT_EQ(r.getTopRight().x, 6);
    EXPECT_EQ(r.getTopRight().y, 5);
}

TEST(RectangleTests, PostfixDecrement) {
    Rectangle r(0, 0, 4, 3);
    --r;
    EXPECT_EQ(r.getTopRight().x, 2);
    EXPECT_EQ(r.getTopRight().y, 3);
}
