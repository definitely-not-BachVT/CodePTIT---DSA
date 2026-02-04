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

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        vector<int> pref(n); // mi
        vector<int> suf(n);  // mx;

        pref[0] = a[0];
        for (int i = 1; i < n; ++i)
            pref[i] = min(pref[i - 1], a[i]);
        suf[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i)
            suf[i] = max(suf[i + 1], a[i]);

        int i = 0, j = 0;
        int mx = -1;
        while (i < n && j < n)
        {
            if (pref[i] < suf[j])
            {
                mx = max(mx, j - i);
                ++j;
            }
            else
                ++i;
        }

        cout << mx << "\n";
    }
}