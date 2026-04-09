#include <bits/stdc++.h>
using namespace std;

vector<int> isPrime(1e6 + 3, 1);
vector<int> snt;
void sieve()
{
     for (long long i = 2; i * i <= 1e6 + 3; ++i)
          if (isPrime[i])
               for (long long j = i * i; j < 1e6 + 3; j += i)
                    isPrime[j] = 0;

     isPrime[0] = isPrime[1] = 0;
     for (long long i = 0; i < 1e6 + 3; ++i)
          if (isPrime[i])
               snt.push_back(i);
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     sieve();

     long long t;
     cin >> t;

     while (t--)
     {
          long long n;
          cin >> n;

          vector<long long> fac;
          for (long long x : snt)
          {
               if (x * x > n)
                    break;

               while (n % x == 0)
               {
                    fac.push_back(x);
                    n /= x;
               }
          }

          if (n > 1)
               fac.push_back(n);

          reverse(fac.begin(), fac.end());
          long long res = 1;
          long long sz = fac.size();

          // cout << "sz la: " << sz << "\n";

          for (int i = 0; i < sz; ++i)
               res = res * pow(snt[i], fac[i] - 1);

          cout << res << "\n";
     }
}