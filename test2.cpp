#include <bits/stdc++.h>
using namespace std;

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int n;
     cin >> n;

     stack<string> st;
     st.push("");

     while (!st.empty())
     {
          string x = st.top();
          st.pop();

          if (x.size() == n)
          {
               cout << x << "\n";
               continue;
          }

          // if (x.size() > n)
          //      continue;

          st.push(x + "1");
          st.push(x + "0");
     }
}