#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1003];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int v, e;
        cin >> v >> e;

        for (int i = 0; i < 1003; ++i)
            adj[i].clear();

        while (e--)
        {
            int x, y;
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for (int i = 1; i <= v; ++i)
            sort(adj[i].begin(), adj[i].end());

        for (int i = 1; i <= v; ++i)
        {
            cout << i << ": ";
            for (int x : adj[i])
                cout << x << " ";
            cout << "\n";
        }
    }
}