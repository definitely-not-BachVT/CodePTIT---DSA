#include <bits/stdc++.h>
using namespace std;

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     while (t--)
     {
          int n;
          cin >> n;

          vector<long long> a(n);
          for (int i = 0; i < n; ++i)
               cin >> a[i];

          vector<int> left(n), right(n);
          stack<int> st;

          for (int i = 0; i < n; ++i)
          {
               while (!st.empty() && a[st.top()] >= a[i])
                    st.pop();

               left[i] = st.empty() ? -1 : st.top();
               st.push(i);
          }

          while (!st.empty())
               st.pop();

          for (int i = n - 1; i >= 0; --i)
          {
               while (!st.empty() && a[st.top()] >= a[i])
                    st.pop();

               right[i] = st.empty() ? n : st.top();
               st.push(i);
          }

          long long ans = 0;

          for (int i = 0; i < n; ++i)
          {
               long long width = right[i] - left[i] - 1;
               ans = max(ans, width * a[i]);
          }

          cout << ans << "\n";
     }
}