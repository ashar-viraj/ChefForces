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

void solve(vector<int> &b, int n)
{
    vector<int> v1;
    int xortotal = 0;
    for(int i = 0; i < n; i++)
    {
        
    }
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
        vector<bool> dp(31);
        vector<int> v(n + 1);
        for (int i = 0; i <= n; i++)
            cin >> v[i];

        int totalxor = 0;
        if (n % 2)
        {
            for (int i = 0; i <= n; i++)
            {
                totalxor ^= v[i];
            }
            bool totaldone = false;
            vector<int> ans;
            for (int i = 0; i <= n; i++)
            {
                if (v[i] == totalxor)
                {
                    if (!totaldone)
                    {
                        totaldone = true;
                        continue;
                    }
                    ans.push_back(v[i] ^ totalxor);
                    totaldone = true;
                }
                else
                {
                    ans.push_back(v[i] ^ totalxor);
                }
            }
            for (auto e : ans)
                cout << e << ' ';
            cout << endl;
        }
    }
    return 0;
}