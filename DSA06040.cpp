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
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(n), b(m), c(k);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < m; ++i)
            cin >> b[i];
        for (int i = 0; i < k; ++i)
            cin >> c[i];

        bool found = false;
        int idx1 = 0, idx2 = 0, idx3 = 0;
        while (idx1 < n && idx2 < m && idx3 < k)
        {
            if (a[idx1] == b[idx2] && a[idx1] == c[idx3])
            {
                cout << a[idx1] << " ";
                ++idx1;
                ++idx2;
                ++idx3;

                found = true;
                continue;
            }

            int mi = min(a[idx1], min(b[idx2], c[idx3]));

            if (a[idx1] == mi)
            {
                ++idx1;
                continue;
            }

            if (b[idx2] == mi)
            {
                ++idx2;
                continue;
            }

            if (c[idx3] == mi)
            {
                ++idx3;
                continue;
            }
        }

        if (!found)
            cout << "-1\n";
        else
            cout << "\n";
    }
}