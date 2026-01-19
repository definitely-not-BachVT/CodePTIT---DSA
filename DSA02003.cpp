#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<long long>> a(n, vector<long long>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> a[i][j];

        set<string> res;
        stack<tuple<string, int, int>> st;

        if (a[0][0] == 1)
            st.push(make_tuple("", 0, 0));

        while (!st.empty())
        {
            auto [path, y, z] = st.top();
            st.pop();

            if (y == n - 1 && z == n - 1)
            {
                res.insert(path);
                continue;
            }

            if (y + 1 < n && a[y + 1][z] == 1)
                st.push(make_tuple(path + "D", y + 1, z));

            if (z + 1 < n && a[y][z + 1] == 1)
                st.push(make_tuple(path + "R", y, z + 1));
        }

        if (res.empty())
            cout << "-1\n";
        else
        {
            for (auto &s : res)
                cout << s << " ";
            cout << "\n";
        }
    }
}
