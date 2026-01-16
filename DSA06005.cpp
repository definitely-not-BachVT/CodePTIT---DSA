/*
DSA06005 và DSA04008 đều sử dụng chung một lời giải.
Output mẫu của DSA06005 đang bị sai.
*/

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

        vector<int> mark(1e5 + 3, 0);
        vector<int> a(n), b(m);

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            mark[a[i]] = 1;
        }

        for (int i = 0; i < m; ++i)
        {
            cin >> b[i];
            if (mark[b[i]] == 1)
                mark[b[i]] = 2;
            else
                mark[b[i]] = 1;
        }

        for (int i = 0; i < 1e5 + 3; ++i)
            if (mark[i])
                cout << i << " ";
        cout << "\n";

        for (int i = 0; i < 1e5 + 3; ++i)
            if (mark[i] == 2)
                cout << i << " ";
        cout << "\n";
    }
}