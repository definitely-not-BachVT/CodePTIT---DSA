#include <bits/stdc++.h>
using namespace std;

long long n, k;
vector<string> res;
vector<long long> curr;

void Try(vector<long long> &a, long long sum, long long idx)
{
    if (sum == k)
    {
        string tmp = "{";
        int size = curr.size();

        for (int i = 0; i < size - 1; ++i)
            tmp = tmp + to_string(a[i]) + " ";
        tmp = tmp + to_string(a[size - 1]) + "}";

        res.push_back(tmp);
        return;
    }

    if (sum > k)
        return;

    if (idx == n)
        return;

    for (int i = idx; i < n; ++i)
    {
        // Pick
        curr.push_back(a[i]);
        Try(a, sum + a[i], i);

        // Unpick
        curr.pop_back();
        Try(a, sum, i + 1);
    }
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
        res.clear();
        curr.clear();

        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        Try(a, 0, 0);

        sort(res.begin(), res.end());
        cout << res.size() << " ";
        for (string x : res)
            cout << x << " ";
        cout << "\n";
    }
}