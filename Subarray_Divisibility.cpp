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
    int n, k, sum = 0, ans = 0, val;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] = (v[i] % n + n) % n;
    }

    um<int, int> freq;
    freq[0] = 1;

    for (int i = 0; i < n; i++)
    {
        (sum += v[i]) %= n;
        int smallAns = freq[sum % n];
        ans += smallAns;
        freq[sum]++;
    }

    cout << endl;
    cout << ans << endl;

    return 0;
}