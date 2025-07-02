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
        string s;   
        cin >> s;
        char check = 'a';
        int l = s.find('a'), r = l;
        bool found = false;
        rep(i, 0, s.size())
        {
            if(s[i] == check)
            {
                l = i-1;
                r = i+1;
                check++;
                found = true;
                break;
            }
        }
        if(!found)
        {
            cout << "NO\n";
            continue;
        }
        while (true)
        {
            if (s[l] == check && l >= 0)
            {
                l--;
                check++;
            }
            else if (s[r] == check && r < s.size())
            {
                r++;
                check++;
            }
            else
            {
                if (l < 0 && r >= s.size())
                    break;
                found = false;
                break;
            }
        }
        if (found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}