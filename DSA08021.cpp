#include <bits/stdc++.h>
using namespace std;

int n, m;
bool inBound(int x, int y)
{
     if (0 <= x && x < n && 0 <= y && y < m)
          return true;
     return false;
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
          cin >> n >> m;

          vector<vector<long long>> step(n, vector<long long>(m, 1e9));
          vector<vector<long long>> a(n, vector<long long>(m, 0));

          for (int i = 0; i < n; ++i)
               for (int j = 0; j < m; ++j)
                    cin >> a[i][j];

          step[0][0] = 0;
          queue<pair<long long, long long>> q;
          q.push({0, 0});

          while (!q.empty())
          {
               auto [x, y] = q.front();
               q.pop();

               if (x == n - 1 && y == m - 1)
                    break;

               if (inBound(x + a[x][y], y) && step[x + a[x][y]][y] > step[x][y] + 1)
               {
                    q.push({x + a[x][y], y});
                    step[x + a[x][y]][y] = step[x][y] + 1;
               }

               if (inBound(x, y + a[x][y]) && step[x][y + a[x][y]] > step[x][y] + 1)
               {
                    q.push({x, y + a[x][y]});
                    step[x][y + a[x][y]] = step[x][y] + 1;
               }
          }

          if (step[n - 1][m - 1] != 1e9)
               cout << step[n - 1][m - 1] << "\n";
          else
               cout << "-1\n";
     }
}