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

        long long prev2 = 0, prev1 = 0;
        vector<long long> dp(n, 0);

        for (int i = 0; i < n; ++i)
        {
            dp[i] = max(prev1, prev2 + a[i]);
            prev2 = prev1;
            prev1 = dp[i];
        }

        cout << dp[n - 1] << "\n";
    }
}