#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second > b.second)
        return true;
    else if (a.second == b.second)
    {
        if (a.first < b.first)
            return true;
        return false;
    }
    return false;
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
        int n;
        cin >> n;

        vector<int> a(n);
        vector<pair<int, int>> ans(n);
        vector<int> mark(1e5 + 3, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            mark[a[i]]++;
        }

        for (int i = 0; i < n; ++i)
            ans[i] = make_pair(a[i], mark[a[i]]);
        sort(ans.begin(), ans.end(), cmp);

        for (auto x : ans)
            cout << x.first << " ";
        cout << "\n";
    }
}