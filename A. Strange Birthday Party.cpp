#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int t, i, n, temp, m, j;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<long long int> k, c;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            k.push_back(temp);
        }
        for (i = 0; i < m; i++)
        {
            cin >> temp;
            c.push_back(temp);
        }
        if (n == 1)
        {
            cout << c[0] << "\n";
            continue;
        }
        sort(k.begin(), k.end());
        long long int cost = 0;
        i = n - 1;
        j = 0;
        for (i = n - 1; i >= 0; i--)
        {
            if (j < m)
            {
                if (c[j] <= c[k[i] - 1])
                {
                    cost += c[j];
                    j++;
                }
                else
                {
                    cost += c[k[i] - 1];
                }
            }
            else
            {
                cost += c[k[i] - 1];
            }
            // cout << "cost = " << cost << "\n";
        }
        cout << cost << "\n";
    }
    return 0;
}