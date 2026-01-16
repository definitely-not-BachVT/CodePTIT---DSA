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

        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        int pos = n;
        int res;
        bool found = false;

        map<int, int> mp;
        for (int i = 1; i <= n; ++i)
        {
            if (mp[a[i]] == 0)
                mp[a[i]] = i;
            else
            {
                if (mp[a[i]] < pos)
                {
                    found = true;
                    res = a[i];
                    pos = mp[a[i]];
                }
            }
        }

        if (found)
            cout << res << "\n";
        else
            cout << "NO\n";
    }
}
