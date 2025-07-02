#include <bits/stdc++.h>
using namespace std;

bool rabinKarp(string txt, string pat, int i)
{
    int j;
    for (j = i; j < i + pat.size(); j++)
    {
        if (txt[j] != pat[j - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string txt, pat;
    cin >> txt >> pat;
    int i, j, count;
    for (i = 0; i <= txt.size() - pat.size(); i++)
    {
        if (txt[i] == pat[0] & rabinKarp(txt, pat, i))
        {
            cout << i << " ";
        }
    }
    return 0;
}