// December Challenge 2020 Division 2
#include <bits/stdc++.h>
using namespace std;

int vaccineDistribution(vector<int> v, int N, int D, int risk)
{
    int days = 0, notRisk = N - risk;
    // cout << "Risk = " << risk << endl;
    // cout << "notRisk = " << notRisk << endl;
    if (risk % D == 0)
    {
        days += risk / D;
    }
    else
    {
        days += risk / D + 1;
    }

    if (notRisk % D == 0)
    {
        days += notRisk / D;
    }
    else
    {
        days += notRisk / D + 1;
    }
    return days;
}

int main()
{
    int T, N, D, i, temp, risk;
    cin >> T;
    while (T--)
    {
        risk = 0;
        cin >> N >> D;
        vector<int> v;
        for (i = 0; i < N; i++)
        {
            cin >> temp;
            v.push_back(temp);
            if (temp <= 9 || temp >= 80)
                risk++;
        }
        cout << vaccineDistribution(v, N, D, risk) << endl;
    }
    return 0;
}