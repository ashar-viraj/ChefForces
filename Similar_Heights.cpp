#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define rep(i, a, b) for (int i = a; i < b; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define impos cout << "-1" << endl
#define acum(x) accumulate(x.begin(), x.end(), 0ll)
#define out(x) cout << x << endl
#define in(x) cin >> x
#define pii pair<int, int>
#define vi vector<int>
#define vpi vector<pii>
#define vvi vector<vector<int>>
#define vvpi vector<vector<pii>>

const int x[4] = {0, -1, 0, 1};
const int y[4] = {-1, 0, 1, 0};
// cout <<"Case #"<< t << ": " << solve() << endl;

int maxSumSubarray(vector<int> &a, int n)
{
    int maxSum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum < 0)
            sum = 0;
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

void getPrimeNumbers(vi &sieve, int n)
{
    sieve[0] = false;
    sieve[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

void solve()
{
    int n, c, q;
    cin >> n >> c >> q;

    string s;
    in(s);
    s = ' ' + s;
    vector<pair<int, int>> a;
    // a.push_back({-1, -1});
    // a.push_back({1,n});

    vi prefix;
    prefix.push_back(n);

    for (int i = 1; i <= c; i++)
    {
        int l, r;
        cin >> l >> r;
        a.push_back({l, r});
        prefix.push_back(prefix[i-1] + (r - l + 1));
    }

    while (q--)
    {
        int k;
        in(k);
        
        while (k > n)
        {
            int in = lower_bound(prefix.begin(),prefix.end(),k) - prefix.begin();
            int ans = a[in - 1].first + (k - prefix[in - 1] - 1);
            k = ans;
        }

        out(s[k]);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}