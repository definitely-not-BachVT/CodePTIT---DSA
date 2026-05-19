#include <bits/stdc++.h>
using namespace std;

void solve()
{
     string s;
     cin >> s;

     int sz = s.size();
     vector<vector<bool>> dp(sz, vector<bool>(sz, false));

     int ans = 1;
     for (int i = 0; i < sz; ++i)
          dp[i][i] = true;

     for (int len = 2; len <= sz; ++len)
     {
          if (len == 2)
          {
               for (int i = 0; i <= sz - len; ++i)
                    if (s[i] == s[i + len - 1])
                    {
                         dp[i][i + len - 1] = true;
                         ans = 2;
                    }

               continue;
          }

          for (int i = 0; i <= sz - len; ++i)
               if (s[i] == s[i + len - 1] && dp[i + 1][i + len - 2])
               {
                    dp[i][i + len - 1] = true;
                    ans = len;
               }
     }

     cout << ans << "\n";
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