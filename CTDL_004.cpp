#include <bits/stdc++.h>
using namespace std;

int n, k;
long long cnt = 0;

void Try(const vector<long long> &a, int idx, int sz, long long last)
{
    if (sz == k)
    {
        ++cnt;
        return;
    }
    if (idx == n)
        return;

    if (sz == 0 || a[idx] > last)
        Try(a, idx + 1, sz + 1, a[idx]);

    Try(a, idx + 1, sz, last);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cnt = 0;
    Try(a, 0, 0, LLONG_MIN);

    cout << cnt;
}
