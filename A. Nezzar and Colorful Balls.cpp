#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for(i = a; i < b; i++)
#define mp make_pair

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, n, temp, a, b, c, d;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> v(n);
        set<int> s;
        map<int, int> freq;
        rep(i, 0, n)
        {
            cin >> v[i];
            s.insert(v[i]);
            freq[v[i]]++;
        }
        int count = 0;
        for(auto itr = s.begin(); itr!= s.end(); itr++)
        {
            // cout<< *itr << " " << freq[*itr] << "\n";
            if(freq[*itr] > count)
            {
                count = freq[*itr];
            }
        }
        cout << count << "\n";
        
    }
    return 0;
}