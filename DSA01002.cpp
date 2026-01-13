#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(k);
        for (int i = 0; i < k; ++i)
            cin >> a[i];

        int idx = k - 1;

        while (idx >= 0 && a[idx] == n - k + idx + 1)
            --idx;

        if (idx == -1)
        {
            for (int i = 0; i < k; ++i)
                cout << i + 1 << " ";
            cout << "\n";
        }
        else
        {
            a[idx]++;
            for (int i = idx + 1; i < k; ++i)
                a[i] = a[i - 1] + 1;

            for (int i = 0; i < k; ++i)
                cout << a[i] << " ";
            cout << "\n";
        }
    }
}