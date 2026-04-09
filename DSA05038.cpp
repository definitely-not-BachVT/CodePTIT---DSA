#include <bits/stdc++.h>
using namespace std;

bool ok(pair<int, int> a, pair<int, int> b)
{
     if (a.first > b.first && a.second > b.second)
          return true;
     else
          return false;
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int n;
     cin >> n;

     vector<pair<int, int>> a(n);
     for (int i = 0; i < n; ++i)
          cin >> a[i].first >> a[i].second;

     vector<int> lis(n + 1, 1);
     for (int i = 0; i < n; ++i)
          for (int j = 0; j < i; ++j)
               if (ok(a[i], a[j]))
                    lis[i] = max(lis[i], lis[i - j] + 1);
     cout << lis[n - 1] << "\n";
}