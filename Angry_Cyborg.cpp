#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, q, l, r;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        int arr[n] = {0};
        for (i = 0; i < q; i++)
        {
            cin >> l >> r;
            int statueDestroy = 1;
            for (int j = l; j <= r; j++, statueDestroy++)
            {
                arr[j - 1] += statueDestroy;
            }
        }
        for (i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}