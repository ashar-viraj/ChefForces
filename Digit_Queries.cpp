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

int isInRange(int n, int k)
{
    int l = to_string(n).size();

    int range = n;
    int ten = 10;
    while ((ten - 1) <= n)
    {
        range += (n - (ten - 1));
        ten *= 10;
    }

    if (range - l >= k)
        return -1;
    else
        return 1;
}

void print(int n, int k)
{
    int prev = n - 1;
    int prevRange = prev;
    int ten = 10;
    while ((ten - 1) <= prev)
    {
        prevRange += (prev - (ten - 1));
        ten *= 10;
    }

    int extra = k - prevRange;

    string ans = to_string(n);
    cout << ans[extra - 1] << endl;
}

int32_t main()
{
    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        int k;
        cin >> k;
        int low = 1, high = k, ans = 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int inRange = isInRange(mid, k);

            if (inRange == 1)
            {
                ans = mid;
                low = mid + 1;
            }
            if (inRange == -1)
                high = mid - 1;
        }

        print(ans, k);
    }
    return 0;
}