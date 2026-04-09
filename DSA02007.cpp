#include <bits/stdc++.h>
using namespace std;

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     while (t--)
     {
          int k;
          cin >> k;

          string s;
          cin >> s;

          // Duyet i -> k
          // Tim so lon nhat co idx lon nhat trong khoang i + 1 -> n (x)
          // Neu x > a[i] => swap. Khong thi thoi

          int n = s.size();
          for (int i = 0; i < n; ++i)
          {
               if (k == 0)
                    break;

               int num = s[i] - '0';
               int mx = s[i] - '0', pos = -1;
               for (int j = i + 1; j < n; ++j)
               {
                    if (s[j] - '0' >= mx)
                    {
                         mx = s[j] - '0';
                         pos = j;
                    }
               }

               if (mx > num)
               {
                    swap(s[i], s[pos]);
                    --k;
               }

               // cout << s << " ";
          }

          cout << s << "\n";
     }
}