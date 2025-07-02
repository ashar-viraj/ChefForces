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

bool isPoss(vector<int> &v, int n, int k, int maxSum)
{
    int rem = n, i = 0, sum = 0;
    k--;
    while (i < n)
    {
        if (v[i] > maxSum)
        {
            return false;
        }
        else if ((sum + v[i]) <= maxSum)
        {
            sum += v[i];
            i++;
        }
        else
        {
            sum = 0;
            k--;
        }
    }

    return k >= 0;
}

int32_t main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    for (auto &e : v)
        cin >> e;

    int low = 0, high = 0, ans;
    for (int i = 0; i < n; i++)
        high += v[i];
    ans = high;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPoss(v, n, k, mid))
        {
            ans = min(mid, ans);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans;

    return 0;
}