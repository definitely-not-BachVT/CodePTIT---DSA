#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
vector<long long> fac(1003), inv(1003);

long long binPow(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b % 2)
            ans = ans * a % MOD;
        a = a * a % MOD;

        b /= 2;
    }
    return ans;
}

void sinh()
{
    fac[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < 1003; ++i)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = binPow(fac[i], MOD - 2);
    }
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
        int n, k;
        cin >> n >> k;

        if (k > n)
        {
            cout << "0\n";
            continue;
        }

        cout << fac[n] * inv[n - k] % MOD << "\n";
    }
}