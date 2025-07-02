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
        vector<int> v(n);
        map<int, int> freq;
        rep(i, 0, n)
        {
            cin >> v[i];
            freq[v[i]]++;
        }

        int ans = 1;
        int i = 0, j = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto e : freq)
        {
            int rem = e.second; 
            int val = e.first;
            while (rem > 0)
            {
                if (pq.empty())
                {
                    pq.push(1);
                    rem--;
                }
                else if (pq.top() < val)
                {
                    int avail = pq.top();
                    int oldAvail = avail;
                    pq.pop();
                    avail = val - avail;
                    if (avail <= rem)
                    {
                        pq.push(val);
                        rem -= avail;
                    }
                    else
                    {
                        pq.push(oldAvail + rem);
                        rem = 0;
                    }
                }
                else
                {
                    pq.push(1);
                    rem--;
                }
            }
        }
        cout << pq.size() << endl;
    }
    return 0;
}