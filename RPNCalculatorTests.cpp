#include "RPNCalculator.h"
#include <gtest/gtest.h>

class RPNCalculatorTest : public ::testing::Test {
protected:
    RPNCalculator<int> calculator;
};

TEST_F(RPNCalculatorTest, AddTest) {
    calculator.push(2);
    calculator.push(3);
    calculator.add();
    EXPECT_EQ(calculator.value(), 5);
}

TEST_F(RPNCalculatorTest, SubtractTest) {
    calculator.push(5);
    calculator.push(3);
    calculator.subtract();
    EXPECT_EQ(calculator.value(), 2);
}

TEST_F(RPNCalculatorTest, MultiplyTest) {
    calculator.push(2);
    calculator.push(3);
    calculator.multiply();
    EXPECT_EQ(calculator.value(), 6);
}

TEST_F(RPNCalculatorTest, DivideTest) {
    calculator.push(6);
    calculator.push(3);
    calculator.divide();
    EXPECT_EQ(calculator.value(), 2);
}

TEST_F(RPNCalculatorTest, SquareTest) {
    calculator.push(4);
    calculator.square();
    EXPECT_EQ(calculator.value(), 16);
}

TEST_F(RPNCalculatorTest, NegateTest) {
    calculator.push(5);
    calculator.negate();
    EXPECT_EQ(calculator.value(), -5);
}

TEST_F(RPNCalculatorTest, ClearTest) {
    calculator.push(5);
    calculator.clear();
    EXPECT_TRUE(calculator.isEmpty());
}

TEST_F(RPNCalculatorTest, PopTest) {
    calculator.push(5);
    EXPECT_EQ(calculator.pop(), 5);
    EXPECT_TRUE(calculator.isEmpty());
}

TEST_F(RPNCalculatorTest, ValueTest) {
    calculator.push(5);
    EXPECT_EQ(calculator.value(), 5);
}

TEST_F(RPNCalculatorTest, IsEmptyTest) {
    EXPECT_TRUE(calculator.isEmpty());
    calculator.push(5);
    EXPECT_FALSE(calculator.isEmpty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}