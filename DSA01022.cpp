#include <bits/stdc++.h>
using namespace std;

vector<long long> fac(12);
void sinh()
{
    fac[0] = 1;
    for (int i = 1; i < 12; ++i)
        fac[i] = i * fac[i - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    sinh();

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        vector<bool> visited(n + 2, false);
        long long res = 1;

        for (int i = 0; i < n; ++i)
        {
            int cnt = 0;
            for (int j = 1; j < a[i]; ++j)
                if (!visited[j])
                    ++cnt;

            res += cnt * fac[n - i - 1];
            visited[a[i]] = true;
        }

        cout << res << "\n";
    }
}