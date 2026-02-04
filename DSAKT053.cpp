#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        string a, b;
        cin >> a >> b;

        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n + 2, vector<int>(m + 3, 0));

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }

        cout << dp[n][m] << "\n";
    }
}