#include <bits/stdc++.h>
using namespace std;

void solve()
{
     string p;
     cin >> p;

     int open_count = 0;
     int match_count = 0;

     for (char c : p)
     {
          if (c == '(')
               open_count++;
          else if (c == ')')
          {
               if (open_count > 0)
               {
                    match_count++;
                    open_count--;
               }
          }
     }

     cout << match_count * 2 << "\n";
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