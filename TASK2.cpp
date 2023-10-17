#include <iostream>

using namespace std;

int main() {
    char operation;
    double num1, num2;

    cout << "Simple Calculator" << endl;
    cout << "Enter operator (+, -, *, /): ";
    cin >> operation;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    switch (operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            cout << "Result: " << num1 / num2 << endl;
            break;
        default:
            cout << "Error: Invalid operator" << endl;
            break;
    }

    return 0;
}
