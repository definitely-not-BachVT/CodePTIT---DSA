#include <bits/stdc++.h>
using namespace std;

int idx = 0;
vector<long long> a;

void sinh(long long x, int sz)
{
    a.push_back(x);

    if (sz == 16)
        return;

    sinh(x * 10 + 0, sz + 1);
    sinh(x * 10 + 9, sz + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    sinh(9, 0);
    sort(a.begin(), a.end());

    while (t--)
    {
        long long n;
        cin >> n;

        for (long long x : a)
            if (x % n == 0)
            {
                cout << x << "\n";
                break;
            }
    }
}