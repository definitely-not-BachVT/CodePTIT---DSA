#include <bits/stdc++.h>
using namespace std;

vector<string> a;
void sinh(long long n, long long idx, string x)
{
     if (idx == n)
     {
          a.push_back(x);
          return;
     }

     for (int i = 1; i <= n; ++i)
          sinh(n, idx + 1, x + to_string(i));
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int test;
     cin >> test;

     while (test--)
     {
          long long s, t;
          cin >> s >> t;
          long long idx = 0;

          while (t != s)
          {
               if (t % 2)
               {
                    t += 1;
                    idx++;
                    continue;
               }

               if (t > s)
               {
                    t /= 2;
                    ++idx;
                    continue;
               }

               t += 1;
               ++idx;
          }

          cout << idx << "\n";
     }
}