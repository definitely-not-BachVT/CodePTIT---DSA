#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     while (t--)
     {
          int n, k;
          cin >> n >> k;

          vector<int> a(n);
          for (int i = 0; i < n; ++i)
               cin >> a[i];

          vector<int> dp(k + 2, 0);
          dp[0] = 1;

          for (int j = 1; j <= k; ++j)
               for (int i = 0; i < n; ++i)
                    if ((j - a[i]) >= 0)
                         dp[j] = (dp[j] + dp[j - a[i]]) % MOD;

          cout << dp[k] << "\n";
     }
}