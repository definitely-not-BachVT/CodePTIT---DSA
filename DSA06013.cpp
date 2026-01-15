#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        map<int, int> mp;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            mp[a[i]]++;
        }

        if (mp[x])
            cout << mp[x] << "\n";
        else
            cout << "-1\n";
    }
}