#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int t, i, n, temp, d, m, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<long long int>> occupied(2, vector<long long int>(500000, 1));
        // long long int occupied[2][n];
        bool possible = true;
        // memset(occupied, 1, sizeof(occupied));
        for (i = 0; i < m; i++)
        {
            cin >> a >> b;
            occupied[a - 1][b - 1] = false;
        }
        for (i = 0; i < n; i++)
        {
            if (occupied[0][i])
            {
                if (occupied[1][i])
                {
                    occupied[0][i] = 0;
                    occupied[1][i] = 0;
                }
                else if (i == n - 1)
                {
                    possible = false;
                    break;
                }
                else if (occupied[0][i + 1])
                {
                    occupied[0][i] = 0;
                    occupied[0][i + 1] = 0;
                }
                else
                {
                    possible = false;
                    break;
                }
            }
            else if (occupied[1][i])
            {
                if (i == n - 1)
                {
                    possible = false;
                    break;
                }
                if (occupied[1][i + 1])
                {
                    occupied[1][i] = 0;
                    occupied[1][i + 1] = 0;
                }
                else
                {
                    possible = false;
                    break;
                }
            }
        }
        if (possible)
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