#include <iostream>
using namespace std;

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main() {
    double num1, num2, result;
    char op;
    bool continueCalc = true;

    while (continueCalc) {
        cout << BOLD << CYAN << "\n========================================\n";
        cout << "         COLOURED CONSOLE CALCULATOR     \n";
        cout << "========================================\n" << RESET;

        cout << YELLOW << "Enter first number: " << RESET;
        cin >> num1;

        cout << YELLOW << "Enter operator (+, -, *, /): " << RESET;
        cin >> op;

        cout << YELLOW << "Enter second number: " << RESET;
        cin >> num2;

        bool validOp = true;

        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    cout << RED << BOLD << "\nError: Division by zero is not allowed!\n" << RESET;
                    validOp = false;
                } else {
                    result = num1 / num2;
                }
                break;
            default:
                cout << RED << BOLD << "\nError: Invalid operator entered!\n" << RESET;
                validOp = false;
                break;
        }

        if (validOp) {
            cout << GREEN << BOLD << "\nResult: " << RESET;
            cout << MAGENTA << num1 << " " << op << " " << num2 << " = " << result << RESET << endl;
        }

        cout << BLUE << "\nDo you want to perform another calculation? (y/n): " << RESET;
        char choice;
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            continueCalc = false;
            cout << CYAN << BOLD << "\nThank you for using the calculator. Goodbye!\n" << RESET;
        }
    }

    return 0;
}
