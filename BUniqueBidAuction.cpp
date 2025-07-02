#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, i, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        int arr[N], arr2[N];
        int minUnique = -1;
        for (i = 0; i < N; i++)
        {
            cin >> arr[i];
            arr2[i] = arr[i];
        }
        sort(arr2, arr2 + N);

        if (arr2[0] != arr2[1])
        {
            minUnique = arr2[0];
        }
        else
        {
            for (i = 1; i < N - 1; i++)
            {
                if (arr2[i] == arr2[i - 1] || arr2[i] == arr2[i + 1])
                {
                    continue;
                }
                minUnique = arr2[i];
                break;
            }
        }
        if (minUnique == -1)
        {
            if (arr2[N - 1] != arr2[N - 2])
            {
                minUnique = arr2[N - 1];
            }
            else
            {
                cout << minUnique << endl;
            }
        }
        if (minUnique == -1)
        {
            continue;
        }
        for (i = 0; i < N; i++)
        {
            if (arr[i] == minUnique)
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}