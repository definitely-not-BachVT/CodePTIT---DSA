#include <bits/stdc++.h>
using namespace std;

int d[10][10];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void solve()
{
     for (int i = 0; i < 8; ++i)
          for (int j = 0; j < 8; ++j)
               d[i][j] = -1;

     string s, e;
     cin >> s >> e;

     int sx = s[0] - 'a';
     int sy = s[1] - '1';
     int ex = e[0] - 'a';
     int ey = e[1] - '1';

     if (sx == ex && sy == ey)
     {
          cout << 0 << "\n";
          return;
     }

     queue<pair<int, int>> q;
     q.push({sx, sy});

     d[sx][sy] = 0;

     while (!q.empty())
     {
          pair<int, int> fr = q.front();
          q.pop();

          int x = fr.first;
          int y = fr.second;

          for (int i = 0; i < 8; ++i)
          {
               int nx = x + dx[i];
               int ny = y + dy[i];

               if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
               {
                    if (d[nx][ny] == -1)
                    {
                         q.push({nx, ny});
                         d[nx][ny] = d[x][y] + 1;

                         if (nx == ex && ny == ey)
                         {
                              cout << d[nx][ny] << "\n";
                              return;
                         }
                    }
               }
          }
     }
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t = 1;
     cin >> t;

     while (t--)
          solve();
}