#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    int T, i, size;
    cin >> T;
    bool newstring;
    while (T--)
    {
        int count = 0;
        bool stringStart = false, stringEnd = true;
        cin >> a >> b;
        size = a.size();
        for (i = 0; i < size; i += 2)
        {
            if (a[i] != b[i])
            {
                stringStart = true;
                stringEnd = false;
            }
            if (a[i] == b[i])
            {
                if (stringStart)
                {
                    count++;
                }
                stringEnd = true;
                stringStart = false;
            }
        }
        if (stringStart)
        {
            count++;
        }
        //odd
        stringStart = false;
        stringEnd = true;
        for (i = 1; i < size; i += 2)
        {
            if (a[i] != b[i])
            {
                stringStart = true;
                stringEnd = false;
            }
            if (a[i] == b[i])
            {
                if (stringStart)
                {
                    count++;
                }
                stringEnd = true;
                stringStart = false;
            }
        }
        if (stringStart)
        {
            count++;
        }
        cout << count << endl;
    }
    return 0;
}