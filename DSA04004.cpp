#include <bits/stdc++.h>
using namespace std;

long long find(long long n, long long k)
{
     long long mid = pow(2, n - 1);

     if (k == mid)
          return n;
     else if (k < mid)
          return find(n - 1, k);
     else
          return find(n - 1, k - mid);
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