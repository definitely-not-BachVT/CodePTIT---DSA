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
    sort(a.begin(), a.end());

    long long mx = -LLONG_MAX;
    mx = max(mx, a[n - 1] * a[n - 2] * a[n - 3]);
    mx = max(mx, a[n - 1] * a[1] * a[0]);
    mx = max(mx, a[1] * a[0]);

    cout << mx << "\n";
}