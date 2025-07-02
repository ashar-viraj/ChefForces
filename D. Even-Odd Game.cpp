#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int t, i, n, temp, d;
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        long long int turn = 1, alice_score = 0, bob_score = 0;
        for (i = n - 1; i >= 0; i--)
        {
            if (turn % 2)
            {
                if (a[i] % 2 == 0)
                {
                    alice_score += a[i];
                }
                //alice
            }
            else
            {
                if (a[i] % 2)
                {
                    bob_score += a[i];
                }
                //bob
            }
            // cout << alice_score << " " << bob_score << endl;
            turn++;
        }
        // cout << alice_score << " " << bob_score << endl;
        if (alice_score == bob_score)
        {
            cout << "Tie\n";
        }
        else if (alice_score > bob_score)
        {
            cout << "Alice\n";
        }
        else
        {
            cout << "Bob\n";
        }
    }
    return 0;
}