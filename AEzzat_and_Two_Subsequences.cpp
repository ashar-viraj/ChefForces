#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, b) for(auto i = a; i < b; i++)
#define endl '\n' 
#define mp make_pair


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, i, j, n, itemp;
    cin >> t;
    for(auto tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<double> v(n);
        double sum = 0, ans = LONG_MIN, tsum = 0;
        rep(i, 0, n)
        {
            cin >> v[i], sum += v[i];
            ans = max(ans, v[i]);
        }
        ans += (sum-ans)/((double)(n-1));
        cout << setprecision(30) << ans << endl;
    }
    return 0;
}