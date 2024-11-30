#include <gtest/gtest.h>
#include "Rectangle.h"

// Тестирование конструктора по умолчанию
TEST(RectangleTests, DefaultConstructor) {
    Rectangle r;
    EXPECT_EQ(r.getBottomLeft().x, 0);
    EXPECT_EQ(r.getBottomLeft().y, 0);
    EXPECT_EQ(r.getTopRight().x, 1);
    EXPECT_EQ(r.getTopRight().y, 1);
}

// Тестирование параметризованного конструктора
TEST(RectangleTests, ParameterizedConstructor) {
    Rectangle r(2, 3, 4, 5);
    EXPECT_EQ(r.getBottomLeft().x, 2);
    EXPECT_EQ(r.getBottomLeft().y, 3);
    EXPECT_EQ(r.getTopRight().x, 7); // 2 + 5
    EXPECT_EQ(r.getTopRight().y, 7); // 3 + 4
}

// Тестирование перемещения прямоугольника
TEST(RectangleTests, SetNewLocation) {
    Rectangle r(2, 3, 4, 5);
    r.setNewLocation(10, 15);
    EXPECT_EQ(r.getBottomLeft().x, 10);
    EXPECT_EQ(r.getBottomLeft().y, 15);
}

// Тестирование изменения ширины
TEST(RectangleTests, ChangeWidth) {
    Rectangle r(0, 0, 4, 5);
    r.changeWidth(10);
    EXPECT_EQ(r.getTopRight().y, 10); // Новая ширина (высота)
}

// Тестирование изменения длины
TEST(RectangleTests, ChangeLength) {
    Rectangle r(0, 0, 4, 5);
    r.changeLength(8);
    EXPECT_EQ(r.getTopRight().x, 8); // Новая длина
}

// Тестирование оператора сложения
TEST(RectangleTests, AdditionOperator) {
    Rectangle r1(0, 0, 4, 5);
    Rectangle r2(0, 0, 3, 6);
    Rectangle result = r1 + r2;

    EXPECT_EQ(result.getBottomLeft().x, 0);
    EXPECT_EQ(result.getBottomLeft().y, 0);
    EXPECT_GE(result.getTopRight().x, r1.getTopRight().x); // Увеличенная длина
    EXPECT_GE(result.getTopRight().y, r1.getTopRight().y); // Увеличенная высота
}

// Тестирование оператора сравнения
TEST(RectangleTests, EqualityOperator) {
    Rectangle r1(0, 0, 4, 5);
    Rectangle r2(0, 0, 4, 5);
    Rectangle r3(0, 0, 3, 6);

    EXPECT_TRUE(r1 == r2);
    EXPECT_FALSE(r1 == r3);
}

// Тестирование оператора неравенства
TEST(RectangleTests, InequalityOperator) {
    Rectangle r1(0, 0, 4, 5);
    Rectangle r2(0, 0, 3, 6);

    EXPECT_TRUE(r1 != r2);
}

// Тестирование префиксного оператора увеличения
TEST(RectangleTests, PrefixIncrement) {
    Rectangle r(0, 0, 4, 5);
    ++r;
    EXPECT_EQ(r.getTopRight().x, 6); // Длина увеличена
    EXPECT_EQ(r.getTopRight().y, 5); // Высота увеличена
}

// Тестирование постфиксного оператора уменьшения
TEST(RectangleTests, PostfixDecrement) {
    Rectangle r(0, 0, 4, 5);
    r--;
    EXPECT_EQ(r.getTopRight().x, 4); // Длина уменьшена
    EXPECT_EQ(r.getTopRight().y, 3); // Высота уменьшена
}

// Тестирование ввода и вывода
TEST(RectangleTests, InputOutputOperators) {
    Rectangle r;
    std::istringstream input("1 2 3 4");
    input >> r;

    EXPECT_EQ(r.getBottomLeft().x, 1);
    EXPECT_EQ(r.getBottomLeft().y, 2);
    EXPECT_EQ(r.getTopRight().x, 5); // 1 + 4
    EXPECT_EQ(r.getTopRight().y, 5); // 2 + 3
}

// Тестирование оператора вычитания
TEST(RectangleTests, SubtractionOperator) {
    Rectangle r1(0, 0, 4, 5);
    Rectangle r2(0, 0, 2, 3);
    Rectangle result = r1 - r2;

    EXPECT_EQ(result.getBottomLeft().x, 0);
    EXPECT_EQ(result.getBottomLeft().y, 0);
    EXPECT_EQ(result.getTopRight().x, 5); // Минимальная длина
    EXPECT_EQ(result.getTopRight().y, 4); // Минимальная высота
}
