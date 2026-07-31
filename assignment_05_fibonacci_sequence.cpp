#include <iostream>
using namespace std;

void printFibonacci(int n)
{

    if (n <= 0)
    {
        cout << "Error: Please enter a positive number." << endl;
        return;
    }

    int a = 0, b = 1;

    cout << "Fibonacci sequence: ";

    for (int i = 0; i < n; i++)
    {
        cout << a;

        if (i < n - 1)
        {
            cout << " ";
        }

        int next = a + b;
        a = b;
        b = next;
    }

    cout << endl;
}

void checkFibonacci(int num)
{

    if (num < 0)
    {
        cout << num << " is NOT a Fibonacci number." << endl;
        return;
    }

    int a = 0, b = 1;

    while (a < num)
    {
        int next = a + b;
        a = b;
        b = next;
    }

    if (a == num)
    {
        cout << num << " is a Fibonacci number." << endl;
    }
    else
    {
        cout << num << " is NOT a Fibonacci number." << endl;
    }
}

int main()
{

    int n;
    cout << "How many terms? ";
    cin >> n;
    printFibonacci(n);

    cout << endl;

    int num;
    cout << "Enter a number to check: ";
    cin >> num;
    checkFibonacci(num);

    return 0;
}