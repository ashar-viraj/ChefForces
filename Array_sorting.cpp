#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a, b, c;
    cin >> a >> b;
    int remain = abs(a.size() - b.size());
    int i, j;
    if (a.size() == b.size())
    {
        c = a;
        i = 0, j = 0;
    }
    else if (a.size() > b.size())
    {
        i = remain, j = 0;
        c = a;
    }
    else
    {
        i = 0, j = remain;
        c = b;
    }
    int k = remain;

    while (i < a.size())
    {
        if (a[i] == b[j])
        {
            c[k] = '0';
        }
        else
        {
            c[k] = '1';
        }
        i++, j++, k++;
    }

    cout << c;

    return 0;
}
