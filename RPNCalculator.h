#ifndef RPNCALCULATOR_H
#define RPNCALCULATOR_H

#include <stack>
#include <fstream>
#include <stdexcept>

template<class T>
class RPNCalculator {
public:
    RPNCalculator();
    ~RPNCalculator();
    void push(T operand);
    void add();
    void subtract();
    void multiply();
    void divide();
    void square();
    void negate();
    bool isEmpty() const;
    void clear();
    void getStack();
    T value() const;
    T pop();

private:
    std::stack<T> stack;
    mutable std::ofstream logFile;
};

template<class T>
RPNCalculator<T>::RPNCalculator() {
    logFile.open("RPN.log", std::ios::out | std::ios::trunc);
    if (!logFile) {
        throw std::runtime_error("Unable to open log file");
    }
}

template<class T>
RPNCalculator<T>::~RPNCalculator() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

template<class T>
void RPNCalculator<T>::push(T operand) {
    stack.push(operand);
}

template<class T>
void RPNCalculator<T>::add() {
    if (stack.size() < 2) {
        logFile << "Error: Not enough operands for addition\n";
        logFile.flush();
        return;
    }
    T op2 = stack.top(); stack.pop();
    T op1 = stack.top(); stack.pop();
    T result = op1 + op2;
    stack.push(result);
    logFile << op1 << " + " << op2 << " = " << result << "\n";
    logFile.flush();
}

template<class T>
void RPNCalculator<T>::subtract() {
    if (stack.size() < 2) {
        logFile << "Error: Not enough operands for subtraction\n";
        logFile.flush();
        return;
    }
    T op2 = stack.top(); stack.pop();
    T op1 = stack.top(); stack.pop();
    T result = op1 - op2;
    stack.push(result);
    logFile << op1 << " - " << op2 << " = " << result << "\n";
    logFile.flush();
}

template<class T>
void RPNCalculator<T>::multiply() {
    if (stack.size() < 2) {
        logFile << "Error: Not enough operands for multiplication\n";
        logFile.flush();
        return;
    }
    T op2 = stack.top(); stack.pop();
    T op1 = stack.top(); stack.pop();
    T result = op1 * op2;
    stack.push(result);
    logFile << op1 << " * " << op2 << " = " << result << "\n";
    logFile.flush();
}

template<class T>
void RPNCalculator<T>::divide() {
    if (stack.size() < 2) {
        logFile << "Error: Not enough operands for division\n";
        logFile.flush();
        return;
    }
    T op2 = stack.top(); stack.pop();
    T op1 = stack.top(); stack.pop();
    T result = op1 / op2;
    stack.push(result);
    logFile << op1 << " / " << op2 << " = " << result << "\n";
    logFile.flush();
}

template<class T>
void RPNCalculator<T>::square() {
    if (stack.empty()) {
        logFile << "Error: Not enough operands for squaring\n";
        logFile.flush();
        return;
    }
    T op1 = stack.top(); stack.pop();
    T result = op1 * op1;
    stack.push(result);
    logFile << op1 << "^2 = " << result << "\n";
    logFile.flush();
}

template<class T>
void RPNCalculator<T>::negate() {
    if (stack.empty()) {
        logFile << "Error: Not enough operands for negation\n";
        logFile.flush();
        return;
    }
    T op1 = stack.top(); stack.pop();
    T result = -op1;
    stack.push(result);
    logFile << op1 << " (negated) = " << result << "\n";
    logFile.flush();
}

template<class T>
bool RPNCalculator<T>::isEmpty() const {
    bool empty = stack.empty();
    return empty;
}

template<class T>
void RPNCalculator<T>::clear() {
    stack = std::stack<T>();
    logFile << "Stack cleared\n";
}

template<class T>
void RPNCalculator<T>::getStack() {
    std::stack<T> tempStack = stack;
    if (tempStack.size() == 0) {
        std::cout << "Stack is empty." << std::endl;
    }
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }
    std::cout << std::endl;
}

template<class T>
T RPNCalculator<T>::value() const {
    if (stack.empty()) {
        throw std::runtime_error("Stack is empty");
    }
    return stack.top();
}

template<class T>
T RPNCalculator<T>::pop() {
    if (stack.empty()) {
        throw std::runtime_error("Stack is empty");
    }
    T top = stack.top();
    stack.pop();
    return top;
}

#endif // RPNCALCULATOR_H