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

        vector<int> mark(10, 0);
        vector<int> a(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            string s = to_string(a[i]);

            for (char c : s)
                mark[c - '0']++;
        }

        for (int i = 0; i < 10; ++i)
            if (mark[i])
                cout << i << " ";
        cout << "\n";
    }
}