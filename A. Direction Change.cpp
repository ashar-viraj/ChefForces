#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define reprev(i, a, b) for (auto i = a; i >= b; i--)
#define endl '\n'
#define mp make_pair
#define MOD 1000000007
#define out(valid) cout << (valid ? "YES\n" : "NO\n")

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, i, j, n, m, itemp;
	cin >> t;
	for (auto tc = 1; tc <= t; tc++)
	{
		cin >> n >> m;
		if (m == 0)
		{
			if (n % 4 == 0)
				cout << "Off\n";
			else
				cout << "On\n";
		}
		else
		{
			if (n % 4 == 0)
				cout << "On\n";
			else
				cout << "Ambiguous\n";
		}
	}
	return 0;
}