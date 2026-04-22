#include <bits/stdc++.h>
using namespace std;

int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;
     while (t--)
     {
          string s;
          cin >> s;
          int n = s.length();

          if (s[0] == '0')
          {
               cout << 0 << "\n";
               continue;
          }

          vector<long long> dp(n + 1, 0);
          dp[0] = 1;
          dp[1] = 1;

          for (int i = 2; i <= n; i++)
          {
               if (s[i - 1] > '0')
                    dp[i] += dp[i - 1];

               if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))
                    dp[i] += dp[i - 2];
          }

          cout << dp[n] << "\n";
     }
}