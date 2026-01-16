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
        int mi1 = INT_MAX;
        int mi2 = INT_MAX;

        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (a[i] < mi1)
            {
                mi2 = mi1;
                mi1 = a[i];

                continue;
            }

            if (a[i] < mi2 && a[i] != mi1)
                mi2 = a[i];
        }

        if (mi1 != INT_MAX && mi2 != INT_MAX)
            cout << mi1 << " " << mi2 << "\n";
        else
            cout << "-1\n";
    }
}