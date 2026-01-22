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
        long long k;

        cin >> n >> k;
        vector<long long> a(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.begin(), a.end());

        long long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int pos1 = lower_bound(a.begin() + i + 1, a.end(), k - a[i]) - a.begin();
            int pos2 = upper_bound(a.begin() + i + 1, a.end(), k - a[i]) - a.begin();

            ans += pos2 - pos1;
        }

        cout << ans << "\n";
    }
}
