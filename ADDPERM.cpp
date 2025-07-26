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
#define pb push_back
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int diff = floor((float)n / (float)k);

        int curr = 1;

        set<int> s;

        if (k * 2 <= n)
        {
            int temp = k, i = 1;
            for (i = 1; i <= n; i += diff, temp--)
            {
                for (int j = min(n, i + diff - 1); j >= i; j--)
                {
                    cout << j << ' ';
                    s.insert(j + curr);
                    curr++;
                }
                if (temp == 2)
                {
                    i += diff;
                    break;
                }
            }

            for (int j = n; j >= i; j--)
            {
                cout << j << ' ';
                s.insert(j + curr);
                curr++;
            }
        }

        else
        {
            for (int i = 1; i < k; i++)
            {
                cout << i << ' ';
                s.insert(i + curr);
                curr++;
            }
            for (int i = n; i >= k; i--)
            {
                cout << i << ' ';
                s.insert(i + curr);
                curr++;
            }
        }

        // cout << " | " << k << ' ' << (s.size() == k);

        cout << endl;
    }
    return 0;
}