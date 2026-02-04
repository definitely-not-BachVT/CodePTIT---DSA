#include <bits/stdc++.h>
using namespace std;

int n, k;
long long lst = -LLONG_MAX;
vector<long long> curr;
void Try(vector<long long> &a, int idx, int sz)
{
    if (sz == k)
    {
        for (long long x : curr)
            cout << x << " ";
        cout << "\n";

        return;
    }

    if (idx == n || sz > k)
        return;

    if (a[idx] > lst)
    {
        curr.push_back(a[idx]);
        Try(a, idx + 1, sz + 1);
        curr.pop_back();
    }

    Try(a, idx + 1, sz);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        curr.clear();
        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        sort(a.begin(), a.end());
        Try(a, 0, 0);
    }
}