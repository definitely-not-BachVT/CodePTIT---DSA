#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<string> res;
    int step = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        bool ok = false;

        for (int j = 0; j < n - i - 1; ++j)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                ok = true;
            }
        }

        if (ok)
        {
            string tmp = "Buoc " + to_string(step++) + ": ";
            for (int x : a)
                tmp += to_string(x) + " ";
            res.push_back(tmp);
        }
    }

    for (string x : res)
        cout << x << "\n";
}
