#include <bits/stdc++.H>
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

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int k = i;
            for (int j = i + 1; j < n; ++j)
                if (a[k] > a[j])
                    k = j;

            if (k != i)
            {
                swap(a[k], a[i]);
                ans++;
            }
        }

        cout << ans << "\n";
    }
}