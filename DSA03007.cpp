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

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        reverse(a.begin(), a.end());

        long long su = 0;
        for (int i = 0; i < n; ++i)
            su += a[i] * b[i];
        cout << su << "\n";
    }
}