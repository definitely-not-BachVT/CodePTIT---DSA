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
          int n;
          cin >> n;
          cin.ignore();

          string line;
          getline(cin, line);

          stringstream ss(line);
          stack<long long> st;
          string token;

          while (ss >> token)
          {
               if (token == "+" || token == "-" ||
                   token == "*" || token == "/")
               {
                    long long b = st.top();
                    st.pop();
                    long long a = st.top();
                    st.pop();

                    long long res;

                    if (token == "+")
                         res = a + b;
                    else if (token == "-")
                         res = a - b;
                    else if (token == "*")
                         res = a * b;
                    else
                         res = a / b;

                    st.push(res);
               }
               else
                    st.push(stoll(token));
          }

          cout << st.top() << "\n";
     }
}