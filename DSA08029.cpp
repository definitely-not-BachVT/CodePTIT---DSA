#include <bits/stdc++.h>
using namespace std;

string Left(string s)
{
     string t = s;
     t[0] = s[3];
     t[1] = s[0];
     t[4] = s[1];
     t[3] = s[4];
     return t;
}

string Right(string s)
{
     string t = s;
     t[1] = s[4];
     t[2] = s[1];
     t[5] = s[2];
     t[4] = s[5];
     return t;
}

int BFS(string start, string goal)
{
     if (start == goal)
          return 0;

     queue<pair<string, int>> q;
     map<string, int> visited;

     q.push({start, 0});
     visited[start] = 1;

     while (!q.empty())
     {
          pair<string, int> curr = q.front();
          q.pop();

          if (curr.first == goal)
               return curr.second;

          string left = Left(curr.first);
          string right = Right(curr.first);

          if (visited[left] == 0)
          {
               q.push({left, curr.second + 1});
               visited[left] = 1;
          }

          if (visited[right] == 0)
          {
               q.push({right, curr.second + 1});
               visited[right] = 1;
          }
     }
}

int main()
{
     ios::sync_with_stdio(false);
     cin.tie(nullptr);

     int t;
     cin >> t;
     while (t--)
     {
          string start, goal;
          for (int i = 0; i < 6; i++)
          {
               char c;
               cin >> c;
               start.push_back(c);
          }

          for (int i = 0; i < 6; i++)
          {
               char c;
               cin >> c;
               goal.push_back(c);
          }
          cout << BFS(start, goal) << "\n";
     }
}
