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
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);

        int count = 0;
        map<int, int> mp;
        for (auto &e : v)
        {
            cin >> e;
            mp[e]++;
            count += (e == k);
        }

        int extra = 0;

        for(int i = 0; i < k; i++) {
            if(mp[i] == 0) extra++;
        }

        // if(count >= extra)
        //     cout << count << endl;
        // else if(count < extra)
        //     cout << extra << endl;

        cout << max(count, extra) << endl;
    }
    return 0;
}