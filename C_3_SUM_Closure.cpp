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
        vector<int> zerov, negv, posv;
        int negval = 0, posval = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            cin >> itemp;
            if (itemp == 0)
            {
                zerov.push_back(0);
            }
            if (itemp > 0)
            {
                posv.push_back(itemp);
            }
            if (itemp < 0)
            {
                negv.push_back(itemp);
            }
            freq[itemp]++;
        }

        bool valid = true;
        if (negv.size() > 2 || posv.size() > 2)
        {
            valid = false;
        }
        else if ((negv.size() == 2 || posv.size() == 2) && (zerov.size() != 0))
        {
            valid = false;
        }
        else
        {
            vector<int> all;
            for (auto e : negv)
                all.push_back(e);
            for (auto e : posv)
                all.push_back(e);
            if (zerov.size())
                all.push_back(0);
            if (zerov.size() > 1)
                all.push_back(0);

            for (int i = 0; i < all.size(); i++)
            {
                for (int j = i + 1; j < all.size(); j++)
                {
                    for (int k = j + 1; k < all.size(); k++)
                    {
                        int req = all[i] + all[j] + all[k];
                        bool found = false;
                        for(auto e : all)
                            if(e == req) found = true;

                        if(!found)
                            valid = false;
                    }
                }
            }
        }
        out(valid);
    }
    return 0;
}
/*
  1   0  1  0  0 1 0 1 1
256 128 64 32 16 8 4 2 1
  9   8  7  6  5 4 3 2 1                              

        1
       11
      111
     1111
    11111
   111111
  1111111
 11111111
111111111
111111111
111111110
111111100
111111000
111110000
111100000
111000000
110000000
100000000
100000001
100000011
100000111
100001111
100011111
100111111
101111111
101111110
101111100
101111000
101110000
101100000
101000000
101000000
101000001
101000011
101000111
101001111
101001111
101001110
101001100
101001000
101001000
101001001
101001011

101001011
*/

/*
5 0
7 0
5 2
6 1
4 4
7 1

4 4
5 2
6 1
7 0
7 1
5 0

5 0
7 0
6 1
7 1
5 2
4 4

1 4
2 2
3 2
4 0
5 0
6 0
*/