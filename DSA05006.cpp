#include <bits/stdc++.h>
using namespace std;

vector<string> a;
void sinh(long long n, long long idx, string x)
{
     if (idx == n)
     {
          a.push_back(x);
          return;
     }

     for (int i = 1; i <= n; ++i)
          sinh(n, idx + 1, x + to_string(i));
}

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

          vector<long long> a(n);
          for (int i = 0; i < n; ++i)
               cin >> a[i];

          vector<long long> dp(n, 0);
          for (int i = 0; i < n; ++i)
               dp[i] = a[i];

          for (int i = 0; i < n; ++i)
               for (int j = 0; j < i; ++j)
                    if (a[i] > a[j])
                         dp[i] = max(dp[i], dp[j] + a[i]);

          cout << *max_element(dp.begin(), dp.end()) << "\n";
     }
}