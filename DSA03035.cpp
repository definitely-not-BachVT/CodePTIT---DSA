#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int mx = 1, curr = 1;
    for (int i = 1; i < n; ++i)
    {
        if (pos[i] < pos[i + 1])
            ++curr;
        else
            curr = 1;

        mx = max(mx, curr);
    }

    cout << n - mx;
}