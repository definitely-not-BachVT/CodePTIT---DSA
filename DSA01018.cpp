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
          int n, k;
          cin >> n >> k;

          vector<int> a(n, 0);
          for (int i = 0; i < k; ++i)
          {
               int x;
               cin >> x;

               a[x - 1] = 1;
          }

          if (next_permutation(a.begin(), a.end()))
          {
               for (int i = 0; i < n; ++i)
                    if (a[i])
                         cout << i + 1 << " ";
               cout << "\n";
          }
          else
          {
               for (int i = n - k; i < n; ++i)
                    cout << i + 1 << " ";
               cout << "\n";
          }
     }
}