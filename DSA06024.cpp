#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int idx = 1;
    for (int i = 0; i < n - 1; ++i)
    {
        long long mi_pos = i, mi = INT_MAX;
        for (int j = i; j < n; ++j)
        {
            if (a[j] < mi)
            {
                mi = a[j];
                mi_pos = j;
            }
        }

        if (i != mi_pos)
            swap(a[i], a[mi_pos]);

        cout << "Buoc " << idx++ << ": ";
        for (int j = 0; j < n; ++j)
            cout << a[j] << " ";
        cout << "\n";
    }
}