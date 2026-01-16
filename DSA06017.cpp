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
        int n, m;
        cin >> n >> m;

        multiset<int> ms;
        n = n + m;

        for (int i = 0; i < n; ++i)
        {
            int tmp;
            cin >> tmp;

            ms.insert(tmp);
        }

        for (int x : ms)
            cout << x << " ";
        cout << "\n";
    }
}