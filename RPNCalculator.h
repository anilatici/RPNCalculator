#ifndef RPNCALCULATOR_H
#define RPNCALCULATOR_H

#include <stack>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <string>

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
    std::vector<T> getStack() const;
    T value() const;
    T pop();

private:
    std::stack<T> stack;
    mutable std::ofstream logFile;

    void logOperation(const std::string& operation) const;
    void logError(const std::string& message) const;
};

template<typename T>
std::string to_string(const T& integer) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(6) << integer;
    std::string result = oss.str();
    result.erase(result.find_last_not_of('0') + 1, std::string::npos);
    result.erase(result.find_last_not_of('.') + 1, std::string::npos);
    return result;
}

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
        if (stack.size() == 1) {
            stack.pop();
        }
        logError("Not enough operands for addition");
        return;
    }
    T op2 = stack.top(); stack.pop();
    T op1 = stack.top(); stack.pop();
    stack.push(op1 + op2);
    std::string logMessage = to_string(op1) + " + " + to_string(op2);
    logOperation(logMessage);
}

template<class T>
void RPNCalculator<T>::subtract() {
    if (stack.size() < 2) {
        if (stack.size() == 1) {
            stack.pop();
        }
        logError("Not enough operands for subtraction");
        return;
    }
    T op2 = stack.top(); stack.pop();
    T op1 = stack.top(); stack.pop();
    stack.push(op1 - op2);
    std::string logMessage = to_string(op1) + " - " + to_string(op2);
    logOperation(logMessage);
}

template<class T>
void RPNCalculator<T>::multiply() {
    if (stack.size() < 2) {
        if (stack.size() == 1) {
            stack.pop();
        }
        logError("Not enough operands for multiplication");
        return;
    }
    T op2 = stack.top(); stack.pop();
    T op1 = stack.top(); stack.pop();
    stack.push(op1 * op2);
    std::string logMessage = to_string(op1) + " * " + to_string(op2);
    logOperation(logMessage);
}

template<class T>
void RPNCalculator<T>::divide() {
    if (stack.size() < 2) {
        if (stack.size() == 1) {
            stack.pop();
        }
        logError("Not enough operands for division");
        return;
    }
    T op2 = stack.top(); stack.pop();
    T op1 = stack.top(); stack.pop();
    stack.push(op1 / op2);
    std::string logMessage = to_string(op1) + " / " + to_string(op2);
    logOperation(logMessage);
}

template<class T>
void RPNCalculator<T>::square() {
    if (stack.empty()) {
        logError("Not enough operands for squaring");
        return;
    }
    T op1 = stack.top(); stack.pop();
    stack.push(op1 * op1);
    std::string logMessage = to_string(op1) + " squared";
    logOperation(logMessage);
}

template<class T>
void RPNCalculator<T>::negate() {
    if (stack.empty()) {
        logError("Not enough operands for negation");
        return;
    }
    T op1 = stack.top(); stack.pop();
    stack.push(-op1);
    std::string logMessage = to_string(op1) + " negated";
    logOperation(logMessage);
}

template<class T>
bool RPNCalculator<T>::isEmpty() const {
    return stack.empty();
}

template<class T>
void RPNCalculator<T>::clear() {
    stack = std::stack<T>();
    logOperation("clear");
}

template<class T>
std::vector<T> RPNCalculator<T>::getStack() const {
    std::stack<T> temporaryStack = stack;
    std::vector<T> stackContents;
    while (!temporaryStack.empty()) {
        stackContents.push_back(temporaryStack.top());
        temporaryStack.pop();
    }
    return stackContents;
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

template<class T>
void RPNCalculator<T>::logOperation(const std::string& operation) const {
    if (logFile.is_open()) {
        logFile << operation << "\n";
        logFile.flush();
    }
}

template<class T>
void RPNCalculator<T>::logError(const std::string& message) const {
    if (logFile.is_open()) {
        logFile << "Error: " << message << "\n";
        logFile.flush();
    }
}

#endif // RPNCALCULATOR_H