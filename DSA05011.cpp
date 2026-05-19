#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
vector<vector<long long>> dp(103, vector<long long>(920, 0));

void precompute()
{
     dp[0][0] = 1;

     for (int i = 1; i <= 102; ++i)
          for (int j = 1; j <= 918; ++j)
               for (int d = 0; d <= 9; ++d)
                    if (j >= d)
                         dp[i][j] = (dp[i][j] + dp[i - 1][j - d]) % MOD;
}

void solve()
{
     int n, k;
     cin >> n >> k;

     cout << dp[n][k] << "\n";
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     precompute();

     while (t--)
          solve();
}