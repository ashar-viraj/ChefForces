// Good Bye 2020
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, itemp, countTemp;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int s = 0;
        unordered_set<int> diversities;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        diversities.insert(arr[0]);
        for (i = 1; i < n; i++)
        {
            if (i == n - 1)
            {
                arr[i]++;
                diversities.insert(arr[i]);
                continue;
            }
            if (arr[i] == arr[i + 1])
            {
                diversities.insert(arr[i]);
                continue;
            }
            if (arr[i] == arr[i - 1])
            {
                arr[i]++;
            }
            diversities.insert(arr[i]);
        }
        diversities.insert(arr[n - 1]);
        cout << diversities.size() << "\n";

        /*itemp = arr[0];
        countTemp = 1;
        for (i = 1; i < n; i++)
        {
            if (arr[i] != itemp)
            {
                counts[itemp - 1] = countTemp;
                itemp = arr[i];
                countTemp = 1;
            }
            else
            {
                countTemp++;
            }
        }
        if (arr[n - 1] == itemp)
        {
            counts[itemp - 1] = countTemp;
            itemp = arr[i];
            countTemp = 1;
        }
        for (i = 0; i < (2 * n) - 1; i++)
        {
            if (counts[i] >= 2)
            {
                counts[i]--;
                counts[i + 1]++;
            }
        }
        int diversities = 0;
        for (i = 0; i < (2 * n); i++)
        {
            if (counts[i] != 0)
            {
                diversities++;
            }
        }*/
    }
    return 0;
}