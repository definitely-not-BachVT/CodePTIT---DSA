#include <bits/stdc++.h>
using namespace std;

void solve()
{
     string x, y;
     cin >> x >> y;

     int n = x.size();
     int m = y.size();

     vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
     for (int i = 0; i <= n; ++i)
          for (int j = 0; j <= m; ++j)
          {
               if (i == 0)
               {
                    dp[i][j] = j;
                    continue;
               }

               if (j == 0)
               {
                    dp[i][j] = i;
                    continue;
               }

               if (x[i - 1] == y[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
               else
                    dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
          }

     cout << dp[n][m] << "\n";
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     while (t--)
          solve();
}