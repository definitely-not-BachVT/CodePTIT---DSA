#include <bits/stdc++.h>
using namespace std;

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     vector<long long> ugly(1e4 + 3, 0);
     ugly[0] = 1;

     int idx = 1;
     long long mulTwo = 2, mulThree = 3, mulFive = 5;
     long long idx2 = 0, idx3 = 0, idx5 = 0;

     while (idx < 1e4 + 3)
     {
          long long nextNum = min(mulTwo, min(mulThree, mulFive));
          ugly[idx++] = nextNum;

          if (nextNum == mulTwo)
          {
               idx2++;
               mulTwo = ugly[idx2] * 2;
          }

          if (nextNum == mulThree)
          {
               idx3++;
               mulThree = ugly[idx3] * 3;
          }

          if (nextNum == mulFive)
          {
               idx5++;
               mulFive = ugly[idx5] * 5;
          }
     }

     int t;
     cin >> t;

     while (t--)
     {
          int n;
          cin >> n;

          cout << ugly[n - 1] << "\n";
     }
}