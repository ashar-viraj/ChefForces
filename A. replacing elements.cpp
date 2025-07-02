#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, temp, d;
    cin >> t;
    while (t--)
    {
        cin >> n >> d;
        vector<int> v;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        if (v[n - 1] <= d)
        {
            cout << "YES\n";
        }
        else if (v[0] + v[1] <= d)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}