#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<long long> a(53);
    a[0] = 1;

    for (int i = 0; i < 53; ++i)
        for (int j = 1; j < 4; ++j)
            if (i - j >= 0)
                a[i] = a[i] + a[i - j];

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        cout << a[n] << "\n";
    }
}