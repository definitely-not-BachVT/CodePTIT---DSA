#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int idx = 1;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
            if (a[i] > a[j])
                swap(a[i], a[j]);

        cout << "Buoc " << idx++ << ": ";
        for (int j = 0; j < n; ++j)
            cout << a[j] << " ";
        cout << "\n";
    }
}
