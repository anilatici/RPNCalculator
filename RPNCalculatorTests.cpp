#include "RPNCalculator.h"
#include <gtest/gtest.h>

class RPNCalculatorTest : public ::testing::Test {
protected:
    RPNCalculator<double> calculator;
};

// START - TESTS FOR ADD FUNCTION

TEST_F(RPNCalculatorTest, AddTest) {
    calculator.push(2);
    calculator.push(3);
    calculator.add();
    EXPECT_EQ(calculator.value(), 5);
}

TEST_F(RPNCalculatorTest, AddTest2) {
    calculator.push(23.2);
    calculator.push(31.5);
    calculator.add();
    EXPECT_EQ(calculator.value(), 54.7);
}

TEST_F(RPNCalculatorTest, AddTest3) {
    calculator.push(-2.10);
    calculator.push(3.20);
    calculator.add();
    EXPECT_EQ(calculator.value(), 1.10);
}

TEST_F(RPNCalculatorTest, AddTest4) {
    calculator.push(-1.10);
    calculator.push(0);
    calculator.add();
    EXPECT_EQ(calculator.value(), -1.10);
}

TEST_F(RPNCalculatorTest, AddTest5) {
    calculator.push(00);
    calculator.push(0);
    calculator.add();
    EXPECT_EQ(calculator.value(), 0);
}

TEST_F(RPNCalculatorTest, AddTest6) {
    calculator.push(-23.10);
    calculator.push(5);
    calculator.add();
    EXPECT_EQ(calculator.value(), -18.10);
}

// END - TESTS FOR ADD FUNCTION

// START - TESTS FOR SUBTRACT FUNCTION

TEST_F(RPNCalculatorTest, SubtractTest) {
    calculator.push(5);
    calculator.push(3);
    calculator.subtract();
    EXPECT_EQ(calculator.value(), 2);
}

TEST_F(RPNCalculatorTest, SubtractTest1) {
    calculator.push(5);
    calculator.push(-3);
    calculator.subtract();
    EXPECT_EQ(calculator.value(), 8);
}

TEST_F(RPNCalculatorTest, SubtractTest2) {
    calculator.push(5);
    calculator.push(5);
    calculator.subtract();
    EXPECT_EQ(calculator.value(), 0);
}

TEST_F(RPNCalculatorTest, SubtractTest3) {
    calculator.push(-5);
    calculator.push(-5);
    calculator.subtract();
    EXPECT_EQ(calculator.value(), 0);
}

TEST_F(RPNCalculatorTest, SubtractTest4) {
    calculator.push(-5);
    calculator.push(5);
    calculator.subtract();
    EXPECT_EQ(calculator.value(), -10);
}

TEST_F(RPNCalculatorTest, SubtractTest5) {
    calculator.push(5);
    calculator.push(0);
    calculator.subtract();
    EXPECT_EQ(calculator.value(), 5);
}

// END - TESTS FOR SUBTRACT FUNCTION

// START - TESTS FOR MULTIPLY FUNCTION

TEST_F(RPNCalculatorTest, MultiplyTest) {
    calculator.push(2);
    calculator.push(3);
    calculator.multiply();
    EXPECT_EQ(calculator.value(), 6);
}

TEST_F(RPNCalculatorTest, MultiplyTest1) {
    calculator.push(2);
    calculator.push(-3);
    calculator.multiply();
    EXPECT_EQ(calculator.value(), -6);
}

TEST_F(RPNCalculatorTest, MultiplyTest2) {
    calculator.push(-2);
    calculator.push(-3);
    calculator.multiply();
    EXPECT_EQ(calculator.value(), 6);
}

TEST_F(RPNCalculatorTest, MultiplyTest3) {
    calculator.push(2);
    calculator.push(0);
    calculator.multiply();
    EXPECT_EQ(calculator.value(), 0);
}

TEST_F(RPNCalculatorTest, MultiplyTest4) {
    calculator.push(0);
    calculator.push(0);
    calculator.multiply();
    EXPECT_EQ(calculator.value(), 0);
}

// END - TESTS FOR MULTIPLY FUNCTION

// START - TESTS FOR DIVIDE FUNCTION

TEST_F(RPNCalculatorTest, DivideTest) {
    calculator.push(6);
    calculator.push(3);
    calculator.divide();
    EXPECT_EQ(calculator.value(), 2);
}

TEST_F(RPNCalculatorTest, DivideTest1) {
    calculator.push(6);
    calculator.push(-3);
    calculator.divide();
    EXPECT_EQ(calculator.value(), -2);
}

TEST_F(RPNCalculatorTest, DivideTest2) {
    calculator.push(-6);
    calculator.push(-3);
    calculator.divide();
    EXPECT_EQ(calculator.value(), 2);
}

TEST_F(RPNCalculatorTest, DivideTest3) {
    calculator.push(6);
    calculator.push(0);
    calculator.divide();
    EXPECT_EQ(calculator.value(), std::numeric_limits<double>::infinity());
}

TEST_F(RPNCalculatorTest, DivideTest4) {
    calculator.push(0);
    calculator.push(6);
    calculator.divide();
    EXPECT_EQ(calculator.value(), 0);
}

TEST_F(RPNCalculatorTest, DivideTest5) {
    calculator.push(6);
    calculator.push(6);
    calculator.divide();
    EXPECT_EQ(calculator.value(), 1);
}

// END - TESTS FOR DIVIDE FUNCTION

// START - TESTS FOR SQUARE FUNCTION

TEST_F(RPNCalculatorTest, SquareTest) {
    calculator.push(4);
    calculator.square();
    EXPECT_EQ(calculator.value(), 16);
}

TEST_F(RPNCalculatorTest, SquareTest1) {
    calculator.push(-4);
    calculator.square();
    EXPECT_EQ(calculator.value(), 16);
}

TEST_F(RPNCalculatorTest, SquareTest2) {
    calculator.push(0);
    calculator.square();
    EXPECT_EQ(calculator.value(), 0);
}

TEST_F(RPNCalculatorTest, SquareTest3) {
    calculator.push(1);
    calculator.square();
    EXPECT_EQ(calculator.value(), 1);
}

TEST_F(RPNCalculatorTest, SquareTest4) {
    calculator.push(-1);
    calculator.square();
    EXPECT_EQ(calculator.value(), 1);
}

TEST_F(RPNCalculatorTest, SquareTest5) {
    calculator.push(1.5);
    calculator.square();
    EXPECT_EQ(calculator.value(), 2.25);
}

TEST_F(RPNCalculatorTest, SquareTest6) {
    calculator.push(-1.5);
    calculator.square();
    EXPECT_EQ(calculator.value(), 2.25);
}

TEST_F(RPNCalculatorTest, SquareTest7) {
    calculator.push(1.5);
    calculator.push(1.5);
    calculator.square();
    EXPECT_EQ(calculator.value(), 2.25);
}

// END - TESTS FOR SQUARE FUNCTION

// START - TESTS FOR NEGATE FUNCTION

TEST_F(RPNCalculatorTest, NegateTest) {
    calculator.push(5);
    calculator.negate();
    EXPECT_EQ(calculator.value(), -5);
}

TEST_F(RPNCalculatorTest, NegateTest1) {
    calculator.push(-5);
    calculator.negate();
    EXPECT_EQ(calculator.value(), 5);
}

TEST_F(RPNCalculatorTest, NegateTest2) {
    calculator.push(0);
    calculator.negate();
    EXPECT_EQ(calculator.value(), 0);
}

TEST_F(RPNCalculatorTest, NegateTest3) {
    calculator.push(0.5);
    calculator.negate();
    EXPECT_EQ(calculator.value(), -0.5);
}

TEST_F(RPNCalculatorTest, NegateTest4) {
    calculator.push(-0.5);
    calculator.negate();
    EXPECT_EQ(calculator.value(), 0.5);
}

TEST_F(RPNCalculatorTest, NegateTest5) {
    calculator.push(0.5);
    calculator.push(0.5);
    calculator.negate();
    EXPECT_EQ(calculator.value(), -0.5);
}

// END - TESTS FOR NEGATE FUNCTION

// START - TESTS FOR CLEAR FUNCTION

TEST_F(RPNCalculatorTest, ClearTest) {
    calculator.push(5);
    calculator.clear();
    EXPECT_TRUE(calculator.isEmpty());
}

TEST_F(RPNCalculatorTest, ClearTest1) {
    calculator.push(5);
    calculator.push(5);
    calculator.clear();
    EXPECT_TRUE(calculator.isEmpty());
}

TEST_F(RPNCalculatorTest, ClearTest2) {
    calculator.push(5);
    calculator.push(5);
    calculator.push(5);
    calculator.clear();
    EXPECT_TRUE(calculator.isEmpty());
}

// END - TESTS FOR CLEAR FUNCTION

// START - TESTS FOR POP FUNCTION

TEST_F(RPNCalculatorTest, PopTest) {
    calculator.push(5);
    EXPECT_EQ(calculator.pop(), 5);
    EXPECT_TRUE(calculator.isEmpty());
}

TEST_F(RPNCalculatorTest, PopTest1) {
    calculator.push(5);
    calculator.push(5);
    EXPECT_EQ(calculator.pop(), 5);
    EXPECT_EQ(calculator.value(), 5);
}

TEST_F(RPNCalculatorTest, PopTest2) {
    calculator.push(5);
    calculator.push(5);
    calculator.push(5);
    EXPECT_EQ(calculator.pop(), 5);
    EXPECT_EQ(calculator.value(), 5);
}

TEST_F(RPNCalculatorTest, PopTest3) {
    calculator.push(5);
    calculator.push(5);
    calculator.push(5);
    EXPECT_EQ(calculator.pop(), 5);
    EXPECT_EQ(calculator.pop(), 5);
    EXPECT_EQ(calculator.value(), 5);
}

// END - TESTS FOR POP FUNCTION

// START - TESTS FOR VALUE FUNCTION

TEST_F(RPNCalculatorTest, ValueTest) {
    calculator.push(5);
    EXPECT_EQ(calculator.value(), 5);
}

TEST_F(RPNCalculatorTest, ValueTest1) {
    calculator.push(5);
    calculator.push(5);
    EXPECT_EQ(calculator.value(), 5);
}

// END - TESTS FOR VALUE FUNCTION

// START - TESTS FOR ISEMPTY FUNCTION

TEST_F(RPNCalculatorTest, IsEmptyTest) {
    EXPECT_TRUE(calculator.isEmpty());
    calculator.push(5);
    EXPECT_FALSE(calculator.isEmpty());
}

TEST_F(RPNCalculatorTest, IsEmptyTest1) {
    EXPECT_TRUE(calculator.isEmpty());
    calculator.push(5);
    calculator.push(5);
    EXPECT_FALSE(calculator.isEmpty());
}

// END - TESTS FOR ISEMPTY FUNCTION

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}