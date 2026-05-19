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

          vector<vector<long long>> a(n + 1, vector<long long>(m + 1, 0));
          for (int i = 0; i <= n; ++i)
               a[i][0] = 1;
          for (int i = 0; i <= m; ++i)
               a[0][i] = 1;

          for (int i = 1; i <= n; ++i)
               for (int j = 1; j <= m; ++j)
                    a[i][j] += a[i - 1][j] + a[i][j - 1];

          cout << a[n][m] << "\n";
     }
}