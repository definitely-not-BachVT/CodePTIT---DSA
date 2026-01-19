#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<string> res;
    int idx = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        int mi_pos = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[mi_pos])
                mi_pos = j;

        if (mi_pos != i)
            swap(a[i], a[mi_pos]);

        string tmp = "Buoc " + to_string(idx++) + ": ";
        for (int j = 0; j < n; ++j)
            tmp += to_string(a[j]) + " ";
        res.push_back(tmp);
    }

    for (int i = n - 2; i >= 0; --i)
        cout << res[i] << "\n";
}
