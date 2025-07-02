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
        string s;
        cin >> n >> s;
        vector<int> sheep;
        int ans = 0, comp = 0;
        rep(i, 0, n)
        {
            if (s[i] == '*')
                sheep.push_back(i);
        }
        if (sheep.empty())
        {
            cout << "0\n";
            continue;
        }
        else if (sheep.size() == 1)
        {
            cout << "0\n";
            continue;
        }
        int pos = sheep[sheep.size() / 2] - 1;
        for (i = sheep.size() / 2 - 1; i >= 0; i--)
        {
            ans += pos - sheep[i];
            pos--;
        }
        pos = sheep[sheep.size() / 2] + 1;
        rep(i, sheep.size() / 2 + 1, sheep.size())
        {
            ans += sheep[i] - pos;
            pos++;
        }
        cout << ans << endl;
    }
    return 0;
}