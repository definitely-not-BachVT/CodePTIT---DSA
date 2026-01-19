#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        long long sum = 0;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
        }

        if (sum % 2)
        {
            cout << "NO\n";
            continue;
        }

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int x : a)
            for (int i = target; i >= x; --i)
                dp[i] = dp[i] || dp[i - x];

        if (dp[target])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}