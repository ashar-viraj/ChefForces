#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(0));
    int BL, i, j;
    cout << "Enter the size of the matrix B : ";
    cin >> BL;
    cout << "\n";
    int B[BL][BL];
    for (i = 0; i < BL; i++)
    {
        for (j = 0; j < BL; j++)
        {
            B[i][j] = rand() % 9;
        }
    }

    cout << "Value of matrix B : \n";
    for (i = 0; i < BL; i++)
    {
        for (j = 0; j < BL; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    int A[BL - 1][BL - 1];
    for (i = 0; i < BL - 1; i++)
    {
        for (j = 0; j < BL - 1; j++)
        {
            A[i][j] = B[i][j] + B[i + 1][j] + B[i][j + 1] + B[i + 1][j + 1];
        }
    }

    cout << "Value in the matrix A : \n";
    for (i = 0; i < BL - 1; i++)
    {
        for (j = 0; j < BL - 1; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}