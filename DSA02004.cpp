#include <bits/stdc++.h>
using namespace std;

int n;
set<string> res;

bool inBound(int x, int y)
{
     if (0 <= x && x < n && 0 <= y && y < n)
          return true;
     else
          return false;
}

void Try(vector<vector<int>> &a, int x, int y, string path)
{
     if (!inBound(x, y) || a[x][y] == 0)
          return;

     if (x == n - 1 && y == n - 1)
     {
          res.insert(path);
          return;
          // ok
     }

     /*
          y    1    2    3
     x
     1         a    a    a

     2         a    a    a

     3         a    a    a
     */

     if (inBound(x, y + 1) && a[x][y + 1])
     {
          a[x][y] = 0;
          Try(a, x, y + 1, path + "R");
          a[x][y] = 1;
     }

     if (inBound(x - 1, y) && a[x - 1][y])
     {
          a[x][y] = 0;
          Try(a, x - 1, y, path + "U");
          a[x][y] = 1;
     }

     if (inBound(x + 1, y) && a[x + 1][y])
     {
          a[x][y] = 0;
          Try(a, x + 1, y, path + "D");
          a[x][y] = 1;
     }

     if (inBound(x, y - 1) && a[x][y - 1])
     {
          a[x][y] = 0;
          Try(a, x, y - 1, path + "L");
          a[x][y] = 1;
     }
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
          res.clear();
          cin >> n;

          vector<vector<int>> a(n, vector<int>(n, 0));
          for (int i = 0; i < n; ++i)
               for (int j = 0; j < n; ++j)
                    cin >> a[i][j];

          Try(a, 0, 0, "");
          if (res.size())
               for (string x : res)
                    cout << x << " ";
          else
               cout << "-1";

          cout << "\n";
     }
}