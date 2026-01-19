#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char>(m, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    vector<vector<int>> visited(n, vector<int>(m, 0));

    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 'W')
            {
                stack<pair<int, int>> st;
                st.push(make_pair(i, j));

                while (!st.empty())
                {
                    pair<int, int> p = st.top();
                    st.pop();

                    int x = p.first, y = p.second;
                    visited[x][y] = 1;
                    a[x][y] = '.';

                    for (int idx1 = -1; idx1 <= 1; ++idx1)
                        for (int idx2 = -1; idx2 <= 1; ++idx2)
                        {
                            int nx = x + idx1;
                            int ny = y + idx2;

                            if (0 <= nx && nx < n && 0 <= ny && ny < m)
                            {
                                if (!visited[nx][ny] && a[nx][ny] == 'W')
                                    st.push(make_pair(nx, ny));
                            }
                        }
                }

                ++cnt;
            }
        }

    cout << cnt << "\n";
}