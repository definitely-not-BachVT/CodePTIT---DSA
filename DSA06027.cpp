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

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int idx = 1;
        vector<string> res;
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
                if (a[i] > a[j])
                    swap(a[i], a[j]);

            string tmp = "Buoc " + to_string(idx) + ": ";
            ++idx;

            for (int j = 0; j < n; ++j)
                tmp = tmp + to_string(a[j]) + " ";
            res.push_back(tmp);
        }

        for (int i = n - 2; i >= 0; --i)
            cout << res[i] << "\n";
    }
}
