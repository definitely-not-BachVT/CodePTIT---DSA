#include <bits/stdc++.h>
using namespace std;

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
        map<int, int> mp;

        bool found = false;
        int res;

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            mp[a[i]]++;

            if (mp[a[i]] > n / 2)
            {
                found = true;
                res = a[i];
            }
        }

        if (found)
            cout << res << "\n";
        else
            cout << "NO\n";
    }
}