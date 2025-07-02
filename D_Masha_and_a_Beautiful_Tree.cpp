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

bool check(vector<int> &v, int left, int right, int start, int end)
{
    if (left == right)
    {
        return v[left] == start;
    }

    int mid = (start + end) / 2;

    if (v[left] <= mid)
    {
        return (check(v, left, (left + right) / 2, start, mid) & check(v, ((left + right) / 2) + 1, right, mid + 1, end));
    }
    else
    {
        return (check(v, left, (left + right) / 2, mid + 1, end) & check(v, ((left + right) / 2) + 1, right, start, mid));
    }
}

int solve(vector<int> &v, int left, int right, int start, int end)
{
    if (left == right)
    {
        return 0;
    }

    int mid = (start + end) / 2;
    int ans = 0;

    if (v[left] <= mid)
    {
        ans += solve(v, left, (left + right) / 2, start, mid);
        ans += solve(v, ((left + right) / 2) + 1, right, mid + 1, end);
    }
    else
    {
        ans += solve(v, left, (left + right) / 2, mid + 1, end);
        ans += solve(v, ((left + right) / 2) + 1, right, start, mid);
    }
    if (v[left] != start)
        ans++;
    v[left] = start;
    v[right] = end;

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
        cin >> n;
        vector<int> v(n);
        rep(i, 0, n)
        {
            cin >> v[i];
        }

        bool valid = check(v, 0, n - 1, 1, n);
        if (valid)
            cout << solve(v, 0, n - 1, 1, n) << endl;
        else
            cout << "-1\n";
    }
    return 0;
}