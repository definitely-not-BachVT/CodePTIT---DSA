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
          int n, m;
          cin >> n >> m;

          vector<long long> ans(n + m - 1), a(n), b(m);
          for (int i = 0; i < n; ++i)
               cin >> a[i];
          for (int i = 0; i < m; ++i)
               cin >> b[i];

          for (int i = 0; i < n; ++i)
               for (int j = 0; j < m; ++j)
                    ans[i + j] += a[i] * b[j];

          for (int x : ans)
               cout << x << " ";
          cout << "\n";
     }
}