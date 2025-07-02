#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

char c[27];

string find(int pos)
{
    string ans = "";
    while (pos)
    {
        ans = c[pos % 27] + ans;
        pos /= 27;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, itemp;
    c[0] = 'a';
    rep(i, 1, 27)
    {
        c[i] = (i - 1) + 'a';
    }

    cin >> t;
    while (t--)
    {
        string s, ans;
        cin >> n >> s;
        map<int, set<string>> word;
        rep(i, 0, s.size())
        {
            rep(j, 1, s.size() - i + 1)
            {
                word[j].insert(s.substr(i, j));
            }
        }
        int idx = 1, pos = 0;
        bool found = false;
        for (auto e : word)
        {
            if (e.second.size() != pow(26, idx))
            {
                i = pos;
                for (auto q : e.second)
                {
                    i++;
                    if (q != find(i))
                    {
                        cout << i << q;
                        ans = q;
                        found = true;
                        break;
                    }
                }
            }
            if (found)
                break;
            pos += pow(26, idx);
            idx++;
        }
        if (!found)
        {
            cout << find(pos + 1) << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}