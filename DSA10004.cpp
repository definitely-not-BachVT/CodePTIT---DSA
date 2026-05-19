#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1003];

void solve()
{
     int v, e;
     cin >> v >> e;

     vector<int> deg(v + 2, 0);
     for (int i = 0; i < e; ++i)
     {
          int x, y;
          cin >> x >> y;

          ++deg[x];
          ++deg[y];
     }

     int cnt1 = 0;
     for (int x : deg)
          if (x % 2)
               ++cnt1;

     if (cnt1 == 0)
          cout << 2 << "\n";
     else if (cnt1 == 2)
          cout << 1 << "\n";
     else
          cout << "0\n";
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