#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

struct Matrix
{
     long long a[2][2];

     void set0()
     {
          for (int i = 0; i < 2; ++i)
               for (int j = 0; j < 2; ++j)
                    a[i][j] = 0;
     }

     void unit()
     {
          set0();
          for (int i = 0; i < 2; ++i)
               a[i][i] = 1;
     }

     void init()
     {
          a[0][0] = a[0][1] = a[1][0] = 1;
          a[1][1] = 0;
     }

     Matrix operator*(Matrix other)
     {
          Matrix ans;
          ans.set0();

          for (int i = 0; i < 2; ++i)
               for (int j = 0; j < 2; ++j)
                    for (int k = 0; k < 2; ++k)
                         ans.a[i][j] = (ans.a[i][j] + (a[i][k] * other.a[k][j]) % MOD) % MOD;

          return ans;
     }
};

Matrix binPow(Matrix a, long long k)
{
     Matrix ans;
     ans.unit();

     while (k)
     {
          if (k % 2)
               ans = ans * a;
          a = a * a;

          k /= 2;
     }

     return ans;
}

void solve()
{
     int n;
     cin >> n;

     Matrix st;
     st.init();

     st = binPow(st, n - 1);
     cout << st.a[0][0] << "\n";
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t = 1;
     cin >> t;

     while (t--)
          solve();
}