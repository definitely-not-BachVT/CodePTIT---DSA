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

        vector<string> res;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        while (n)
        {
            string s = "[";
            for (int i = 0; i < n - 1; ++i)
                s = s + to_string(a[i]) + " ";
            s = s + to_string(a[n - 1]) + "]";
            res.push_back(s);

            --n;
            vector<int> b(n);
            for (int i = 0; i < n; ++i)
                b[i] = a[i] + a[i + 1];
            a = b;
        }

        int size = res.size();
        for (int i = size - 1; i >= 0; --i)
            cout << res[i] << " ";
        cout << "\n";
    }
}