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

    int t, i, j, n, itemp, l, r, s;
    cin >> t;
    while (t--)
    {
        cin >> n >> l >> r >> s;
        l--, r--;
        int add = 1, reqs = s;
        vector<int> ans, fans;
        map<int, int> m;
        while (ans.size() != (r - l + 1))
        {
            ans.push_back(add);
            reqs -= add++;
        }
        if (reqs < 0)
        {
            cout << "-1\n";
        }
        else if (reqs == 0)
        {
            rep(i, 0, l)
                fans.push_back(add++);
            rep(i, l, r + 1)
                fans.push_back(ans[i - l]);
            rep(i, r + 1, n)
                fans.push_back(add++);
            for (auto e : fans)
                cout << e << " ";
            cout << endl;
        }
        else
        {
            bool found = true;
            ans[ans.size() - 1] += reqs;
            int maxadd = n;
            for (i = ans.size() - 1; i >= 1; i--)
            {
                if (ans[i] <= maxadd)
                    break;
                else
                {
                    ans[i - 1] += ans[i] - maxadd;
                    ans[i] = maxadd;
                    maxadd--;
                }
            }
            rep(i, 0, ans.size())
            {
                if (m[ans[i]])
                {
                    found = false;
                    break;
                }
                else
                {
                    m[ans[i]] = 1;
                }
            }
            if (!found || *max_element(ans.begin(), ans.end()) > n)
            {
                cout << "-1\n";
            }
            else
            {
                int k = 1;
                rep(i, 0, l)
                {
                    while (m[k])
                    {
                        k++;
                    }
                    cout << k << " ";
                    m[k] = 1;
                }
                for (auto e : ans)
                {
                    cout << e << " ";
                }
                rep(i, r + 1, n)
                {
                    while (m[k])
                    {
                        k++;
                    }
                    cout << k << " ";
                    m[k] = 1;
                }
                cout << endl;
            }
        }
    }
    return 0;
}