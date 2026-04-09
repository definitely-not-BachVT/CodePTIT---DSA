#include <bits/stdc++.h>
using namespace std;

vector<long long> adj[1005];
bool visited[1005];

void bfs(int u)
{
     visited[u] = true;
     queue<int> q;
     q.push(u);

     while (!q.empty())
     {
          int fr = q.front();
          q.pop();

          for (int x : adj[fr])
               if (!visited[x])
               {
                    visited[x] = true;
                    q.push(x);
               }
     }
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
          for (int i = 0; i < 1005; ++i)
          {
               adj[i].clear();
               visited[i] = false;
          }

          int v, e;
          cin >> v >> e;

          for (int i = 0; i < e; ++i)
          {
               int x, y;
               cin >> x >> y;

               adj[x].push_back(y);
               adj[y].push_back(x);
          }

          int cnt = 0;
          for (int i = 1; i <= v; ++i)
          {
               if (!visited[i])
               {
                    ++cnt;
                    bfs(i);
               }
          }

          cout << cnt << "\n";
     }
}