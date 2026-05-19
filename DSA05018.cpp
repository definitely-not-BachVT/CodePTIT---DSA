#include <bits/stdc++.h>
using namespace std;

int main()
{
     int t;
     cin >> t;

     while (t--)
     {
          string s;
          cin >> s;

          int n = s.size();
          vector<vector<long long>> dp(n, vector<long long>(n, 0));

          for (int i = 0; i < n; ++i)
               dp[i][i] = 1;

          for (int len = 2; len <= n; ++len)
          {
               for (int j = 0; j <= n - len; ++j)
                    if (s[j] == s[j + len - 1])
                    {
                         if (len == 2)
                              dp[j][j + len - 1] = 2;
                         else
                              dp[j][j + len - 1] = dp[j + 1][j + len - 2] + 2;
                    }
                    else
                         dp[j][j + len - 1] = max(dp[j + 1][j + len - 1], dp[j][j + len - 2]);
          }

          cout << dp[0][n - 1] << "\n";
     }
}