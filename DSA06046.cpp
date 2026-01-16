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
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.begin(), a.end());

        long long mi = INT_MAX;
        for (int i = 1; i < n; ++i)
            mi = min(mi, abs(a[i] - a[i - 1]));

        cout << mi << "\n";
    }
}