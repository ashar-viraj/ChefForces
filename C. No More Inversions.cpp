#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int u = 2 * k - n - 1;
        for (i = 1; i < u + 1; i++)
        {
            cout << i << " ";
        }
        for (i = k; i > u; i--)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}