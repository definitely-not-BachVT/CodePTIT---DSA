#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
vector<vector<long long>> dp(103, vector<long long>(10, 0));

void preprocess()
{
     for (int i = 0; i <= 9; ++i)
          dp[1][i] = 1;

     // dp[2][j]

     for (int n = 2; n < 103; ++n)
          for (int i = 1; i <= 9; ++i)
               for (int j = i; j <= 9; ++j)
                    dp[n][i] = (dp[n][i] + dp[n - 1][j]) % MOD;
}

void solve()
{
     int n;
     cin >> n;

     long long ans = 0;
     for (int len = 1; len <= n; ++len)
          for (int i = 0; i <= 9; ++i)
               ans = (ans + dp[len][i]) % MOD;
     cout << ans << "\n";
}

// void testing()
// {
//      int n;
//      cin >> n;

//      for (int i = 0; i <= 9; ++i)
//           cout << dp[n][i] << "\n";

//      long long ans = 0;
//      for (int i = 0; i <= 9; ++i)
//           ans = (ans + dp[n][i]) % MOD;
//      cout << "ans la: " << ans << "\n";
// }

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     preprocess();

     while (t--)
          solve();
     // testing();
}