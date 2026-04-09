#include <bits/stdc++.h>
using namespace std;

int palin(string s)
{
     int n = s.size();
     int mx = 0;

     int l, r;
     int len;

     for (int center = 0; center < n; ++center)
     {
          l = r = center;
          len = 0;

          while (l >= 0 && r < n && s[l] == s[r])
          {
               ++len;
               --l;
               ++r;
          }
     }
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     while (t--)
     {
          string s;
          cin >> s;
     }
}