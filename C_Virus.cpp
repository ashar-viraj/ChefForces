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
#define um unordered_map
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
        cin >> n >> m;
        queue<int> q;
        um<int, bool> isinfect, isprotect;
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> itemp;
            itemp--;
            q.push(itemp);
            isinfect[itemp] = true;
        }

        while (q.size())
        {
            int size = q.size();
            ans += size;
            bool isProtectDone = false;
            while (size--)
            {
                int house = q.front();
                q.pop();
                if (!isprotect[(house - 1 + n) % n])
                {
                    if (!isProtectDone && !isinfect[(house - 1 + n) % n])
                        isprotect[(house - 1 + n) % n] = true, isProtectDone = true;
                    else if (!isinfect[(house - 1 + n) % n])
                        isinfect[(house - 1 + n) % n] = true, q.push((house - 1 + n) % n);
                }
                if (!isprotect[(house + 1) % n])
                {
                    if (!isProtectDone && !isinfect[(house + 1) % n])
                        isprotect[(house + 1) % n] = true, isProtectDone = true;
                    else if (!isinfect[(house + 1) % n])
                        isinfect[(house + 1) % n] = true, q.push((house + 1) % n);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
1 11 21 31 41

p : 9
days passed : 2
6 10 10



*/