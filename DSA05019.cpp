#include <bits/stdc++.h>
using namespace std;

int mxS(vector<int> &a)
{
     int n = a.size();
     int mx = 0;

     vector<int> left(n), right(n);
     stack<int> st;

     for (int i = 0; i < n; ++i)
     {
          while (!st.empty() && a[st.top()] >= a[i]) // FIX 2
               st.pop();

          left[i] = st.empty() ? -1 : st.top();
          st.push(i);
     }

     while (!st.empty())
          st.pop();

     for (int i = n - 1; i >= 0; --i)
     {
          while (!st.empty() && a[st.top()] >= a[i]) // FIX 2
               st.pop();

          right[i] = st.empty() ? n : st.top();
          st.push(i);
     }

     for (int i = 0; i < n; ++i)
     {
          int width = right[i] - left[i] - 1;
          int side = min(a[i], width);
          mx = max(mx, side);
     }

     return mx;
}

int main()
{
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     while (t--)
     {
          int n, m;
          cin >> n >> m;

          vector<vector<int>> a(n, vector<int>(m));
          for (int i = 0; i < n; ++i)
               for (int j = 0; j < m; ++j)
                    cin >> a[i][j];

          int ans = 0;
          vector<int> level(m, 0);

          for (int i = 0; i < n; ++i)
          {
               for (int j = 0; j < m; ++j)
               {
                    if (a[i][j])
                         level[j]++;
                    else
                         level[j] = 0;
               }

               ans = max(ans, mxS(level));
          }

          cout << ans << "\n";
     }
}