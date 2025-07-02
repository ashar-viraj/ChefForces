#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define MOD 1000000007
#define f first
#define s second
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void reveseTry(string s, int n)
{
    reverse(s.begin(), s.end());
    int start1 = 0, start2 = 0, ans = -1;
    while (start2 <= n)
    {
        if (s[0] != s[start2])
        {
            ans = 0;
            break;
        }
        start2++;
    }
    if (ans == -1)
    {
        cout << "-1\n";
        return;
    }

    // cout << start1 << ' ' << start2 << endl;

    vector<int> v;
    int ansSize = 0;
    while (ansSize != n)
    {
        if (start1 == start2)
        {
            start1++;
            continue;
        }
        v.push_back(2 * n - (start1 + 1) - 1);
        ansSize++;
        start1++;
    }

    sort(v.begin(), v.end());

    for (auto e : v)
        cout << e << " ";
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        string s;
        cin >> s;
        int start1 = 0, start2 = 0, ans = -1;
        while (start2 <= n)
        {
            if (s[0] != s[start2])
            {
                ans = 0;
                break;
            }
            start2++;
        }
        if (ans == -1)
        {
            reveseTry(s, n);
            continue;
        }
        // cout << start1 << ' ' << start2 << endl;

        vector<int> v;
        int ansSize = 0;
        while (ansSize != n)
        {
            if (start1 == start2)
            {
                start1++;
                continue;
            }
            v.push_back(start1 + 1);
            ansSize++;
            start1++;
        }

        for (auto e : v)
            cout << e << " ";
        cout << endl;
    }
    return 0;
}