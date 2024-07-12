#include <iostream>
#include <string>
#include "RPNCalculator.h"

int main() {
    std::cout << "D00243449 Nebi Anil Atici" << std::endl << std::endl;
    std::cout << "Welcome to the RPN Calculator!" << std::endl << std::endl;
    std::cout << "You can use the following commands:" << std::endl;
    std::cout << "-Press 'c' to clear the stack," << std::endl;
    std::cout << "-Press 's' to square," << std::endl;
    std::cout << "-Press 'n' to negate," << std::endl;
    std::cout << "-Press 'p' to pop current value," << std::endl;
    std::cout << "-Press 'q' to quit." << std::endl << std::endl;
    std::cout << "Please enter numbers first to use the commands." << std::endl << std::endl;
    std::cout << "You can use the following operators:" << std::endl;
    std::cout << "-Press '+' to add," << std::endl;
    std::cout << "-Press '-' to subtract," << std::endl;
    std::cout << "-Press '*' to multiply," << std::endl;
    std::cout << "-Press '/' to divide." << std::endl << std::endl;

    RPNCalculator<double> calculator;
    std::string input;
    double value;

    while (true) {
        if (calculator.isEmpty()) {
            std::cout << "X > ";
        } else {
            std::cout << calculator.value() << " > ";
        }

        std::getline(std::cin, input);

        if (input == "q") {
            break;
        } else if (input == "c") {
            calculator.clear();
        } else if (input == "s") {
            calculator.square();
        } else if (input == "n") {
            calculator.negate();
        } else if (input == "p") {
            if (!calculator.isEmpty()) {
                calculator.pop();
            }
        } else if (input == "+") {
            calculator.add();
        } else if (input == "-") {
            calculator.subtract();
        } else if (input == "*") {
            calculator.multiply();
        } else if (input == "/") {
            calculator.divide();
        } else {
            try {
                value = std::stod(input);
                calculator.push(value);
            } catch (const std::invalid_argument&) {
                std::cout << "Invalid input" << std::endl;
            }
        }
    }

    return 0;
}