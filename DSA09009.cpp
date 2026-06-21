#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool visited[1005];

void bfs(int start)
{
     queue<int> q;
     q.push(start);

     visited[start] = true;

     while (!q.empty())
     {
          int fr = q.front();
          q.pop();

          for (int x : adj[fr])
               if (!visited[x])
               {
                    q.push(x);
                    visited[x] = true;
               }
     }
}

void solve()
{
     for (int i = 0; i < 1005; ++i)
     {
          adj[i].clear();
          visited[i] = false;
     }

     int n, e;
     cin >> n >> e;

     for (int i = 0; i < e; ++i)
     {
          int x, y;
          cin >> x >> y;

          adj[x].push_back(y);
          adj[y].push_back(x);
     }

     int cnt = 0;
     for (int i = 1; i <= n; ++i)
          if (!visited[i])
          {
               ++cnt;
               bfs(i);
          }

     cout << cnt << "\n";
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t = 1;
     cin >> t;

     while (t--)
          solve();
}