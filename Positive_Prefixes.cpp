// December Challenge 2020 Division 2
#include <bits/stdc++.h>
using namespace std;

void positivePrefixes(int N, int K)
{
    int i;
    vector<int> v;
    for (i = 0; i < N; i++)
    {
        v.push_back(-(i + 1));
    }
    i = 0;
    while (K > 0 && i < N)
    {
        v[i] = -v[i];
        i += 2;
        K--;
    }
    if (K != 0)
    {
        if (N % 2 == 0)
        {
            i = N - 1;
        }
        else
        {
            i = N - 2;
        }
        while (K > 0)
        {
            v[i] = -v[i];
            i -= 2;
            K--;
        }
    }
    for (i = 0; i < N; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int T, N, K;
    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        positivePrefixes(N, K);
    }
    return 0;
}