#include <bits/stdc++.h>
using namespace std;

void solve()
{
     string s;
     cin >> s;
     stack<string> st;

     for (int i = s.size() - 1; i >= 0; i--)
     {
          if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' || s[i] == '%')
          {
               string op1 = st.top();
               st.pop();

               string op2 = st.top();
               st.pop();

               st.push(op1 + op2 + s[i]);
          }
          else
               st.push(string(1, s[i]));
     }

     cout << st.top() << "\n";
}

int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int t = 1;
     cin >> t;
     while (t--)
          solve();
}