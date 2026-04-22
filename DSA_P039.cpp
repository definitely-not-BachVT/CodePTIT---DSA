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

          vector<vector<long long>> a(n, vector<long long>(n));
          for (int i = 0; i < n; ++i)
               for (int j = 0; j < n; ++j)
                    cin >> a[i][j];

          vector<long long> dp(1 << n, 0);
          for (int mask = 0; mask < (1 << n); ++mask)
          {
               int i = 0;
               int tmp = mask;

               while (tmp > 0)
               {
                    i += (tmp & 1);
                    tmp >>= 1;
               }

               for (int j = 0; j < n; ++j)
                    if (!(mask & (1 << j)))
                    {
                         int next_mask = mask | (1 << j);
                         dp[next_mask] = max(dp[next_mask], dp[mask] + a[i][j]);
                    }
          }

          cout << dp[(1 << n) - 1] << "\n";
     }
}