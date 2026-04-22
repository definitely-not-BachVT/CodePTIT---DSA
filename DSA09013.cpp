#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
vector<int> id(1005), low(1005);
int timer = 0;

vector<pair<int, int>> curr;

void dfs(int u, int p)
{
     id[u] = low[u] = ++timer;

     for (int v : adj[u])
     {
          if (v == p)
               continue;

          if (id[v])
               low[u] = min(low[u], id[v]);
          else
          {
               dfs(v, u);
               low[u] = min(low[u], low[v]);

               if (low[v] > id[u])
                    curr.push_back({min(u, v), max(u, v)});
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
          curr.clear();

          for (int i = 0; i < 1005; ++i)
          {
               adj[i].clear();
               id[i] = id[i] = 0;
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

          for (int i = 1; i <= n; ++i)
               if (!id[i])
                    dfs(i, 0);

          sort(curr.begin(), curr.end());
          for (auto x : curr)
               cout << x.first << " " << x.second << " ";
          cout << "\n";
     }
}