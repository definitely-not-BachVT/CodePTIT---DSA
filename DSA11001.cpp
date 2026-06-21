#include <bits/stdc++.h>
using namespace std;

void solve()
{
     string s;
     cin >> s;

     stack<string> st;

     for (char c : s)
     {
          if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
          {
               string op2 = st.top();
               st.pop();

               string op1 = st.top();
               st.pop();

               st.push(op1 + c + op2);
          }
          else
               st.push(string(1, c));
     }

     cout << st.top() << "\n";
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     while (t--)
          solve();
}