#include <bits/stdc++.h>
using namespace std;

int n;
long long a[20][20];
bool visited[20];
int p[20];
long long ans, curr, mi;

void Try(int i)
{
     for (int j = 1; j < n; ++j)
          if (!visited[j])
          {
               p[i] = j;
               visited[j] = true;
               curr = curr + a[p[i - 1]][j];

               if (i == n - 1)
                    ans = min(ans, curr + a[j][0]);

               else if (curr + mi * (n - i) < ans)
                    Try(i + 1);

               visited[j] = false;
               curr = curr - a[p[i - 1]][j];
          }
}

void solve()
{
     cin >> n;

     mi = 1e18;
     ans = 1e18;
     curr = 0;

     for (int i = 0; i < n; ++i)
     {
          visited[i] = false;
          for (int j = 0; j < n; ++j)
          {
               cin >> a[i][j];
               if (i != j)
                    mi = min(mi, a[i][j]);
          }
     }

     p[0] = 0;
     visited[0] = true;
     Try(1);

     cout << ans << "\n";
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t = 1;
     // cin >> t;

     while (t--)
     {
          solve();
     }
}