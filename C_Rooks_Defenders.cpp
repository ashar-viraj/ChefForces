#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
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
    cin >> n >> m;
    vector<int> row(n + 1, 0), col(n + 1, 0);
    while (m--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x1, y1;
            cin >> x1 >> y1;
            row[x1]++;
            col[y1]++;
        }
        else if (t == 2)
        {
            int x1, y1;
            cin >> x1 >> y1;
            row[x1]--;
            col[y1]--;
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int rowCnt = 0, colCnt = 0;
            rep(i, x1, x2 + 1)
                rowCnt += (row[i] != 0);
            rep(i, y1, y2 + 1)
                colCnt += (col[i] != 0);

            if (rowCnt != (x2 - x1 + 1) && colCnt != (y2 - y1 + 1))
                cout << "No\n";
            else
                cout << "Yes\n";
        }
    }
    return 0;
}