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

    int t, i, j, n, itemp;
    cin >> t;
    while (t--)
    {
        string stemp;
        cin >> n;
        vector<string> s;
        map<int, map<char, int>> freq;
        rep(i, 0, n)
        {
            cin >> stemp;
            sort(stemp.begin(), stemp.end());
            s.push_back(stemp);
        }
        for (int i = 0; i < s.size(); i++)
            rep(j, 0, 5)
                freq[i]['a' + j] = count(s[i].begin(), s[i].end(), 'a' + j);

        vector<int> v[5];
        for (auto e : freq)
            rep(i, 0, 5)
                v[i].push_back(e.second['a' + i] - (s[e.first].size() - e.second['a' + i]));

        rep(i, 0, 5)
            sort(v[i].begin(), v[i].end());

        int ans = 0, count = 0, length = 0, add;
        for (i = 0; i < 5; i++)
        {
            length = 0;
            count = 0;
            for (auto itr = v[i].rbegin(); itr != v[i].rend(); itr++)
            {
                if (count + *itr <= 0)
                    break;
                count += *itr;
                length++;
            }
            ans = max(ans, length);
        }
        cout << ans << endl;
    }
    return 0;
}