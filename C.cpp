#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &v, int i, int j, unordered_map<int, unordered_map<int, vector<int>>> &dp, int chance)
{
    if(i == j)
    {
        vector<int> ans = {0,0};
        ans[chance] = v[i];
        return ans;
    }
    
    if(dp[i][j] != 0)
        return dp[i][j];
    
    vector<int> ans1 = solve(v, i+1, j, dp, (chance^1));
    ans1[chance] += v[i];
    vector<int> ans2 = solve(v, i, j-1, dp, (chance^1));
    ans2[chance] += v[j];
    
    vector<int> ans = ans1;
    
    if(ans1[chance] >= ans1[chance^1] || ans2[chance] >= ans2[chance ^ 1])
        dp[i][j] = chance+1;
    else
        dp[i][j] = 1 + (chance != 1);
    
    if(ans2[chance] >= ans2[chance ^ 1] && ans2[chance] > ans[chance])
        ans = ans2;
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    long long int r = 0, g = 0, i = 0, j = n-1;
    
    unordered_map<int, unordered_map<int, int>> dp;
    
    vector<int> ans = solve(v, 0, n-1, dp, 0);
    
    if(ans[0] >= ans[1])
        cout << "Pucca\n";
    else
        cout << "Garu\n";
    
    return 0;
}
