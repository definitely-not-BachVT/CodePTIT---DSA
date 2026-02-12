#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
     if (a.second < b.second)
          return true;
     else if (a.second > b.second)
          return false;
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int n;
     cin >> n;

     vector<string> chuot, child_and_woman, danong, chunhiem;
     for (int i = 0; i < n; ++i)
     {
          string x, y;
          cin >> x >> y;

          if (y == "rat")
               chuot.push_back(x);
          else if (y == "woman" || y == "child")
               child_and_woman.push_back(x);
          else if (y == "man")
               danong.push_back(x);
          else if (y == "captain")
               chunhiem.push_back(x);
     }

     for (auto x : chuot)
          cout << x << "\n";
     for (auto x : child_and_woman)
          cout << x << "\n";
     for (auto x : danong)
          cout << x << "\n";
     for (auto x : chunhiem)
          cout << x << "\n";
}