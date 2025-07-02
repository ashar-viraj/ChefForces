// Codeforces Round #693
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> v;
        int temp;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        int arr[n], maxScore = 0;
        memset(arr, 0, sizeof(arr));
        for (i = n - 1; i >= 0; i--)
        {
            if (v[i] + i <= n - 1)
            {
                arr[i] = v[i] + arr[v[i] + i];
            }
            else
            {
                arr[i] = v[i];
            }
            if (arr[i] > maxScore)
            {
                maxScore = arr[i];
            }
        }
        // for (i = 0; i < n; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << "\n";
        cout << maxScore << "\n";
    }
    return 0;
}