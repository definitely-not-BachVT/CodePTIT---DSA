#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1003];
vector<int> radj[1003];
bool visited[1003];

void bfs1(int u)
{
     queue<int> q;
     q.push(u);
     visited[u] = true;

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

void bfs2(int u)
{
     queue<int> q;
     q.push(u);
     visited[u] = true;

     while (!q.empty())
     {
          int fr = q.front();
          q.pop();

          for (int x : radj[fr])
               if (!visited[x])
               {
                    visited[x] = true;
                    q.push(x);
               }
     }
}

void solve()
{
     int v, e;
     cin >> v >> e;

     for (int i = 1; i <= v; ++i)
     {
          adj[i].clear();
          radj[i].clear();
          visited[i] = false;
     }

     for (int i = 0; i < e; ++i)
     {
          int x, y;
          cin >> x >> y;

          adj[x].push_back(y);
          radj[y].push_back(x);
     }

     bfs1(1);
     int cnt = 0;

     for (int i = 1; i <= v; ++i)
          if (visited[i])
               ++cnt;

     if (cnt != v)
     {
          cout << "NO\n";
          return;
     }

     for (int i = 1; i <= v; ++i)
          visited[i] = false;

     cnt = 0;
     bfs2(1);

     for (int i = 1; i <= v; ++i)
          if (visited[i])
               ++cnt;

     if (cnt != v)
     {
          cout << "NO\n";
          return;
     }

     cout << "YES\n";
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     while (t--)
          solve();
}