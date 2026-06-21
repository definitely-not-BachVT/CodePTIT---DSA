#include <bits/stdc++.h>
using namespace std;

long long calc(int id, vector<string> &a)
{
     if (a[id] == "+" || a[id] == "-" || a[id] == "*" || a[id] == "/")
     {

          long long left_val = calc(2 * id + 1, a);
          long long right_val = calc(2 * id + 2, a);

          if (a[id] == "+")
               return left_val + right_val;
          if (a[id] == "-")
               return left_val - right_val;
          if (a[id] == "*")
               return left_val * right_val;
          if (a[id] == "/")
               return left_val / right_val;

          return 0;
     }

     return stoll(a[id]);
}

void solve()
{
     int n;
     cin >> n;

     vector<string> a(n);
     for (int i = 0; i < n; ++i)
          cin >> a[i];

     cout << calc(0, a) << "\n";
}

int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     while (t--)
          solve();
}