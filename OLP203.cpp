#include <bits/stdc++.h>
using namespace std;

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     unsigned long long x, y;
     unsigned long long z;

     cin >> x >> y;
     cin >> z;

     --x;
     --y;

     unsigned long long cheo = x + y;
     // Done
     cout << cheo * (cheo + 1) / 2 + y + 1 << "\n";

     for (unsigned long long i = 0; i < 200000; ++i)
     {
          if (i * (i + 1) / 2 >= z)
          {
               x = i - 1;
               break;
          }
     }

     unsigned long long start = x * (x + 1) / 2;
     y = z - start;
     x = x - y + 2;

     cout << x << " " << y << "\n";
}