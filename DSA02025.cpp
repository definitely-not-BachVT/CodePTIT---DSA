#include <bits/stdc++.h>
using namespace std;

int n;
int demLap(string x, string y)
{
     int cnt = 0;

     int idx1 = 0, idx2 = 0;
     int sz1 = x.size(), sz2 = y.size();

     while (idx1 < sz1 && idx2 < sz2)
     {
          if (x[idx1] == y[idx2])
          {
               ++cnt;
               ++idx1;
               ++idx2;
          }
          else if (x[idx1] > y[idx2])
               ++idx2;
          else
               ++idx1;
     }

     return cnt;
}

vector<vector<long long>> lap(11, vector<long long>(11, 0));
vector<string> a(11);

long long ans = LLONG_MAX;
vector<bool> used(11, false);

void Try(long long last, long long curr, long long idx)
{
     if (idx == n - 1)
     {
          ans = min(ans, curr);
          return;
     }

     if (curr > ans)
          return;

     for (int i = 0; i < n; ++i)
     {
          if (!used[i])
          {
               used[i] = true;
               Try(i, curr + lap[i][last], idx + 1);
               used[i] = false;
          }
     }
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     cin >> n;

     for (int i = 0; i < n; ++i)
          cin >> a[i];

     for (int i = 0; i < n; ++i)
          for (int j = 0; j < n; ++j)
               lap[i][j] = demLap(a[i], a[j]);

     for (int i = 1; i < n; ++i)
     {
          used[i] = true;
          Try(i, 0, 0);
          used[i] = false;
     }

     cout << ans;

     // for (int i = 0; i < n; ++i)
     // {
     //      for (int j = 0; j < n; ++j)
     //           cout << lap[i][j] << " ";
     //      cout << "\n";
     // }
}