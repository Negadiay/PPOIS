#include <gtest/gtest.h>
#include "Rectangle.h"

// ������������ ������������ �� ���������
TEST(RectangleTests, DefaultConstructor) {
    Rectangle r;
    EXPECT_EQ(r.getBottomLeft().x, 0);
    EXPECT_EQ(r.getBottomLeft().y, 0);
    EXPECT_EQ(r.getTopRight().x, 1);
    EXPECT_EQ(r.getTopRight().y, 1);
}

// ������������ ������������������ ������������
TEST(RectangleTests, ParameterizedConstructor) {
    Rectangle r(2, 3, 4, 5);
    EXPECT_EQ(r.getBottomLeft().x, 2);
    EXPECT_EQ(r.getBottomLeft().y, 3);
    EXPECT_EQ(r.getTopRight().x, 7); // 2 + 5
    EXPECT_EQ(r.getTopRight().y, 7); // 3 + 4
}

// ������������ ����������� ��������������
TEST(RectangleTests, SetNewLocation) {
    Rectangle r(2, 3, 4, 5);
    r.setNewLocation(10, 15);
    EXPECT_EQ(r.getBottomLeft().x, 10);
    EXPECT_EQ(r.getBottomLeft().y, 15);
}

// ������������ ��������� ������
TEST(RectangleTests, ChangeWidth) {
    Rectangle r(0, 0, 4, 5);
    r.changeWidth(10);
    EXPECT_EQ(r.getTopRight().y, 10); // ����� ������ (������)
}

// ������������ ��������� �����
TEST(RectangleTests, ChangeLength) {
    Rectangle r(0, 0, 4, 5);
    r.changeLength(8);
    EXPECT_EQ(r.getTopRight().x, 8); // ����� �����
}

// ������������ ��������� ��������
TEST(RectangleTests, AdditionOperator) {
    Rectangle r1(0, 0, 4, 5);
    Rectangle r2(0, 0, 3, 6);
    Rectangle result = r1 + r2;

    EXPECT_EQ(result.getBottomLeft().x, 0);
    EXPECT_EQ(result.getBottomLeft().y, 0);
    EXPECT_GE(result.getTopRight().x, r1.getTopRight().x); // ����������� �����
    EXPECT_GE(result.getTopRight().y, r1.getTopRight().y); // ����������� ������
}

// ������������ ��������� ���������
TEST(RectangleTests, EqualityOperator) {
    Rectangle r1(0, 0, 4, 5);
    Rectangle r2(0, 0, 4, 5);
    Rectangle r3(0, 0, 3, 6);

    EXPECT_TRUE(r1 == r2);
    EXPECT_FALSE(r1 == r3);
}

// ������������ ��������� �����������
TEST(RectangleTests, InequalityOperator) {
    Rectangle r1(0, 0, 4, 5);
    Rectangle r2(0, 0, 3, 6);

    EXPECT_TRUE(r1 != r2);
}

// ������������ ����������� ��������� ����������
TEST(RectangleTests, PrefixIncrement) {
    Rectangle r(0, 0, 4, 5);
    ++r;
    EXPECT_EQ(r.getTopRight().x, 6); // ����� ���������
    EXPECT_EQ(r.getTopRight().y, 5); // ������ ���������
}

// ������������ ������������ ��������� ����������
TEST(RectangleTests, PostfixDecrement) {
    Rectangle r(0, 0, 4, 5);
    r--;
    EXPECT_EQ(r.getTopRight().x, 4); // ����� ���������
    EXPECT_EQ(r.getTopRight().y, 3); // ������ ���������
}

// ������������ ����� � ������
TEST(RectangleTests, InputOutputOperators) {
    Rectangle r;
    std::istringstream input("1 2 3 4");
    input >> r;

    EXPECT_EQ(r.getBottomLeft().x, 1);
    EXPECT_EQ(r.getBottomLeft().y, 2);
    EXPECT_EQ(r.getTopRight().x, 5); // 1 + 4
    EXPECT_EQ(r.getTopRight().y, 5); // 2 + 3
}

// ������������ ��������� ���������
TEST(RectangleTests, SubtractionOperator) {
    Rectangle r1(0, 0, 4, 5);
    Rectangle r2(0, 0, 2, 3);
    Rectangle result = r1 - r2;

    EXPECT_EQ(result.getBottomLeft().x, 0);
    EXPECT_EQ(result.getBottomLeft().y, 0);
    EXPECT_EQ(result.getTopRight().x, 5); // ����������� �����
    EXPECT_EQ(result.getTopRight().y, 4); // ����������� ������
}
