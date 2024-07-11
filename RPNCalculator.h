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
    public:
    void push(T value) {
        stack.push(value);
    }
    void add();
    void subtract();
    void multiply();
    void divide();
    void square();
    void negate();
    bool isEmpty();
    void clear();
    T value();
    T pop();

private:
    std::stack<T> stack;
    std::ofstream logFile;
};

template<class T>
RPNCalculator<T>::RPNCalculator() {
    logFile.open("RPN.log", std::ios::out | std::ios::app);
}

template<class T>
RPNCalculator<T>::~RPNCalculator() {
    logFile.close();
}

template<class T>
void RPNCalculator<T>::add() {
    if (stack.size() < 2) {
        stack = std::stack<T>();
        return;
    }
    T op2 = stack.top(); stack.pop();
    T op1 = stack.top(); stack.pop();
    T result = op1 + op2;
    stack.push(result);
    logFile << op1 << " + " << op2 << " = " << result << "\n";
}

template<class T>
void RPNCalculator<T>::subtract() {
    if (stack.size() < 2) {
        stack = std::stack<T>();
        return;
    }
    T op2 = stack.top(); stack.pop();
    T op1 = stack.top(); stack.pop();
    T result = op1 - op2;
    stack.push(result);
    logFile << op1 << " - " << op2 << " = " << result << "\n";
}

template<class T>
void RPNCalculator<T>::multiply() {
    if (stack.size() < 2) {
        stack = std::stack<T>();
        return;
    }
    T op2 = stack.top(); stack.pop();
    T op1 = stack.top(); stack.pop();
    T result = op1 * op2;
    stack.push(result);
    logFile << op1 << " * " << op2 << " = " << result << "\n";
}

template<class T>
void RPNCalculator<T>::divide() {
    if (stack.size() < 2) {
        stack = std::stack<T>();
        return;
    }
    T op2 = stack.top(); stack.pop();
    T op1 = stack.top(); stack.pop();
    T result = op1 / op2;
    stack.push(result);
    logFile << op1 << " / " << op2 << " = " << result << "\n";
}

template<class T>
void RPNCalculator<T>::square() {
    if (stack.empty()) {
        stack = std::stack<T>();
        return;
    }
    T op1 = stack.top(); stack.pop();
    T result = op1 * op1;
    stack.push(result);
    logFile << op1 << "^2 = " << result << "\n";
}

template<class T>
void RPNCalculator<T>::negate() {
    if (stack.empty()) {
        stack = std::stack<T>();
        return;
    }
    T op1 = stack.top(); stack.pop();
    T result = -op1;
    stack.push(result);
    logFile << "-" << op1 << " = " << result << "\n";
}

template<class T>
bool RPNCalculator<T>::isEmpty() {
    return stack.empty();
}

template<class T>
void RPNCalculator<T>::clear() {
    stack = std::stack<T>();
    logFile << "Stack cleared\n";
}

template<class T>
T RPNCalculator<T>::value() {
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
    T result = stack.top();
    stack.pop();
    return result;
}

#endif // RPNCALCULATOR_H