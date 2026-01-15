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
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        auto it = lower_bound(a.begin(), a.end(), k);
        if (it == a.end())
        {
            cout << "NO\n";
            continue;
        }

        if (*it != k)
        {
            cout << "NO\n";
            continue;
        }

        cout << it - a.begin() + 1 << "\n";
    }
}