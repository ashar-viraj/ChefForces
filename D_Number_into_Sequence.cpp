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
        unordered_map<int, int> mp;
        int i = 2, temp = n;
        while (i * i <= n)
        {
            while (n % i == 0)
            {
                mp[i]++;
                n /= i;
            }
            i++;
        }
        if (n != 1)
            mp[n]++;

        n = temp;
        int freq = 1, num = n;
        for (auto e : mp)
            if (e.second > freq)
                num = e.first, freq = e.second;

        if (num == n)
        {
            cout << 1 << "\n"
                 << n << endl;
            continue;
        }

        cout << freq << endl;
        freq--;
        while (freq > 0)
        {
            cout << to_string((int)num) << ' ';
            freq--;
        }

        cout << to_string((int)(n / (int)pow(num, mp[num] - 1))) << endl;
    }
    return 0;
}