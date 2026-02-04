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
        long long n, k;
        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        long long cnt = 0;
        sort(a.begin(), a.end());

        long long left = 0;
        for (int right = 1; right < n; ++right)
        {
            while (a[right] - a[left] >= k)
                ++left;

            cnt += right - left;
        }

        cout << cnt << "\n";
    }
}