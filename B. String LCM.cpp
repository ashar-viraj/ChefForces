// #include <bits/stdc++.h>
// using namespace std;

// void StringLCM(string a, string b)
// {
//     // find the shortest substring in the string
//     string x, y, stemp;
//     bool found;
//     int i, j, k;
//     for (i = 0; i < a.size(); i++)
//     {
//         if (a.size() % (i + 1) != 0)
//         {
//             continue;
//         }
//         stemp = a.substr(0, i + 1);
//         found = true;
//         for (j = 0; j < a.size(); j += i + 1)
//         {
//             if (a.substr(j, stemp.size()) != stemp)
//             {
//                 found = false;
//                 break;
//             }
//         }
//         if (found)
//         {
//             x = stemp;
//             break;
//         }
//     }
//     for (i = 0; i < b.size(); i++)
//     {
//         if (b.size() % (i + 1) != 0)
//         {
//             continue;
//         }
//         stemp = b.substr(0, i + 1);
//         // cout << stemp;
//         found = true;
//         for (j = 0; j < b.size(); j += i + 1)
//         {
//             if (b.substr(j, stemp.size()) != stemp)
//             {
//                 found = false;
//                 break;
//             }
//         }
//         if (found)
//         {
//             y = stemp;
//             break;
//         }
//     }
//     // cout << "x = " << x << "\n";
//     // cout << "y = " << y << "\n";
//     // abc abc abc abc abc abc abc
//     // abc abc abc abc abc abc abc
//     // abc abc abc abc abc abc abc
//     if (x == y)
//     {
//         string s = "";
//         int l1 = a.size() / x.size(), l2 = b.size() / x.size();
//         int l = l1 * l2 / (__gcd(l1, l2));
//         // cout << "l = " << l << "\n";
//         for (i = 0; i < l; i++)
//         {
//             s += x;
//         }
//         cout << s << "\n";
//     }
//     else
//     {
//         cout << "-1\n";
//     }
// }

// int main()
// {
//     int t, i;
//     string a, b;
//     cin >> t;
//     while (t--)
//     {
//         cin >> a >> b;
//         if (a.size() == b.size())
//         {
//             if (a == b)
//             {
//                 cout << a << "\n";
//             }
//             else
//             {
//                 cout << "-1\n";
//             }
//         }
//         else if (a.size() > b.size())
//         {
//             StringLCM(a, b);
//         }
//         else
//         {
//             StringLCM(b, a);
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, t, n, x, temp;
    cin >> t;
    while (t--)
    {
        int count = 0;
        cin >> n >> x;
        vector<int> v;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        bool arr[1000000], found = false;
        memset(arr, false, sizeof(arr));
        for (i = 0; i < n; i++)
        {
            if (arr[v[i]])
            {
                cout << "1\n";
                found = true;
                break;
            }
            if (v[i] > n)
            {
                arr[v[i] - n] = true;
            }
            arr[v[i] + n] = true;
        }
        if (!found)
        {
            cout << "-1\n";
        }
    }
    return 0;
}