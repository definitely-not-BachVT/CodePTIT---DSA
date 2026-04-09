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

          vector<long long> a(n);
          for (int i = 0; i < n; ++i)
               cin >> a[i];

          vector<long long> dp1(n, 0);

          for (int i = 0; i < n; ++i)
               dp1[i] = a[i];

          for (int i = 1; i < n; ++i)
               for (int j = 0; j < i; ++j)
                    if (a[i] > a[j])
                         dp1[i] = max(dp1[i], dp1[j] + a[i]);

          vector<long long> dp2(n, 0);
          for (int i = 0; i < n; ++i)
               dp2[i] = a[i];

          for (int i = n - 2; i >= 0; --i)
               for (int j = n - 1; j > i; --j)
                    if (a[i] > a[j])
                         dp2[i] = max(dp2[i], dp2[j] + a[i]);

          long long mx = -LLONG_MAX;
          for (int i = 0; i < n; ++i)
               mx = max(mx, dp1[i] + dp2[i] - a[i]);

          cout << mx << "\n";
     }
}