#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int t, i, it1, it2, temp, a, b, k, j, l;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> k;
        vector<long long int> boy, girl, BG;
        map<long long int, long long int> gcount;
        long long int id[a], count = 0;
        memset(id, 0, sizeof(id));
        vector<pair<long long int, long long int>> pairs;
        for (i = 0; i < k; i++)
        {
            cin >> temp;
            boy.push_back(temp);
        }
        for (i = 0; i < k; i++)
        {
            cin >> temp;
            gcount[temp]++;
            girl.push_back(temp);
        }

        long long int total = k;
        for (i = 0; i < k; i++)
        {
            pairs.push_back(make_pair(boy[i], girl[i]));
            id[boy[i]-1]++;
        }
        sort(pairs.begin(), pairs.end());
        
        long long int boyptr = pairs[0].first;
        total -= id[pairs[0].first-1];
        gcount[pairs[0].second]--;
        count += total-gcount[pairs[0].second];
        
        for(i = 1; i < pairs.size(); i++)
        {
            if(total==0)
            {
                break;
            }
            if(pairs[i].first != boyptr)
            {
                boyptr = pairs[i].first;
                total-=id[pairs[i].first-1];
            }
            if(total==0)
            {
                break;
            }
            gcount[pairs[i].second]--;
            count += total-gcount[pairs[i].second];
        }
        cout << count << "\n";
    }
    return 0;
}
/*
1
5
5
12
4 3 5 1 5 4 3 2 2 4 2 1
2 1 4 3 2 5 3 1 2 1 3 4
*/