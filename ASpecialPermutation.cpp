#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, i, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        vector<int> v;
        for (i = 0; i < N; i++)
        {
            v.push_back(N - i);
        }
        if (N % 2 == 1)
        {
            swap(v[N / 2], v[(N / 2) + 1]);
        }
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}