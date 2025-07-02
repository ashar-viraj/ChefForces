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

    int t, i, j, n, m, itemp;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        vector<int> a(n), b(n), c(m), painterShouldPaint;
        map<int, int> initial, colorsRequired, colorsAvailable;
        map<int, vector<int>> changesRequired;
        int cr = 0; //colors required in number
        // vector<pair<int, int>> changesRequired;

        rep(i, 0, n)
        {
            cin >> a[i];
            initial[a[i]] = i + 1;
        }
        rep(i, 0, n)
        {
            cin >> b[i];
            if (a[i] != b[i])
            {
                cr++;
                changesRequired[b[i]].push_back(i+1);
                colorsRequired[b[i]]++;
            }
        }
        rep(i, 0, m)
        {
            cin >> c[i];
            colorsAvailable[c[i]]++;
        }
        if (cr > m)
        {
            cout << "NO\n";
            continue;
        }
        int count = 0;
        bool valid = true;
        rep(i, 0, m)
        {
            if(changesRequired[c[i]].empty())
            {
                changesRequired.erase(c[i]);
                count++;
            }
            else
            {
                for(j = 0; j <= count; j++)
                {
                    painterShouldPaint.push_back(changesRequired[c[i]][0]);
                    // valid++;
                }
                changesRequired[c[i]].erase(changesRequired[c[i]].begin());
                if(changesRequired[c[i]].empty())
                {
                    changesRequired.erase(c[i]);
                }
                count = 0;
            }
        }
        for(auto itr = changesRequired.begin(); itr!=changesRequired.end(); itr++)
        {
            if(!itr->second.empty())
            {
                valid = false;
                break;
            }
        }
        if(!valid)
        {
            cout << "NO\n";
            continue;
        }
        if(count!=0)
        {
            if(initial[c[c.size()-1]] != 0)
            {
                rep(i, 0, count)
                {
                    painterShouldPaint.push_back(initial[c[c.size()-1]]);
                }
            }
            else
            {
                valid = false;
            }
        }
        if(valid)
        {
            cout << "YES\n";
            rep(i, 0, painterShouldPaint.size())
            {
                cout << painterShouldPaint[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}