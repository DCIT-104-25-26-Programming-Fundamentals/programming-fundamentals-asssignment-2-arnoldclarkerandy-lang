#include <iostream>
using namespace std;

void printTable(int num)
{

    cout << "Multiplication Table for " << num << ":" << endl;

    for (int i = 1; i <= 12; i++)
    {
        cout << num << "  x  " << i << "  =  " << num * i << endl;
    }
}

void printAllTables(int n)
{

    if (n <= 0)
    {
        cout << "Error: Please enter a positive number." << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        printTable(i);

        if (i < n)
        {
            cout << "---------------------------" << endl;
        }
    }
}

// ── MAIN ─────────────────────────────────────────────────────────────────
int main()
{

    int choice;

    cout << "==============================" << endl;
    cout << " Multiplication Table Menu    " << endl;
    cout << "==============================" << endl;
    cout << "1. Single table" << endl;
    cout << "2. Tables from 1 to N" << endl;
    cout << "Choose (1 or 2): ";
    cin >> choice;

    if (choice == 1)
    {
        // Part A
        int num;
        cout << "Enter a number: ";
        cin >> num;

        if (num <= 0)
        {
            cout << "Error: Please enter a positive number." << endl;
        }
        else
        {
            cout << endl;
            printTable(num);
        }
    }
    else if (choice == 2)
    {
        int n;
        cout << "Enter N: ";
        cin >> n;
        cout << endl;
        printAllTables(n);
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}