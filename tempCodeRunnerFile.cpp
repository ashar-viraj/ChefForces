int i = 0; i <= v[0].size(); i++)
        {
            for (int j = 0; j < (1 << v.size()); j++)
            {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }