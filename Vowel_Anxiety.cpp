#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<int> vs;
typedef pair<int, int> pi;
typedef unordered_map<int, int> mpii;
typedef unordered_map<int, bool> mpib;
#define MOD 1000000007

#define For(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define Forn(i, s, e) for (int(i) = (s); (i) <= (e); ++(i))
#define ford(i, s, e) for (int(i) = (s); (i) >= (e); --(i))
#define fi first
#define se second
#define sz(v) v.size()
#define ALL(v) v.begin(), v.end()
// Modular Exponential
int power(long long x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> v(N);
        for (int i = 0; i < N; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int sum = 0;
        int maxi1 = INT_MIN;
        int maxi2 = INT_MIN;
        for (int i = 0; i < N; i++)
        {
            sum += v[i];
            int sum2 = 0;
            for (int j = i + 1; j < N; j++)
            {
                sum2 += (1000 - v[j]);
            }
            maxi1 = max(maxi1, sum * sum2);
        }
        sum = 0;
        for (int i = N - 1; i >= 0; i--)
        {
            sum += v[i];
            int sum2 = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                sum2 += (1000 - v[j]);
            }
            maxi2 = max(maxi2, sum * sum2);
        }
        // cout << at << " " << def << endl;
        cout << max(maxi1, maxi2) << endl;
    }
    return 0;
}