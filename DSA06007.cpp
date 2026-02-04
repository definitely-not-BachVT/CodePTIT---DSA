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

        int fi = -1, lst = n;

        vector<long long> pre(n); // prefix max

        pre[0] = a[0];
        for (int i = 1; i < n; ++i)
            pre[i] = max(pre[i - 1], a[i]);

        vector<long long> suf(n); // suffix min
        suf[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i)
            suf[i] = min(suf[i + 1], a[i]);

        int left = 0, right = n - 1;
        for (int i = 0; i < n; ++i)
            if (suf[i] != pre[i])
            {
                left = i;
                break;
            }

        for (int i = n - 1; i >= 0; --i)
            if (suf[i] != pre[i])
            {
                right = i;
                break;
            }

        cout << left + 1 << " " << right + 1 << "\n";
    }
}