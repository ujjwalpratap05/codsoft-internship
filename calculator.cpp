#include <iostream>

void calculator() {
    double num1, num2;
    char operation;

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter an operator (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    switch(operation) {
        case '+':
            std::cout << "Result: " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << "Result: " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                std::cout << "Result: " << num1 / num2 << std::endl;
            } else {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            }
            break;
        default:
            std::cout << "Error: Invalid operator." << std::endl;
            break;
    }
}

int main() {
    calculator();
    return 0;
}
