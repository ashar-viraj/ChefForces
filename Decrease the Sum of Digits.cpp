/*#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class A{
public:
    long long int n, min_mov = 0;
    short int s;
};

int main(){
    short int t, i;
    cin >> t;
    A dsd[t];
    for(i = 0; i < t; i++){
        cin >> dsd[i].n;

    }
}*/

// A normal IO example code
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, k, t;
	int cnt = 0;
	cin >> n >> k;
	for (int i=0; i<n; i++)
	{
		cin >> t;
		if (t % k == 0)
			cnt++;
	}
	cout << cnt << "\n";
	return 0;
}
