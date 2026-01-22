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

        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        vector<long long> tails;
        for (int i = 0; i < n; ++i)
        {
            auto it = upper_bound(tails.begin(), tails.end(), a[i]);
            if (it == tails.end())
                tails.push_back(a[i]);
            else
                *it = a[i];
        }

        cout << n - tails.size() << "\n";
    }
}