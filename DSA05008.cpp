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

        vector<bool> dp(k + 3, false);
        dp[0] = true;

        for (int i = 0; i < n; ++i)
            for (int j = k; j >= a[i]; --j)
                dp[j] = dp[j] || dp[j - a[i]];

        if (dp[k])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}