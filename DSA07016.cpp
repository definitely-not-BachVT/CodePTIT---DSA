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

          stack<int> st;
          int num = 1;

          for (int i = 0; i <= s.length(); i++)
          {
               st.push(num++);

               if (i == s.length() || s[i] == 'I')
               {
                    while (!st.empty())
                    {
                         cout << st.top();
                         st.pop();
                    }
               }
          }

          cout << "\n";
     }
}