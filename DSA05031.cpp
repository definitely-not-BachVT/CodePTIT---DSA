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
          int n;
          cin >> n;

          int sq = sqrt(n);
          vector<int> dp(n + 2, 1e9);

          dp[0] = 0;
          for (int i = 1; i <= n; ++i)
               for (int j = 1; j * j <= i; ++j)
                    dp[i] = min(dp[i], dp[i - j * j] + 1);

          cout << dp[n] << "\n";
     }
}