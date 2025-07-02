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

void setVowelsInRange(vector<vector<int>> &vowelsInRange, string &s)
{
    unordered_map<char, int> vowIdx;
    vowIdx['a'] = 0;
    vowIdx['b'] = 1;
    vowIdx['c'] = 2;
    vowIdx['d'] = 3;
    vowIdx['e'] = 4;

    for (int i = 1; i < s.size(); i++)
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            vowelsInRange[i][vowIdx[s[i]]] = 1;

    for (int i = 1; i < s.size(); i++)
        for (int j = 0; j < 5; j++)
            vowelsInRange[i][j] += vowelsInRange[i - 1][j];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m, itemp;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        cout << "Case :" << tc << ": ";
        string s;
        cin >> s;
        s = '0' + s;
        n = s.size();
        vector<vector<int>> startIdx(26);
        for (int i = 1; i < n; i++)
            startIdx[s[i] - 'a'].push_back(i);

        vector<vector<int>> vowelsInRange(n, vector<int>(5, 0));

        setVowelsInRange(vowelsInRange, s);

        bool valid = false;
        /*
        a : word1 vow freq
        b : word2 vow freq
        c : word3 vow freq
        */
        for (auto c : startIdx)
        {
            for (int i = 0; i < c.size() && !valid; i++)
            {
                for (int j = i + 1; j < c.size() && !valid; j++)
                {
                    int astart = c[i], cstart = c[j];
                    for (int k = 0; !valid && (s[astart + k] == s[cstart + k]) && (astart < cstart); k++)
                    {
                        int as, ae, bs, be, cs, ce;
                        as = astart, ae = astart + k;
                        cs = cstart, ce = cstart + k;
                        bs = ae + 1, be = cs - 1;
                        if ((ae - as < 1) || (ce - cs < 1) || (be - bs < 0))
                            continue;
                        vector<int> avow(5, 0), bvow(5, 0), cvow(5, 0);

                        
                    }
                }
            }
            if (valid)
                break;
        }

        if (valid)
            cout << "Spell!\n";
        else
            cout << "Nothing\n";
    }
    return 0;
}