#include <bits/stdc++.h>
using namespace std;

int main()
{
     ios::sync_with_stdio(false);
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

          if (n == 1)
          {
               cout << 1 << "\n";
               continue;
          }

          vector<int> inc(n, 1), dec(n, 1);

          for (int i = 1; i < n; ++i)
               if (a[i] > a[i - 1])
                    inc[i] = inc[i - 1] + 1;

          for (int i = n - 2; i >= 0; --i)
               if (a[i] > a[i + 1])
                    dec[i] = dec[i + 1] + 1;

          int ans = 1;
          for (int i = 0; i < n; ++i)
               ans = max(ans, inc[i] + dec[i] - 1);

          cout << ans << "\n";
     }
}