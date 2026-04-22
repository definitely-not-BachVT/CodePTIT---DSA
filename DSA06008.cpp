#include <bits/stdc++.h>
using namespace std;

long long cntPair(int a, const vector<int> &b, const vector<int> &cnt)
{
     if (a == 0)
          return 0;

     if (a == 1)
          return cnt[0];

     auto it = upper_bound(b.begin(), b.end(), a);
     long long ans = b.end() - it;
     ans += cnt[0] + cnt[1];

     if (a == 2)
          ans -= (cnt[3] + cnt[4]);
     if (a == 3)
          ans += cnt[2];

     return ans;
}

void solve()
{
     int n, m;
     cin >> n >> m;

     vector<int> a(n), b(m);
     vector<int> cnt(5, 0);

     for (int i = 0; i < n; i++)
          cin >> a[i];

     for (int i = 0; i < m; i++)
     {
          cin >> b[i];
          if (b[i] < 5)
               cnt[b[i]]++;
     }

     sort(b.begin(), b.end());

     long long ans = 0;
     for (int i = 0; i < n; i++)
     {
          ans += cntPair(a[i], b, cnt);
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