#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> n >> m;
    vector<int> v(n);

    for (int i = 0; i < m; i++)
        cin >> v[i];

    vector<int> states(m + 1, 0);

    for (int i = 0; i <= m; i++)
    {
        int nextState = states[i] ^ 1;
        if (nextState == 0)
            continue;
        for (int j = 0; j < n; j++)
        {
            if (i + v[j] > m)
                continue;
            if (nextState == 1)
                states[i + v[j]] = nextState;
        }
    }
    if (states[m])
        cout << "First";
    else
        cout << "Second";
    return 0;
}