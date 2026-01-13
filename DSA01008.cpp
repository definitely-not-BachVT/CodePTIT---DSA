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
        int n, k;
        cin >> n >> k;

        vector<int> a(n, 0);
        for (int i = n - 1; i > n - 1 - k; --i)
            a[i] = 1;

        do
        {
            for (int i = 0; i < n; ++i)
                cout << a[i];
            cout << "\n";
        } while (next_permutation(a.begin(), a.end()));
    }
}