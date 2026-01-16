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
        bool found = false;

        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(n), b(m), c(k);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < m; ++i)
            cin >> b[i];
        for (int i = 0; i < k; ++i)
            cin >> c[i];

        int idx1 = 0, idx2 = 0, idx3 = 0;
        while ((idx1 < n) && (idx2 < m) && (idx3 < k))
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

            if (mi == a[idx1])
            {
                ++idx1;
                continue;
            }

            if (mi == b[idx2])
            {
                ++idx2;
                continue;
            }

            if (mi == c[idx3])
            {
                ++idx3;
                continue;
            }
        }

        if (!found)
            cout << "NO\n";
        else
            cout << "\n";
    }
}