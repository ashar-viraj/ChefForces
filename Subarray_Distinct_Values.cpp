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

int32_t main()
{
    int n, k;
    cin >> n >> k;
    um<int, int> freq;
    set<int> distinct;
    vector<int> v(n);

    rep(i, 0, n)
    {
        cin >> v[i];
    }

    int i = 0, j = 0, ans = 0;
    while (j < n)
    {
        freq[v[j]]++;
        distinct.insert(v[j++]);
        if (distinct.size() > k)
        {
            while (distinct.size() != k)
            {
                if (freq[v[i]] == 1)
                    distinct.erase(v[i]);
                freq[v[i]]--;
                i++;
            }
        }
        ans += (j - i);
    }

    cout << ans;

    return 0;
}