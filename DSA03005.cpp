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

        long long sum = 0;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
        }

        sort(a.begin(), a.end());

        long long opt1 = 0, opt2 = 0;
        long long sum1 = 0, sum2 = 0;

        for (int i = 0; i < k; ++i)
            sum1 += a[i];
        sum2 = sum - sum1;
        opt1 = abs(sum2 - sum1);

        sum1 = 0;
        sum2 = 0;

        reverse(a.begin(), a.end());
        for (int i = 0; i < k; ++i)
            sum1 += a[i];
        sum2 = sum - sum1;
        opt2 = abs(sum2 - sum1);

        cout << max(opt1, opt2) << '\n';
    }
}