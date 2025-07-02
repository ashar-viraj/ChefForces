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
        map<string, map<char, bool>> pc; //already pcesent characters in words
        map<string, map<char, bool>> rc; //replaceable characters
        map<char, int> charCount;
        vector<string> v;
        rep(i, 0, n)
        {
            cin >> s;
            pc[s.substr(1, s.size() - 1)][s[0]] = true;
            v.push_back(s);
            charCount[s[0]]++;
        }
        for (auto itr = pc.begin(); itr != pc.end(); itr++)
        {
            for (auto ptr = charCount.begin(); ptr != charCount.end(); ptr++)
            {
                if (!itr->second[ptr->first])
                {
                    rc[itr->first][ptr->first] = true;
                }
            }
        }
        int count = 0, increase;
        for (auto itr = rc.begin(); itr != rc.end(); itr++)
        {
            auto ptr = itr;
            ptr++;
            if (ptr == rc.end())
                break;
            int remove = 0;
            while (ptr != rc.end())
            {
                increase = (itr->second.size()) * (ptr->second.size());
                remove = 0;
                for (auto ltr = ptr->second.begin(); ltr != ptr->second.end(); ltr++)
                {
                    if (itr->second[ltr->first] && charCount[ltr->first] < 2)
                    {
                        remove++;
                    }
                    if (!itr->second[ltr->first])
                    {
                        itr->second.erase(ltr->first);
                    }
                }
                count += increase;
                count -= remove;
                ptr++;
            }
        }
        cout << count * 2 << "\n";
    }
    return 0;
}