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
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        auto it = lower_bound(a.begin(), a.end(), x);
        if (*it == x)
            cout << "1\n";
        else
            cout << "-1\n";
    }
}