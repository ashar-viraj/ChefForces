#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, k1, k2, w, b, itemp;
    cin >> t;
    while (t--)
    {
        cin >> n >> k1 >> k2;
        cin >> w >> b;
        int possw, possb;
        possw = k1 < k2 ? k1 : k2;
        possb = k1 > k2 ? n-k1 : n-k2;
        possw += (abs(k1-k2)/2);
        possb += (abs(k1-k2)/2);
        if(w <= possw && b <= possb)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}