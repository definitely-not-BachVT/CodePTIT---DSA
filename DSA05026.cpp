#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long C, n;
    cin >> C >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<bool> dp(C + 2, false);
    dp[0] = true;

    for (int i = 0; i < n; ++i)
        for (int j = C; j >= a[i]; --j)
            dp[j] = dp[j] || dp[j - a[i]];

    for (int i = C; i >= 0; --i)
        if (dp[i])
        {
            cout << i << "\n";
            break;
        }
}