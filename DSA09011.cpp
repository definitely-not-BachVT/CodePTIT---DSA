#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];

        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (a[i][j] == 1 && !visited[i][j])
                {
                    ++cnt;

                    stack<pair<int, int>> st;
                    st.push(make_pair(i, j));
                    visited[i][j] = true;

                    while (!st.empty())
                    {
                        pair<int, int> tp = st.top();
                        st.pop();

                        int x = tp.first;
                        int y = tp.second;

                        for (int dx = -1; dx <= 1; ++dx)
                            for (int dy = -1; dy <= 1; ++dy)
                            {
                                int nx = x + dx;
                                int ny = y + dy;

                                if (0 <= nx && nx < n && 0 <= ny && ny < m)
                                    if (a[nx][ny] && !visited[nx][ny])
                                    {
                                        visited[nx][ny] = true;
                                        st.push(make_pair(nx, ny));
                                    }
                            }
                    }
                }
            }
        }

        cout << cnt << "\n";
    }
}