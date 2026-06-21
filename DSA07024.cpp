#include <bits/stdc++.h>
using namespace std;

void solve()
{
     int n;
     cin >> n;

     vector<int> a(n);
     for (int i = 0; i < n; ++i)
          cin >> a[i];

     stack<int> st;
     vector<int> left(n, -1), right(n, n);

     for (int i = 0; i < n; ++i)
     {
          while (!st.empty() && a[st.top()] > a[i])
               st.pop();

          if (st.empty())
               left[i] = -1;
          else
               left[i] = st.top();

          st.push(i);
     }

     while (!st.empty())
          st.pop();

     for (int i = n - 1; i >= 0; --i)
     {
          while (!st.empty() && a[st.top()] > a[i])
               st.pop();

          if (st.empty())
               right[i] = n;
          else
               right[i] = st.top();

          st.push(i);
     }

     int ans = 0;
     for (int i = 0; i < n; ++i)
     {
          int curr = a[i];
          int length = right[i] - left[i] + 1;

          if (curr <= length)
               ans = max(ans, curr);
     }

     cout << ans << "\n";
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