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
    int n;
    cin >> n;
    vector<int> v(n);
    um<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans = 0, len = 0, i = 0, j = 0;
    while (j < n)
    {
        if (freq[v[j]] == 1)
        {
            freq[v[i]]--;
            len--;
            i++;
            continue;
        }

        freq[v[j]]++;
        j++;
        len++;
        ans = max(ans, len);
    }
    cout << ans << endl;
    return 0;
}