#include <bits/stdc++.h>
using namespace std;

void solve()
{
     int n;
     cin >> n;

     vector<long long> a(n);
     for (int i = 0; i < n; ++i)
          cin >> a[i];

     vector<long long> prefix(n);
     prefix[0] = a[0];
     long long s = 0;

     for (int i = 1; i < n; ++i)
          prefix[i] = prefix[i - 1] + a[i];

     map<long long, long long> idx;
     for (int i = 0; i < n; ++i)
          idx[prefix[i]] = i;

     sort(prefix.begin(), prefix.end());
     vector<int> p(n);

     for (int i = 0; i < n; ++i)
          p[idx[prefix[i]]] = n - i;

     for (int i = 0; i < n; ++i)
          cout << p[i] << " ";
     cout << "\n";
}

int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     while (t--)
          solve();
}