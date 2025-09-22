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
#define pb push_back
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    string s, t;
    cin >> s >> t;
    t = s;
    bool hasNeed = false;
    if (t[0] == '.')
    {
        t[0] = 'o';
        hasNeed = true;
    }
    for (int i = 1; i < t.size(); i++)
    {
        if (t[i] == '#')
        {
            if (hasNeed)
                hasNeed = false;
        }
        else
        {
            if (!hasNeed)
            {
                t[i] = 'o';
                hasNeed = true;
            }
        }
    }

    cout << t;
    return 0;
}