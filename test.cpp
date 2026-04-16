#include <bits/stdc++.h>
using namespace std;

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int n;
     cin >> n;

     queue<string> q;
     q.push("0");
     q.push("1");

     while (!q.empty())
     {
          string x = q.front();
          q.pop();

          if (x.size() == n)
          {
               cout << x << "\n";
               continue;
          }

          if (x.size() > n)
               break;

          q.push(x + "0");
          q.push(x + "1");
     }
}