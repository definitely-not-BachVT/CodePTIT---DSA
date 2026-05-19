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

          vector<long long> a(n);
          for (int i = 0; i < n; ++i)
               cin >> a[i];

          vector<long long> prefix_mx(n, -1e10 - 3);
          vector<long long> suffix_mi(n, 1e10 + 3);

          for (int i = 0; i < n; ++i)
               if (i == 0)
                    prefix_mx[i] = a[i];
               else
                    prefix_mx[i] = max(a[i], prefix_mx[i - 1]);

          for (int i = n - 1; i >= 0; --i)
               if (i == n - 1)
                    suffix_mi[i] = a[i];
               else
                    suffix_mi[i] = min(a[i], suffix_mi[i + 1]);

          int cnt = 0;
          vector<long long> pos;
          for (int i = 0; i < n - 1; ++i)
               if (prefix_mx[i] <= suffix_mi[i + 1])
               {
                    ++cnt;
                    pos.push_back(i + 1);
               }

          // for (int x : prefix_mx)
          //      cout << x << " ";
          // cout << "\n";
          // for (int x : suffix_mi)
          //      cout << x << " ";

          cout << cnt << "\n";
          for (long long x : pos)
               cout << x << " ";
          cout << "\n";
     }
}