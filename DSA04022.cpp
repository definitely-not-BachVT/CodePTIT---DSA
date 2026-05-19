#include <bits/stdc++.h>
using namespace std;

char find(long long n, long long k)
{
     long long mid = pow(2, n - 1);
     if (k == mid)
          return char('A' + n - 1);
     else if (k > mid)
          return find(n - 1, k - mid);
     else
          return find(n - 1, k);
}

void solve()
{
     long long n, k;
     cin >> n >> k;

     cout << find(n, k) << "\n";
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