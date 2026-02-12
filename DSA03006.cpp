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
          int ok = 1;
          int n;
          cin >> n;

          vector<int> a(n);
          for (int i = 0; i < n; ++i)
               cin >> a[i];

          int mid = n / 2;
          vector<int> pos(n + 1, 0);
          for (int i = 0; i < n; ++i)
               pos[a[i]] = i;

          vector<int> b = a;
          sort(a.begin(), a.end());

          for (int i = 0; i < n; ++i)
               if (a[i] != b[i] && a[i] != b[n - i - 1])
               {
                    ok = 0;
                    continue;
               }

          if (ok)
               cout << "Yes\n";
          else
               cout << "No\n";
     }
}