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
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.begin(), a.end());

        int idx = 0;
        while (a[idx] == 0)
            ++idx;

        bool left = true;
        long long trai = 0;
        long long phai = 0;

        while (idx < n)
        {
            if (left)
            {
                left = false;
                trai = trai * 10 + a[idx];

                ++idx;
            }
            else
            {
                left = true;
                phai = phai * 10 + a[idx];

                ++idx;
            }
        }

        cout << trai + phai << '\n';
    }
}