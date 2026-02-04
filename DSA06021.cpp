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
        int n, x, idx;
        cin >> n >> x;

        int fi_left, fi_right;

        vector<int>
            a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (i > 0 && a[i] < a[i - 1])
                idx = i;
        }

        fi_left = a[0];
        fi_right = (idx > 0) ? a[idx] : a[0];

        if (fi_left <= x && x <= fi_right)
        {
            cout << lower_bound(a.begin(), a.begin() + idx, x) - a.begin() + 1 << "\n";
        }
        else
            cout << lower_bound(a.begin() + idx, a.end(), x) - a.begin() + 1 << "\n";
    }
}