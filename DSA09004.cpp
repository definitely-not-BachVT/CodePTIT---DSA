#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1003];
vector<bool> visited(1003, false);

void dfs(int u)
{
    cout << u << " ";
    // stack<int> st;
    // st.push(u);
    visited[u] = true;

    for (int x : adj[u])
    {
        if (!visited[x])
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
            adj[y].push_back(x);
        }

        for (int i = 0; i < 1003; ++i)
            sort(adj[i].begin(), adj[i].end());

        dfs(u);
        cout << "\n";
    }
}