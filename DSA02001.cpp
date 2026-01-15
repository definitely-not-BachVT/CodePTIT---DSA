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

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        while (n)
        {
            cout << "[";
            for (int i = 0; i < n - 1; ++i)
                cout << a[i] << " ";
            cout << a[n - 1] << "]";
            cout << "\n";

            --n;
            vector<int> b(n);
            for (int i = 0; i < n; ++i)
                b[i] = a[i] + a[i + 1];
            a = b;
        }
    }
}