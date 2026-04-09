#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
     stack<char> st;

     for (char c : s)
     {
          if (c == ')')
          {
               bool ope = false;

               while (!st.empty() && st.top() != '(')
               {
                    char top = st.top();
                    st.pop();

                    if (top == '+' || top == '-' ||
                        top == '*' || top == '/')
                         ope = true;
               }

               if (!st.empty())
                    st.pop();

               if (!ope)
                    return true;
          }
          else
          {
               if (c != ' ')
                    st.push(c);
          }
     }

     return false;
}

int main()
{
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;
     cin.ignore();

     while (t--)
     {
          string s;
          getline(cin, s);

          if (check(s))
               cout << "Yes\n";
          else
               cout << "No\n";
     }
}