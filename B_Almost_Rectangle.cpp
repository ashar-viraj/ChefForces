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
        cin >> n;
        vector<string> vs;
        string s;
        rep(i, 0, n)
        {
            cin >> s;
            vs.push_back(s);
        }
        int point[4][2], p = 0;
        rep(i, 0, n)
        {
            s = vs[i];
            rep(j, 0, n)
            {
                if (s[j] == '*')
                {
                    point[p][0] = i;
                    point[p][1] = j;
                    p++;
                }
                if(p == 2)
                    break;
            }
        }
        if (point[0][0] == point[1][0])
        {
            point[2][0] = (point[0][0] + 1) % n;
            point[3][0] = (point[1][0] + 1) % n;
            point[2][1] = point[0][1];
            point[3][1] = point[1][1];
        }
        else if (point[0][1] == point[1][1])
        {
            point[2][0] = point[0][0];
            point[3][0] = point[1][0];
            point[2][1] = (point[0][1] + 1) % n;
            point[3][1] = (point[0][1] + 1) % n;
        }
        else
        {
            point[2][0] = point[0][0];
            point[2][1] = point[1][1];
            point[3][0] = point[1][0];
            point[3][1] = point[0][1];
        }
        vs[point[2][0]][point[2][1]] = '*';
        vs[point[3][0]][point[3][1]] = '*';
        rep(i, 0, n)
        {
            cout << vs[i] << endl;
        }
    }
    return 0;
}