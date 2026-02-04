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

        long long cnt = 0;
        for (int i = 0; i < n - 2; ++i)
        {
            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                if (a[i] + a[left] + a[right] < k)
                {
                    cnt += right - left;
                    ++left;
                }
                else
                    --right;
            }
        }

        cout << cnt << "\n";
    }
}