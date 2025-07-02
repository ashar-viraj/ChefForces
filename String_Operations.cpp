// December Challenge 2020 Division 2
#include <bits/stdc++.h>
using namespace std;

// bool same(const tuple<int, int, int> a, const tuple<int, int, int> b)
// {
//     if (get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b))
//     {
//         return true;
//     }
//     return false;
// }

pair<int, int> countOddEven(string s)
{
    pair<int, int> p;
    int i, o = 0, e = 0, one = 0;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            one++;
        }
        if (s[i] == '0')
        {
            if (one % 2 == 0)
            {
                e++;
            }
            else
            {
                o++;
            }
        }
    }
    p = make_pair(e, o);
    return p;
}

int stringOperation(string s)
{
    set<tuple<int, int, int>> v;
    set<string> repeat;
    pair<int, int> p;
    int i, j, l, e, o;
    string temp;
    for (i = 0; i < s.size(); i++)
    {
        for (j = i + 1; j <= s.size(); j++)
        {
            temp = s.substr(i, j - i);
            if (!repeat.empty() & repeat.find(temp) == repeat.end())
                continue;
            l = temp.size();
            p = countOddEven(temp);
            e = p.first;
            o = p.second;
            tuple<int, int, int> ttemp = make_tuple(l, e, o);
            v.insert(ttemp);
        }
    }
    return v.size();
}
int main()
{
    int t, i;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        cout << stringOperation(s) << "\n";
    }
    return 0;
}