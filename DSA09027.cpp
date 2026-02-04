#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1003];
vector<bool> visited(1003, false);
int ed;
bool found = false;

void dfs(int u)
{
    if (u == ed)
    {
        found = true;
        return;
    }

    if (found)
        return;

    visited[u] = true;
    for (int x : adj[u])
        if (!visited[x])
        {
            visited[x] = true;
            dfs(x);
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
        for (int i = 0; i < 1003; ++i)
        {
            visited[i] = false;
            adj[i].clear();
        }

        int v, e;
        cin >> v >> e;

        while (e--)
        {
            int x, y;
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int q;
        cin >> q;

        while (q--)
        {
            found = false;
            for (int i = 0; i < 1003; ++i)
                visited[i] = false;

            int u;
            cin >> u >> ed;

            dfs(u);
            if (found)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}