#include <bits/stdc++.h>
using namespace std;

int main()
{
     ios::sync_with_stdio(false);
     cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
          int s, d;
          cin >> s >> d;

          if (s == 0)
          {
               if (d == 1)
                    cout << 0 << "\n";
               else
                    cout << -1 << "\n";
               continue;
          }

          if (s > 9 * d)
          {
               cout << -1 << "\n";
               continue;
          }

          vector<int> digit(d, 0);

          s -= 1;

          for (int i = d - 1; i >= 0; i--)
          {
               int val = min(9, s);
               digit[i] = val;
               s -= val;
          }

          digit[0] += 1;

          for (int i = 0; i < d; i++)
               cout << digit[i];

          cout << "\n";
    }
}
