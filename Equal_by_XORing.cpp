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

string tobinary(int a)
{
    string ans = "";
    while (a)
    {
        ans = (char)(a % 2 + '0') + ans;
        a /= 2;
    }
    return ans;
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
        int a, b;
        cin >> a >> b >> n;
        int lsb1 = (1 << (int)log2(a ^ b)), lsb2 = (1 << (int)log2(n));
        // cout < < < < lsb1 << ' ' << lsb2 << endl;
        if (a == b)
        {
            cout << "0\n";
        }
        else
        {
        
            if ((n & (n - 1)) == 0)
            {
                if ((a ^ b) < n)
                    cout << "1\n";
                else
                    cout << "-1\n";
            }
            else if ((a ^ b) < n || (lsb1 < lsb2))
            {
                cout << "1\n";
            }
            else
            {
                
                int ans = 0;
                if (lsb1 > lsb2)
                {
                    cout << "-1\n";
                }
                else
                {
                    cout << "2\n";
                }
            }
        
        }
    }
    return 0;
}