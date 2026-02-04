#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<long long>> a(n, vector<long long>(m, 0));
        auto dp = a;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];

        dp[0][0] = 1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (i - 1 >= 0)
                    dp[i][j] += dp[i - 1][j];
                if (j - 1 >= 0)
                    dp[i][j] += dp[i][j - 1];
            }

        cout << dp[n - 1][m - 1] << "\n";
    }
}
