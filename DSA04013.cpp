#include <bits/stdc++.h>
using namespace std;

void solve()
{
     int n;
     cin >> n;
     vector<int> a(n);
     for (int i = 0; i < n; ++i)
          cin >> a[i];
     sort(a.begin(), a.end());

     int l = 0;
     int r = n / 2;
     int ans = n;

     while (l < n / 2 && r < n)
     {
          if (a[l] * 2 <= a[r])
          {
               ans--;
               l++;
               r++;
          }
          else
               r++;
     }

     cout << ans << "\n";
}

int main()
{

     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     while (t--)
          solve();
}