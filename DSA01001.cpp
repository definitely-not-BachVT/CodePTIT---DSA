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
        string a;
        cin >> a;

        int n = a.size();
        int idx = n - 1;

        while (idx >= 0 && a[idx] == '1')
        {
            a[idx] = '0';
            idx--;
        }

        if (idx >= 0)
            a[idx] = '1';

        cout << a << "\n";
    }
}