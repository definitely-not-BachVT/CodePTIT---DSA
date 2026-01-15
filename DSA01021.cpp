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

        vector<int> a(k);
        vector<int> mark(n + 3, 0);
        for (int i = 0; i < k; ++i)
        {
            cin >> a[i];
            mark[a[i]]++;
        }

        vector<int> p1 = a;
        vector<int> p2(k);

        int idx = k - 1;
        while (idx >= 0 && a[idx] == n - k + idx + 1)
            --idx;

        if (idx == -1)
        {
            cout << k << "\n";
            continue;
        }

        a[idx]++;
        for (int i = idx + 1; i < k; ++i)
            a[i] = a[i - 1] + 1;

        p2 = a;

        int cnt = 0;
        for (int x : p2)
            if (mark[x] == 0)
                ++cnt;

        cout << cnt << "\n";
    }
}