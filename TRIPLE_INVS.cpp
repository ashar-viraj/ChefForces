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
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<int> v(n);
        rep(i, 0, n) cin >> v[i];

        int state[4] = {0};
        bool valid = true;

        if (v[0] == 1 || v[0] == 2)
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i] == 0)
                {
                    if (v[i + 1] == 3)
                    {
                        valid = false;
                    }
                    else if (v[i + 1] == 1)
                    {
                        state[1] = 1;
                    }
                    else if (v[i + 1] == 2)
                    {
                        state[2] = 2;
                    }
                    else
                    {
                        state[1] = 0;
                        state[2] = 0;
                    }
                }
                else if (v[i] == 1)
                {
                    if (state[1] == 0 || state[1] == 1)
                    {
                        if (v[i + 1] == 0)
                        {
                            valid = false;
                            break;
                        }
                        else if (v[i + 1] == 1)
                        {
                            state[1] = 1;
                        }
                        else if (v[i + 1] == 2)
                        {
                            state[2] = 2;
                        }
                        else
                        {
                            state[1] = 0;
                            state[2] = 0;
                        }
                    }
                    else
                    {
                    }
                }
                else if (v[i] == 2)
                {
                }
                else
                {
                }
            }
        }
        else
        {
        }
    }
    return 0;
}