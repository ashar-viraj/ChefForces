#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, N, i;
    cin >> T;
    while (T--)
    {
        cin >> N;
        int arr[N], operation[N];
        bool deleteStart[N], deleteEnd[N];
        // memset(present, false, sizeof(bool));
        cout << "Perfect 1\n";
        for (i = 0; i < N; i++)
        {
            cin >> arr[N];
            operation[i] = 0;
            deleteStart[i] = false;
            deleteEnd[i] = true;
        }
        cout << "Perfect 2\n";
        for (i = 0; i < N; i++)
        {
            cout << "Loop is " << i << endl;
            if (arr[i] == arr[i + 1])
            {
                continue;
            }
            if (deleteStart[arr[i] - 1])
            {
                operation[arr[i] - 1]++;
                deleteStart[arr[i] - 1] = true;
            }
            else
            {
                operation[arr[i] - 1]++;
                deleteStart[arr[i] - 1] = true;
            }
        }
        cout << "Perfect 3\n";
        for (i = 0; i < N; i++)
        {
            if (deleteStart[i])
            {
                operation[arr[i]]++;
            }
        }
        cout << "Perfect 4\n";
        int min = INT_MAX;
        for (i = 0; i < N; i++)
        {
            if (operation[i] < min)
                min = operation[i];
        }
        cout << min << endl;
    }
    return 0;
}