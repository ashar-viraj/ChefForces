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

void solve()
{
    int n;
    cin >> n;

    if (n == 3)
    {
        out("-1");
        return;
    }

    if (n == 6)
    {
        cout << "5 2 1 4 3" << endl;
        return;
    }

    vi ans(n);
    int k = 0;
    for (int i = 2; i <= n; i += 2)
    {
        ans[k] = i;
        k += 2;
    }

    k = 1;
    for (int i = 1; i <= n; i += 2)
    {
        ans[k] = i;
        k += 2;
    }

    for (int i = 0; i < n; i++)
    {
        if (ans[i] == 5)
            continue;

        cout << ans[i] << " ";
    }
    if (n >= 5)
        cout << "5";
    cout << endl;

    // int one = 0, two = 0, three = 0, zero = 0;
    // // for (int i = 0; i <= n; i++)
    // // {
    // //     if (i % 4 == 1)
    // //         one++;
    // //     else if (i % 4 == 2)
    // //         two++;
    // //     else if (i % 4 == 3)
    // //         three++;
    // //     else if (i % 4 == 0)
    // //         zero++;
    // // }
    // if (n == 3)
    // {
    //     out("-1");
    //     return;
    // }

    // vi ans;

    // for (int i = 1; i <= n; i++)
    // {
    //     if (i % 4 == 1)
    //         ans.push_back(i);
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     if (i % 4 == 0)
    //         ans.push_back(i);
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     if (i % 4 == 2)
    //         ans.push_back(i);
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     if (i % 4 == 3)
    //         ans.push_back(i);
    // }

    // // for (int i = 0; i < n; i++)
    // // {
    // //     cout << ans[i] << " ";
    // // }

    // // for(int i=0;i<n-2;i++)
    // // {
    // //     if( (ans[i]^ans[i+1]) == ans[i+2])
    // //     {
    // //         cout<<ans[i]<<" "<<ans[i+1]<<" "<<ans[i+2];
    // //     }
    // // }
    // cout << endl;
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