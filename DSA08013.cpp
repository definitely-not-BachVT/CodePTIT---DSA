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

          vector<vector<int>> a(n, vector<int>(n, 1e9));
          vector<vector<bool>> visited(n, vector<bool>(n, false));

          vector<vector<char>> c(n, vector<char>(n));
          for (int i = 0; i < n; ++i)
               for (int j = 0; j < n; ++j)
                    cin >> c[i][j];

          long long start_x, start_y, ed_x, ed_y;
          cin >> start_x >> start_y >> ed_x >> ed_y;

          a[start_x][start_y] = 0;
          visited[start_x][start_y] = true;

          queue<pair<int, int>> q;
          q.push({start_x, start_y});

          while (!q.empty())
          {
               auto [x, y] = q.front();
               q.pop();

               int dx = 0, dy = 0;
               while (x + dx < n && c[x + dx][y] != 'X')
               {
                    if (!visited[x + dx][y])
                    {
                         q.push({x + dx, y});
                         visited[x + dx][y] = true;
                    }

                    a[x + dx][y] = min(a[x + dx][y], a[x][y] + 1);
                    ++dx;
               }

               while (y + dy < n && c[x][y + dy] != 'X')
               {
                    if (!visited[x][y + dy])
                    {
                         q.push({x, y + dy});
                         visited[x][y + dy] = true;
                    }

                    a[x][y + dy] = min(a[x][y + dy], a[x][y] + 1);
                    ++dy;
               }

               dx = 0;
               dy = 0;

               while (x + dx >= 0 && c[x + dx][y] != 'X')
               {
                    if (!visited[x + dx][y])
                    {
                         q.push({x + dx, y});
                         visited[x + dx][y] = true;
                    }

                    a[x + dx][y] = min(a[x + dx][y], a[x][y] + 1);
                    --dx;
               }

               while (y + dy >= 0 && c[x][y + dy] != 'X')
               {
                    if (!visited[x][y + dy])
                    {
                         q.push({x, y + dy});
                         visited[x][y + dy] = true;
                    }

                    a[x][y + dy] = min(a[x][y + dy], a[x][y] + 1);
                    --dy;
               }
          }

          // for (int i = 0; i < n; ++i)
          // {
          //      for (int j = 0; j < n; ++j)
          //           cout << a[i][j] << " ";
          //      cout << "\n";
          // }

          cout << a[ed_x][ed_y] << "\n";
     }
}