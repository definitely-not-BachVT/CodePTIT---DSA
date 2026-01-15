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

        long long sum = 0;
        long long mx = -LLONG_MAX;

        for (int i = 0; i < n; ++i)
        {
            sum += a[i];
            mx = max(mx, sum);

            if (sum < 0)
                sum = 0;
        }

        cout << mx << "\n";
    }
}