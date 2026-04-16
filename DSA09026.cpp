#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1003];
bool visited[1003];
int ok, n, e, start, ed;

void bfs(int start)
{
     queue<pair<int, string>> q;
     q.push({start, to_string(start)});

     while (!q.empty())
     {
          auto [x, y] = q.front();
          q.pop();

          if (x == ed)
          {
               ok = 1;
               cout << y << "\n";
               break;
          }

          for (int z : adj[x])
               if (!visited[z])
               {
                    visited[z] = true;
                    q.push({z, y + " " + to_string(z)});
               }
     }

     if (!ok)
          cout << "-1\n";
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     while (t--)
     {
          ok = 0;
          cin >> n >> e >> start >> ed;

          for (int i = 0; i < 1003; ++i)
          {
               visited[i] = false;
               adj[i].clear();
          }

          for (int i = 0; i < e; ++i)
          {
               int x, y;
               cin >> x >> y;

               adj[x].push_back(y);
          }

          bfs(start);
     }
}