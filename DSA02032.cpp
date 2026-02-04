#include <bits/stdc++.h>
using namespace std;

long long n, k;
vector<vector<long long>> res;
vector<long long> curr;

void Try(vector<long long> &a, long long sum, int idx)
{
    if (sum == k)
    {
        res.push_back(curr);
        return;
    }

    if (sum > k || idx == n)
        return;

    if (sum + a[idx] <= k)
    {
        curr.push_back(a[idx]);
        Try(a, sum + a[idx], idx);
        curr.pop_back();
    }

    Try(a, sum, idx + 1);
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
        sort(a.begin(), a.end());

        Try(a, 0, 0);
        res.erase(unique(res.begin(), res.end()), res.end());

        int SZ = res.size();
        if (SZ)
        {
            cout << SZ << " ";
            for (vector<long long> x : res)
            {
                int sz = x.size();
                cout << "{";

                for (int i = 0; i < sz - 1; ++i)
                    cout << x[i] << " ";
                cout << x[sz - 1] << "} ";
            }
            cout << "\n";
        }
        else
            cout << "-1\n";
    }
}