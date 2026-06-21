#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
     if (c == '^')
          return 3;
     if (c == '*' || c == '/')
          return 2;
     if (c == '+' || c == '-')
          return 1;
     return -1;
}

void solve()
{
     string s;
     cin >> s;

     stack<char> st;
     string res = "";

     for (int i = 0; i < s.size(); i++)
     {

          if (isalpha(s[i]) || isdigit(s[i]))
               res += s[i];
          else if (s[i] == '(')
               st.push(s[i]);
          else if (s[i] == ')')
          {
               while (!st.empty() && st.top() != '(')
               {
                    res += st.top();
                    st.pop();
               }

               if (!st.empty())
                    st.pop();
          }
          else
          {
               while (!st.empty() && prec(st.top()) >= prec(s[i]))
               {
                    res += st.top();
                    st.pop();
               }
               st.push(s[i]);
          }
     }

     while (!st.empty())
     {
          if (st.top() != '(')
               res += st.top();
          st.pop();
     }

     cout << res << "\n";
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