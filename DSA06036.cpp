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

        bool ok = false;
        for (int i = 0; i < n - 2; ++i)
        {
            int left = i + 1;
            int right = n - 1;

            if (ok)
                break;

            while (left < right)
            {
                if (a[i] + a[left] + a[right] == k)
                {
                    ok = true;
                    break;
                }
                if (a[i] + a[left] + a[right] < k)
                    ++left;
                else
                    --right;
            }
        }

        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}