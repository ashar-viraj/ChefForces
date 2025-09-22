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
    int n;

    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, -1));
    um<int, um<int, bool>> col;

    for (int i = 0; i < n; i++)
    {
        set<int> s;
        for (int j = 0; j < 2 * n; j++)
            s.insert(j);

        for (int j = 0; j < n; j++)
        {
            int val;
            for (auto e : s)
            {
                if (!col[j][e])
                {
                    v[i][j] = e;
                    col[j][e] = true;
                    val = e;
                    break;
                }
            }

            s.erase(val);
        }
    }

    for (auto row : v)
    {
        for (auto e : row)
        {
            cout << e << ' ';
        }

        cout << endl;
    }

    return 0;
}