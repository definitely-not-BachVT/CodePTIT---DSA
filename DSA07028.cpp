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
          int n;
          cin >> n;

          vector<int> a(n);
          for (int i = 0; i < n; ++i)
               cin >> a[i];

          vector<int> left(n, -1);
          stack<int> st;

          st.push(-1);
          for (int i = 0; i < n; ++i)
          {
               while (!st.empty() && a[st.top()] <= a[i])
                    st.pop();

               if (st.empty())
                    left[i] = i - -1;
               else
                    left[i] = i - st.top();

               st.push(i);
          }

          for (int x : left)
               cout << x << " ";
          cout << "\n";
     }
}