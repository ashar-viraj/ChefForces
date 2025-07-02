#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, itemp;
    cin >> t;
    while (t--)
    {
        cin >> n;
        map<int, int> freq;
        int ans = 0;
        rep(i, 0, n)
        {
            cin >> itemp;
            freq[itemp - i]++;
        }
        for (auto e : freq)
        {
            ans += (e.second * (e.second - 1)) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}

// 16
// 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
// 9 13 11 15 13 16 16 11 15 15 16 16 16 16 15 16
//