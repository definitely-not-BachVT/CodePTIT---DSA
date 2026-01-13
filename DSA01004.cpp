#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < k; ++i)
            a[i] = 1;

        do
        {
            for (int i = 0; i < n; ++i)
                if (a[i])
                    cout << i + 1;
            cout << " ";
        } while (prev_permutation(a.begin(), a.end()));

        cout << "\n";
    }
}