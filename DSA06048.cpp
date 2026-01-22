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

        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        vector<long long> b = a;
        sort(b.begin(), b.end());

        int pos = lower_bound(b.begin(), b.end(), a[0]) - b.begin();
        cout << (n - pos) % n << "\n";
    }
}
