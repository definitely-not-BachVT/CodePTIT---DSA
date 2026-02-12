#include <iostream>
using namespace std;

unsigned long long len[93];

char solve(int N, unsigned long long K)
{
     if (N == 1)
          return 'A';
     if (N == 2)
          return 'B';

     if (K <= len[N - 2])
          return solve(N - 2, K);
     else
          return solve(N - 1, K - len[N - 2]);
}

int main()
{
     int T;
     cin >> T;

     len[1] = 1;
     len[2] = 1;
     for (int i = 3; i < 93; i++)
          len[i] = len[i - 1] + len[i - 2];

     while (T--)
     {
          int N;
          unsigned long long K;
          cin >> N >> K;

          cout << solve(N, K) << endl;
     }

     return 0;
}
