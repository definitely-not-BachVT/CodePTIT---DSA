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

          long long res = 0;
          stack<long long> st;

          reverse(s.begin(), s.end());

          for (char c : s)
          {
               if (isdigit(c))
                    st.push(c - '0');
               else
               {
                    long long tp1 = st.top();
                    st.pop();
                    long long tp2 = st.top();
                    st.pop();

                    if (c == '*')
                         st.push(tp1 * tp2);
                    else if (c == '+')
                         st.push(tp1 + tp2);
                    else if (c == '/')
                         st.push(tp1 / tp2); // *
                    else if (c == '-')
                         st.push(tp1 - tp2);
               }
          }

          cout << st.top() << "\n";
     }
}