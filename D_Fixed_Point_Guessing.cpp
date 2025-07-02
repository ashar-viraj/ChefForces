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

void solve(int low, int high)
{
    if (low == high)
    {
        cout << "! " << high << endl
             << endl;
        fflush(stdout);
        cout.flush();
        return;
    }

    int mid = (low + high) / 2;
    cout << "? " << low << ' ' << mid << endl
         << endl;

    vector<int> v;
    fflush(stdout);
    cout.flush();
    for (int i = low; i <= mid; i++)
    {
        int val;
        cin >> val;
        v.push_back(val);
    }
    int lieInRange = 0;

    for (auto e : v)
    {
        if (e >= low && e <= mid)
            lieInRange++;
    }
    if (lieInRange % 2)
    {
        solve(low, mid);
    }
    else
    {
        solve(mid + 1, high);
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
        solve(1, n);
    }
    return 0;
}
/*
1
5
? 1 3

2 4 5
? 1 2

2 4
? 1 1

4
! 2
*/