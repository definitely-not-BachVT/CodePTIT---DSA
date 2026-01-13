#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<long long> mx_prefix(n);
    mx_prefix[0] = max((long long)0, a[0]);

    for (int i = 1; i < n; ++i)
        mx_prefix[i] = max(mx_prefix[i - 1], mx_prefix[i - 1] + a[i]);

    while (q--)
    {
        int left, right;
        cin >> left >> right;

        --left;
        --right;

        if (left != 0)
            cout << mx_prefix[right] - mx_prefix[left - 1];
        else
            cout << mx_prefix[right];

        cout << "\n";
    }
}