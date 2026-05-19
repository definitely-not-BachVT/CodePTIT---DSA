#include <bits/stdc++.h>
using namespace std;

void solve()
{
     int n;
     cin >> n;

     vector<int> a(n);
     for (int i = 0; i < n; ++i)
          cin >> a[i];

     vector<int> inc(n, 0);
     for (int i = 1; i < n; ++i)
     {
          if (a[i] > a[i - 1])
               inc[i] = inc[i - 1] + 1;
          else
               inc[i] = 0;
     }

     vector<int> rinc(n, 0);
     for (int i = n - 2; i >= 0; --i)
     {
          if (a[i] > a[i + 1])
               rinc[i] = rinc[i + 1] + 1;
          else
               rinc[i] = 0;
     }

     // for (int x : inc)
     //      cout << x << " ";
     // cout << "\n";

     // for (int x : rinc)
     //      cout << x << " ";
     // cout << "\n";

     int ans = 0;
     for (int i = 0; i < n; ++i)
          ans = max(ans, inc[i] + rinc[i] + 1);

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