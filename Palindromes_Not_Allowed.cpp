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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        string inp;
        cin >> inp;
        vector<int> freq(128);
        for (int i = 0; i < n; i++)
        {
            freq[inp[i]]++;
        }

        string s = "";
        for (int i = 0; i < n; i++)
            s += " ";

        vector<pair<int, char>> chars;
        for (int i = 'a'; i <= 'z'; i++)
            if (freq[i] != 0)
                chars.push_back({freq[i], (char)i});

        sort(chars.begin(), chars.end());
        reverse(chars.begin(), chars.end());
        int i = 0;
        for (int k = 0; k < 3; k++)
        {
            for (int j = k; j < n && i < chars.size();)
            {
                if (chars[i].first == 0)
                {
                    i++;
                }
                else
                {
                    s[j] = chars[i].second;
                    chars[i].first--;
                    j += 3;
                }
            }
        }
        bool valid = true;

        for (int i = 0; i < n; i++)
        {
            if (i - 1 >= 0 && s[i] == s[i - 1])
                valid = false;
            if (i - 2 >= 0 && s[i] == s[i - 2])
                valid = false;
            if (i + 1 < n && s[i] == s[i + 1])
                valid = false;
            if (i + 2 < n && s[i] == s[i + 2])
                valid = false;
        }

        if (valid)
        {
            cout << "YES\n"
                 << s << endl;
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}