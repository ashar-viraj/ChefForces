#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define MOD 1000000007
const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> curr(k + 1, 0), below(k + 1, 0);
    below[0] = 1;
    for (int i = 1; i <= k; i++)
        below[i] += below[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        for (auto &e : curr)
            e = 0;
        for (int j = k; j >= 0; j--)
        {
            int rangeStart = j - v[i] - 1, rangeEnd = j;
            int smallAns = below[rangeEnd];
            if (rangeStart >= 0)
                smallAns = (smallAns - below[rangeStart] + MOD) % MOD;

            curr[j] = smallAns;
        }

        if (i == 0)
            break;

        for (int i = 1; i <= k; i++)
            (curr[i] += curr[i - 1]) %= MOD;
        below = curr;
    }

    cout << curr[k] << endl;

    return 0;
}