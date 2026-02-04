#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<long long>> a(n, vector<long long>(m)), dp(n, vector<long long>(m, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];

        dp[0][0] = a[0][0];
        for (int j = 1; j < m; ++j)
            dp[0][j] = dp[0][j - 1] + a[0][j];
        for (int i = 1; i < n; ++i)
            dp[i][0] = dp[i - 1][0] + a[i][0];

        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + a[i][j];

        cout << dp[n - 1][m - 1] << "\n";
    }
}