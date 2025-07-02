#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
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

    vector<int> close(26);
    for (int i = 0; i < 26; i++)
    {
        char c = i + 'a';
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            close[i] = 1;
            continue;
        }

        int mi = 30;
        for (int j = 0; j < 26; j++)
        {
            if (i == j)
                continue;
            char c2 = j + 'a';
            if (c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u')
            {
                mi = min(mi, abs(i - j));
            }
        }
        int cnt = 0;
        for (int j = 0; j < 26; j++)
        {
            char c2 = j + 'a';
            if (c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u')
            {
                if (abs(j - i) == mi)
                    cnt++;
            }
        }
        close[i] = cnt;
    }
    // cout << "OK\n";
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        string s;
        cin >> s;
        int ans = 1;
        rep(i, 0, n)
        {
            ans = (ans * (close[s[i] - 'a'])) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}