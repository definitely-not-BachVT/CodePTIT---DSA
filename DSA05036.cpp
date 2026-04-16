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

          vector<double> a(n), b(n);
          for (int i = 0; i < n; ++i)
               cin >> a[i] >> b[i];

          vector<int> dpa(n, 1), dpb(n, 1);
          for (int i = 0; i < n; ++i)
               for (int j = 0; j < n; ++j)
                    if (a[i] > a[j])
                         dpa[i] = max(dpa[i], dpa[j] + 1);

          for (int i = 0; i < n; ++i)
               for (int j = 0; j < n; ++j)
                    if (b[i] < b[j])
                         dpb[i] = max(dpb[i], dpb[j] + 1);

          // for (int x : dpb)
          //      cout << x << " ";
          // cout << "\n";

          int ans = 0;
          for (int i = 0; i < n; ++i)
               ans = max(ans, min(dpa[i], dpb[i]));

          cout << ans << "\n";
     }
}