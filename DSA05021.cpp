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

          vector<pair<long long, long long>> a(n);
          for (int i = 0; i < n; ++i)
               cin >> a[i].first >> a[i].second;

          vector<long long> dp(n, 1);
          sort(a.begin(), a.end());
          for (int i = 0; i < n; ++i)
               for (int j = 0; j < i; ++j)
                    if (a[j].second < a[i].first)
                         dp[i] = max(dp[i], dp[j] + 1);

          // for (long long x : dp)
          //      cout << x << " ";
          // cout << "\n";
          cout << *max_element(dp.begin(), dp.end()) << "\n";
     }
}