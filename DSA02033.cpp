#include <bits/stdc++.h>
using namespace std;

int n;
bool check(vector<int> &a)
{
    for (int i = 0; i < n - 1; ++i)
        if (a[i] == a[i + 1] - 1 || a[i] == a[i + 1] + 1)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            a[i] = i + 1;

        do
        {
            if (check(a))
            {
                for (int i = 0; i < n; ++i)
                    cout << a[i];
                cout << "\n";
            }
        } while (next_permutation(a.begin(), a.end()));
    }
}