// Good Bye 2020
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, temp;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> v;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        unordered_set<int> areas;
        for (i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                areas.insert(v[i] - v[j]);
            }
        }
        cout << areas.size() << "\n";
    }
    return 0;
}