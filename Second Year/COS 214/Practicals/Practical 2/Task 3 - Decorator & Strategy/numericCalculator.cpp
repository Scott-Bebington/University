#include "numericCalculator.h"
NumericCalculator::NumericCalculator(): Calculator()
{
}
int NumericCalculator::performCalculation()
{
    string inputString = getInputString();

    // Split the input string by commas
    vector<string> parts;
    istringstream iss(inputString);
    string part;
    while (getline(iss, part, ',')) {
        parts.push_back(part);
    }

    // Check if the input has the correct number of parts
    if (parts.size() != 3) {
        throw "Invalid input format"; // Handle the error appropriately
    }

    char operation = parts[0][0]; // Get the first character of the first part
    int operand1 = stoi(parts[1]);
    int operand2 = stoi(parts[2]);

    int result = 0;

    switch (operation) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            if (operand2 != 0) {
                result = operand1 / operand2;
            } else {
                throw "Division by zero"; // Handle division by zero error
            }
            break;
        default:
            throw "Unsupported operation"; // Handle unsupported operation error
    }

    return result;
}