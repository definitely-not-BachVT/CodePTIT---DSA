#include <bits/stdc++.h>
using namespace std;

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int n, k;
     cin >> n >> k;

     vector<string> a(n);
     for (int i = 0; i < n; ++i)
          cin >> a[i];

     vector<pair<long long, long long>> range(n);
     for (int i = 0; i < n; ++i)
     {
          string x = a[i];

          sort(x.begin(), x.end());
          range[i].first = stoll(x);

          reverse(x.begin(), x.end());
          range[i].second = stoll(x);
     }

     long long ans = LLONG_MAX;
     vector<vector<long long>> diff(n, vector<long long>(n, 0));
     for (int i = 0; i < n; ++i)
          for (int j = 0; j < n; ++j)
          {
               if (range[i].second > range[j].first && range[i].second < range[j].second)
                    diff[i][j] = 0;

               if (range[j].second > range[i].first && range[j].second < range[i].second)
                    diff[i][j] = 0;

               diff[i][j] = min(abs(range[j].first - range[i].second), abs(range[i].first - range[j].second));
               ans = min(ans, diff[i][j]);
          }

     cout << ans;
}
