#include <iostream>
using namespace std;

int main()
{
     int t;
     cin >> t;

     while (t--)
     {
          int n, s, m;
          cin >> n >> s >> m;

          int sum = s * m;
          int su = s / 7;
          int bsu = s - su;

          if (m > n)
          {
               cout << -1 << endl;
               continue;
          }

          if (bsu * n < sum)
          {
               cout << -1 << endl;
               continue;
          }

          int res = (sum + n - 1) / n;
          cout << res << endl;
     }

     return 0;
}
