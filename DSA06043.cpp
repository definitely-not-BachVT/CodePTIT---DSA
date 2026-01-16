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

        long long sum = 0;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
        }

        bool found = false;
        long long curr = 0;
        for (int i = 0; i < n; ++i)
        {
            curr += a[i];
            if (curr == sum - curr + a[i])
            {
                found = true;
                cout << i + 1 << "\n";
                break;
            }
        }

        if (!found)
            cout << "-1\n";
    }
}