// December Challenge 2020 Division 2
#include <bits/stdc++.h>
using namespace std;

void hailXOR(vector<long long int> v, long long int n, long long int x)
{
    long long int i = 0, k, j, p, temp, time = 0;
    while (time != x)
    {
        temp = 0;
        if (i == n - 1)
        {
            break;
        }
        if (v[i] == 0)
        {
            i++;
            continue;
        }
        p = pow(2, log2(v[i]));
        for (k = i + 1; k < n; k++)
        {
            if (v[k] ^ p < v[k])
            {
                v[i] ^= p;
                v[k] ^= p;
                temp = 1;
                break;
            }
        }
        if (temp == 0)
        {
            v[i] ^= p;
            v[n - 1] ^= p;
            time++;
        }
    }
    if (n == 2)
    {
        time--;
        while (time != x)
        {
            v[0] ^= 1;
            v[1] ^= 1;
            time++;
        }
    }
    for (k = 0; k < n; k++)
    {
        cout << v[k] << " ";
    }
    cout << "\n";
}

int main()
{
    long long int t, i, n, x, temp;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        vector<long long int> v;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        hailXOR(v, n, x);
    }
    return 0;
}

//===============================================================================================================================================

// #include <bits/stdc++.h>
// using namespace std;

// void hailXOR(vector<long long int> v, int N, long long X)
// {
//     int i = 0, j, k, l, remaining;
//     long long int p, temp;
//     // bool idxI, idxJ;
//     for (l = 1; l <= X; l++)
//     {
//         j = 0;
//         temp = 0;
//         while (v[i] <= 0)
//         {
//             i++;
//         }
//         if (i == N)
//         {
//             break;
//         }
//         p = pow(2, log2(v[i]));
//         v[i] ^= p;
//         for (k = i + 1; k < N; k++)
//         {
//             if (v[k] ^ p < v[k])
//             {
//                 v[k] = v[k] ^ p;
//                 temp = 1;
//                 break;
//             }
//         }
//         if (temp == 0)
//         {
//             v[N - 1] = v[N - 1] ^ p;
//         }
//         remaining = i;
//     }

//     if (remaining != X)
//     {
//         if (N < 3 && remaining % 2 == 1)
//         {
//             v[0] ^= 1;
//             v[1] ^= 1;
//         }
//     }

//     for (i = 0; i < N; i++)
//     {
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     int T, N;
//     long long int i, X, temp;
//     cin >> T;
//     while (T--)
//     {
//         cin >> N >> X;
//         vector<long long int> v;
//         for (i = 0; i < N; i++)
//         {
//             cin >> temp;
//             v.push_back(temp);
//         }
//         hailXOR(v, N, X);
//     }
//     return 0;
// }