#include <bits/stdc++.h>
using namespace std;

long long binPow(long long a, long long k)
{
     long long ans = 1;
     while (k)
     {
          if (k % 2)
               ans = ans * a;
          a = a * a;

          k /= 2;
     }
     return ans;
}

void solve()
{
     string s;
     cin >> s;

     int n = s.size();
     long long ans = 0;
     for (int i = 0; i < n; ++i)
     {
          int k = n - i;
          ans = ans + (s[i] - '0') * ((binPow(10, k) - 1) / (10 - 1)) * (n + 1 - k);
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