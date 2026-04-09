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

          vector<string> tokens;
          stringstream ss(line);
          string token;

          while (ss >> token)
               tokens.push_back(token);

          stack<long long> st;

          for (int i = tokens.size() - 1; i >= 0; --i)
          {
               string tk = tokens[i];

               if (tk == "+" || tk == "-" ||
                   tk == "*" || tk == "/")
               {
                    long long a = st.top();
                    st.pop();
                    long long b = st.top();
                    st.pop();

                    long long res;

                    if (tk == "+")
                         res = a + b;
                    else if (tk == "-")
                         res = a - b;
                    else if (tk == "*")
                         res = a * b;
                    else
                         res = a / b;

                    st.push(res);
               }
               else
                    st.push(stoll(tk));
                    }

          cout << st.top() << "\n";
     }
}