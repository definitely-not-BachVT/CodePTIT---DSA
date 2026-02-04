#include <bits/stdc++.h>
using namespace std;

int n;
long long k;
vector<long long> a, curr;
vector<vector<long long>> res;

void Try(int idx, long long sum)
{
    if (sum == k)
    {
        res.push_back(curr);
        return;
    }

    if (idx == n || sum > k)
        return;

    if (sum + a[idx] <= k)
    {
        curr.push_back(a[idx]);
        Try(idx, sum + a[idx]);
        curr.pop_back();
    }

    Try(idx + 1, sum);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        a.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        sort(a.begin(), a.end());

        curr.clear();
        res.clear();

        Try(0, 0);

        if (res.empty())
        {
            cout << "-1\n";
            continue;
        }

        for (auto &v : res)
        {
            cout << "[";
            for (int i = 0; i < v.size(); ++i)
            {
                if (i)
                    cout << " ";
                cout << v[i];
            }
            cout << "]";
        }
        cout << "\n";
    }
}
