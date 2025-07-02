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

bool isPoss(vector<int> &t, int n, int time, int k)
{
    for (auto e : t)
    {
        int taskComplete = time / e;
        k = max(k - taskComplete, 0ll);
    }
    return k <= 0;
}

int32_t main()
{
    int n, k;
    cin >> n >> k;
    vector<int> t(n);
    for (auto &e : t)
        cin >> e;

    sort(t.begin(), t.end());
    int low = 0, high = t[n - 1] * k, ans = high;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPoss(t, n, mid, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << endl;

    return 0;
}