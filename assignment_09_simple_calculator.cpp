#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b == 0)
    {
        return -999999;
    }
    return a / b;
}

int modulus(int a, int b)
{
    if (b == 0)
    {
        return -999999;
    }
    return a % b;
}

double exponentiate(double base, double exp)
{
    return pow(base, exp);
}

void showMenu()
{
    cout << "\n============================" << endl;
    cout << "      SIMPLE CALCULATOR     " << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

int main()
{

    int choice;

    while (true)
    {

        showMenu();
        cin >> choice;

        if (choice == 7)
        {
            cout << "Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 7)
        {
            cout << "Invalid choice. Please enter 1-7." << endl;
            continue;
        }

        double a, b;
        cout << "Enter first number : ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;

        cout << fixed << setprecision(2);

        if (choice == 1)
        {
            cout << "Result: " << a << " + " << b
                 << " = " << add(a, b) << endl;
        }
        else if (choice == 2)
        {
            cout << "Result: " << a << " - " << b
                 << " = " << subtract(a, b) << endl;
        }
        else if (choice == 3)
        {
            cout << "Result: " << a << " * " << b
                 << " = " << multiply(a, b) << endl;
        }
        else if (choice == 4)
        {
            double result = divide(a, b);
            if (result == -999999)
            {
                cout << "Error: Cannot divide by zero." << endl;
            }
            else
            {
                cout << "Result: " << a << " / " << b
                     << " = " << result << endl;
            }
        }
        else if (choice == 5)
        {
            int ia = (int)a, ib = (int)b;
            int result = ia % ib;
            if (result == -999999)
            {
                cout << "Error: Cannot divide by zero." << endl;
            }
            else
            {
                cout << "Result: " << ia << " % " << ib
                     << " = " << result << endl;
            }
        }
        else if (choice == 6)
        {
            cout << "Result: " << a << " ^ " << b
                 << " = " << exponentiate(a, b) << endl;
        }
    }

    return 0;
}