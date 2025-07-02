#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (i = a; i < b; i++)
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
        if (n == 2)
        {
            int a, b, c, d;
            cin >> a >> b;
            cin >> c >> d;
            if (a < b)
            {
                cout << "0\n";
            }
            else
            {
                cout << (c==1 ? 2 : 1) << "\n";
            }
        }
        else
        {
            vector<int> fp;
            map<int, int>  position, l;
            rep(i, 0, n)
            {
                cin >> itemp;
                position[itemp] = i;
                fp.push_back(itemp);
            }
            rep(i, 0, n)
            {
                cin >> itemp;
                l[fp[i]] = itemp;
            }
            sort(fp.begin(), fp.end());
            int operation = 0;
            for(i = 1; i < n; i++)
            {
                if(position[fp[i]] <= position[fp[i-1]])
                {
                    itemp = (abs(position[fp[i-1]] - position[fp[i]]) / l[fp[i]] + 1);
                    operation += itemp;
                    position[fp[i]] = position[fp[i]] + itemp*l[fp[i]];
                }
            }
            cout  << operation << "\n";
        }   
    }
    return 0;
}