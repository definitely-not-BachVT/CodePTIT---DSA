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
          string s;
          cin >> s;

          stack<int> st;

          int sz = s.size();
          int cnt = 0;

          int open = 0;

          for (int i = 0; i < sz; ++i)
               if (s[i] == ']')
               {
                    if (open == 0)
                         st.push(i);
                    else
                         --open;
               }
               else
               {
                    if (st.empty())
                         ++open;
                    else
                    {
                         cnt += i - st.top();
                         st.pop();
                    }
               }

          cout << cnt << "\n";
     }
}