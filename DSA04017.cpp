#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n), b(n - 1);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n - 1; i++)
            cin >> b[i];

        int left = 0, right = n - 2;
        int ans = n;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (a[mid] == b[mid])
            {
                left = mid + 1;
            }
            else
            {
                ans = mid + 1;
                right = mid - 1;
            }
        }

        cout << ans << "\n";
    }
}
