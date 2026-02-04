#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i].first >> a[i].second;

        sort(a.begin(), a.end(),
             [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 return a.second < b.second;
             });

        int cnt = 0;
        int lastEnd = -1;

        for (auto &x : a)
        {
            if (x.first >= lastEnd)
            {
                cnt++;
                lastEnd = x.second;
            }
        }

        cout << cnt << "\n";
    }
}
