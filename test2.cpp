#include <bits/stdc++.h>
using namespace std;

long long MOD = 998244353;

long long count1(long long r)
{
     if (r < 1)
          return 0;
     return (r - 1) / 4 + 1;
}

long long count3(long long r)
{
     if (r < 3)
          return 0;
     return (r + 1) / 4;
}

long long count0(long long r)
{
     if (r < 0)
          return 0;
     return 1 + count3(r);
}

void solve()
{
     long long n, x;
     cin >> n >> x;

     long long ca1 = count1(x - 1) % MOD;
     long long cb1 = (count1(n) - count1(x - 1)) % MOD;
     long long ans1 = (ca1 * cb1) % MOD;

     long long ca0 = count0(x - 1) % MOD;
     long long cb3 = (count3(n) - count3(x - 1)) % MOD;
     long long ans2 = (ca0 * cb3) % MOD;

     long long ans = (ans1 + ans2) % MOD;
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

     return 0;
}