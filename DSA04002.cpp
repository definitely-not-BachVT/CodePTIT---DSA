#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long binPow(long long a, long long k)
{
    if (k == 1)
        return a;

    long long tmp = binPow(a, k / 2);
    if (k % 2)
        return tmp % MOD * tmp % MOD * a % MOD;
    else
        return tmp % MOD * tmp % MOD;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string n, r;
        cin >> n;

        r = n;
        reverse(r.begin(), r.end());

        cout << binPow(stoll(n), stoll(r)) << "\n";
    }

    // for (int i = 1; i < 15; ++i)
    //     cout << binPow(i, rev(i)) << "\n";
}
