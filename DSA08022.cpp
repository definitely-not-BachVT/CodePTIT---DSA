#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, k;
    cin >> n >> k;

    vector<vector<long long>> a(n, vector<long long>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        p[i] = i;

    vector<vector<int>> res;
    do
    {
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += a[i][p[i]];
            if (sum > k)
                break;
        }

        if (sum == k)
            res.push_back(p);

    } while (next_permutation(p.begin(), p.end()));

    cout << res.size() << "\n";
    for (auto x : res)
    {
        for (auto y : x)
            cout << y + 1 << " ";
        cout << "\n";
    }
}