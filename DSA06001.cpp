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
        int left = 0, right = n - 1;

        int idx = 0;
        while (idx < n)
        {
            if (idx++ % 2)
                cout << a[left++] << " ";
            else
                cout << a[right--] << " ";
        }

        cout << "\n";
    }
}