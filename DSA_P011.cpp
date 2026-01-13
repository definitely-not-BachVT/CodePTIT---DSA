#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == '#')
            {
                ++cnt;
                a[i][j] = '.';
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));

                while (!q.empty())
                {
                    pair<int, int> p = q.front();
                    q.pop();

                    int x = p.first;
                    int y = p.second;

                    if (x - 1 >= 0 && a[x - 1][y] == '#')
                    {
                        q.push(make_pair(x - 1, y));
                        a[x - 1][y] = '.';
                    }

                    if (y - 1 >= 0 && a[x][y - 1] == '#')
                    {
                        q.push(make_pair(x, y - 1));
                        a[x][y - 1] = '.';
                    }

                    if (x + 1 < n && a[x + 1][y] == '#')
                    {
                        q.push(make_pair(x + 1, y));
                        a[x + 1][y] = '.';
                    }

                    if (y + 1 < m && a[x][y + 1] == '#')
                    {
                        q.push(make_pair(x, y + 1));
                        a[x][y + 1] = '.';
                    }
                }
            }
        }

    cout << cnt;
}