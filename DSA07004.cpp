#include <bits/stdc++.h>
using namespace std;

int main()
{
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     while (t--)
     {
          string s;
          cin >> s;

          stack<char> st;

          for (char c : s)
          {
               if (c == '(')
               {
                    st.push(c);
               }
               else
               {
                    if (!st.empty() && st.top() == '(')
                         st.pop();
                    else
                         st.push(c);
               }
          }

          int open = 0, close = 0;

          while (!st.empty())
          {
               if (st.top() == '(')
                    open++;
               else
                    close++;
               st.pop();
          }

          int ans = (open + 1) / 2 + (close + 1) / 2;

          cout << ans << "\n";
     }
}