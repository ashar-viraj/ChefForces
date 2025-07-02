#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (i = a; i < b; i++)
#define endl '\n'
#define mp make_pair

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, itemp;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        map<string, map<char, bool>> m;
        rep(i, 0, n)
        {
            cin >> s;
            m[s.substr(1, s.size() - 1)][s[0]] = true;
        }
        int count = 0;
        for (auto itr = m.begin(); itr != m.end(); itr++)
        {
            auto ptr = itr;
            ptr++;
            if (ptr == m.end())
                break;
            while (ptr != m.end())
            {
                int increase = itr->second.size() * ptr->second.size(), decrease = 0;
                for (auto ltr = ptr->second.begin(); ltr != ptr->second.end(); ltr++)
                {
                    if (itr->second[ltr->first])
                    {
                        decrease++;
                    }
                    else
                    {
                        itr->second.erase(ltr->first);
                    }
                }
                count += increase - (itr->second.size() + ptr->second.size()) * decrease + decrease * decrease;
                ptr++;
            }
        }
        cout << count*2 << endl;
    }
    return 0;
}