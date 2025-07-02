#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    char c;
    map<string, bool> m;
    // map<string, map<char, bool>> m;
    // cin >> s;
    // for (int i = 0; i < 7; i++)
    // {
    //     cin >> c;
    //     m[s][c] = true;
    // }
    // cin >> s;
    // for (int i = 0; i < 6; i++)
    // {
    //     cin >> c;
    //     m[s][c] = true;
    // }
    // cin >> s;
    // for (int i = 0; i < 5; i++)
    // {
    //     cin >> c;
    //     m[s][c] = true;
    // }
    // cin >> s;
    // for (int i = 0; i < 5; i++)
    // {
    //     cin >> c;
    //     m[s][c] = true;
    // }
    for(int i = 0; i < 6; i++)
    {
        cin >> s;
        m[s] = true;
    }
    for (auto itr = m.begin(); itr != m.end(); itr++)
    {
        auto ptr =itr;
        ptr++;
        if(ptr == m.end())
            break;
        cout  << itr->first << "\n";
        while(ptr != m.end())
        {
            cout << (ptr->first) << " ";
            ptr++;
        }
        cout  << "\n\n";
    }

    return 0;
}
/*
bell
b
tell
c
hell
e
hell
a
bell
d
tell
q
tell
f
hell
r
bell
w
bell
t
*/

/*
bell
b
tell
c
hell
c
bell
a
tell
b
hell
a
bell
d
tell
d
hell
d
bell
e
tell
f
hell
e
bell
h
tell
h
hell
f
*/