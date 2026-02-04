#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1003];
vector<bool> visited(1003, false);

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty())
    {
        int fr = q.front();
        q.pop();
        cout << fr << " ";

        for (int x : adj[fr])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
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
        int v, e, u;
        cin >> v >> e >> u;

        for (int i = 0; i < 1003; ++i)
            adj[i].clear();
        for (int i = 0; i < 1003; ++i)
            visited[i] = false;

        for (int i = 0; i < e; ++i)
        {
            int x, y;
            cin >> x >> y;

            adj[x].push_back(y);
            // adj[y].push_back(x);
        }

        for (int i = 0; i < 1003; ++i)
            sort(adj[i].begin(), adj[i].end());

        bfs(u);
        cout << "\n";
    }
}