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
        vector<int> v(n + 1);
        v[0] = -2;
        rep(i, 1, n + 1)
        {
            cin >> v[i];
        }

        vector<vector<int>> inp;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] != 0)
                inp.push_back({v[i], i, i});
            else if (v[i] != v[i - 1])
                inp.push_back({v[i], i, i});
        }
        for (int i = 0; i < inp.size(); i++)
        {
            if (inp[i][0] == 0)
                if (i + 1 < inp.size())
                    inp[i][2] = inp[i + 1][1] - 1;
                else
                    inp[i][2] = n;
        }

        int oneCount = 0, minusOneCount = 0;
        i = 1;
        vector<vector<int>> ans;
        int start = -1;
        while (i < v.size())
        {
            cout << i << ' ' << oneCount << ' ' << minusOneCount << ' ' << start << endl;
            if (i + 1 <= n && v[i] != 0 && v[i] == v[i + 1])
            {
                if (start != -1)
                {
                    ans.push_back({start, i - 1});
                    start = -1;
                }
                ans.push_back({i, i + 1});
                i += 2;
            }
            else if (v[i] == 0)
            {
                if (start == -1)
                    start = i;
                i++;
            }
            else if (v[i] == 1)
            {
                if (minusOneCount != 0)
                {
                    if (start != -1)
                    {
                        ans.push_back({start, i - 1});
                        start = -1;
                    }
                    ans.push_back({i, i});
                    minusOneCount--;
                    i++;
                }
                else if (oneCount != 0)
                {
                    if (start != -1)
                    {
                        if (start != i - 1)
                            ans.push_back({start, i - 2});
                        ans.push_back({i - 1, i});
                        start = -1;
                        oneCount--;
                        i++;
                    }
                    else
                    {
                        ans.push_back({i, i});
                        oneCount++;
                        i++;
                    }
                }
                else
                {
                    if (start != -1)
                    {
                        if (start != i - 1)
                            ans.push_back({start, i - 2});
                        ans.push_back({i - 1, i});
                        minusOneCount++;
                        start = -1;
                        i++;
                    }
                    else
                    {
                        ans.push_back({i, i});
                        oneCount++;
                        i++;
                    }
                }
            }
            else
            {
                if (oneCount != 0)
                {
                    if (start != -1)
                    {
                        ans.push_back({start, i - 1});
                        start = -1;
                    }
                    oneCount--;
                    ans.push_back({i, i});
                    i++;
                }
                else if (minusOneCount != 0)
                {
                    if (start != -1)
                    {
                        if (start != i - 1)
                            ans.push_back({start, i - 2});
                        ans.push_back({i - 1, i});
                        start = -1;
                        minusOneCount--;
                        i++;
                    }
                    else
                    {
                        ans.push_back({i, i});
                        minusOneCount++;
                        i++;
                    }
                }
                else
                {
                    if (start != -1)
                    {
                        if (start != i - 1)
                            ans.push_back({start, i - 2});
                        ans.push_back({i - 1, i});
                        oneCount++;
                        start = -1;
                        i++;
                    }
                    else
                    {
                        ans.push_back({i, i});
                        minusOneCount++;
                        i++;
                    }
                }
            }
            cout << i - 1 << " : \n";
            for (auto e : ans)
            {
                cout << e[0] << ' ' << e[1] << endl;
            }
            cout << endl;
        }
        if (oneCount != 0 || minusOneCount != 0)
        {

            cout << "-1\n";
            continue;
        }
        if (start != -1)
            ans.push_back({start, n});

        cout << ans.size() << endl;

        for (auto e : ans)
        {
            cout << e[0] << ' ' << e[1] << endl;
        }
    }
    return 0;
}