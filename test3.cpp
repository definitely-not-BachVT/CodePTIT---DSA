#include <bits/stdc++.h>
using namespace std;

void f()
{
     int n;
     cin >> n;

     vector<int> c(n + 1, 0);
     for (int i = 0; i < n; i++)
     {
          int a;
          cin >> a;
          if (a <= n)
               c[a]++;
     }

     vector<int> h(n + 1, 0);
     int m = 0;

     for (int i = 1; i <= n; i++)
          if (c[i] > 0)
               for (int j = i; j <= n; j += i)
                    h[j] += c[i];

     for (int i = 1; i <= n; i++)
          if (h[i] > m)
               m = h[i];

     cout << m << "\n";
}

int main()
{

     int t;
     cin >> t;
     while (t--)
          f();
}