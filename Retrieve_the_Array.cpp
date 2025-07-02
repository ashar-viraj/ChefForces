#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define MOD 1000000007
#define um unorederd_map
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
#define f first
#define s second
class Solution
{
public:
    int maxTrailingZeros(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<pair<int, int>>> freq(n, vector<pair<int, int>>(m, {0, 0}));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                while (mat[i][j] % 2 == 0)
                {
                    freq[i][j].f++;
                    mat[i][j] /= 2;
                }
                while (mat[i][j] % 5 == 0)
                {
                    freq[i][j].s++;
                    mat[i][j] /= 5;
                }
            }
        }

        vector<vector<pair<int, int>>> up, down, left, right;
        up = freq;
        down = freq;
        left = freq;
        right = freq;

        for (int i = 1; i < n; i++)
            for (int j = 0; j < m; j++)
                up[i][j].f += up[i - 1][j].f, up[i][j].s += up[i - 1][j].s;

        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j < m; j++)
                down[i][j].f += down[i + 1][j].f, down[i][j].s += down[i + 1][j].s;

        for (int j = 1; j < m; j++)
            for (int i = 0; i < n; i++)
                left[i][j].f += left[i][j - 1].f, left[i][j].s += left[i][j - 1].s;

        for (int j = m - 2; j >= 0; j--)
            for (int i = 0; i < n; i++)
                right[i][j].f += right[i][j + 1].f, right[i][j].s += right[i][j + 1].s;

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int smallAns;
                smallAns = min(up[i][j].f + down[i][j].f - freq[i][j].f, up[i][j].s + down[i][j].s - freq[i][j].s);
                ans = max(smallAns, ans);

                smallAns = min(left[i][j].f + right[i][j].f - freq[i][j].f, left[i][j].s + right[i][j].s - freq[i][j].s);
                ans = max(smallAns, ans);

                smallAns = min(left[i][j].f + up[i][j].f - freq[i][j].f, left[i][j].s + up[i][j].s - freq[i][j].s);
                ans = max(smallAns, ans);

                smallAns = min(right[i][j].f + up[i][j].f - freq[i][j].f, right[i][j].s + up[i][j].s - freq[i][j].s);
                ans = max(smallAns, ans);

                smallAns = min(right[i][j].f + down[i][j].f - freq[i][j].f, right[i][j].s + down[i][j].s - freq[i][j].s);
                ans = max(smallAns, ans);

                smallAns = min(left[i][j].f + down[i][j].f - freq[i][j].f, left[i][j].s + down[i][j].s - freq[i][j].s);
                ans = max(smallAns, ans);
            }
        }
    }
};

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
        vector<int> b(n), a(n);
        int toal = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            toal += b[i];
        }
        int total = toal / (n + 1);
        for (int i = 0; i < n; i++)
        {
            cout << b[i] - total << ' ';
        }
        cout << endl;
    }
    return 0;
}

/*
bi = total + ai;

total : b sum
s : asum
bsum = (n+1)*asum

total - s-a[0]

(n-1)s + (s-a0)
ns-a0 = total - b0
a0 = n(total/(n+1))-total+b0
a0 = total(n/(n+1) - 1) + b0
a0 = total(n-n-1)/(n+1) + b0
a0 = b0 - total/(n+1)
ai = bi - total/(n+1)
*/
/*
 <ImageButton
            android:onClick="paintClicked"
            android:src="@drawable/pallete_normal"
            android:tag="@color/skin" />
*/