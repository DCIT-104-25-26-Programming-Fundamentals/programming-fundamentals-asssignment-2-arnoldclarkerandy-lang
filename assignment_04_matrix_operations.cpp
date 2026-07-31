#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void printMatrix(int mat[][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

void readMatrix(int mat[][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void transposeMatrix(int mat[][10], int rows, int cols)
{

    int transposed[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transposed[j][i] = mat[i][j];
        }
    }

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(mat, rows, cols);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transposed, cols, rows);
}

void addMatrices(int A[][10], int B[][10], int rows, int cols)
{

    int result[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nMatrix A:" << endl;
    printMatrix(A, rows, cols);

    cout << "\nMatrix B:" << endl;
    printMatrix(B, rows, cols);

    cout << "\nA + B =" << endl;
    printMatrix(result, rows, cols);
}

void multiplyMatrices(int A[][10], int B[][10], int M, int N, int P)
{

    int result[10][10];

    for (int i = 0; i < M; i++)
        for (int j = 0; j < P; j++)
            result[i][j] = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < P; j++)
        {
            for (int k = 0; k < N; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nMatrix A:" << endl;
    printMatrix(A, M, N);

    cout << "\nMatrix B:" << endl;
    printMatrix(B, N, P);

    cout << "\nA x B =" << endl;
    printMatrix(result, M, P);
}

// ── MAIN ─────────────────────────────────────────────────────────────────
int main()
{

    int choice;

    cout << "==============================" << endl;
    cout << "   Matrix Operations Menu     " << endl;
    cout << "==============================" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Choose (1-3): ";
    cin >> choice;

    if (choice == 1)
    {
        int mat[10][10], rows, cols;

        cout << "\nEnter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(mat, rows, cols);
        transposeMatrix(mat, rows, cols);
    }
    else if (choice == 2)
    {
        int A[10][10], B[10][10], rows, cols;

        cout << "\nEnter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "\n-- Enter Matrix A --" << endl;
        readMatrix(A, rows, cols);

        cout << "\n-- Enter Matrix B --" << endl;
        readMatrix(B, rows, cols);

        addMatrices(A, B, rows, cols);
    }
    else if (choice == 3)
    {
        int A[10][10], B[10][10];
        int M, N, P;

        cout << "\n-- Matrix A dimensions --" << endl;
        cout << "Rows (M): ";
        cin >> M;
        cout << "Columns (N): ";
        cin >> N;

        cout << "\n-- Matrix B dimensions --" << endl;
        cout << "Rows must equal " << N << " (columns of A)" << endl;
        cout << "Columns (P): ";
        cin >> P;

        cout << "\n-- Enter Matrix A --" << endl;
        readMatrix(A, M, N);

        cout << "\n-- Enter Matrix B --" << endl;
        readMatrix(B, N, P);

        multiplyMatrices(A, B, M, N, P);
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}