#include <bits/stdc++.h>
using namespace std;

long long n, k;
set<vector<long long>> res;
vector<long long> curr;
long long sum = 0;

void Try(vector<long long> &a, int idx)
{
    if (sum > k)
        return;

    if (sum == k)
    {
        res.insert(curr);
        return;
    }

    if (idx == n)
        return;

    sum += a[idx];
    curr.push_back(a[idx]);
    Try(a, idx + 1);

    sum -= a[idx];
    curr.pop_back();
    Try(a, idx + 1);
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
        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.begin(), a.end());

        Try(a, 0);

        for (vector<long long> x : res)
        {
            int size = x.size();
            cout << "[";

            for (int i = 0; i < size - 1; ++i)
                cout << x[i] << " ";
            cout << x[size - 1] << "] ";
        }

        if (res.size() == 0)
            cout << -1;

        curr.clear();
        res.clear();

        cout << "\n";
    }
}