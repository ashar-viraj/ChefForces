#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t, i, n, imposter;
    cin >> t;
    while (t--)
    {
        imposter = -1;
        cin >> n;
        int arr[n], arr2[n + 1];

        // cout << "Enter in arr1\n";
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        // cout << "Enter in arr2\n";
        for (i = 0; i < n + 1; i++)
        {
            cin >> arr2[i];
        }
        sort(arr, arr + n);
        sort(arr2, arr2 + n + 1);
        int j = 0;
        for (i = 0; i < n; i++, j++)
        {
            if (arr[i] != arr2[j])
            {
                cout << arr2[j];
                j++;
            }
        }
        if (imposter == -1)
        {
            imposter = arr2[n];
        }
        cout << imposter << endl;
    }
    return 0;
}